//
// Created by agw on 04/03/2022.
//
#include <string>
#include "../OTProtocolMessage.h"

#ifndef CAKE_TALKTOOT_H
#define CAKE_TALKTOOT_H


class Talker {
public:
    std::string pathToTalk;
    //TODO: Needs more information
    explicit Talker(const std::string& pathToTalk);

    void talk(const OTProtocolMessage *message) {
        // Write the message to a file

    }

};

Talker::Talker(const std::string& pathToTalk) {
    this->pathToTalk = pathToTalk;
}




#endif //CAKE_TALKTOOT_H
