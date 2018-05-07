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
                if (sm[2] < sm[1])
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
        if(frame_per_second < 0)
            throw invalid_argument("");

        string input;
        regex r(R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))");
        smatch sm;
        int lineNr = 0, counter = 0;
        vector<int> frameOrder;

        while (getline(*in, input)) {
            if (!counter)
                ++lineNr;
            ++counter;

            switch (counter) {
                case 1:
                    frameOrder.emplace_back(stoi(input));

                    if (frameOrder.back() != lineNr)
                        throw OutOfOrderFrames();

                    *out << input << "\n";
                    break;

                case 2:
                    if (std::regex_match(input, sm, r)) {
                        int m = 60, s = 60, ms = 1000;
                        vector<int> times;
                        vector<string> timesStr;
                        int microsecSum1 = stoi(sm[1]) * m * s * ms +
                                           stoi(sm[2]) * s * ms +
                                           stoi(sm[3]) * ms +
                                           stoi(sm[4]) +
                                           offset_in_micro_seconds;
                        int microsecSum2 = stoi(sm[5]) * m * s * ms +
                                           stoi(sm[6]) * s * ms +
                                           stoi(sm[7]) * ms +
                                           stoi(sm[8]) +
                                           offset_in_micro_seconds;

                        if (microsecSum1 < 0 || microsecSum2 < 0)
                            throw NegativeFrameAfterShift(lineNr, input);

                        if (microsecSum1 > microsecSum2)
                            throw SubtitleEndBeforeStart(lineNr, input);

                        int remains;
                        times.emplace_back(microsecSum1 / (m * s * ms));
                        remains = microsecSum1 % (m * s * ms);
                        times.emplace_back(remains / (s * ms));
                        remains %= (s * ms);
                        times.emplace_back(remains / ms);
                        remains %= ms;
                        times.emplace_back(remains);

                        times.emplace_back(microsecSum2 / (m * s * ms));
                        remains = microsecSum2 % (m * s * ms);
                        times.emplace_back(remains / (s * ms));
                        remains %= (s * ms);
                        times.emplace_back(remains / ms);
                        remains %= ms;
                        times.emplace_back(remains);

                        for(int i = 0; i < times.size(); ++i)
                            timesStr.emplace_back("");

                        for (int i = 0; i < 2; ++i) {
                            for (int j = 0; j < 3; j++) {
                                timesStr[j + i * 4] = to_string(times[j + i * 4]);
                                while (timesStr[j + i * 4].size() < 2)
                                    timesStr[j + i * 4] = '0' + timesStr[j + i * 4];
                            }
                        }

                        for (int i = 0; i < 2; ++i) {
                            timesStr[3 + i * 4] = to_string(times[3 + i * 4]);
                            while (timesStr[3 + i * 4].size() < 3)
                                timesStr[3 + i * 4] = '0' + timesStr[3 + i * 4];
                        }

                        *out << timesStr[0] << ":"
                             << timesStr[1] << ":"
                             << timesStr[2] << ","
                             << timesStr[3];
                        *out << " --> ";
                        *out << timesStr[4] << ":"
                             << timesStr[5] << ":"
                             << timesStr[6] << ","
                             << timesStr[7] << "\n";
                    } else
                        throw InvalidSubtitleLineFormat(lineNr, input);

                    break;

                default:
                    if (input == "") {
                        *out << input << "\n";
                        counter = 0;
                    } else
                        *out << input << "\n";

                    break;
            }
        }
    }

    SubtitlesException::SubtitlesException(int lineNr, string line) :
            lineNr_(lineNr), line_(line), invalid_argument("") {
        msg = "At line " + to_string(lineNr_) + ": " + line_;
    }

    int SubtitlesException::LineAt() const {
        return lineNr_;
    }

}
