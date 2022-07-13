// WUTF8Console C++ library test

#include <iostream>
#include <stdio.h>

// Include the WUTF8Console C++ library


#include "wutf8console-test.h"


// If Unicode UTF-8 is needed in the arguments in main()'s argv,
// link the libwinsane.o file when compiling in Windows.

int main(int argc, char** argv) {

	// Set the console to UTF-8 in Windows.

	wutf8console::setupConsole();

	wutf8consoleTest::doTest();
	
	return 0;


}
