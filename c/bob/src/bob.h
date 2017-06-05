//
// Created by red on 6/4/17.
//

#ifndef BOB_BOB_H
#define BOB_BOB_H

#include <string.h>
#include <stdlib.h>

#define DEFAULT_RESPONSE "Whatever."
#define QUESTION_RESPONSE "Sure."
#define AGGRESSIVE_RESPONSE "Whoa, chill out!"
#define EMPTY_REMARK_RESPONSE "Fine. Be that way!"

typedef struct {
    int size;
    char *vec;
} char_vector;

#define CHAR_VECTOR_FREE(char_v) free(char_v.vec)


const char* hey_bob(char*);

#endif //BOB_BOB_H
