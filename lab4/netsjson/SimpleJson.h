//
// Created by slawek on 19.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"
#include <experimental/optional>
#include <string>

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::std::literals::operator ""s;
using ::std::experimental::optional;

namespace nets {
    class JsonValue {
    public:
        JsonValue();

        JsonValue(int a);

        JsonValue(double a);

        JsonValue(string a);

        JsonValue(bool a);

        JsonValue(vector<JsonValue> a);

        JsonValue(map<string, JsonValue> a);

        optional<JsonValue> ValueByName(const string &name) const;

        string ToString() const;

    private:
        int iVal;
        double dVal;
        string sVal;
        bool bVal;
        vector<JsonValue> vVal;
        map<string, JsonValue> mVal;
        bool iInit = false;
        bool dInit = false;
        bool bInit = false;
        bool sInit = false;
        bool vInit = false;
        bool mInit = false;

    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
