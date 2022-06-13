#include "access.h"

int set_date_time_access(const char *filename, char *format_date, char *format_time){
    SYSTEMTIME syst;
    SYSTEMTIME local_sys;
    FILETIME ftaccess;
    HANDLE hfile;
    if((hfile = CreateFile(filename, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL)) != INVALID_HANDLE_VALUE){
        GetFileTime(hfile,NULL, &ftaccess, NULL);
        FileTimeToSystemTime(&ftaccess, &local_sys);
        if(convert_from_str_date_time(format_date, format_time, &local_sys) == 0){
            TzSpecificLocalTimeToSystemTime(NULL, &local_sys, &syst);
            SystemTimeToFileTime(&syst, &ftaccess);
            SetFileTime(hfile, NULL, &ftaccess, NULL);
            CloseHandle(hfile);
            return EXIT_SUCCESS;
        }
    }
    return EOF;
}
