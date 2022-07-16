//
// Created by smurf on 16.07.22.
//

#ifndef PLANIEREN_PLANIERENSTORAGE_H
#define PLANIEREN_PLANIERENSTORAGE_H
#include <string>
#include <vector>
#include <tuple>

class DateTime {
    struct Date {
        int date_;
        int month_;
        int year_;
    };
    struct Time {
        int hours_;
        int minutes_;
        int seconds_;
    };
    Date date__;
    Time time__;
public:
    DateTime(const std::string & date, const std::string & time) {
        std::string tmp;
        std::vector<int> vec_date(3);
        for (auto &c: date) {
            if (c != '.') {
                tmp += c;
            } else {
                vec_date.push_back(std::stoi(tmp));
                tmp.clear();
            }
        }
        date__.date_ = vec_date[0];
        date__.month_ = vec_date[1];
        date__.year_ = vec_date[2];
        tmp.clear();
        std::vector<int> vec_time(3);
        for (auto &c: time) {
            if (c != ':') {
                tmp += c;
            } else {
                vec_time.push_back(std::stoi(tmp));
                tmp.clear();
            }
        }
        time__.hours_ = vec_time[0];
        time__.minutes_ = vec_time[1];
        time__.seconds_ = vec_time[2];
    }
};

class PlanierenStorage {
    DateTime datetime_;
    std::string task_;
};


#endif //PLANIEREN_PLANIERENSTORAGE_H
