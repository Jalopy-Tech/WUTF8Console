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