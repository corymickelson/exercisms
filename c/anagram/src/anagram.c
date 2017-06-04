//
// Created by red on 6/3/17.
//

#include "anagram.h"

BOOL anagram_check(char *key, char *candidate) {
    int matches = 0;
    int matched_indexes[strlen(key)];
    for (int i = 0; i < strlen(candidate); ++i) {
        char target = candidate[i];
        for (int j = 0; j < strlen(key); ++j) {
            if (key[j] == target) {
                BOOL skip = FALSE;
                for (int k = 0; k < matches; ++k) {
                    if (matched_indexes[k] == j) {
                        skip = TRUE;
                        break;
                    }
                }
                if (skip) continue;
                matched_indexes[matches] = j;
                matches++;

            } else continue;
        }
    }
    return matches == strlen(key);
}

struct Vector empty_anagram = { NULL, 0 };
struct Vector anagrams_for(char *key, struct Vector candidates) {
    char (*anagrams)[MAX_STR_LEN] = calloc((size_t) candidates.size, sizeof(char*));
    struct Vector results = {
            anagrams,
            0
    };
    for (int i = 0; i < candidates.size; ++i) {
        if (strlen(key) != strlen(candidates.vec[i])) continue;
        if (anagram_check(key, candidates.vec[i]) == TRUE) {
            char *src = candidates.vec[i];
            char *dest = results.vec[results.size];
            strcpy(dest, src);
            results.size++;
        }
    }
    return results.size == 0 ? empty_anagram : results;
}

