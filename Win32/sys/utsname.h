#ifndef __SYS_UTSNAME_H
#define __SYS_UTSNAME_H

#include <windows.h>

struct utsname {
	char nodename[MAX_COMPUTERNAME_LENGTH + 1];
	char release[32];
	char sysname[16];
};

int	uname(struct utsname *name);

#endif
