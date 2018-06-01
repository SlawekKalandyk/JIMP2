//
// Created by slawek on 01.06.18.
//

#include "TeacherHash.h"

namespace academia {

    size_t TeacherHash::operator()(const Teacher &teacher) const {
        std::hash<int> intHash;
        std::hash<string> stringHash;
        size_t idHash = intHash(teacher.Id());
        size_t nameHash = stringHash(teacher.Name());
        size_t deptHash = stringHash(teacher.Department());

        return idHash * 17 + nameHash * 37 + deptHash * 53;
    }

    bool Teacher::operator==(const Teacher &teacher) const {
        return id_ == teacher.Id() &&
            name_ == teacher.Name() &&
            department_ == teacher.Department();
    }

    bool Teacher::operator!=(const Teacher &teacher) const {
        return !(*this == teacher);
    }
}
