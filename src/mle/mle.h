//
// Created by larsb on 10-03-2022.
//

#ifndef CAKECPP_MLE_H
#define CAKECPP_MLE_H


#include <cstdint>
#include <cstdio>
#include "tlv.h"

class mle {
public:
    struct message {
        char securityHeader[1]{};
        char auxHeader[14]{};
        uint8_t tlvs_length;
        tlv tlvs[];
        message(char securityHeader[1],char auxHeader[14],uint8_t tlvs_length,tlv tlvs[]);
        message(const message &old);

        void writeToFile(FILE* file);

        static message parentRequest();
    };
};


#endif //CAKECPP_MLE_H
