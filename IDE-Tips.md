## IDE Tips

### Embarcadero Dev-C++ 6.3

Here are some tips for using [Embarcadero Dev-C++ 6.3](https://github.com/Embarcadero/Dev-Cpp) and Unicode:

- If Unicode characters only display when the line with the Unicode is selected, do the following:

  1. Go to the menu *Tools* -> *Editor options...*.

  2. Select the *Fonts* page tab.

  3. Uncheck any boxes under the font that has the pattern *ID xxxxx translation missing*.

  4. Click *Ok* to save changes.

- If Unicode is present in the code, make sure the file is being saved as UTF-8 encoding. The application should prompt for this when saving for the first time. To manually check, use the menu: *File* -> *Save As...*.

- To link the [libwinsane library](#Passing-in-Unicode-UTF-8-Arguments-to-main) to a project, follow one of the instructions for linking a library below. The library folder is `\obj` and the library file is `libwinsane.o`.

- To link a library to a project, you can either specify the full path of the library or specify both the library file and library path folder separately as follows:

  1. Go to the menu *Project* -> *Project Options...*.

  2.  Go to the *Parameters* page tab.

  3. Click the *Add library or object* button.

  4.  Choose the library file. If you want to specify the library folder path separately, then edit out the path here.

  5. If you decided to specify the library folder path separately, go to the *Directories* page tab and then *Library Directories* sub page tab. Add the folder using the browser button in the bottom right. Make sure to use the *Add* button, so that the folder is added to the list above.

  6. Click *Ok* to save changes.

- To link a library for all projects using a particular compiler set, you can either specify the full path of the library or specify both the library file and library path folder separately as follows:

  1. Go to the menu *Tools* -> *Compiler Options...*.
  2.  Select the compiler set.
  3. Under the section *Add the following commands when calling the linker*, add the library. If you want to specify the library folder path separately, then only add the filename here otherwise include the full path. Separate this command from existing options using spaces. Don't put in a carriage-return character. Put the library in double quotes if it contains spaces. Don't include a hyphen prefix or letter prefix.
  4. If you decided to specify the library folder path separately, go to the *Directories* page tab and then *Library Directories* sub page tab. Add the folder using the browser button in the bottom right. Make sure to use the *Add* button, so that the folder is added to the list above.
  5. Click *Ok* to save changes.

- To add an include folder to a project:

  1. Go to the menu *Project* -> *Project Options...*.
  2.  Go to the *Directories* page tab and then *Include Directories* sub page tab.

  3. Add the folder using the browser button in the bottom right. Make sure to use the *Add* button, so that the folder is added to the list above.

  4. Click *Ok* to save changes.

- To add an include folder for all projects using a particular compiler set:

  1. Go to the menu *Tools* -> *Compiler Options...*.

  2. Select the compiler set.

  3. Go to the *Directories* page tab and then *Include Directories* sub page tab. Add the folder using the browser button in the bottom right. Make sure to use the *Add* button, so that the folder is added to the list above.

  4. Click *Ok* to save changes.


### Code::Blocks

Here are some tips for using [Code::Blocks](https://www.codeblocks.org/) and Unicode:
- Code contained in `#ifdef _WIN32` gates might be ghosted out with the code in the `#else` part not ghosted out. This is because the IDE isn't recognizing  _WIN32 even if the compiler is. To fix this, do the following:

  1. Go to the menu *Settings* -> *Compiler...* .

  2. Select the relevant compiler.

  3. Go to the *Compiler settings* page tab which should already be displayed by default.

  4. Go to the *#defines* subpage tab.

  5. Add the line `_WIN32`to the large text box.

  6. Click *Ok* to save the settings.

  7. Close and reopen the project to allow the new settings to take effect.

- To link [libwinsane.o](#Passing-in-Unicode-UTF-8-Arguments-to-main), do the following:

  1. Go to the menu: *Project* -> *Build options...* .

  2. On the left tree, select the whole project at the top of the tree.

  3. Select the relevant compiler.

  4. Go to the *Linker settings* page tab.

  5. In *Link libraries* use the *Add* button to add the file `libwinsane.o`.

  6. Click Ok to save changes.
- To add an include folder (for static and dynamic-link libraries):
  1. Go to the menu: *Project* -> *Build options...* .
  2. On the left tree, select the whole project at the top of the tree.
  3. Select the relevant compiler.
  4. Go to the *Search Directories* page tab.
  5. Add the include folder.
  6. Click Ok to save changes.
- To add a library (for static and dynamic-link libraries)::
  1. Go to the menu: *Project* -> *Build options...* .
  2. On the left tree, select the whole project at the top of the tree.

  3. Select the relevant compiler.

  4. Go to the *Linker settings* page tab.

  5. In *Link libraries* use the *Add* button to add the library file.

  6. Click Ok to save changes.

### Visual Studio Code

Here are some tips for using [Visual Studio](https://visualstudio.microsoft.com/) and Unicode:

- To add the wutf8console.cpp file to be compiled, do the following:

  1. Edit the *tasks.json* file.
  
  2. Find the `"args": [` section within the `"tasks": [` section.
  
  3. Before the `"-o",` line, add these lines:
     ```json
     "-g",
     "${fileDirname}\\wutf8console.cpp",
     ```

- To link [libwinsane.o](#Passing-in-Unicode-UTF-8-Arguments-to-main), do the following:

  1. Edit the *tasks.json* file.
  
  2. Find the `"args": [` section within the `"tasks": [` section.
  
  3. Before the `"-o",` line, add this line:<br>
     ```json
     "libwinsane.o",
     ```

### Visual Studio
- To link [libwinsane.o](#Passing-in-Unicode-UTF-8-Arguments-to-main), do the following:

  1. In the *Solution Explorer* tree, find the project.

  2. Right click on the project and select *Add* -> *Existing Item...*.

  3. Select the *libwinsane.o* file.
- To add an include folder (for static and dynamic-link libraries):
  1. In the *Solution Explorer* tree, find the project.
  2. Right click on the project and select *Properties*.
  3. Go to *Configuration Properties* > *C/C++* > *General*.
  4. Add the include folder to the *Additional Include Directories*.

- To add a library folder (for static and dynamic-link libraries):
  1. In the *Solution Explorer* tree, find the project.
  2. Right click on the project and select *Properties*.
  3. Go to *Configuration Properties* > *Linker* > *General*.
  4. Add the library folder to the *Additional Library Directories*.
- To add a library file (for static and dynamic-link libraries):
  1. In the *Solution Explorer* tree, find the project.
  2. Right click on the project and select *Properties*.
  3. Go to *Configuration Properties* > *Linker* > *Input*.
  4. Add the library folder to the *Additional Dependencies*.

- To add the *preprocessor definition* `WUTF8CONSOLE_IMPORTS` (dynamic-link libraries):
  1. In the *Solution Explorer* tree, find the project.
  2. Right click on the project and select *Properties*.
  3. Go to *Configuration Properties* > *C/C++* >*Preprocessor*.
  4. Add `WUTF8CONSOLE_IMPORTS` to the *Preprocessor Definitions*.

- To create a dynamic-link library (DLL) from source:

  1. Create a new project using the *Dynamic link library in C++* template.

  2. Copy the `wutf8console.h` and `wutf8console.cpp` source code files from `/src` to the project folder and then add them into the project.

  3. In the copied `wutf8console.cpp`, replace the line:

     ```cpp
     #include "wutf8console.h"
     ```

     with:

     ```cpp
     #include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
     #include <utility>
     #include <limits.h>
     #include "wutf8console.h"
     
     // DLL internal state variables:
     static unsigned long long previous_;  // Previous value, if any
     static unsigned long long current_;   // Current sequence value
     static unsigned index_;
     ```

  4. Make sure there is a preprocessor definition `WUTF8CONSOLE_ExPORTS` present in the project properties .
