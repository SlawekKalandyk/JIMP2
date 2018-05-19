//
// Created by slawek on 07.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>

using ::std::ostream;
using ::std::string;
using ::std::vector;
using ::std::reference_wrapper;
using ::std::to_string;
using ::std::initializer_list;
using ::std::cref;
using ::std::ostringstream;
using ::std::stringstream;

namespace academia {

    class Serializer;

    class Serializable {
    public:
        virtual void Serialize(Serializer *) const =0;
    };

    class Serializer {
    public:
        //Serializer(ostream *out) : out_(out) {};

        Serializer(stringstream *out) : out_(out) {};

        virtual void IntegerField(const string &field_name, int value) =0;

        virtual void DoubleField(const string &field_name, double value) =0;

        virtual void StringField(const string &field_name, const string &value) =0;

        virtual void BooleanField(const string &field_name, bool value) =0;

        virtual void SerializableField(const string &field_name, const academia::Serializable &value) =0;

        virtual void ArrayField(const string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) =0;

        virtual void Header(const string &object_name) =0;

        virtual void Footer(const string &object_name) =0;

        stringstream *out_;
    };

    class XmlSerializer : public Serializer {
    public:
        XmlSerializer(stringstream *out) : Serializer(out) {};

        void Header(const string &object_name) override;

        void IntegerField(const string &field_name, int value) override;

        void StringField(const string &field_name, const string &value) override;

        void Footer(const string &object_name) override;

        void DoubleField(const string &field_name, double value) override;

        void BooleanField(const string &field_name, bool value) override;

        void SerializableField(const string &field_name, const academia::Serializable &value) override;

        void ArrayField(const string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) override;
    };

    class JsonSerializer : public Serializer {
    public:
        JsonSerializer(stringstream *out) : Serializer(out) {};

        void Header(const string &object_name) override;

        void IntegerField(const string &field_name, int value) override;

        void StringField(const string &field_name, const string &value) override;

        void Footer(const string &object_name) override;

        void DoubleField(const string &field_name, double value) override;

        void BooleanField(const string &field_name, bool value) override;

        void SerializableField(const string &field_name, const academia::Serializable &value) override;

        void ArrayField(const string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) override;
    };

    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int id, const string &roomName, Type type);

        string RoomTypeToString(const Room::Type &room) const;

        void Serialize(Serializer *ser) const override;

    private:
        int id_;
        string roomName_;
        Type type_;
    };

    class Building : public Serializable {
    public:
        Building(int id, string buildingName, vector<Room> roomList);

        vector<reference_wrapper<const Serializable>> Wrapper() const;
        //dlaczego jako argument nie może być vector<Serializable>
        //a wywolanie z vector<Room>?

        void Serialize(Serializer *ser) const override;

    private:
        int id_;
        string buildingName_;
        vector<Room> roomList_;
    };

}


#endif //JIMP_EXERCISES_SERIALIZATION_H
