//
// Created by slawek on 13.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>

using ::std::string;

namespace academia {
    class StudyYear {
    public:
        StudyYear();

        StudyYear(int year) : year_(year) {};

        StudyYear operator++();

        StudyYear operator--();

        StudyYear operator==(const StudyYear &year) const;

    private:
        int year_;
    };

    class Student {
    public:
        Student() : id_() {};

        Student(string id, string first_name, string last_name, string program, int year) :
                id_(id), first_name_(first_name), last_name_(last_name), program_(program), studyYear_(year) {};

        string Id();

        string FirstName();

        string LastName();

        string Program();

        StudyYear Year();

        string ChangeLastName(string newName);

    private:
        string id_, first_name_, last_name_, program_;
        StudyYear studyYear_;
    };
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
