# WUTF8Console C++ Library

**A C++ library to have a Windows UTF-8 console for Unicode input and output.**

## Table of Contents
[Overview](#Overview)<br>
[Requirements](#Requirements)<br>
[Examples](#Examples)<br>
[Instructions](#Instructions)<br>
[Background](#Background)<br>
[Using Namespaces](#Using-namespaces)<br>
[Passing in Unicode UTF-8 Arguments to main](#Passing-in-Unicode-UTF-8-Arguments-to-main)<br>
[Input Buffer Size](#Input-Buffer-Size)<br>
[Single Characters and Unicode](#Single-Characters-and-Unicode)<br>
[Windows Console Font](#Windows-Console-Font)<br>
[Source Code and Precompiled Binaries](#Source-Code-and-Precompiled-Binaries)<br>
[Command Reference](#Command-Reference)<br>
[License](#License)<br>
[Contact](#Contact)<br>
[Thanks](#Thanks)<br>

## Overview

The Windows console (called *Windows Terminal* or *Command Prompt*) cannot input in Unicode (UTF-8) using standard C++ input commands such as `cin >>`, `getline()`, and `scanf()`, even though it can output in Unicode (UTF-8). Platforms such as Linux and macOS don't have this problem. The [WUTF8Console C++ library](https://github.com/Jalopy-Tech/WUTF8Console/releases) solves this problem in Windows.

This library allows a C++ console program to use all common C++ input commands to input with Unicode (UTF-8) in Windows. It works by replacing the standard commands with ones that handle UTF-16 input needed by Windows and automatically translating the input to UTF-8 for data types such as `std::string` and `char*`. The replacement commands include `cin >>` (operators and other methods), `getline()`,  and `scanf()`. Output commands from namespace *std* such as `cout <<` , `cerr <<` and `printf()` also work normally.

Because this library allows both input and output in Unicode (UTF-8), modern IDEs such as [Embarcadero Dev-C++ 6.3](https://github.com/Embarcadero/Dev-Cpp),  [Code::Blocks](https://www.codeblocks.org/), [Visual Studio Code](https://code.visualstudio.com/) and [Visual Studio](https://visualstudio.microsoft.com/) can be used instead of old IDEs such as [Dev-C++ 5.2](https://sourceforge.net/projects/orwelldevcpp/). The IDE and console application won't be tied to a Windows locale coding page.

Using cross-platform compilation is not a problem when using this library.

## Requirements

The following are required to use the WUTF8Console C++ library:

- Source code and precompiled binaries available in the [releases](https://github.com/Jalopy-Tech/WUTF8Console/releases) section.
- Windows 10 and 11. Older Windows operating systems may work.
- The Windows console needs to be set to a font that can display the desired Unicode characters to see it working. See the section [Windows Console Font](#Windows-Console-Font).

### Compiling from Source

The WUTF8Console C++ library can be compiled from source. This is the recommended approach. The requirements are:

- C++ version of C++14 or higher. It compiles with ISO C++14, ISO C++17 and ISO C++20. It won't compile with C++11.
- Compilers [TDM GCC](https://gcc.gnu.org/), [MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/), [MinGW-w64](https://www.mingw-w64.org/), and [LLVM Clang](https://clang.llvm.org/) work.

For further information, see the section [Source Code and Precompiled Binaries](#Source-Code-and-Precompiled-Binaries).

### Using Precompiled Binaries

Pre-compiled WUTF8Console C++ library binaries are available in both release and debug versions. They have been prepared using the following compilers:

- MinGW-w64 v8.1.0 (static and dynamic-link libraries)
- MSVC using Visual Studio 2022 (static and dynamic-link libraries)
- TDM GCC 9.2 (static and dynamic-link libraries)
- LLVM Clang (static libraries only)

If you experience problems, it is recommended to compile from source code. For further information, see the section [Source Code and Precompiled Binaries](#Source-Code-and-Precompiled-Binaries).

## Examples

Here is an example of main.cpp using the library for Windows-only compilation:

```cpp
// WUTF8Console C++ library - main() example for Windows
// https://github.com/Jalopy-Tech/WUTF8Console

#include <iostream>
#include <stdio.h>


// Include the WUTF8Console C++ library
// Please don't use "using namespace std;" as this will create
// an ambiguous compiler error.

#include "wutf8console.h"

using wutf8console::cin;
using wutf8console::getline;
using wutf8console::scanf;
using std::cout;
using std::endl;

using std::string;


// If Unicode UTF-8 is needed in the arguments in main()'s argv,
// link the libwinsane.o file when compiling in Windows.

int main(int argc, char** argv) {

	// Set the console to UTF-8 in Windows.
	
	wutf8console::setupConsole();


	// Print welcome message using printf().
	
	char website[] = "https://github.com/Jalopy-Tech/WUTF8Console";
	printf("Welcome to the WUTF8Console library for C++ \n%s\n\n", website);


	// Print info using cout <<
	
	cout << "In Windows, this library fixes common input commands such as " << endl;
	cout << "cin, getline, and scanf when using Unicode UTF-8." << endl << endl;
	cout << "Make sure the Windows console is set to a font that can " << endl;
	cout << "display your desired Unicode characters." << endl <<endl;


	// Prompt for string using cout << and get input using getline() with cin
	
	cout << "Please enter some text that includes Unicode: ";
	string s;
	getline(cin, s);
	cout << endl << "You entered: " << s << endl;
	cout << endl << "Thank you." << endl;

	return 0;
}
```

Here is an example of main.cpp using the library for cross-platform compilation:

```cpp
// WUTF8Console C++ library main() example for cross-platform

#include <iostream>
#include <stdio.h>

// Use these input commands.
// Include the WUTF8Console C++ library if using Windows
// Please don't use "using namespace std;" as this will create
// an ambiguous compiler error.

#ifdef _WIN32 // Windows platform (including 64 bit)
#include "wutf8console.h"
using wutf8console::cin;
using wutf8console::getline;
using wutf8console::scanf;
#else // Non-Windows platform
using std::cin;
using std::getline;
using std::scanf;
#endif


// Use these output commands.

using std::cout;
using std::endl;


// Use these other commands.

using std::string;


// If Unicode UTF-8 is needed in the arguments in main()'s argv,
// link the libwinsane.o file when compiling in Windows.

int main(int argc, char** argv)
{

	// Set the console to UTF-8 in Windows.
#ifdef _WIN32 // Windows platform (including 64 bit)
	wutf8console::setupConsole();
#endif

	// Print welcome message.

	string website = "https://github.com/Jalopy-Tech";

	cout << "Welcome to the WUTF8Console library for C++ " << endl;
	cout << "(" << website << ")" << endl << endl;
	cout << "In Windows, this library fixes common input commands such as ";
	cout << "cin, getline, and scanf when using Unicode UTF-8." << endl;
	cout << "For non-Windows platforms, the standard commands will be used.";
	cout << endl << endl;
	cout << "Make sure your console is set to a font that can display your ";
	cout << "desired Unicode characters." << endl <<endl;


	// Get input and print it out.

	cout << "Please enter some text that includes Unicode: ";
	string s;
	getline(cin, s);
	cout << "You entered: " << s << endl;

	cout << "Thank you." << endl;

	return 0;
}
```

Here is a screenshot of the Windows console using the WUFT8Console C++ library:

<img align="center"  src="./images/Screenshot-WUTF8Console.png" alt="Screenshot-WUTF8Console"  />

## Instructions

To use the WUTF8Console C++ library  with your console application, do the following:

1. Download the [latest release](https://github.com/Jalopy-Tech/WUTF8Console/releases) and add the source code or link the library to your source code.

2. Include this header in your source code:

   ```cpp
   #include "wuft8console.h"
   ```

   For cross-platform compilation, put this inside `#ifdef _WIN32` guards.

3. Use `using wutf8console::[member-name];`declarations for input commands and use `using std::[member-name];` declarations for output commands. Don't use the `using namespace std;` directive as this will create an ambiguous compiler error (and is considered bad practice anyway).

   Use a set of input commands and a set of output commands.  Example code to use `cin`, `getline()`, `scanf()`, `cout` and `endl`:

   ```cpp
   // Use input commands
   
   using wutf8console::cin;
   using wutf8console::getline;
   using wutf8console::scanf;
   
   
   // Use output commands
   
   using std::cout;
   using std::endl;
   ```

   OR

   For cross-platform compilation, use two alternative sets of input commands (one for Windows and one for non-Windows) and one set of output commands.  Example code to use `cin`, `getline()`, `scanf()`, `cout` and `endl`:

   ```cpp
   #ifdef _WIN32 // Windows platform (including 64 bit)
   #include "wutf8console.h"
   using wutf8console::cin;
   using wutf8console::getline;
   using wutf8console::scanf;
   #else // Non-Windows platform
   using std::cin;
   using std::getline;
   using std::scanf;
   #endif
   
   
   // Use these output commands.
   
   using std::cout;
   using std::endl;
   ```

   For alternative namespace options, see the section [Using Namespaces](#Using-Namespaces).

4. Before doing any input from or output to the console, add this line:

   ```cpp
   wutf8console::setupConsole();
   ```

   For cross-platform compilation, put this inside `#ifdef _WIN32` guards. This command will set the Windows console to use Unicode.

5. Use the commands you declared such as `cin >>`, `getline()`, `scanf()`, `cout <<` and `printf()` normally. When the data types `std::string` and `char*` are used with these commands , Unicode will be input from and output to the Windows console correctly. Don't use wide character data types such as `wchar_t*`, `wstring` or `L"Wide Literal"`: they are not needed and they are not welcome!

6. If Unicode (UTF-8) is needed in the arguments passed into `main()`s `argv`list, link the *libwinsane.o* file when compiling in Windows. See the section [Passing in Unicode UTF-8 arguments to *main()*](#Passing-in-Unicode-UTF-8-arguments-to-main()).

7. Make sure the Windows console is set to a font that can display your desired Unicode characters. See the section [Windows Console Font](#Windows-Console-Font).

## Background

This library has been written for students learning C++ coding in Windows where foreign-language input to the Windows console is needed.  Before now, non-ASCII characters could only be entered with these commands when using an obsolete non-Unicode compliant IDE such as [Dev-C++ 5.2](https://sourceforge.net/projects/orwelldevcpp/) with the Windows locale coding page set to the desired language.

 Modern IDEs such as [Embarcadero Dev-C++ 6.3](https://github.com/Embarcadero/Dev-Cpp),  [Code::Blocks](https://www.codeblocks.org/), [Visual Studio Code](https://code.visualstudio.com/) and [Visual Studio](https://visualstudio.microsoft.com/) could not be used. These IDEs can now be used when using this library. 

I hope this library is useful for:

- Programmers who wish to create a simple Windows console application with Unicode input and/or output.
- Schools, teachers and students in non-English speaking environments where students are learning C++ in Windows. Online C++ resources and examples invariably use standard commands for input and output.
- Developers who wish to build a professional UTF-8-compliant console application (including cross-platform applications). Although this library hasn't been designed for such tasks, I would love to hear from you in this regard.

Without this library, there are only three possibilities in Windows for Unicode input to the Windows console:

1. Use the Windows locale setting to use non-Unicode Windows coding pages. In fact this isn't even Unicode and it's a mess! This doesn't work when using modern IDEs.

   OR

2. Use the wide-character versions of the C++ commands such as wscanf() and wcin >>. Good luck with this! They are fraught with problems and are a pain to use.

   OR

3. Use the Microsoft Windows API to input Unicode with commands such as `ReadConsole()`. This is a hassle when wishing to write a simple console application in C++. It is also unreasonable to expect students to do this when they are learning C++ for the first time and barely know basic programming constructs such as for loops and if/else statements!

## Using Namespaces

The input commands need to use the version in namespace *wutf8console* when compiled in Windows. The output commands can use the version in namespace *std*.

### Using *using* declarations

You can use `using` declarations for both input and output. See the section [Instructions](#Instructions). for an example. Don't use the `using namespace std;` directive as this will create an ambiguous compiler error (and is considered bad practice anyway). 

For cross-platform compilation,  input commands need two sets: one for Windows and one for non-Windows. Example code to use  `cin`, `getline()`, `scanf()`, `cout` and `printf()`:

```cpp
// Use these input commands.

#ifdef _WIN32 // Windows platform (including 64 bit)
#include "wutf8console.h"
using wutf8console::cin;
using wutf8console::getline;
using wutf8console::scanf;
#else // Non-Windows platform
using std::cin;
using std::getline;
using std::scanf;
#endif

// Use these output commands.

using std::cout;
using std::endl;


// Use other commands

using std::string;

//...

cout << "Welcome" << endl << "Enter your name: ";
string name;
cin >> name;
```

There are some commands such as `fgets()` and `gets()` that when used with a `using` declaration, might cause a "conflicts with a previous declaration" compile error. These commands have been depreciated since C++14, but if you need to use them, you can specify the namespace *wutf8console* explicitly for these commands as described in the next section.

### Specifying the namespace explicitly

You can specify the namespace explicitly for each command such as:

```cpp
std::cout << "Welcome" << std::endl << "Enter your name: ";
std::string name;
wutf8console::cin >> name;
```

To make this cross-platform compatible, use preprocessor directives to provide two alternatives for input:

```cpp
std::cout << "Welcome" << std::endl << "Enter your name: ";
std::string name;
#ifdef _WIN32 // Windows platforms (including 64-bit)
wutf8console::cin >> name;
#else // Non-windows platforms
std::cin >> name;
#endif
```

### Using the *using namespace* directive

Using the `using namespace` directive to include everything from the namespace is not considered good coding practice even though it features commonly in sample code such as the `using namespace std;` directive. If you wish to use this directive, make sure that there is no ambiguity between the namespace *wuft8console* and the namespace *std*.

Ambiguity can be avoided by using the `using namespace` directive in different scopes to avoid clashes.

Alternatively you could use the `using namespace std;` directive, but explicitly specify the namespace *wutf8console* in each input command. For example:

```cpp
using namespace std;

//...

cout << "Welcome" << endl << "Enter your name: ";
string name;
wutf8console::cin >> name;
```

To make this code cross-platform compatible, use preprocessor directives to provide two alternatives for input:

```cpp
using namespace std;

//...

cout << "Welcome" << endl << "Enter your name: ";
string name;
#ifdef _WIN32 // Windows platforms (including 64-bit)
wutf8console::cin >> name;
#else // Non-windows platforms
cin >> name;
#endif
```

## Passing in Unicode UTF-8 Arguments to main

When compiling in Windows, arguments won't be passed into`int main(int argc, char** argv)` as Unicode by default. A simple fix to this, if needed, is to use a library called [libwinsane](https://github.com/skeeto/scratch/tree/master/libwinsane) which consists of a single object file *libwinsane.o* which can be linked with your project when compiling/linking in Windows. No `#include` directive is needed in your source code.

You are welcome to try my pre-compiled [libwinsane.o](https://github.com/Jalopy-Tech/WUTF8Console/blob/main/libwinsane/libwinsane.o) file, but I recommend compiling it from source using the *make* command as follows:

1. Make sure your compiler (bin folder) is in your Windows PATH.

2. Download the 5 files in the [libwinsane repository](https://github.com/skeeto/scratch/tree/master/libwinsane) to a new local folder.

3. Edit the *Makefile* file: on line 2, change the line from:<br>
    `CROSS   = x86_64-w64-mingw32-`<br>
      to:<br>
    `CROSS   =`

4. Open the folder in a Windows console (Terminal).

5. Run the `make` command. Your make command might not be `make`. For example, it might be `mingw32-make`.

Once compiled, do the following:

1. Copy the *libwinsane.o* file to your source code folder.
2. Set you compiler/linker to link this file. This can be done using an IDE feature or by manually adding an option to the linker such as `.\libwinsane.o` . For tips on linking within a specific IDE, see the section [IDE Tips](#IDE-Tips).

To test your executable, run it in the console with an additional Unicode argument. The following code will output the argument:

```cpp
int main(int argc, char** argv) {

	// Set the console to UTF-8 in Windows.
	
	wutf8console::setupConsole();
	
    
	cout << "The executable is " << argv[0] << "." << endl;
	if (argc >= 2)
	    cout << "The first additional argument is " << argv[1] << "." << endl;
	else
	    cout << "There are no additional arguments." << endl;

	return 0;
}
```

## Input Buffer Size

The commands `scanf()` and `gets()` need to have a input buffer size which is set to an array size of 4,096 characters. If a different buffer size is required, the `INPUT_BUFFER_SIZE` value can be adjusted at the start of *wutf8console.h*.

## Single Characters and Unicode

The `char` data type uses one byte, which can only store ASCII characters and therefore cannot be used to store single Unicode characters. I recommend storing a single Unicode character as a `std::string` of length 1 or an `int`. I don't recommend using `wchar_t` as this may cause cross-platform issues.

Commands like `scanf("%c", &c);` and `cin >> c;` won't help: they will accept any Unicode character as input, but will only store an ASCII character in the `char` variable c.

## Windows Console Font

When using the Windows console (called *Windows Terminal* or *Command Prompt*), the font that is set needs to be able to display the desired Unicode characters.

To view or change the font, do the following:

1. Open the console.

2. Click on the top left icon, then select Properties.

3. The font and font size can be viewed and changed.

4. Click Ok to save changes.

Fonts such as *NimSimSun*, *Lucinda Console* or *Consolas* may be suitabe. If there are no suitable fonts, a suitable font may be available online for download. Adding the relevant language to Windows may also add a suitable font. For some languages, special changes may need to be done to allow the Windows console to display the desired font.

A particular Windows locale (a coding page) is not needed as Unicode UTF-8 is used instead.

## Source Code and Precompiled Binaries

Source code and precompiled binaries are available for download in the [releases](https://github.com/Jalopy-Tech/WUTF8Console/releases) section.

### Source Code

To compile with source code, add the `wutf8console.h` and `wutf8console.cpp` files from the `\src` folder to your source code. This is the recommended approach.

### Libwinsane Object File

The `libwinsane.o` precompiled object file is available from the `\obj` folder. To use this library, link this file to your project.

### Static Libraries

The precompiled static libraries are available in the `\lib` folder with the header available in the`\include` folder. There are release and debug versions of each. To add a static library:

- Include the `\include` folder
- Add the appropriate folder in the `\lib` folder to the library paths in your project.
- Link the appropriate `libwutf8console.a` or `wutf8console.lib` file to your project.

Libraries are available from the following compilers:

 - MinGW-w64 v8.1.0
- MSVC using Visual Studio 2022
- TDM GCC 9.2
- LLVM Clang

### Dynamic-Link Libraries (DLLs)

The precompiled dynamic-link libraries (DLLs) are available in folders in the `\lib` folder with the header available in the`\include`folder. There are release and debug versions of each. To add a dynamic-link library:

- Include the `\include` folder
- Add the appropriate folder in the `\lib` folder to the library paths in your project.
- Link the appropriate `libwutf8consoledll.a` or `wutf8consoledll.lib` file to your project.
- Copy the `wutf8console.dll` file to a location in the PATH for the executable such as in the folder of the executable.
- For compiling with MSVC, add the *preprocessor definition* `WUTF8CONSOLE_IMPORTS`in the project's properties.

Libraries are available from the following compilers:

 - MinGW-w64 v8.1.0
- MSVC using Visual Studio 2022
- TDM GCC 9.2

## Command Reference

The following commands are available in the *wutf8console* namespace:

### Input functions

```cpp
istream& getline(istream& is, string& str); // [recommended]
istream& getline(istream& is, string& str, const char delim); // [recommended]
int scanf(const char* format, ...);
int fscanf(FILE * stream, const char* format, ...);
char* fgets(char *str, int num, FILE *stream); // [depreciated!]
char* gets(char *str); // [depreciated!]
int getc(FILE *stream ); // [not recommended]
int fgetc(FILE *stream ); // [not recommended]
int getchar(); // [not recommended]
```

### cin >> input operators

```cpp
Cin& operator>>(string& s); // [recommended]
Cin& operator>>(char* cstr);
Cin& operator>>(char& c);  // [not recommended]
Cin& operator>>(T& t); // T is a generic typename // [recommended]
```

### cin istream public members

```cpp
streamsize gcount() const; // [not recommended]
int get(); // [not recommended]
Cin& get(char& c);  // [not recommended]
Cin& get(char* s, streamsize n); // [not recommended]
Cin& get(char* s, streamsize n, char delim); // [not recommended]
//Cin& get(streambuf& sb); // [not yet implemented]
//Cin& get(streambuf& sb, char delim); // [not yet implemented]
Cin& getline(char* s, streamsize n );
Cin& getline(char* s, streamsize n, char delim ); 
Cin& ignore(streamsize n = 1, int delim = EOF);
int peek();
Cin& putback(char c);
Cin& read(char* s, streamsize n);
streamsize readsome(char* s, streamsize n);
Cin& seekg(streampos pos);
Cin& seekg(streamoff off, ios_base::seekdir way);
int sync();
streampos tellg();
Cin& unget();
```

### cin ios public members

```cpp
bool bad() const;
void clear(iostate state = goodbit);
//istream& copyfmt(const istream& rhs); [not yet implemented]
bool eof() const;
iostate exceptions() const;
void exceptions(iostate except);
bool fail() const;
char fill() const;
char fill(char fillch);
bool good() const;
std::locale imbue(const locale& loc);
char narrow(char c, char dfault) const;
explicit operator bool() const;
bool operator!() const;
//streambuf* rdbuf() const; // [not yet implemented]
//streambuf* rdbuf (streambuf* sb); // [not yet implemented]
iostate rdstate() const;
void setstate(iostate state);
ostream* tie() const;
ostream* tie(ostream* tiestr);
char widen(char c) const;
```

### Other functions

```cpp
bool setupConsole(); // [necessary]
```

## License

Copyright &copy; 2022 Robert J. Joynt.

The WUTF8Console C++ Library is free software under the [MIT License](https://github.com/Jalopy-Tech/WUTF8Console/blob/main/LICENSE.md).

## Contact

For further inquires, please email: robertjjoynt@gmail.com .

## Thanks

- To Dokyun Ahn (Eric), my student, for bringing this problem to my attention and testing the library.
- [Chris Wellons](https://nullprogram.com/blog/2021/12/30/) for writing the [libwinsane library](https://github.com/skeeto/scratch/tree/master/libwinsane) which allows Unicode UTF-8 arguments to be passed into  a Windows console C++ program.
- To [Jarod42](https://stackoverflow.com/users/2684539/jarod42) for providing the [code](https://stackoverflow.com/questions/39101454/pushing-and-popping-the-first-element-of-a-stdtuple) to pop off the first element of a tuple in Stack Overflow.
