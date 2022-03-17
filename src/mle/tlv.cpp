//
// Created by larsb on 10-03-2022.
//

#include <cstdio>
#include "tlv.h"

const char *PAN_ID;
const char *NETWORK_NAME;

int NETWORK_NAME_LENGTH;


void tlv::writeModeTLV(FILE* file) {
    fputc('\x01', file);
    fputc('\x01', file);
    fputc('\x0b', file);


    /*
     * first four bits reserved last four bits are as follows
     *      | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
     *      | - reserved  - | R | S | D | N |
     * R:receiver on when idle, only MTD acting SED sets '0';
     * S:secure data request set to '1' to secure;
     * D:device type - '1' FTD , '0' MTD;
     * N:network data, set '0' if only need stable
     * */

}

 void tlv::writeChallengeTLV(FILE* file) {
    char value[4] = {'A','B','C','D'};

    fputc('\x03', file);
    fputc('\x04',file);
    fputs(value,file);
}

void tlv::writeScanMaskTLV(FILE* file) {
    fputc('\x0e',file);
    fputc('\x01',file);
    fputc('\xc0',file);

}

void tlv::writeVersionTLV(FILE* file) {
    fputc('\x12',file);
    fputc('\x02',file);
    fputc('\x00',file);
    fputc('\x02',file);
}

void tlv::writeThreadDiscoveryRequestTLV(FILE *fp) {
    fputc('\x1a', fp);  // type   = thread discovery
    fputc('\x04', fp);  // length = 4
    fputc('\x80',fp);   // subtype = 0x80
    fputc('\x02', fp);  // sublength = 2
    fputc('\x18', fp);  // vers =2 and joiner flag set
    fputc('\x00',fp);   // reserved = all set to 00
}

void tlv::writeThreadDiscoveryResponseTLV(FILE *fp) {

    fputc('\x1a', fp);  // type   = thread discovery
    fputc((char) (16+NETWORK_NAME_LENGTH), fp);  // length

    // Discovery Response subTLV
    fputc('\x81',fp);   // subtype = 0x81
    fputc('\x02', fp);  // sublength = 2
    fputc('\x18', fp);  // vers =2 and joiner flag set
    fputc('\x00',fp);   // reserved = all set to 00

    // Extended Pan ID subTLV
    fputc('\x02',fp);   // subtype = 0x02
    fputc('\x08', fp);  // sublength = 8
    fputs(PAN_ID,fp);   // The Extended PAN ID

    // Network Name subTLV
    putc('\x03',fp);   // subtype = 0x02
    fputc((char) NETWORK_NAME_LENGTH, fp);  // sublength = 8
    fputs(NETWORK_NAME,fp);   // The Extended PAN ID

    // TODO: optional Steering data, Joiner UDP port and Commissioner UDP port
}


