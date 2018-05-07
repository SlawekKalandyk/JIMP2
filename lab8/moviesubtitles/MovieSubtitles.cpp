//
// Created by slawek on 29.04.18.
//

#include "MovieSubtitles.h"

namespace moviesubs {

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                                std::istream *in, std::ostream *out) {
        string input;
        regex r (R"(\{(\d+)}\{(\d+)}((?:\{.*})*)(.+))");
        smatch sm;
        int frameoffset = (offset_in_micro_seconds * frame_per_second) / 1000;

        while(getline(*in, input)) {
            if(std::regex_match(input, sm, r)) {
                for(int i = 1; i <= 2; ++i)
                    *out << '{' << to_string(stoi(sm[i]) + frameoffset) << '}';

                *out << sm[3] << sm[4] << "\n";
            }
        }
    }

/* do zrobienia później, czemu taki syf napisałem to wciąż nie wiem
    void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                              std::istream *in, std::ostream *out) {
        string input, tmp;
        int inputCharNr = 0, characterNr;
        int offsetBelow1000 = offset_in_micro_seconds % 1000;
        int offsetSeconds = offset_in_micro_seconds / 1000;
        vector<int> time;

        while (getline(*in, input)) {
            *out << input << "\n"; // line number

            getline(*in, input);

            inputCharNr = 0;
            for (int i = 0; i < 2; ++i) {
                characterNr = 2;

                inputCharNr += 2;
                TimeEmplaceBack(time, inputCharNr, characterNr, input); //hh

                inputCharNr += 3;
                TimeEmplaceBack(time, inputCharNr, characterNr, input); //mm

                inputCharNr += 3;
                TimeEmplaceBack(time, inputCharNr, characterNr, input); //ss

                characterNr = 3;
                inputCharNr += 4;
                TimeEmplaceBack(time, inputCharNr, characterNr, input); //ms

                inputCharNr += 6;
            }


            time.shrink_to_fit();

            int msIndex = 3;
            while (time[msIndex]) { //offsetting
                time[msIndex] += offsetBelow1000;
                if (!offsetSeconds) {
                    if (time[msIndex - 1] + offsetSeconds < 60)
                        time[msIndex - 1] += offsetSeconds;
                    else {
                        time[msIndex - 1] = (time[msIndex - 1] + offsetSeconds) % 60;
                        int offsetMinutes = (time[msIndex - 1] + offsetSeconds) / 60;

                        if (time[msIndex - 2] + offsetMinutes < 60)
                            time[msIndex - 2] += offsetMinutes;
                        else {
                            time[msIndex - 2] = (time[msIndex - 2] + offsetMinutes) % 60;
                            time[msIndex - 3] = (time[msIndex - 2] + offsetMinutes) / 60;
                        }
                    }
                }

                msIndex += 4;
            }

            for (int j = 0; j < 3; ++j) {
                if (j != 2) {
                    if (time[0] == 0) {
                        *out << "00" << to_string(time[0]) << ':';
                        time.erase(time.begin());
                    } else if (time[0] < 10) {
                        *out << '0' << to_string(time[0]) << ':';
                        time.erase(time.begin());
                    } else {
                        *out << to_string(time[0]) << ':';
                        time.erase(time.begin());
                    }
                } else {
                    if (time[0] == 0) {
                        *out << "00" << to_string(time[0]) << ',';
                        time.erase(time.begin());
                    } else if (time[0] < 10) {
                        *out << '0' << to_string(time[0]) << ',';
                        time.erase(time.begin());
                    } else {
                        *out << to_string(time[0]) << ',';
                        time.erase(time.begin());
                    }
                }
            }

            if (time[0] == 0) {
                *out << "000" << to_string(time[0]) << ' --> ';
                time.erase(time.begin());
            } else if (time[0] < 10) {
                *out << "00" << to_string(time[0]) << " --> ";
                time.erase(time.begin());
            } else if (time[0] < 100) {
                *out << '0' << to_string(time[0]) << " --> ";
                time.erase(time.begin());
            } else {
                *out << to_string(time[0]) << " --> ";
                time.erase(time.begin());
            }

            for (int j = 0; j < 3; ++j) {
                if (j != 2) {
                    if (time[0] == 0) {
                        *out << "00" << to_string(time[0]) << ':';
                        time.erase(time.begin());
                    } else if (time[0] < 10) {
                        *out << '0' << to_string(time[0]) << ':';
                        time.erase(time.begin());
                    } else {
                        *out << to_string(time[0]) << ':';
                        time.erase(time.begin());
                    }
                } else {
                    if (time[0] == 0) {
                        *out << "00" << to_string(time[0]);
                        time.erase(time.begin());
                    } else if (time[0] < 10) {
                        *out << '0' << to_string(time[0]);
                        time.erase(time.begin());
                    } else {
                        *out << to_string(time[0]);
                        time.erase(time.begin());
                    }
                }
            }

            if (time[0] == 0) {
                *out << "000" << to_string(time[0]) << ':';
                time.erase(time.begin());
            } else if (time[0] < 10) {
                *out << "00" << to_string(time[0]);
                time.erase(time.begin());
            } else if (time[0] < 100) {
                *out << '0' << to_string(time[0]);
                time.erase(time.begin());
            } else {
                *out << to_string(time[0]);
                time.erase(time.begin());
            }

            while (getline(*in, input) && input != "") {
                *out << input << "\n";
            }

            *out << "\n";
        }
    }


    void SubRipSubtitles::TimeEmplaceBack(vector<int> &time, const int &inputCharNr,
                                          const int &charNr, const string &input) {
        time.emplace_back(stoi(input.substr(inputCharNr - charNr, charNr)));
    }
*/

}


