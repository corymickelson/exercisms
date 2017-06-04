//
// Created by red on 6/3/17.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sybdb.h>
#include "raindrops.h"

int_vector factors_of(int numb) {
    int *vec = calloc((size_t) numb / 2, sizeof(int));
    int_vector factors = {0, vec};
    int factor_index = 0;
    for (int i = 1; i <= numb; ++i) {
        int remainder = numb % i;
        if (remainder == 0) {
            factors.vec[factors.size] = i;
            factors.size++;
        }
    }
    return factors;
}

void inplace_reverse(char *str) {
    if (str) {
        char *end = str + strlen(str) - 1;

        // Thank you stackoverflow https://stackoverflow.com/questions/784417/reversing-a-string-in-c
#define XOR_SWAP(a, b) do\
        {\
            a^=b;\
            b^=a;\
            a^=b;\
        }while(0)

        while (str < end) {
            XOR_SWAP(*str, *end);
            str++;
            end--;
        }
#undef XOR_SWAP
    }
}

void tostring(int num, char *str, int base) {
    int i = 0;
    BOOL isNegative = FALSE;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }
    if (num < 0 && base == 10) {
        isNegative = TRUE;
        num = -num;
    }
    while (num != 0) {
        int rem = num % base;
        str[i++] = (char) ((rem > 9) ? (rem - 10) + 'a' : rem + '0');
        num = num / base;
    }
    if (isNegative) str[i++] = '-';

    str[i] = '\0';
    inplace_reverse(str);
}

void int_vector_free(int_vector v) {
    free(v.vec);
}

char *convert(char *buffer, int size, int fact) {
    int_vector factors = factors_of(fact);
    for (int i = 0; i < factors.size; ++i) {
        switch (factors.vec[i]) {
            case 3: {
                char *pling = "Pling";
                strcat(buffer, pling);
                break;
            }
            case 5: {
                char *plang = "Plang";
                strcat(buffer, plang);
                break;
            }
            case 7: {
                char *plong = "Plong";
                strcat(buffer, plong);
                break;
            }
            default: {
                if (strlen(buffer) == 0 && i == factors.size - 1) {
                    char* src = malloc(5);
                    tostring(factors.vec[i], src, 10);
                    strcpy(buffer, src);
                }
                break;
            }
        }
    }
    int_vector_free(factors);
    return buffer;
}