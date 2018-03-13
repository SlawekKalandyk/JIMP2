//
// Created by kalaslaw on 13.03.18.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>

std::unique_ptr<TinyUrlCodec> Init(){

}
void NextHash(std::arrray<char, 6> *state){

}
std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){

}
std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){

}
