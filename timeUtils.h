#ifndef TIMEUTILS_H
#define TIMEUTILS_H
#include <ctime> 
#include <sstream>
#include <iomanip>
using namespace std;

// time now
inline std::time_t now_epoch() {
    return std::time(nullptr);
}

// time in X amount of days (set to 14 for now but can be changed by sysAdmin later)
inline std::time_t days_from_now(int days) {
    return now_epoch() + days * 24 * 60 * 60;
}

// time in year-month-day format neatly
inline std::string ymd(std::time_t t) {
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    return oss.str();
}

// time remaining until due date 
inline int days_remaining(std::time_t due) {
    double secs = std::difftime(due, now_epoch());
    return static_cast<int>(secs / (24 * 60 * 60));
}


#endif
