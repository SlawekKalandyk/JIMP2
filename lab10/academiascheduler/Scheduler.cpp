//
// Created by slawek on 19.05.18.
//

#include "Scheduler.h"

namespace academia {

    int SchedulingItem::CourseId() const {
        return courseId_;
    }

    int SchedulingItem::TeacherId() const {
        return teacherId_;
    }

    int SchedulingItem::RoomId() const {
        return roomId_;
    }

    int SchedulingItem::TimeSlot() const {
        return timeSlot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }

    Schedule Schedule::OfTeacher(int teacherId) const {
        Schedule teacherSchedule;

        copy_if(items_.begin(), items_.end(),
                back_inserter(teacherSchedule.items_), [teacherId](SchedulingItem item) {
                    return item.TeacherId() == teacherId;
                });

        return teacherSchedule;
    }

    Schedule Schedule::OfRoom(int roomId) const {
        Schedule roomSchedule;

        copy_if(items_.begin(), items_.end(),
                back_inserter(roomSchedule.items_), [roomId](SchedulingItem item) {
                    return item.RoomId() == roomId;
                });

        return roomSchedule;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule yearSchedule;

        copy_if(items_.begin(), items_.end(),
                back_inserter(yearSchedule.items_), [year](SchedulingItem item) {
                    return item.Year() == year;
                });

        return yearSchedule;
    }

    vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        vector<int> resultVector;

        for (int i = 0; i < n_time_slots; ++i)
            resultVector.emplace_back(i + 1);

        resultVector.erase(remove_if(resultVector.begin(), resultVector.end(), [this](int timeSlot) {
            return any_of(items_.begin(), items_.end(), [timeSlot](SchedulingItem item) {
                return timeSlot == item.TimeSlot();
            });
        }), resultVector.end());

/*
        remove_copy_if(resultVector.begin(), resultVector.end(),
                       result.begin(), [this](int timeSlot) {
                    return any_of(items_.begin(), items_.end(), [timeSlot](SchedulingItem item) {
                        return timeSlot == item.TimeSlot();
                    });
                });

        result.shrink_to_fit();
*/ //dlaczego to nie działało?! dopełniało 4 zerami tak, by było 10 liczb...

        return resultVector;

    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        items_.emplace_back(item);
    }

    size_t Schedule::Size() const {
        return items_.size();
    }

    SchedulingItem Schedule::operator[](int n) const {
        if (n < items_.size())
            return items_[n];
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const vector<int> &rooms,
                                                 const map<int, vector<int>> &teacher_courses_assignment,
                                                 const map<int, set<int>> &courses_of_year,
                                                 int n_time_slots) {


        throw NoViableSolutionFound();
    }

}