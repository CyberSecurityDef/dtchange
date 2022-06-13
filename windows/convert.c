#include "convert.h"

int convert_from_str_date_time(const char *format_date, const char *format_time, SYSTEMTIME *syst){
    if(format_date != NULL){
        if(sscanf(format_date, "%hu:%hu:%hu", &syst->wDay, &syst->wMonth, &syst->wYear) != 3)
            if(sscanf(format_date, "%hu-%hu-%hu", &syst->wDay, &syst->wMonth, &syst->wYear) != 3)
                if(sscanf(format_date, "%hu.%hu.%hu", &syst->wDay, &syst->wMonth, &syst->wYear) != 3)
                    return EOF;
    }
    if(format_time != NULL){
        if(sscanf(format_time, "%hu:%hu:%hu", &syst->wHour, &syst->wMinute, &syst->wSecond) != 3)
            if(sscanf(format_time, "%hu-%hu-%hu", &syst->wHour, &syst->wMinute, &syst->wSecond) != 3)
                if(sscanf(format_time, "%hu.%hu.%hu", &syst->wHour, &syst->wMinute, &syst->wSecond) != 3)
                    return EOF;
    }
    return 0;
}
