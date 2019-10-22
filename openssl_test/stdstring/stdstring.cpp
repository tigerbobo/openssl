#include "stdafx.h"
#include "stdstring.h"

#include <stdarg.h>

stdstring formatstring(stdstring strFormat, ...)
{
	va_list args;
	TCHAR buffer[2048] = { 0 };

	va_start(args, strFormat);
	_vstprintf_s(buffer, _countof(buffer), strFormat.c_str(), args);
	va_end(args);

	return stdstring(buffer);
}

stdstring trimleft(stdstring string, stdstring trim)
{
	string.erase(0, string.find_first_not_of(trim));
	return string;
}

stdstring trimright(stdstring string, stdstring trim)
{
	string.erase(string.find_last_not_of(trim) + 1);
	return string;
}

stdstring trimstring(stdstring string, stdstring trim)
{
	string = trimleft(string, trim);
	string = trimright(string, trim);

	return string;
}

void splitstring(stdstring &substring, stdstring string, int index, TCHAR separator)
{
	intptr_t find, result, offset;

	find = 0;
	offset = 0;
	substring = _T("");

	while (true)
	{
		result = string.find(separator, offset);
		if (result >= 0)
			find = find + 1;

		if ((find == index + 1) || ((-1 == result) && (find == index)))
		{
			substring = string.substr(offset, result - offset);
			break;
		}
		else
			offset = result + 1;

		if (-1 == result)
			break;
	}
}