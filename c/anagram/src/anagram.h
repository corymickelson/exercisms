#ifndef ANAGRAM_H
#define ANAGRAM_H

#define MAX_STR_LEN 20

#include <string.h>
#include <sybdb.h>
#include <stdlib.h>
#include <ctype.h>

struct Vector {
   char (*vec)[MAX_STR_LEN];
   int size;
};

struct Vector anagrams_for(char *, struct Vector);

#endif
