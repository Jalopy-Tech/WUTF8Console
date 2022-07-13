/* WUTF8Console C++ library testing
 *
 * Written by: Robert Joynt
 * Date: July, 2022
 *
 * This C++ file allows the WUTFConsole library
 * to be tested.
 *
 */

#ifndef WUTF8CONSOLE_TEST_H
#define WUTF8CONSOLE_TEST_H

#include "wutf8console.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>


namespace wutf8consoleTest {
	void doTest();

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
