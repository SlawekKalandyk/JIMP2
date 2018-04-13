//
// Created by slawek on 13.04.18.
//

#include "StudentRepository.h"

namespace academia {

    StudyYear::StudyYear() {

    }

    StudyYear StudyYear::operator++() {
        year_++;
        return *this;
    }

    StudyYear StudyYear::operator--() {
        year_--;
        return *this;
    }

    StudyYear StudyYear::operator==(const StudyYear &year) const{
        if(year_ == year.year_) {
            return 1;
        } else {
            return 0;
        }
    }

    string Student::Id() {
        return id_;
    }

    string Student::FirstName() {
        return first_name_;
    }

    string Student::LastName() {
        return last_name_;
    }

    string Student::Program() {
        return program_;
    }

    StudyYear Student::Year() {
        return studyYear_;
    }

    string Student::ChangeLastName(string newName) {
        last_name_ = newName;
    }
}