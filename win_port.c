#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/utsname.h>
#include <sys/times.h>

int	uname(struct utsname *name)
{
	char buf[256];
	DWORD size = MAX_COMPUTERNAME_LENGTH;
	int i;
	OSVERSIONINFO osver;

	GetComputerName(buf, &size);
	for (i = 0; i < strlen(buf); i++) {
		name->nodename[i] = tolower(buf[i]);
	}

	osver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osver);
	sprintf(buf, "%ld.%ld (Build %d)", osver.dwMajorVersion, osver.dwMinorVersion, osver.dwBuildNumber & 0xffff);
	strcpy(name->release, buf);

	strcpy(name->sysname, "Windows");

	if (osver.dwPlatformId == VER_PLATFORM_WIN32_NT)
		strcat(name->sysname, " NT");

	return 0;
}

clock_t	times(struct tms *buffer)
{
	return GetTickCount();
}
