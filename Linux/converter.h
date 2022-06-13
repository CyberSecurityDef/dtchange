#ifndef __CONVERTER_H__
#define __CONVERTER_H__

#include <sys/stat.h>
#include <time.h>

#include "error.h"

#define SYSTEM_YEAR 1900

time_t convert_from_str_time(char *format_date, char *format_time);

#endif // __CONVERTER_H__
