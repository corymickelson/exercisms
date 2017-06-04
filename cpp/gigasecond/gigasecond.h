//
// Created by red on 5/23/17.
//

#ifndef GIGASECOND_GIGASECOND_H
#define GIGASECOND_GIGASECOND_H

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost;
using namespace std;

class gigasecond {
public:
   static posix_time::ptime advance(posix_time::ptime time);
};


#endif //GIGASECOND_GIGASECOND_H
