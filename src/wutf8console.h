/* WUTF8Console C++ library v1.3
 *
 * Copyright (c) 2022, Robert J. Joynt.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Written by: Robert J. Joynt
 * Date: July, 2022
 * Updated: August, 2022
 *
 * This C++ library  allows a C++ console program to use all
 * common C++ input commands to input with UTF-8 in Windows.
 *
 * For more information, visit:
 * https://github.com/Jalopy-Tech/WUTF8Console
 *
 */

#pragma once

#ifndef WUTF8CONSOLE_H
#define WUTF8CONSOLE_H


// Allow strcpy() and _wscanf_l() in for MSVC compiler

#define _CRT_SECURE_NO_WARNINGS


// Set up for creating DLL with MSVC
// otherwise WUTF8CONSOLE_API is set to nothing

#ifdef WUTF8CONSOLE_EXPORTS
    #define WUTF8CONSOLE_API __declspec(dllexport)
#elif WUTF8CONSOLE_IMPORTS
    #define WUTF8CONSOLE_API __declspec(dllimport)
#else
    #define WUTF8CONSOLE_API
#endif


// Set GNUC_NEWLINE_FIX flag for fixing extra newline problem
// with GCC compilers

#ifdef __GNUC__
    #define GNUC_NEWLINE_FIX
#endif


#include <iostream> // for cin
#include <stdio.h>  // for scanf
#include <stdlib.h> // for scanf
#include <string> // for C++ strings
#include <cstdio> // for scanf
#include <tuple> //for tuples used by scanf
#include <iostream> // for istream class
#include <stdio.h> // for FILE in fgets()
#include <Windows.h> // for setConsoleOutput()
#include <wchar.h > // for wie character strings
#include <locale> // needed for _wprintf_l()
#include <codecvt> // for code conversions
#include <fcntl.h> // for UTF-16 input
#include <io.h> // for io class
#include <ios> // for iostate

namespace wutf8console
{
    // Set the maxium size of input size for functions such as scanf
    // Adjust as necessary.

    const int INPUT_BUFFER_SIZE = 4096;


    // Function to set Windows output to UTF-8 and input to UTF-16

    WUTF8CONSOLE_API bool setupConsole();


    // This class is inherited from istream for the replacement cin object
    // This class uses std::wcin and wide-character-to-narrow-character
    // conversions.

    class WUTF8CONSOLE_API Cin : public std::istream
    {
        public:
            Cin() : std::istream(0) {}

            // Input operators

            Cin& operator>>(std::string& s);
            Cin& operator>>(char* cstr);
            Cin& operator>>(char& c);
            template<typename T>
            Cin& operator>>(T& t);


            // istream members

            std::streamsize gcount() const;

            int get();
            Cin& get(char& c);

            Cin& get(char* s, std::streamsize n);
            Cin& get(char* s, std::streamsize n, char delim);

            //Cin& get(std::streambuf sb);
            //Cin& get(std::streambuf& sb, char delim);

            Cin& getline(char* s, std::streamsize n);
            Cin& getline(char* s, std::streamsize n, char delim);

            Cin& ignore(std::streamsize n = 1, int delim = EOF);

            int peek();

            Cin& putback(char c);

            Cin& read(char* s, std::streamsize n);

            std::streamsize readsome(char* s, std::streamsize n);

            Cin& seekg(std::streampos pos);
            Cin& seekg(std::streamoff off, std::ios_base::seekdir way);

            int sync();

            std::streampos tellg();

            Cin& unget();


            // ios members

            bool bad() const;

            void clear(std::ios_base::iostate state = std::ios_base::goodbit);

            //std::istream& copyfmt(const std::istream& rhs);

            bool eof() const;

            std::istream::ios_base::iostate exceptions() const;
            void exceptions(std::istream::iostate except);

            bool fail() const;

            char fill() const;
            char fill(char fillch);

            bool good() const;

            std::locale imbue(const std::locale& loc);

            char narrow(char c, char dfault) const;

            explicit operator bool() const;

            bool operator!() const;

            //std::streambuf* rdbuf() const;
            //std::streambuf* rdbuf (std::streambuf* sb);

            std::istream::iostate rdstate() const;

            void setstate(std::istream::iostate state);

            std::ostream* tie() const;
            std::ostream* tie(std::ostream* tiestr);

            char widen(char c) const;

    }; // class Cin


    // This handles non-character inout operations


    template<typename T>
    Cin& Cin::operator>>(T& t)
    {
        std::wcin >> t;

        return *this;
    }

    // The replacement cin object
    extern WUTF8CONSOLE_API Cin cin;


    // Replacements for standard input functions

    WUTF8CONSOLE_API char* fgets(char* str, int num, FILE* stream);
    WUTF8CONSOLE_API char* gets(char* str);
    WUTF8CONSOLE_API int getc(FILE* stream);
    WUTF8CONSOLE_API int fgetc(FILE* stream);
    WUTF8CONSOLE_API int getchar();

    WUTF8CONSOLE_API std::istream& getline(std::istream& is, std::string& str);
    WUTF8CONSOLE_API std::istream& getline(Cin& is, std::string& str);
    WUTF8CONSOLE_API std::istream& getline(std::istream& is, std::string& str, const char delim);
    WUTF8CONSOLE_API std::istream& getline(Cin& is, std::string& str, const char delim);

    // Conversion functions used to convert between wide character (UTF-16)
    // and narrow character (UTF-8).

    WUTF8CONSOLE_API std::wstring s2ws(const std::string& str);
    WUTF8CONSOLE_API std::string ws2s(const std::wstring& wstr);
    WUTF8CONSOLE_API const wchar_t c2wc(const char c);
    WUTF8CONSOLE_API const char wc2c(const wchar_t wc);
    WUTF8CONSOLE_API char* wstr2strcpy(char* destination, const wchar_t* source);
    WUTF8CONSOLE_API wchar_t* str2wstrcpy(wchar_t* destination, const char* source);


    // Used to pop off the first element of a tuple

    template <typename Tuple, std::size_t ... Is>
    WUTF8CONSOLE_API auto pop_front_impl(const Tuple& tuple, std::index_sequence<Is...>);

    template <typename Tuple, std::size_t ... Is>
    auto pop_front_impl(const Tuple& tuple, std::index_sequence<Is...>)
    {
        return std::make_tuple(std::get<1 + Is>(tuple)...);
    }

    template <typename Tuple>
    WUTF8CONSOLE_API auto pop_front(const Tuple& tuple);

    template <typename Tuple>
    auto pop_front(const Tuple& tuple)
    {
        return pop_front_impl(tuple,
                              std::make_index_sequence<std::tuple_size<Tuple>::value - 1>());
    }

    // scanfparser() recursively parses trough the scanf arguments in order to catch
    // and replace char* pointers with wchar_t* pointers. Then _wscanf_l is called to do the
    // UTF-16 version of the scanf() function.

    // This version of scanfparser() fires when there are no more arugments to be parsed.
    // The _wscanf_l() function is run with the parsed scanf arguments to do the UTF-16 version
    // of scanf().

    template<typename ...Args2>
    WUTF8CONSOLE_API int scanfparser(const std::tuple<>& unparsedArgsTuple,
                                     Args2 ... parsedArgs);

    template<typename ...Args2>
    int scanfparser(const std::tuple<>& unparsedArgsTuple,
                    Args2 ... parsedArgs)
    {
        int i;
        i = _wscanf_l(parsedArgs...);

        return i;
    }


    // Declare versions of scanfparser

    template<typename T, typename ...Args1, typename ...Args2>
    WUTF8CONSOLE_API int scanfparser(const std::tuple<T*, Args1 ...>& unparsedArgsTuple,
                                     Args2 ... parsedArgs);


    template<typename ...Args1, typename ...Args2>
    WUTF8CONSOLE_API int scanfparser(const std::tuple<char*, Args1 ...>& unparsedArgsTuple,
                                     Args2 ... parsedArgs);

    template<typename ...Args1, typename ...Args2>
    WUTF8CONSOLE_API int scanfparser(const std::tuple<Args1 ...>& unparsedArgsTuple,
                                     Args2 ... parsedArgs);


    // This version of scanfparser() fires when a generic argument type is found

    template<typename T, typename ...Args1, typename ...Args2>
    int scanfparser(const std::tuple<T*, Args1 ...>& unparsedArgsTuple,
                    Args2 ... parsedArgs)
    {

        T* t = std::get<0>(unparsedArgsTuple);

        auto newUnparsedArgsTuple = pop_front(unparsedArgsTuple);

        return scanfparser(newUnparsedArgsTuple, parsedArgs..., &*t);
    }


    // This version of scanfparser() fires when a char* pointer argument type is found
    // in the tuple. It is taken out of the tuple.
    // The argument is replaced with a wchar_t* pointer. When recursing back, the wchar_t* pointer
    // array is copied to the char* pointer array.

    template<typename ...Args1, typename ...Args2>
    int scanfparser(const std::tuple<char*, Args1 ...>& unparsedArgsTuple, Args2 ...parsedArgs)
    {

        char* cstr = std::get<0>(unparsedArgsTuple);
        wchar_t wcstr[INPUT_BUFFER_SIZE] = L"";

        auto newUnparsedArgsTuple = pop_front(unparsedArgsTuple);

        int n = scanfparser(newUnparsedArgsTuple, parsedArgs..., &*wcstr);

        wstr2strcpy(cstr, wcstr);

        return n;
    }

    // Replacement function for scanf()
    // This uses scanfparser() to recursively parse trough the scanf arguments in order to catch
    // and replace char* pointers with wchar_t* pointers. Then _wscanf_l is called to do the
    // UTF-16 version of the scanf() function.
    template<typename ...Args>
    WUTF8CONSOLE_API int scanf(const char* format, Args ...args);

    template<typename ...Args>
    int scanf(const char* format, Args ...args)
    {
        // create a wide version of the format string

        wchar_t wformat[INPUT_BUFFER_SIZE];
        str2wstrcpy(wformat, format);

        // store the scanf() arguments in a tuple

        auto unparsedArgsTuple = std::tuple<Args...>(args...);


        // set the locale. This is needed when the _wscanf_l() function is called

        _locale_t locale;
        locale = _create_locale(LC_ALL, "");

        // Call scanfparser to recursively parse the arguments in the tuple.
        // As the arguments are parsed, they are taken out the tuple
        // and appended to the argument list at the end.
        // wformat and locale are the first aruments in this argument list
        // (not including the tuple at the start).

        return scanfparser(unparsedArgsTuple, &*wformat, locale);
    }

    // Replacement function for fscanf()
    // Uses replacement function for scanf if using stdin

    template<typename ...Args>
    WUTF8CONSOLE_API int fscanf(FILE* stream, const char* format, Args ...args);

    template<typename ...Args>
    int fscanf(FILE* stream, const char* format, Args ...args)
    {
        if (stream == stdin) {
            return scanf(format, args...);
        } else
            return std::fscanf(stream, format, args...);
    }

} // namespace wutf8console


#endif // #define WUTF8CONSOLE_H
