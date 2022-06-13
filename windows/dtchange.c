#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <windows.h>

#include "access.h"
#include "created.h"
#include "modificed.h"

void help(void){
    printf("OPTIONS:\n\t");
    printf("-a\tDate or time of access\n\t");
    printf("-c\tDate or time of create\n\t");
    printf("-m\tDate or time of modificed\n\t");
    printf("-t\tTime format [h:m:s] | [h-m-s] | [h.m.s]\n\t");
    printf("-d\tDate format [dd:mm:yyyy] | [dd-mm-yyyy] | [dd.mm.yyyy]\n\t");
    printf("-h\tUsing help\n");
    printf("EXAMPLES:\n\t");
    printf("dtchange -a filename -t 13:45:50\n\t");
    printf("dtchange -m filename -d 03:05:2020\n\t");
    printf("dtchange -m filename -t 13:45:50 -d 03:05:2020\n");
}

int main(int argc, char **argv){
    int opt = 0;
    bool access_state;
    bool modificed_state;
    bool create_state;
    char *date = NULL;
    char *ttime = NULL;
    char *path = NULL;
    opterr = access_state = modificed_state = create_state = false;
    if(argc == 1){
        help();
        return EOF;
    }
    while((opt = getopt(argc, argv, "a:m:c:d:t:h")) != EOF){
        switch(opt){
            case  'a' :
                access_state = true;
                path = optarg;
                break;
            case 'm' :
                modificed_state = true;
                path = optarg;
                break;
            case 'c' :
                create_state = true;
                path = optarg;
                break;
            case 'd' :
                date = optarg;
                break;
            case 't' :
                ttime = optarg;
                break;
            case 'h' :
                help();
                break;
            default :
                fprintf(stderr, "Invalid argument %c\n", optopt);
                return EOF;
        }
    }
    if(access_state){
        if(set_date_time_access(path, date, ttime) == EXIT_SUCCESS)
            printf("Changed access file!\n");
    }
    if(create_state){
        if(set_date_time_created(path, date, ttime) == EXIT_SUCCESS)
            printf("Changed create file!\n");
    }
    if(modificed_state){
        if(set_date_time_modificed(path, date, ttime) == EXIT_SUCCESS)
            printf("Changed modifice file!\n");
    }
    return 0;
}
