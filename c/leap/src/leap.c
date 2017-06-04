//
// Created by red on 6/3/17.
//

#include "leap.h"

BOOL is_leap_year(int year) {
   if(year % 4 == 0) {
      if(year % 100 == 0) {
         return year % 400 == 0;
      }
      else return TRUE;
   }
   else return FALSE;
}
