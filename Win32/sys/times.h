#ifndef __SYS_TIMES_H
#define __SYS_TIMES_H

#include <windows.h>

struct tms {
	clock_t tms_utime;
	clock_t tms_cstime;
	clock_t tms_cutime;
	clock_t tms_stime;
};

clock_t	times(struct tms *buffer);

#endif
