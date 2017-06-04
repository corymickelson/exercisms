//
// Created by red on 6/3/17.
//

#define CEILING_POS(X) ((X-(int)(X)) > 0 ? (int)(X+1) : (int)(X))
#define CEILING_NEG(X) ((X-(int)(X)) < 0 ? (int)(X-1) : (int)(X))
#define CEILING(X) ( ((X) > 0) ? CEILING_POS(X) : CEILING_NEG(X) )

#ifndef RAINDROPS_RAINDROPS_H
#define RAINDROPS_RAINDROPS_H

#define MAX_INT_VECTOR_SIZE

#include <stdlib.h>

typedef struct {
    int size;
    int *vec;
} int_vector;

char* convert(char*, int, int);

#endif //RAINDROPS_RAINDROPS_H
