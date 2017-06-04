//
// Created by red on 6/3/17.
//

#include "gigasecond.h"

time_t gigasecond_after(time_t when) {
    int gigasecond = (int) pow(10, 9);
    time_t gigasecond_after_when = (time_t) gigasecond + when;
    return gigasecond_after_when;
}
