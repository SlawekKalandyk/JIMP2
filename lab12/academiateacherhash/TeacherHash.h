//
// Created by slawek on 01.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <functional>

using ::std::string;

namespace academia {

    class TeacherId {
    public:
        TeacherId(int id) : id_(id) {};

        operator int() const { return id_; };
    private:
        int id_;
    };

    class Teacher {
    public:
        Teacher(TeacherId id, string name, string department) :
                id_(id), name_(move(name)), department_(move(department)) {};

        TeacherId Id() const { return id_; };

        string Name() const { return name_; };

        string Department() const { return department_; };

        bool operator ==(const Teacher &teacher) const;

        bool operator !=(const Teacher &teacher) const;
    private:
        TeacherId id_;
        string name_;
        string department_;
    };


    class TeacherHash {
    public:
        TeacherHash() {};

        size_t operator ()(const Teacher &teacher) const;
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
