/* WUTF8Console C++ library v1.3
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
        int i;
        i = std::wcin.get();

        // If the newline character is entered, the GCC compilation
        // of this method puts two newline characters in the buffer.
        // The second one needs to be skipped.


        #ifdef GNUC_NEWLINE_FIX
        if (i == 10) {
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
        }
        #endif
        return i;
    }

    Cin& Cin::get(char& c)
    {
        wchar_t wc;

        std::wcin.get(wc);

        c = wc2c(wc);

        // If the newline character is entered, the GCC compilation
        // of this method puts two newline characters in the buffer.
        // The second one needs to be skipped.

        #ifdef GNUC_NEWLINE_FIX
        if ((int) c == 10) {
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
        }
        #endif
        return *this;
    }

    Cin& Cin::get(char* cstr, std::streamsize n)
    {
        wchar_t wcstr[INPUT_BUFFER_SIZE];
        std::wstring ws;

        std::wcin.get(wcstr, n);
        wstr2strcpy(cstr, wcstr);


        // If the newline character is entered, the GCC compilation
        // of this method puts two newline characters in the buffer.
        // The second one needs to be skipped.

        #ifdef GNUC_NEWLINE_FIX
        if (std::wcin.rdbuf()->sgetc() == 10)
            std::wcin.rdbuf()->sbumpc();
        #endif

        return *this;
    }

    Cin& Cin::get(char* cstr, std::streamsize n, char delim)
    {
        wchar_t wcstr[INPUT_BUFFER_SIZE];
        std::wcin.get(wcstr, n, c2wc(delim));
        wstr2strcpy(cstr, wcstr);


        // If the newline character is entered, the GCC compilation
        // of this method puts two newline characters in the buffer.
        // The second one needs to be skipped.

        #ifdef GNUC_NEWLINE_FIX
        if (std::wcin.rdbuf()->sgetc() == 10)
            std::wcin.rdbuf()->sbumpc();
        #endif

        return *this;
    }

    // Not yet implemented

    // Cin& Cin::get(std::streambuf sb) {
    //     std::wcin.get());
    //	return *this;
    // }

    //Cin& Cin::get(std::streambuf& sb, char delim) {
    //	std::wcin.get(sb, c2wc(delim)));
    //	return *this;
    //}

    Cin& Cin::getline(char* cstr, std::streamsize n )
    {
        wchar_t wcstr[INPUT_BUFFER_SIZE];

        std::wcin.getline(wcstr,n);
        wstr2strcpy(cstr, wcstr);

        // If the newline character is entered, the GCC compilation
        // of this method puts two newline characters in the buffer.
        // The second one needs to be skipped.

        #ifdef GNUC_NEWLINE_FIX
        if (std::wcin.rdbuf()->sgetc() == 10)
            std::wcin.rdbuf()->sbumpc();
        #endif

        return *this;
    }

    Cin& Cin::getline(char* cstr, std::streamsize n, char delim )
    {
        wchar_t wcstr[INPUT_BUFFER_SIZE];
        std::wcin.getline(wcstr, n, c2wc(delim));
        wstr2strcpy(cstr, wcstr);

        #ifdef GNUC_NEWLINE_FIX
        if (delim == 10 && std::wcin.rdstate() != std::ios_base::eofbit) {
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
        }
        #endif

        return *this;
    }

    Cin& Cin::ignore(std::streamsize n, int delim)
    {
        std::wcin.ignore(n, delim);

        // If the newline character is entered, the GCC compilation
        // of this method puts two newline characters in the buffer.
        // The second one needs to be skipped.

        #ifdef GNUC_NEWLINE_FIX
        if (delim == 10 && std::wcin.rdstate() != std::ios_base::eofbit) {
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
        }
        #endif
        return *this;
    }

    int Cin::peek()
    {
        return std::wcin.peek();
    }

    Cin& Cin::putback(char c)
    {
        std::wcin.putback(c2wc(c));
        return *this;
    }

    Cin& Cin::read(char* cstr, std::streamsize n)
    {
        wchar_t wcstr[INPUT_BUFFER_SIZE];

        std::wcin.read(wcstr, n);

        // terminate the wcstr in order to copy it

        wcstr[n] = 0;
        wstr2strcpy(cstr, wcstr);

        return *this;
    }

    std::streamsize Cin::readsome(char* cstr, std::streamsize n)
    {
        wchar_t wcstr[INPUT_BUFFER_SIZE];

        std::streamsize size;
        size = std::wcin.readsome(wcstr, n);

        // terminate the wcstr in order to copy it

        wcstr[n] = 0;
        wstr2strcpy(cstr, wcstr);

        return size;
    }

    Cin& Cin::seekg(std::streampos pos)
    {
        std::wcin.seekg(pos);
        return *this;
    }

    Cin& Cin::seekg(std::streamoff off, std::ios_base::seekdir way)
    {
        std::wcin.seekg(off, way);
        return *this;
    }

    int Cin::sync()
    {
        return std::wcin.sync();
    }

    std::streampos Cin::tellg()
    {
        return std::wcin.tellg();
    }

    Cin& Cin::unget()
    {
        std::wcin.unget();

        return *this;
    }


    // ios members

    bool Cin::eof() const
    {
        return std::wcin.eof();
    }

    bool Cin::fail() const
    {
        return std::wcin.fail();
    }

    bool Cin::bad() const
    {
        return std::wcin.bad();
    }

    void  Cin::clear (std::ios_base::iostate state)
    {
        std::wcin.clear(state);
    }

    // Not yet implemented

    //std::istream& Cin::copyfmt(const std::istream& rhs) {
    //	return std::wcin.copyfmt(rhs);
    //}

    std::istream::iostate Cin::exceptions() const
    {
        return std::wcin.exceptions();
    }

    void Cin::exceptions(std::istream::iostate except)
    {
        std::wcin.exceptions(except);
    }

    char Cin::fill() const
    {
        return wc2c(std::wcin.fill());
    }

    char Cin::fill (char fillch)
    {
        return wc2c(std::wcin.fill(c2wc(fillch)));
    }

    bool Cin::good() const
    {
        return std::wcin.good();
    }

    std::locale Cin::imbue(const std::locale& loc)
    {
        return std::wcin.imbue(loc);
    }

    char Cin::narrow(char c, char dfault) const
    {
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
        return std::wcin.rdstate();
    }

    void Cin::setstate (std::istream::iostate state)
    {
        std::wcin.setstate(state);
    }

    std::ostream* Cin::tie() const
    {
        return std::cin.tie();
    }

    std::ostream* Cin::tie (std::ostream* tiestr)
    {
        return std::cin.tie(tiestr);
    }

    char Cin::widen(char c) const
    {
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
            std::getline(std::wcin,ws);
            str = ws2s(ws);

            // The GCC compilation leaves the newline in the buffer.
            // This newline needs to be skipped.

            #ifdef GNUC_NEWLINE_FIX
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
            #endif
            return is;

        } else
            return std::getline(is, str);
    }

    std::istream& getline(std::istream& is, std::string& str)
    {
        if (&is == &std::cin || &is == &cin) {
            std::wstring ws;
            std::getline(std::wcin, ws);
            str = ws2s(ws);

            // The GCC compilation leaves the newline in the buffer.
            // This newline needs to be skipped.

            #ifdef GNUC_NEWLINE_FIX
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
            #endif
            return is;

        } else
            return std::getline(is, str);
    }

    std::istream& getline(Cin& is, std::string& str, const char delim)
    {
        if (&is == &cin) {
            std::wstring ws;
            std::getline(std::wcin, ws, c2wc(delim));
            str = ws2s(ws);

            // The GCC compilation leaves the newline in the buffer.
            // This newline needs to be skipped.

            #ifdef GNUC_NEWLINE_FIX
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
            #endif

            return is;
        } else
            return std::getline(is, str, delim);
    }

    std::istream& getline(std::istream& is, std::string& str, const char delim)
    {
        if (&is == &std::cin || &is == &cin) {
            std::wstring ws;
            std::getline(std::wcin, ws, c2wc(delim));
            str = ws2s(ws);

            // The GCC compilation leaves the newline in the buffer.
            // This newline needs to be skipped.

            #ifdef GNUC_NEWLINE_FIX
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
            #endif

            return is;
        } else
            return std::getline(is, str, delim);
    }

    char* fgets(char *cstr, int num, FILE *stream)
    {
        if (stream == stdin) {
            wchar_t wcstr[INPUT_BUFFER_SIZE];
            fgetws(wcstr, num, stream) ;
            wstr2strcpy(cstr, wcstr);

            // The GCC compilation leaves the newline in the buffer.
            // This newline needs to be skipped.

            #ifdef GNUC_NEWLINE_FIX
            if (std::wcin.rdbuf()->sgetc() == 10)
                std::wcin.rdbuf()->sbumpc();
            #endif

            return cstr;
        } else
            return std::fgets(cstr, num, stream);
    }

    char* gets(char *cstr)
    {
        wchar_t wcstr[INPUT_BUFFER_SIZE];


        // Only the MSVC compiler implements the wide version of gets(): getws()

        #if _MSC_VER
        _getws_s(wcstr, INPUT_BUFFER_SIZE - 1);

        #else

        // No implementation of getws(), so use fgetws()

        fgetws(wcstr, INPUT_BUFFER_SIZE, stdin);
        for (int i = 0; i < INPUT_BUFFER_SIZE; i++) {

            // Take out the newline as gets() doesn't include it

            if (wcstr[i] == 10) {
                wcstr[i] = 0;
                break;
            }
        }

        #endif

        wstr2strcpy(cstr, wcstr);

        // The GCC compilation leaves the newline in the buffer.
        // This newline needs to be skipped.

        #ifdef GNUC_NEWLINE_FIX
        if (std::wcin.rdbuf()->sgetc() == 10)
            std::wcin.rdbuf()->sbumpc();
        #endif

        return cstr;
    }

    int fgetc(FILE * stream )
    {
        int i;
        if (stream == stdin) {
            i = fgetwc(stream);

            // The GCC compilation leaves the newline in the buffer.
            // This newline needs to be skipped.

            #ifdef GNUC_NEWLINE_FIX
            if (i == 10) {
                if (std::wcin.rdbuf()->sgetc() == 10)
                    std::wcin.rdbuf()->sbumpc();
            }
            #endif

            return i;
        } else
            return std::fgetc(stream);
    }

    int getc(FILE * stream )
    {
        int i;

        if (stream == stdin) {
            i = getwc(stream);

            // The GCC compilation leaves the newline in the buffer.
            // This newline needs to be skipped.

            #ifdef GNUC_NEWLINE_FIX
            if (i == 10) {
                if (std::wcin.rdbuf()->sgetc() == 10)
                    std::wcin.rdbuf()->sbumpc();
            }
            #endif

            return i;
        } else
            return std::getc(stream);
    }

    int getchar()
    {
        // namespace must be explicit as getc seems to have a conflict in std

        return wutf8console::getc(stdin);
    }

} //namespace wutf8console
