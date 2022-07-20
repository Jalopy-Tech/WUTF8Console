// WUTF8Console C++ library tests

#include <iostream>
#include <stdio.h>

// Include the WUTF8Console C++ library


#include "wutf8console-tests.h"


// Using these output functions

	using std::cout;
	using std::endl;

// If Unicode UTF-8 is needed in the arguments in main()'s argv,
// link the libwinsane.o file when compiling in Windows.

int main(int argc, char** argv) {

	// Set the console to UTF-8 in Windows.

	wutf8console::setupConsole();

    wutf8consoleTests::doTests(argc, argv);

	return 0;


}
