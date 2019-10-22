#pragma once

#include <tchar.h>
#include <sstream>

#ifdef UNICODE
#define stdcout	std::wcout
#define stdstring std::wstring
#define stdstringstream std::wstringstream
#else
#define stdcout	std::cout
#define stdstring std::string
#define stdstringstream std::stringstream
#endif

extern stdstring formatstring(stdstring strFormat, ...);

extern stdstring trimleft(stdstring string, stdstring trim = _T(" \r\n\t"));
extern stdstring trimright(stdstring string, stdstring trim = _T(" \r\n\t"));
extern stdstring trimstring(stdstring string, stdstring trim = _T(" \r\n\t"));

extern void splitstring(stdstring &sub, stdstring string, int index, TCHAR delim);