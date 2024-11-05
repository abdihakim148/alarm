#include "alarms.h"

using namespace std;

class Alarms {
    public:
        map<int, Alarm> alarms;


        void create(Alarm alarm) {
            alarms.insert({alarm.id, alarm});
        }

        void erase(int id) {
            alarms.erase(id);
        }
};