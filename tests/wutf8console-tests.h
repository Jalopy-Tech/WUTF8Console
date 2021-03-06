/* WUTF8Console C++ library tests
 *
 * Written by: Robert Joynt
 * Date: July, 2022
 *
 * This C++ file allows the WUTFConsole library
 * to be tested.
 *
 */

#ifndef WUTF8CONSOLE_TESTS_H
#define WUTF8CONSOLE_TESTS_H

#include "wutf8console.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>


namespace wutf8consoleTests {

	void doTests(int argc, char** argv);

	void argumentsDisplayTest(int argc, char** argv);

	void coutOutputStringTest();
	void coutOutputCstrTest();

	void printfTest();

	void cinInputStringTest();
	void cinInputCstrTest();
	void cinInputStringIntTest();
	void cinInputStringIntCharTest();

	void cinGetlineLineTest();
	void cinGetCstrTest();
	void cinGetCharTest();

	void getlineStringTest();
	void getsCstrTest();
	void fgetsCstrTest();

	void getcIntTest();
	void scanfCstrTest();
	void scanfIntCstrTest();
	void scanfCstrFloatTest();

}

#endif
