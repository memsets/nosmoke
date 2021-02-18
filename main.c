#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define FILENAME "time.dat"

typedef unsigned long u64;

typedef struct {
    u64 seconds;
    u64 minutes;
    u64 hours;
    u64 days;
    u64 years;
} date_t;

u64 get_time();
void print_date(date_t last_date);
void save_time(u64 t);
u64 get_last_time();
date_t convert_tstodate(u64 last_time);

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

u64 get_time()
{
    u64 t = time(NULL);
    return t;
}

void print_date(date_t last_date)
{
    printf("%lu years %lu days %lu hours %lu minutes %lu seconds\n",
            last_date.years, last_date.days, last_date.hours, 
            last_date.minutes, last_date.seconds);
}

int main(int argc, char *argv[])
{
    u64 t = get_time();
    save_time(t);
    t = get_last_time();
    
    printf("(debug): last timestamp = [%lu] seconds \n", t);

    date_t last_date = convert_tstodate(t);
    print_date(last_date);

   return 0;
}
