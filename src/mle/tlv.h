//
// Created by larsb on 10-03-2022.
//

#ifndef CAKECPP_TLV_H
#define CAKECPP_TLV_H

struct tlv {
public:
    char type[1];
    char length[1];
    char value[];

    tlv();
    tlv(tlv &old);
    tlv(char tlvType[1], char tlvLength[1], char tlvValue[]);
    void writeToFile(FILE* file);

    static tlv modeTLV();
    static tlv challengeTLV();
    static tlv scanmaskTLV();
    static tlv versionTLV();

};


#endif //CAKECPP_TLV_H
