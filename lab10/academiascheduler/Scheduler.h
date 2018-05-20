//
// Created by slawek on 19.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <memory>
#include <set>
#include <vector>
#include <utility>
#include <map>
#include <iostream>
#include <stdexcept>

using ::std::vector;
using ::std::copy_if;
using ::std::back_inserter;
using ::std::generate_n;
using ::std::remove_if;
using ::std::find;
using ::std::any_of;
using ::std::find_if;
using ::std::remove_copy_if;
using ::std::binary_search;
using ::std::map;
using ::std::set;
using ::std::invalid_argument;

namespace academia {
    class SchedulingItem {
    public:
        SchedulingItem(const int &course, const int &teacher,
                       const int &room, const int &timeSlot,
                       const int &year) :
                courseId_(course), teacherId_(teacher),
                roomId_(room), timeSlot_(timeSlot),
                year_(year) {};


        int CourseId() const;

        int TeacherId() const;

        int RoomId() const;

        int TimeSlot() const;

        int Year() const;

    private:
        int courseId_, teacherId_, roomId_, timeSlot_, year_;
    };

    class Schedule {
    public:
        Schedule OfTeacher(int teacherId) const;

        Schedule OfRoom(int roomId) const;

        Schedule OfYear(int year) const;

        vector<int> AvailableTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size() const;

        SchedulingItem operator[](int n) const;

    private:
        vector<SchedulingItem> items_;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const vector<int> &rooms,
                                            const map<int, vector<int>> &teacher_courses_assignment,
                                            const map<int, set<int>> &courses_of_year,
                                            int n_time_slots) =0;
    };

    class GreedyScheduler : public Scheduler {
    public:
        Schedule PrepareNewSchedule(const vector<int> &rooms,
                                    const map<int, vector<int>> &teacher_courses_assignment,
                                    const map<int, set<int>> &courses_of_year,
                                    int n_time_slots) override;
    };

    class NoViableSolutionFound : public invalid_argument {
    public:
        NoViableSolutionFound() : invalid_argument("") {};
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
