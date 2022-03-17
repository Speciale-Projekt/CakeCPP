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
        static void writeAUXheader(FILE* fp);
        static void writeParentRequest(char * path);

        static void writeDiscoveryRequest(char * path);
        static void writeDiscoveryResponse(char * path);
};


#endif //CAKECPP_MLE_H
