//
// Created by slawek on 29.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <regex>

using ::std::stringstream;
using ::std::string;
using ::std::getline;
using ::std::cout;
using ::std::endl;
using ::std::to_string;
using ::std::stoi;
using ::std::vector;
using ::std::invalid_argument;
using ::std::regex;
using ::std::smatch;

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

    class SubtitlesException : public invalid_argument {
    public:
        SubtitlesException() : invalid_argument("") {};

        SubtitlesException(int lineNr, string line);

        virtual int LineAt() const;

        virtual const char *what() const throw() { return msg.c_str(); };

    private:
        int lineNr_;
        string line_;
        string msg;
    };

    class NegativeFrameAfterShift : public SubtitlesException {
    public:
        using SubtitlesException::SubtitlesException;
    };

    class SubtitleEndBeforeStart : public SubtitlesException {
    public:
        using SubtitlesException::SubtitlesException;
    };

    class InvalidSubtitleLineFormat : public SubtitlesException {
    public:
        using SubtitlesException::SubtitlesException;
    };

    class OutOfOrderFrames : public SubtitlesException {
    public:
        using SubtitlesException::SubtitlesException;
    };

    class MissingTimeSpecification : public SubtitlesException {
    public:
        using SubtitlesException::SubtitlesException;
    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
                                 std::istream *in, std::ostream *out) override;
    };

}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
