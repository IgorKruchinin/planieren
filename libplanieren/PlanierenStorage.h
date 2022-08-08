//
// Created by smurf on 16.07.22.
//

#ifndef PLANIEREN_PLANIERENSTORAGE_H
#define PLANIEREN_PLANIERENSTORAGE_H
#include <string>
#include <vector>
#include <fstream>
//#include "macro_config.h"
#include "USM/USM.h"

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
    DateTime(int day, int month, int year, int hour, int minute, int sec) {
        date__.date_ = day;
        date__.month_ = month;
        date__.year_ = year;
        time__.hours_ = hour;
        time__.minutes_ = minute;
        time__.seconds_ = sec;
    }
    std::string date_to_string() {
        return std::to_string(date__.year_) + '.' + std::to_string(date__.month_) + '.' + std::to_string(date__.date_) ;
    }
    std::string time_to_string() {
        return std::to_string(time__.hours_) + ':' + std::to_string(time__.minutes_) + ':' + std::to_string(time__.seconds_);
    }
};

struct Task {
    DateTime datetime_;
    std::string task_;
    Task(const std::string& date, const std::string& time, const std::string& task)
        :datetime_(date, time), task_(task) {}
};

class Profile {
    std::string name_;
    std::vector<Task> tasks_;
    ProfileStorage storage_;
public:
    Profile(const std::string& name)
        :name_(name), storage_(name){
        if (!storage_.opened()) {
            storage_.create_ssec("tasks");
            storage_.create_ssec("date");
            storage_.create_ssec("time");
            storage_.to_file();
        } else {
            size_t size = storage_.gets("tasks").get_objects().size();
            for (size_t i = 0; i < size; ++i) {
                tasks_.emplace_back(storage_.gets("date")[i], storage_.gets("time")[i], storage_.gets("tasks")[i]);
            }
        }
    }
    void create_task(const std::string& date, const std::string& time, const std::string& task) {
        tasks_.emplace_back(date, time, task);
        size_t last_index = tasks_.size() - 1;
        storage_.gets("tasks").add(tasks_[last_index].task_);
        storage_.gets("date").add(tasks_[last_index].datetime_.date_to_string());
        storage_.gets("time").add(tasks_[last_index].datetime_.time_to_string());
        storage_.to_file();
    }
    std::vector<Task>& get_tasks() {
        return tasks_;
    }
};

#endif //PLANIEREN_PLANIERENSTORAGE_H
