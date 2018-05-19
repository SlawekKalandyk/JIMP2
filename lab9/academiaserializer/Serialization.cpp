//
// Created by slawek on 07.05.18.
//

#include "Serialization.h"

namespace academia {

    Room::Room(int id, const string &roomName, Room::Type type) :
            id_(id), roomName_(roomName), type_(type) {
    }

    void Room::Serialize(Serializer *ser) const {
        ser->Header("room");
        ser->IntegerField("id", id_);
        ser->StringField("name", roomName_);
        ser->StringField("type", RoomTypeToString(type_));
        ser->Footer("room");
    }

    string Room::RoomTypeToString(const Room::Type &room) const {
        switch (room) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

    void XmlSerializer::Header(const string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::IntegerField(const string &field_name, int value) {
        *out_ << "<" << field_name << ">";
        *out_ << to_string(value);
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::StringField(const string &field_name, const string &value) {
        *out_ << "<" << field_name << ">";
        *out_ << value;
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::Footer(const string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }

    void XmlSerializer::DoubleField(const string &field_name, double value) {
        *out_ << "<" << field_name << ">";
        *out_ << to_string(value);
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const string &field_name, bool value) {
        *out_ << "<" << field_name << ">";
        *out_ << to_string(value);
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const string &field_name,
                                   const vector<reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" << field_name << ">";

        for (auto &i: value) {
            i.get().Serialize(this);
        }

        *out_ << "<\\" << field_name << ">";
    }

    Building::Building(int id, string buildingName, vector<Room> roomList) :
            id_(id), buildingName_(buildingName), roomList_(roomList) {

    }

    vector<reference_wrapper<const Serializable>> Building::Wrapper() const {
        vector<reference_wrapper<const Serializable>> result;

        for(auto &i: roomList_) {
            result.emplace_back(cref(i));
        }

        return result;
    }


    void Building::Serialize(Serializer *ser) const {
        ser->Header("building");
        ser->IntegerField("id", id_);
        ser->StringField("name", buildingName_);
        ser->ArrayField("rooms", Wrapper());
        ser->Footer("building");
    }

    void JsonSerializer::Header(const string &object_name) {
        *out_ << "{";
    }

    void JsonSerializer::IntegerField(const string &field_name, int value) {
        if(out_->str().back() != '{')
            *out_ << ", ";

        *out_ <<"\"" << field_name << "\": " << to_string(value);
    }

    void JsonSerializer::StringField(const string &field_name, const string &value) {
        if(out_->str().back() != '{')
            *out_ << ", ";

        *out_ <<"\"" << field_name << "\": \"" << value << "\"";
    }

    void JsonSerializer::Footer(const string &object_name) {
        *out_  << "}";
    }

    void JsonSerializer::DoubleField(const string &field_name, double value) {
        if(out_->str().back() != '{')
            *out_ << ", ";

        *out_ <<"\"" << field_name << "\": " << to_string(value);
    }

    void JsonSerializer::BooleanField(const string &field_name, bool value) {
        if(out_->str().back() != '{')
            *out_ << ", ";

        *out_ <<"\"" << field_name << "\": " << to_string(value);
    }

    void JsonSerializer::SerializableField(const string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
    }

    void JsonSerializer::ArrayField(const string &field_name,
                                    const vector<reference_wrapper<const academia::Serializable>> &value) {
        if(out_->str().back() != '{')
            *out_ << ", ";

        *out_ << "\"" << field_name << "\": [";

        for(auto &i: value) {
            if(out_->str().back() != '[')
                *out_ << ", ";

            i.get().Serialize(this);
        }

        *out_ <<"]";
    }
}
