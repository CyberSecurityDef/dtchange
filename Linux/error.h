#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define EIDF 134
#define EITF 135

char *error(int code);

#endif // __ERROR_H__
