//
// Created by slawek on 29.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>

using ::std::stringstream;
using ::std::string;
using ::std::getline;
using ::std::cout;
using ::std::endl;
using ::std::to_string;
using ::std::stoi;

namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                         std::istream *in, std::ostream *out) =0;

        virtual ~MovieSubtitles() = default;
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                 std::istream *in, std::ostream *out) override;
    };

    class SubtitlesException : public std::invalid_argument {
    public:
        SubtitlesException();

        SubtitlesException(int lineNum, string line);

        virtual int LineAt() const;

    };

    class NegativeFrameAfterShift : public SubtitlesException {
    public:
    };

    class SubtitleEndBeforeStart : public SubtitlesException {
    public:
    };

    class InvalidSubtitleLineFormat : public SubtitlesException {
    public:
    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                 std::istream *in, std::ostream *out) override;
    };

}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
