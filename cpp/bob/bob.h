//
// Created by red on 5/21/17.
//

#ifndef BOB_BOB_H
#define BOB_BOB_H

#include <string.h>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <array>

using namespace std;
using namespace boost;

const static string question_response = "Sure";
const static string default_response = "Whatever.";
const static string chill_response = "Whoa, chill out!";
const static string misdirection = "Fine. Be that way!";

class bob {
public:
    static string hey(string content);

private:
    static void clean_content(string &content);

    static bool scream(string &content);
};


#endif //BOB_BOB_H
