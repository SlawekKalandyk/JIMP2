//
// Created by slawek on 29.04.18.
//

#include "MovieSubtitles.h"

namespace moviesubs {

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                                std::istream *in, std::ostream *out) {

        if (frame_per_second < 0)
            throw invalid_argument("");

        string input;
        regex r(R"(\{(\d+)}\{(\d+)}((?:\{.*})*)(.+))");
        smatch sm;
        int frameoffset = (offset_in_micro_seconds * frame_per_second) / 1000;
        int shifted, lineNr = 0;

        while (getline(*in, input)) {
            ++lineNr;

            if (std::regex_match(input, sm, r)) {
                if(sm[2] < sm[1])
                    throw SubtitleEndBeforeStart(lineNr, input);

                for (int i = 1; i <= 2; ++i) {
                    shifted = stoi(sm[i]) + frameoffset;

                    if (shifted < 0)
                        throw NegativeFrameAfterShift(lineNr, input);

                    *out << '{' << to_string(shifted) << '}';

                }

                *out << sm[3] << sm[4] << "\n";
            } else
                throw InvalidSubtitleLineFormat(lineNr, input);
        }
    }


    void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                              std::ostream *out) {
        /* string input;
         regex r (R"()");
         smatch sm;
         int shifted;

         while(getline(*in, input)) {

         } */
    }

    SubtitlesException::SubtitlesException(int lineNr, string line) :
            lineNr_(lineNr), line_(line), invalid_argument("") {
        msg = "At line " + to_string(lineNr_) + ": " + line_;
    }

    int SubtitlesException::LineAt() const {
        return lineNr_;
    }

    /*const char *SubtitlesException::what() const {
        return msg.c_str();
    }*/
}
