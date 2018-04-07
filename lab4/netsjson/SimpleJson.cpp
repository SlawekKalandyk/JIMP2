//
// Created by slawek on 19.03.18.
//

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

    JsonValue::JsonValue() {

    }

    JsonValue::JsonValue(int a) {
        iVal = a;
        iInit = true;
    }

    JsonValue::JsonValue(double a) {
        dVal = a;
        dInit = true;
    }

    JsonValue::JsonValue(string a) {
        sVal = a;
        sInit = true;
    }

    JsonValue::JsonValue(bool a) {
        bVal = a;
        bInit = true;
    }

    JsonValue::JsonValue(vector<JsonValue> a) {
        vVal = a;
        vInit = true;
    }

    JsonValue::JsonValue(map<string, JsonValue> a) {
        mVal = a;
        mInit = true;
    }

    optional<JsonValue> JsonValue::ValueByName(const string &name) const {

    }

    string JsonValue::ToString() const {
        string output;

        if (iInit) {
            output = std::to_string(iVal);
        }
        if (dInit) {
            output = std::to_string(dVal);

            for (int i = 0; i < output.size(); i++) {
                if (output[i] == '.') {
                    while (output[output.size() - 1] == '0') {
                        output = output.substr(0, output.size() - 1);

                        if (output[output.size() - 1] == '.') {
                            output = output.substr(0, output.size() - 1);
                            break;
                        }
                    }

                    break;
                }
            }
        }
        if (bInit) {
            if (bVal) {
                output = "true";
            } else {
                output = "false";
            }
        }
        if (sInit) {
            output = sVal;

            for (int i = output.size() - 1; i >= 0; i--) {
                if (output[i] == '"' || output[i] == '\\') {
                    output.insert(i, "\\");
                }
            }

            output = "\"" + output + "\"";
        }
        if (vInit) {
            output = "[";
            for (int i = 0; i < vVal.size(); i++) {
                output += vVal.at(i).ToString();
                if (i != vVal.size() - 1) {
                    output += ", ";
                } else {
                    output += "]";
                }
            }
        }
        if (mInit) {
            output += "{";

            for (const auto &n : mVal) {
                JsonValue data {n.first};
                output += data.ToString() + ": " + n.second.ToString() + ", ";
            }

            output = output.substr(0, output.size() - 2) + "}";
        }

        return output;
    }
}
