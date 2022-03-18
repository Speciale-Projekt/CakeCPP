//
// Created by agw on 04/03/2022.
//
#include <string>
#include <fstream>

#ifndef CAKE_OTPROTOCOLMESSAGE_H
#define CAKE_OTPROTOCOLMESSAGE_H

class OTProtocolMessage {
public:
    static std::string ParseFromFile(const std::string &path) {
        std::string message;
        std::ifstream file(path);
        if (file.is_open()) {
            std::string line;
            while (getline(file, line)) {
                message += line;
            }
            file.close();
        }
        return message;
    }

    void Writetofile(const std::string &path, const std::string &message) {
        std::ofstream file(path);
        if (file.is_open()) {
            file << message;
            file.close();
        }
    }

private:
    std::string parseToString(std::string message) {
        return message;
    }

};

#endif //CAKE_OTPROTOCOLMESSAGE_H
