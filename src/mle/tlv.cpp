//
// Created by larsb on 10-03-2022.
//

#include <cstdio>
#include "tlv.h"
tlv::tlv(char *tlvType, char *tlvLength, char *tlvValue) {
    *type=*tlvType;
    *length=*tlvLength;
    *value=*tlvValue;
}

tlv tlv::modeTLV() {
    char tlvType[1];
    char tlvLength[1];
    char tlvValue[] = {'\x0B'};

    tlvType[0] = '\x01';
    tlvLength[0] = '\x01';

    /*
     * first four bits reserved last four bits are as follows
     *      | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
     *      | - reserved  - | R | S | D | N |
     * R:receiver on when idle, only MTD acting SED sets '0';
     * S:secure data request set to '1' to secure;
     * D:device type - '1' FTD , '0' MTD;
     * N:network data, set '0' if only need stable
     * */

    return {tlvType,tlvLength,tlvValue};
}

 tlv tlv::challengeTLV() {
    char tlvType[1] = {'\x03'};
    char tlvLength[] = {'\x04'};
    char tlvValue[4] = {'A','B','C','D'};

    return {tlvType, tlvLength, tlvValue};

}

tlv tlv::scanmaskTLV() {
    char tlvType[1] = {'\x0e'};
    char tlvLength[1] = {'\x01'};
    char tlvValue[] ={'\xc0'} ;

    return {tlvType, tlvLength, tlvValue};
}

tlv tlv::versionTLV() {
    char tlvType[1] = {'\x12'};
    char tlvLength[1] = {'\x02'};
    char tlvValue[] =  {'\x00', '\x02'};

    return {tlvType,  tlvLength, tlvValue};
}

void tlv::writeToFile(FILE *file) {
    fputc(type[0], file);
    fputc(length[0],file);
    for(int i = 0; i< (int) length[0];i++){
        fputc(value[i],file);
    }
}

tlv::tlv() {

}

tlv::tlv(tlv &old) {
    type[0]=old.type[0];
    length[0]=old.length[0];
    for(int i = 0; i < (int) old.length[0]; i++){
        value[i]=old.value[i];
    }
}


