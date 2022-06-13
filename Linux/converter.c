#include "converter.h"

time_t convert_from_str_time(char *format_date, char *format_time){
    struct tm *t = NULL;
    time_t tt = time(NULL);
    t = localtime(&tt);
    if(format_date != NULL){
        if(sscanf(format_date, "%d:%d:%d", &t->tm_mday, &t->tm_mon, &t->tm_year) != 3)
            if(sscanf(format_date, "%d-%d-%d", &t->tm_mday, &t->tm_mon, &t->tm_year) != 3)
                if(sscanf(format_date, "%d.%d.%d", &t->tm_mday, &t->tm_mon, &t->tm_year) != 3){
                    errno = EIDF;
                    return EOF;
                }
        t->tm_mon -= 1;
        t->tm_year -= SYSTEM_YEAR;
    }

    if(format_time != NULL){
        if(sscanf(format_time, "%d:%d:%d", &t->tm_hour, &t->tm_min, &t->tm_sec) != 3)
            if(sscanf(format_time, "%d-%d-%d", &t->tm_hour, &t->tm_min, &t->tm_sec) != 3)
                if(sscanf(format_time, "%d.%d.%d", &t->tm_hour, &t->tm_min, &t->tm_sec) != 3){
                    errno = EITF;
                    return EOF;
                }

    }
    return mktime(t);
}
