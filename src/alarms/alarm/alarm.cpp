#include "alarm.h"


using namespace std;


int ID = 1;



string red = "\033[31m", yellow = "\033[33m", blue = "\033[34m", green = "\033[32m", cyan = "\033[36m", magenta = "\033[35m", reset = "\033[0m", move = "\033[A", clear = "\r\033[K";


class Alarm {
    public:
        int id;
        tm time;
        bool active;



        // A constructor to initialize a New instance of the Alarm class.
        Alarm(tm time) {
            id = ID;
            active = true;
            ID++;
        }


        // This function returns the difference between the current time and the time this Alarm instance should ring.
        // The items are in this order: hour_difference, minute_difference, second_difference. Respectively.
        std::tuple<int, int, int> alarm_diff() {
            time_t seconds_since_epoch = std::time(nullptr);
            std::tm* now = std::localtime(&seconds_since_epoch);
            std::tm currentTime = *now;
            int now_seconds, alarm_seconds, seconds;
            now_seconds = (currentTime.tm_hour*60*60) + currentTime.tm_min*60 + currentTime.tm_sec;
            alarm_seconds = (time.tm_hour*60*60) + time.tm_min*60 + time.tm_sec;
            seconds = alarm_seconds - now_seconds;

            
            int hour, min, sec;
            hour = seconds / (60*60); min = (seconds / 60) % 60; sec = seconds % 60;
            return std::make_tuple(hour, min,sec);
        }


        // activates the alarm.
        void activate() {
            active = true;
        }

        // deactivate alarm.
        void deactivate() {
            active = false;
        }
};