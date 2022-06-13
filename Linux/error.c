#include "error.h"

char *error(int code){
    if(code == 134)
        return ("Invalid date format");
    else if(code == 135)
        return ("Invalid time format");
    else
        return strerror(code);
}
