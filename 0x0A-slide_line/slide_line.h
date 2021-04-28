#ifndef SLIDE_LINE
#define SLIDE_LINE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

int move_next_number(int *line, size_t size, size_t position);
void merge_elements(int *line, size_t size, size_t i, size_t j);
int slide_line(int *line, size_t size, int direction);
#endif
