//
// Created by larsb on 10-03-2022.
//

#ifndef CAKECPP_TLV_H
#define CAKECPP_TLV_H

class tlv {
public:
    static void writeModeTLV(FILE *file);
    static void writeChallengeTLV(FILE* file);
    static void writeScanMaskTLV(FILE* file);
    static void writeVersionTLV(FILE* file);

    static void writeThreadDiscoveryRequestTLV(FILE *fp);
    static void writeThreadDiscoveryResponseTLV(FILE *fp);
};


#endif //CAKECPP_TLV_H
