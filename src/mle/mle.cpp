//
// Created by larsb on 10-03-2022.
//

#include "mle.h"

mle::message::message(char *securityHeader, char *auxHeader, uint8_t tlvs_length, tlv *tlvs) {
    this->securityHeader[0]=securityHeader[0];
    for(int i = 0; i< 14;i++){
        this->auxHeader[0]=auxHeader[0];
    }
    this->tlvs_length=tlvs_length;
    for(int i = 0; i< tlvs_length;i++){
        this->tlvs[i]=tlvs[i];
    }
}

void mle::message::writeToFile(FILE *file) {
    if(securityHeader[0] == '\x00'){
        fputc(securityHeader[0],file);
        fputs(auxHeader,file);
    } else {
        fputc(securityHeader[0],file);
    }
    for(int i = 0; i < tlvs_length; i++){
        tlvs[i].writeToFile(file);
    }

}

mle::message mle::message::parentRequest() {
    char securityHeader[1];
    char aux[14];
    uint8_t tlvs_length = 4;
    tlv tlvs[4];

    securityHeader[0] = '\xFF';
    for(char & i : aux){
        i = '\x00';
    }
    tlvs[0] = tlv::modeTLV();
    tlvs[1] = tlv::challengeTLV();
    tlvs[2] = tlv::scanmaskTLV();
    tlvs[3] = tlv::versionTLV();

    return {securityHeader,aux,tlvs_length,tlvs};
}

mle::message::message(const mle::message &old) {
    securityHeader[0]=old.securityHeader[0];
    for(int i = 0; i< sizeof(auxHeader);i++){
        auxHeader[i]=old.auxHeader[i];
    }
    tlvs_length=old.tlvs_length;
    for(int i = 0; i< tlvs_length;i++){
        tlvs[i]=old.tlvs[i];
    }
}
