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
	cout << "For non-Windows platforms, the standard commands will be used." << endl << endl;
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
