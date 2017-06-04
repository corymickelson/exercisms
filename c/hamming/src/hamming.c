//
// Created by red on 6/3/17.
//

#include <string.h>
#include "hamming.h"

int compute(char* base, char* comparison) {
    int distance = 0;
    int usable_len = (int) (strlen(base) < strlen(comparison) ? strlen(base) : strlen(comparison));
    for (int i = 0; i < usable_len; ++i) {
        char base_c = base[i];
        char compare_c =comparison[i];
        if(base_c != compare_c) {
            distance++;
        }
    }
    return distance;
}
