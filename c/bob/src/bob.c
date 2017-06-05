//
// Created by red on 6/4/17.
//

#include <sybdb.h>
#include <ctype.h>
#include "bob.h"

void str_splice(char *str, char *buf, size_t start, size_t end) {
    size_t j = 0;
    for (; start <= end; start++) {
        buf[j++] = str[start];
    }
    buf[j] = 0;
}

char *clear_char(char *s, char x) {
    char *head_segment = calloc(strlen(s) , sizeof(char));
    char *tail_segment = NULL;
    char *buffer = calloc(strlen(s) , sizeof(char));
    strcpy(buffer, s);
    size_t len = strlen(buffer);
    for (int i = 0; i < len; ++i) {
        if (buffer[i] == x) {
            tail_segment = calloc((len - i) , sizeof(char));
            str_splice(buffer, head_segment, 0, (size_t) (i - 1));
            str_splice(buffer, tail_segment, (size_t) (i + 1), len-1);
            strcat(head_segment, tail_segment);
            strcpy(buffer, head_segment);
            len--;
        }
    }
    return buffer;
}
BOOL is_yelling(char* str) {
    BOOL result = TRUE;
    for (int i = 0; i < strlen(str); ++i) {
        if(isupper((int) str[i]) == 0) {
            result = FALSE;
            break;
        }
    }
    return result;
}
const char *
hey_bob(char *sentence) {
    char * response = DEFAULT_RESPONSE;
    char terminating_puncs[3] = {'\!', '?', '.'};
    char removable_chars[33] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@',
                              '#', '$', '^', '&', '*', '?', '.', ',', ';', '-', '_', '+', '=',
                              '(', ')', '[', ']', '{', '}', '\\', '|'};
    char punc = sentence[strlen(sentence) - 1];
    char *workable_characters = clear_char(sentence, ' ');//str_remove_all(sentence, ' ');
    char sent_punc = 0;
    for (int i = 0; i < 3; ++i) {
        if (terminating_puncs[i] == punc) sent_punc = punc; // hold on to this value, needed shortly.
    }
    for (int j = 0; j < 33; ++j) {
        char *sentence_iteration = clear_char(workable_characters, removable_chars[j]);
        strcpy(workable_characters, sentence_iteration);
    }
    if(strlen(workable_characters) == 0) response = EMPTY_REMARK_RESPONSE;
    if(is_yelling(workable_characters)) response = AGGRESSIVE_RESPONSE;
    if(sent_punc == '?') response = QUESTION_RESPONSE;

    free(workable_characters);
    return response;
}
