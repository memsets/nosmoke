#ifndef NOSMOKE_H
#define NOSMOKE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

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

#endif
