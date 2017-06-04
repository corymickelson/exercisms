//
// Created by red on 6/3/17.
//

#include "anagram.h"

BOOL anagram_check(char *key, char *candidate) {
    int key_len = (int) strlen(key);
    int candidate_len = (int) strlen(candidate);
    int matches = 0;
    int matched_indexes[key_len];

    for (int mi = 0; mi < key_len; ++mi) {
        matched_indexes[mi] = -1;
    }

    for (int i = 0; i < candidate_len; ++i) {
        char target = candidate[i];
        for (int j = 0; j < key_len; ++j) {
            if (key[j] == target) {
                BOOL skip = FALSE;
                for (int k = 0; k < matches; ++k) {
                    if (matched_indexes[k] == j) {
                        skip = TRUE;
                        break;
                    }
                }
                if (skip) continue;
                else {
                    matched_indexes[matches] = j;
                    matches++;
                    break;
                }
            } else continue;
        }
    }
    return matches == strlen(key);
}

void str_lower(char* str) {
    size_t len = strlen(str);
    for (int i = 0; i < len; ++i) {
        str[i] = (char)tolower((int)str[i]);
    }
}

struct Vector empty_anagram = {NULL, 0};

struct Vector anagrams_for(char *base, struct Vector candidates) {
    char *key = malloc(strlen(base));
    strcpy(key, base);
    str_lower(key);
    char (*anagrams)[MAX_STR_LEN] = calloc(MAX_STR_LEN, sizeof(char *)); //freed by testing handler
    struct Vector results = {anagrams, 0};
    for (int i = 0; i < candidates.size; ++i) {
        char *candidate = malloc(MAX_STR_LEN);
        strcpy(candidate, candidates.vec[i]);
        str_lower(candidate);
        if (strlen(key) != strlen(candidate)) continue;
        if (strcmp(key, candidate) == 0) continue;
        if (anagram_check(key, candidate) == TRUE) {
            char *src = candidates.vec[i];
            char *dest = results.vec[results.size];
            strcpy(dest, src);
            results.size++;
        }
        free(candidate);
    }
    free(key);
    return results.size == 0 ? empty_anagram : results;
}

