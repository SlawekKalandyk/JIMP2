//
// Created by slawek on 29.04.18.
//

#include "MovieSubtitles.h"

namespace moviesubs {

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                                std::istream *in, std::ostream *out) {
        string input, tmp;
        int frame_offset = (offset_in_micro_seconds * frame_per_second) / 1000;
        int i = 0;

        while(getline(*in, input)) {
            for(int j = 0; j < 2; ++j) {
                *out << "{";

                while (input[i] != '}') {
                    tmp += input[i];
                    ++i;
                }

                ++i;
                tmp = tmp.substr(1);
                *out << to_string(stoi(tmp) + frame_offset) << "}";
                tmp = "";
            }

            *out << input.substr(i) <<"\n";
            input = "";
            i = 0;
        }
    }
}
