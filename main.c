#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "nosmoke.h"

int main(int argc, char *argv[])
{
    u64 t = 0;
    u64 t_new = 0;

    if (argc == 1) {
        printf("usage:\n \t ns go \n \t ns check \n");
        return 0;
    }

    if (argc > 1) {
        if (strcmp("go", argv[1]) == 0) {
            t = get_time();
            save_time(t);
        } else if (strcmp("check", argv[1]) == 0) {
            t = get_last_time();
            
            t_new = get_time();
            t_new -= t;

            printf("(debug): saved timestamp = [%lu] seconds \n", t);
            printf("(debug): new timestamp = [%lu] seconds \n", t_new);

            date_t my_date = convert_tstodate(t_new);
            print_date(my_date);
        } else {
            printf("(debug): uncorrect argument \n");
        }
    }
    

   return 0;
}
