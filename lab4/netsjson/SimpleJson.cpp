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
        iInit = 1;
    }

    JsonValue::JsonValue(double a) {
        dVal = a;
        dInit = 1;
    }

    JsonValue::JsonValue(string a) {
        sVal = a;
        sInit = 1;
    }

    JsonValue::JsonValue(bool a) {
        bVal = a;
        bInit = 1;
    }

    JsonValue::JsonValue(vector<JsonValue> a) {
        vVal = a;
        vInit = 1;
    }

    JsonValue::JsonValue(map<string, JsonValue> a) {
        mVal = a;
        mInit = 1;
    }

    optional<JsonValue> JsonValue::ValueByName(const string &name) const {
        return mVal.at(name);
    }

    string JsonValue::ToString() const {
        string output;

        if (iInit) {
            output = std::to_string(iVal);
        } else if (dInit) {
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
        } else if (bInit) {
            if (bVal) {
                output = "true";
            } else {
                output = "false";
            }
        } else if (sInit) {
            output = sVal;

            for(int i = output.size() - 1; i >= 0; i--) {
                if(output[i] == '"' || output[i] == '\\') {
                    output.insert(i,"\\");
                }
            }

            output = "\"" + output + "\"";
        } else if (vInit) {
            output = "[";
            for (int i = 0; i < vVal.size(); i++) {
                output += vVal.at(i).ToString();
                if (i != vVal.size() - 1) {
                    output += ", ";
                } else {
                    output += "]";
                }
            }
        } else if (mInit) {
            //output = mVal.ToString();

        }

        return output;
    }
}
