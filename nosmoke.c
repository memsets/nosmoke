#include "nosmoke.h"

u64 get_time()
{
    u64 t = time(NULL);
    return t;
}

void save_time(u64 t)
{
    FILE *f = fopen(FILENAME, "w");
    fprintf(f, "%lu",(u64) t);
    fclose(f); 
}

u64 get_last_time()
{
    u64 last_time = 0;
    
    FILE *f = fopen(FILENAME, "r");
    fscanf(f, "%lu", &last_time);
    fclose(f);
    return last_time;
}

date_t convert_tstodate(u64 last_time)
{
    date_t last_date;

    last_date.years   = last_time / (60 * 60 * 24 * 365);
    last_date.days    = last_time / (60 * 60 * 24) % 365;
    last_date.hours   = last_time / 60 / 60 % 24;
    last_date.minutes = last_time / 60 % 60;
    last_date.seconds = last_time % 60;
    
    return last_date;
}

void print_date(date_t last_date)
{
    printf("%lu years %lu days %lu hours %lu minutes %lu seconds\n",
            last_date.years, last_date.days, last_date.hours, 
            last_date.minutes, last_date.seconds);
}
