#ifndef SLIDE_LINES_H
#define SLIDE_LINES_H
#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);

#endif
