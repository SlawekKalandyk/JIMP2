//
// Created by kalaslaw on 13.03.18.
//

#include "MinimalTimeDifference.h"
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>



unsigned int ToMinutes(std::string time_HH_MM){
    unsigned int hours, minutes;

    if(time_HH_MM.size() == 4){
        hours = std::stoi(time_HH_MM.substr(0,1));
        minutes = std::stoi(time_HH_MM.substr(2,2));
    }
    else{
        hours = std::stoi(time_HH_MM.substr(0,2));
        minutes = std::stoi(time_HH_MM.substr(3,2));
    }

    return hours * 60 + minutes;
}

unsigned int MinimalTimeDifference(std::vector<std::string> times){
    std::vector<unsigned int> times_in_minutes;
    unsigned int max_difference = 0, min_difference = 0;

    for(std::string time : times){
        times_in_minutes.push_back(ToMinutes(time));
    }
    for(int i = 0; i < times_in_minutes.size() - 1; i++) {
        for(int j = i + 1; j < times_in_minutes.size() - 1; j++) {
            if (max_difference < abs(times_in_minutes[i] - times_in_minutes[j])) {
                max_difference = abs(times_in_minutes[i] - times_in_minutes[j]);
            }
            if (min_difference > abs(times_in_minutes[i] - times_in_minutes[j])) {
                min_difference = abs(times_in_minutes[i] - times_in_minutes[j]);
            }
        }
    }

    if(max_difference > 12 * 60){
        max_difference = 24 * 60 - max_difference;
    }
    if(max_difference > min_difference){
        return min_difference;
    }
    else{
        return max_difference;
    }


}
