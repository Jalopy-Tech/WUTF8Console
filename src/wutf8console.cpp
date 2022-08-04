/* WUTF8Console C++ library v1.1
 * See wutf8console.h for instructions
 *
 * Copyright (c) 2022, Robert J. Joynt.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */


#include "wutf8console.h"


namespace wutf8console
{

	bool setupConsole()
	{
		int inResult = SetConsoleOutputCP(CP_UTF8);
		int outResult =_setmode( _fileno( stdin ), _O_U16TEXT );
		return (inResult != 0 && outResult != 0);
	}


	// Input operators
	// Note: there is a template for operator >> in the header file.
	// It coveres all data type not listed below.


	Cin& Cin::operator>>(std::string& s)
	{
		std::wstring ws;

		std::wcin >> ws;
		s = ws2s(ws);

		return *this;
	}

	Cin& Cin::operator>>(char* cstr)
	{
		std::wstring ws;

		std::wcin >> ws;
		strcpy(cstr, ws2s(ws).c_str());
		return *this;
	}

	Cin& Cin::operator>>(char& c)
	{
		wchar_t wc;

		std::wcin >> wc;
		c = wc2c(wc);
		return *this;
	}


	// istream members

	std::streamsize Cin::gcount() const
	{
		return std::wcin.gcount();
	}

	int Cin::get()
	{

		std::wcin.sync();
		return std::wcin.get();
	}

	Cin& Cin::get(char& c)
	{
		wchar_t wc;

		std::wcin.sync();
		std::wcin.get(wc);
		c = wc2c(wc);
		return *this;
	}

	Cin& Cin::get(char* cstr, std::streamsize n)
	{
		wchar_t wcstr[INPUT_BUFFER_SIZE];
		std::wstring ws;

		std::wcin.sync();
		std::wcin.get(wcstr,n);
		wstr2strcpy(cstr, wcstr);


		return *this;
	}

	Cin& Cin::get(char* cstr, std::streamsize n, char delim)
	{
		wchar_t wcstr[INPUT_BUFFER_SIZE];
		std::wstring ws;
		std::wcin.sync();
		std::wcin.get(wcstr, n, c2wc(delim));
		wstr2strcpy(cstr, wcstr);


		return *this;
	}

	// Not yet implemented

	//Cin& Cin::get(std::streambuf& sb) {
	//	std::wcin.get(sb);
	//	return *this;
	//}

	//Cin& Cin::get (std::streambuf& sb, char delim) {
	//	std::wcin.get(sb, c2wc(delim)));
	//	return *this;
	//}

	Cin& Cin::getline(char* cstr, std::streamsize n )
	{
		wchar_t wcstr[INPUT_BUFFER_SIZE];
		std::wstring ws;
		std::wcin.sync();
		std::wcin.getline(wcstr,n);
		wstr2strcpy(cstr, wcstr);

		return *this;
	}

	Cin& Cin::getline(char* cstr, std::streamsize n, char delim )
	{
		wchar_t wcstr[INPUT_BUFFER_SIZE];
		std::wstring ws;
		std::wcin.sync();
		std::wcin.getline(wcstr, n, c2wc(delim));
		wstr2strcpy(cstr, wcstr);

		return *this;
	}

	Cin& Cin::ignore(std::streamsize n, int delim)
	{
		std::wcin.ignore(n, delim);
		return *this;
	}

	int Cin::peek()
	{
		std::wcin.sync();
		return std::wcin.peek();
	}

	Cin& Cin::putback(char c)
	{
		std::wcin.sync();
		std::wcin.putback(c2wc(c));
		return *this;
	}


	Cin& Cin::read(char* cstr, std::streamsize n)
	{
		wchar_t wcstr[INPUT_BUFFER_SIZE];
		std::wstring ws;
		std::wcin.sync();
		std::wcin.read(wcstr,n);
		wstr2strcpy(cstr, wcstr);

		return *this;
	}

	std::streamsize Cin::readsome(char* cstr, std::streamsize n)
	{
		wchar_t wcstr[INPUT_BUFFER_SIZE];
		std::wstring ws;
		std::streamsize size;
		std::wcin.sync();
		size = std::wcin.readsome(wcstr, n);
		wstr2strcpy(cstr, wcstr);

		return size;
	}


	Cin& Cin::seekg(std::streampos pos)
	{
		std::wcin.sync();
		std::wcin.seekg(pos);
		return *this;
	}
	Cin& Cin::seekg(std::streamoff off, std::ios_base::seekdir way)
	{
		std::wcin.sync();
		std::wcin.seekg(off, way);
		return *this;
	}

	int Cin::sync()
	{
		return std::wcin.sync();
	}

	std::streampos Cin::tellg()
	{
		std::wcin.sync();
		return std::wcin.tellg();
	}

	Cin& Cin::unget()
	{
		std::wcin.sync();
		std::wcin.unget();

		return *this;
	}


	// ios members

	bool Cin::eof() const
	{
		std::wcin.sync();
		return std::wcin.eof();
	}

	bool Cin::fail() const
	{
		std::wcin.sync();
		return std::wcin.fail();
	}

	bool Cin::bad() const
	{
		std::wcin.sync();
		return std::wcin.bad();
	}

	void  Cin::clear (std::ios_base::iostate state)
	{
		std::wcin.sync();
		std::wcin.clear(state);
	}

	// Not yet implemented

	//std::istream& Cin::copyfmt(const std::istream& rhs) {
	//	return std::wcin.copyfmt(rhs);
	//}

	std::istream::iostate Cin::exceptions() const
	{
		std::wcin.sync();
		return std::wcin.exceptions();
	}

	void Cin::exceptions(std::istream::iostate except)
	{
		std::wcin.sync();
		std::wcin.exceptions(except);
	}


	char Cin::fill() const
	{
		std::wcin.sync();
		return wc2c(std::wcin.fill());
	}

	char Cin::fill (char fillch)
	{
		std::wcin.sync();
		return wc2c(std::wcin.fill(c2wc(fillch)));
	}

	bool Cin::good() const
	{
		std::wcin.sync();
		return std::wcin.good();
	}

	std::locale Cin::imbue(const std::locale& loc)
	{
		std::wcin.sync();
		return std::wcin.imbue(loc);
	}

	char Cin::narrow(char c, char dfault) const
	{
		std::wcin.sync();
		return std::wcin.narrow(c, dfault);
	}

	Cin::operator bool() const
	{
		if (std::wcin)
			return true;
		else
			return false;
	}

	bool Cin::operator!() const
	{
		if (!std::wcin)
			return true;
		else
			return false;
	}

	// Not yet implemented

	//std::streambuf* Cin::rdbuf() const {
	//	return std::wcin.rdbuf();
	//}

	//std::streambuf*  Cin::rdbuf (std::streambuf* sb) {
	//	return std::wcin.rdbuf(sb);
	//}

	std::istream::iostate Cin::rdstate() const
	{
		std::wcin.sync();
		return std::wcin.rdstate();
	}

	void Cin::setstate (std::istream::iostate state)
	{
		std::wcin.sync();
		std::wcin.setstate(state);
	}


	std::ostream* Cin::tie() const
	{
		std::wcin.sync();
		return std::cin.tie();
	}

	std::ostream* Cin::tie (std::ostream* tiestr)
	{
		std::wcin.sync();
		return std::cin.tie(tiestr);
	}

	char Cin::widen(char c) const
	{
		std::wcin.sync();
		return wc2c(std::wcout.widen(c));
	}



	// The replacement cin object

	Cin cin;


	// Conversion functions used to convert between wide character (UTF-16)
	// and narrow character (UTF-8).

	std::wstring s2ws(const std::string& str)
	{

		int count = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int) str.length(), NULL, 0);
		std::wstring wstr(count, 0);
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int) str.length(), &wstr[0], count);
		return wstr;
	}

	std::string ws2s(const std::wstring& wstr)
	{

		int count = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int) wstr.length(), NULL, 0, NULL, NULL);
		std::string str(count, 0);
		WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], count, NULL, NULL);
		return str;
	}

	const wchar_t c2wc(const char c)
	{
		std::string s(1, c);
		std::wstring ws = s2ws(s);
		return ws[0];
	}

	const char wc2c(const wchar_t wc)
	{
		std::wstring ws(1, wc);
		std::string s = ws2s(ws);
		return s[0];
	}


	char* wstr2strcpy(char* destination, const wchar_t* source)
	{
		std::wstring ws(source);
		std::string s = ws2s(ws);
		return strcpy(destination, s.c_str());
	}

	wchar_t* str2wstrcpy(wchar_t* destination, const char* source )
	{
		std::string s(source);
		std::wstring ws = s2ws(s);

		return wcscpy(destination, ws.c_str());
	}


	// Replacements for standard input functions

	std::istream& getline(Cin& is, std::string& str)
	{
		if (&is == &cin) {
			std::wstring ws;
			std::wcin.sync();
			std::getline(std::wcin,ws);
			str = ws2s(ws);

			return is;

		} else
			return std::getline(is, str);
	}

	std::istream& getline(std::istream& is, std::string& str)
	{
		if (&is == &std::cin || &is == &cin) {
			std::wstring ws;
			std::wcin.sync();
			std::getline(std::wcin,ws);
			str = ws2s(ws);

			return is;

		} else
			return std::getline(is, str);
	}

	std::istream& getline(Cin& is, std::string& str, const char delim)
	{
		if (&is == &cin) {
			std::wstring ws;
			std::wcin.sync();
			std::getline(std::wcin, ws, c2wc(delim));
			str = ws2s(ws);

			return is;
		} else
			return std::getline(is, str, delim);
	}

	std::istream& getline(std::istream& is, std::string& str, const char delim)
	{
		if (&is == &std::cin || &is == &cin) {
			std::wstring ws;
			std::wcin.sync();
			std::getline(std::wcin, ws, c2wc(delim));
			str = ws2s(ws);

			return is;
		} else
			return std::getline(is, str, delim);
	}

	char* fgets(char *cstr, int num, FILE *stream)
	{
		if (stream == stdin) {
			wchar_t wcstr[INPUT_BUFFER_SIZE];
			std::wcin.sync();
			fgetws(wcstr, num, stream) ;
			wstr2strcpy(cstr, wcstr);
			return cstr;
		} else
			return std::fgets(cstr, num, stream);
	}

	char* gets(char *cstr)
	{
		wchar_t wcstr[INPUT_BUFFER_SIZE];

		std::wcin.sync();
		fgetws(wcstr, INPUT_BUFFER_SIZE, stdin);
		//_getws(wcstr);
		wstr2strcpy(cstr, wcstr);
		return cstr;
	}

	int fgetc(FILE * stream )
	{
		if (stream == stdin) {
			std::wcin.sync();
			return getwc(stream);
		} else
			return std::getc(stream);
	}

	int getc(FILE * stream )
	{
		if (stream == stdin) {
			std::wcin.sync();
			return getwc(stream);
		} else
			return std::getc(stream);
	}

	int getchar()
	{

		// namespace must be explicit as getc seems to have a conflict in std

		return wutf8console::getc(stdin);
	}

} //namespace wutf8console
