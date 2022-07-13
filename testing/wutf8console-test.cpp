// WUTF8Console C++ library testing
// See wutf8console-test.h for instructions

#include "wutf8console-test.h"


namespace wutf8consoleTest {

// Using these input functions

#ifdef _WIN32

	using wutf8console::cin;
	using wutf8console::getline;
	using wutf8console::scanf;
#else
	using std::cin;
	using std::scanf;
#endif

// Using these output functions

	using std::cout;
	using std::endl;

// Using other functions

	using std::string;

	string unicodeString = "헬로월드";
	string unicodeLine = "Hello World! × " + unicodeString;


	void coutOutputStringTest() {
		extern std::string unicodeString;

		cout << "TEST: cout output string test..." << endl;
		cout << "Unicode line: " << unicodeLine << endl << endl;

	}

	void coutOutputCstrTest() {
		extern std::string unicodeString;

		cout << "TEST: cout output cstr test..." << endl;
		cout << "Unicode char*: " << unicodeString.c_str() << endl << endl;
	}


	void printfTest() {
		extern std::string unicodeString;

		printf("TEST: printf cstr...\n");
		printf("Unicode Line: %s\n\n", unicodeLine.c_str());
	}


	void cinInputStringTest () {
		string s;

		cout << "TEST: cin input string..." << endl;
		cout << "Enter a one-word string: ";
		cin >> s;
		std::cout << "The string is: " << s << endl;
	}

	void cinInputCstrTest () {

		char cstr[100];

		cout << "TEST: cin input cstr..." << endl;
		cout << "Enter a one-word cstr: ";
		cin >> cstr;
		cout << "The cstr is: " << cstr << endl << endl;
	}

	void cinInputStringIntTest () {
		string s;
		int i;

		cout << "TEST: cin input string int..." << endl;
		cout << "Enter a one-word string and int: ";
		cin >> s >> i;
		std::cout << "The string is: " << s << " and the int is " << i << endl << endl;
	}

	void cinInputStringIntCharTest () {
		string s;
		int i;
		char c;

		cout << "TEST: cin input string int char..." << endl;
		cout << "Enter a one-word string, int and char: ";
		cin >> s >> i >> c;
		std::cout << "The string is: " << s << ", the int is " << i << ", and the char is " << c << endl << endl;
	}

	void cinGetlineLineTest() {
		char cstr[100];

		cout << "TEST: cin getline/gcount line..." << endl;
		cout << "Enter a line: ";
		cin.getline(cstr, 100);
		cout << "The cstr is: " << cstr << endl << endl;
		std::cout << "The gcount is: " << cin.gcount() << endl << endl;
	}

	void cinGetCstrTest() {
		char cstr[100];

		cout << "TEST: cin get cstr..." << endl;
		cout << "Enter a cstr: ";
		cin.get(cstr, 100);
		cout << "The cstr is: " << cstr << endl << endl;
	}

	void cinGetCharTest() {
		char c;

		cout << "TEST: cin get char..." << endl;
		cout << "Enter a char: ";
		cin.get(c);
		cout << "The char is: " << c << endl << endl;
	}




	void fgetsCstrTest() {
		char cstr[100];

		cout << "TEST: fgets cstrline..." << endl;
		cout << "Enter a cstr [max 8]: ";
#ifdef _WIN32
		wutf8console::fgets(cstr, 8, stdin);
#else
		std::fgets(cstr, 8, stdin);
#endif
		cout << "The cstrline is: " << cstr << endl << endl;
	}

	void getsCstrTest() {
		char cstr[100];

		cout << "TEST: gets cstr..." << endl;
		cout << "Enter a cstrline: ";
#ifdef _WIN32
		wutf8console::gets(cstr);
#else
		// gets is depreciated
		fgets(cstr, 100, stdin);
#endif

		cout << "The cstrline is: " << cstr << endl << endl;
	}

	void getcIntTest() {
		int i;

		cout << "TEST: gets int..." << endl;
		cout << "Enter a char: ";
#ifdef _WIN32
		i = wutf8console::getc(stdin);
#else
		i = fgetc(stdin);
#endif

		cout << "The int is: " << i << endl << endl;
	}


	void getlineStringTest() {
		std::string s;

		printf("TEST: getline...\n");
		printf("Enter a stringline: ");
		getline(cin, s);
		cout << "The stringline is :" << s << std::endl;
	}

	void scanfCstrTest() {
		char cstr[100];
		int n;
		printf("TEST: scanf cstr...\n");
		printf("Enter a cstr: ");
		n = scanf("%s", cstr);
		printf("cstr is: %s\n\n", cstr);
		printf("return is %d\n\n", n);
	}

	void scanfIntCstrTest() {
		char cstr[100];
		int i;
		int n;
		printf("TEST: scanf cstr...\n");
		printf("Enter an int and cstr: ");
		n = scanf("%i %s", &i, cstr);
		printf("i is %d and cstr is: %s\n\n", i, cstr);
		printf("return is %d\n\n", n);
	}

	void scanfCstrFloatTest() {
		char cstr[100];
		float f;
		int j;
		printf("TEST: scanf cstr float...\n");
		printf("Enter a cstr and float: ");
		j = scanf("%s %f", cstr, &f);
		printf("cstr is: %s and f is %f and \n\n", cstr, f);
		printf("return is %d\n\n", j);
	}

	void doTest() {




		coutOutputStringTest();
		coutOutputCstrTest();
		printfTest();

		cinGetCstrTest();
		cinGetCharTest();


		fgetsCstrTest();
		fgetsCstrTest();

		getlineStringTest();
		
		cinGetlineLineTest();	
		
		cinInputStringTest();
		cinInputCstrTest();
		cinInputStringIntTest();
		cinInputStringIntCharTest();

		
		scanfCstrTest();
		scanfIntCstrTest();
		scanfCstrFloatTest();
		
		fgetsCstrTest();
		getsCstrTest();
		getcIntTest();
		
		
		cinGetCstrTest();
		cinGetCharTest();





	}

}


