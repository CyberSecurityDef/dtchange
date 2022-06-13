#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>

#include "error.h"
#include "access.h"
#include "modificed.h"

void help(void){
    printf("OPTIONS:\n\t");
    printf("-a\tDate of access\n\t");
    printf("-m\tDate of modificed\n\t");
    printf("-t\tTime format [h:m:s] | [h-m-s] | [h.m.s]\n\t");
    printf("-d\tDate format [dd:mm:yyyy] | [dd-mm-yyyy] | [dd.mm.yyyy]\n\t");
    printf("-h\tUsing help\n");
    printf("EXAMPLES:\n\t");
    printf("dtchange -a filename\n\t");
    printf("dtchange -a filename -t 13:45:50\n\t");
    printf("dtchange -m filename -d 03:05:2020\n\t");
    printf("dtchange -m filename -t 13:45:50 -d 03:05:2020\n");
}

int main(int argc, char **argv){
    int opt = 0;
    bool access_state;
    bool modificed_state;
    char *date = NULL;
    char *ttime = NULL;
    char *path = NULL;
    opterr = access_state = modificed_state = false;
    if(argc == 1){
	help();
	return EOF;
    }
    while((opt = getopt(argc, argv, "a:m:d:t:h")) != EOF){
        switch(opt){
            case  'a' :
                access_state = true;
                path = optarg;
                break;
            case 'm' :
                modificed_state = true;
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
        if(set_date_time_access(path, date, ttime) == EOF){
            fprintf(stderr, "%s\n", error(errno));
            return EIDF;
        }
    }
    if(modificed_state){
        if(set_date_time_modificed(path, date, ttime) == EOF){
            fprintf(stderr, "%s\n", error(errno));
            return EITF;
        }
    }
    return 0;
}
