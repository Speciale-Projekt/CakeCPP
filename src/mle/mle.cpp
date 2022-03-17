//
// Created by larsb on 10-03-2022.
//

#include "mle.h"
void mle::writeAUXheader(FILE* fp){
    char frame_counter[] = { 'a', 'b', 'c', 'd'};

    fputc('\xB0',fp);
    fputs(frame_counter,fp); // Frame counter
    for(int i = 0; i<5; i++){
        fputc('\xff', fp); // Key identifier all xFF when in key mode 2
    }
}

void writeMIC(FILE* fp){
    fputc('\x00',fp);
    fputc('\x00',fp);
}

void mle::writeParentRequest(char * path) {
    FILE * file = fopen(path, "w");
    char  command[] = {'\x10'};
    writeAUXheader(file);
    fputc(command[0], file);
    writeMIC(file);

    tlv::writeModeTLV(file);
    tlv::writeChallengeTLV(file);
    tlv::writeScanMaskTLV(file);
    tlv::writeVersionTLV(file);
    fflush(file);
    fclose(file);

}

void mle::writeDiscoveryRequest(char *path) {
    FILE * file = fopen(path, "w");
    char securityHeader[] = { '\xFF'};
    char  command[] = {'\x10'};

    fputc(securityHeader[0],file);
    fputc(command[0], file);

    tlv::writeThreadDiscoveryRequestTLV(file);
    fflush(file);
    fclose(file);

}

void mle::writeDiscoveryResponse(char *path) {
    FILE * file = fopen(path, "w");
    char securityHeader[] = { '\xFF'};
    char  command[] = {'\x11'};

    fputc(securityHeader[0],file);
    fputc(command[0], file);

    tlv::writeThreadDiscoveryResponseTLV(file);
    fflush(file);
    fclose(file);

}
