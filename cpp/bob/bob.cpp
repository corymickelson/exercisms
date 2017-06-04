//
// Created by red on 5/21/17.
//

#include <vector>
#include "bob.h"


string bob::hey(string content) {
    vector<char> special_puncs = {'.', '!', '?'};
    char &punc = content[content.length() - 1];
    char ending_punc = 0;
    for (int i = 0; i < special_puncs.size(); ++i) {
        if (special_puncs[i] == punc) ending_punc = special_puncs[i];
    }
    clean_content(content);
    if (content.length() == 0) return misdirection;
    if (scream(content)) return chill_response;

    switch (ending_punc) {
        case '?': {
            return question_response;
        }
        default: {
            return default_response;
        }
    }

}

void bob::clean_content(string &content) {
    replace_all(content, " ", "");
    regex expr("[!@#$%^&*,0-9]");
    content = regex_replace(content, expr, "");
}

bool bob::scream(string &content) {
    return false;
}
