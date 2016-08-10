//Calendar.cpp - Managing class of assignments, essentially a calendar - Aidan St G

#include "Calendar.h"
#include <ctime>
#include <iostream>
#include <sstream>

using std::cout;
using std::string;

Calendar::Calendar()
{
    time_t t = time(0);   // get time now
    struct tm* today = localtime( & t );

    year = today->tm_year + 1900;
    month = today->tm_mon + 1;
    day = today->tm_mday;
    weekday = today->tm_wday + 1;
    yearday = today->tm_yday;

    //Array<Assignment>** Cal = new Array<Assignment>*[7];
    calendar = new Array< Array<Assignment> >( 7 );

    for ( int i = 0; i < 7; i++ ) {
        //Assignment** assignm = new Assignment*[10];
        calendar->add( new Array<Assignment>( 10 ) );
    }

}

Calendar::~Calendar() {

}

int Calendar::getWeekDay() {
    return weekday;
}

int Calendar::getDay() {
    return day;
}

int Calendar::getMonth() {
    return month;
}

int Calendar::getYear() {
    return year;
}

string Calendar::getDate( int index ) {
    return daysoftheyear[ yearday + index ];
}
