#include "access.h"

int set_date_time_access(char *paths, char *format_date, char *format_time){
    struct utimbuf t_access;
    struct stat st;
    time_t t;
    memset(&t_access, '\0', sizeof(t_access));
    if((t = convert_from_str_time(format_date, format_time)) != EOF){
        lstat(paths, &st);
        t_access.actime = t;
        t_access.modtime = st.st_mtim.tv_sec;
        if(format_date == NULL && format_time == NULL)
            return utime(paths, NULL);
        return utime(paths, &t_access);
    }
    return EOF;
}
