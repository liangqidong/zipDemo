#include <windows.h>

#include <iostream>
#include "unzip.h"

int main()
{
	const char *password = nullptr;
	HZIP hz = OpenZip(TEXT("G:\\Temp\\www\\aa.zip"), password);
	ZIPENTRY ze; GetZipItem(hz, -1, &ze); int numitems = ze.index;
	for (int i = 0; i < numitems; i++)
	{
		GetZipItem(hz, i, &ze);
		UnzipItem(hz, i, ze.name);
	}
	CloseZip(hz);
	return 0;
}