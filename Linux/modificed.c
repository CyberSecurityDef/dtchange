#include "modificed.h"

int set_date_time_modificed(char *paths, char *format_date, char *format_time){
    struct utimbuf modif;
    struct stat st;
    time_t t;
    memset(&modif, '\0', sizeof(modif));
    if((t = convert_from_str_time(format_date, format_time)) != EOF){
        lstat(paths, &st);
        modif.actime = st.st_atim.tv_sec;
        modif.modtime = t;
        if(format_date == NULL && format_time == NULL)
            return utime(paths, NULL);
        return utime(paths, &modif);
    }
    return EOF;
}
