#ifndef __CONVERT_H__
#define __CONVERT_H__

#include <stdio.h>
#include <windows.h>

int convert_from_str_date_time(const char *format_date, const char *format_time, SYSTEMTIME *syst);

#endif // __CONVERT_H__
