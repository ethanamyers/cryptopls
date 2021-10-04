#include "string_manipulation.h"

#include <iostream>

//
// Created by ethan on 9/27/21.
//

#include "string_manipulation.h"

char atoh(char mschar_in, char lschar_in){
    char out = 0x00;
    if(mschar_in >= 0x30 && mschar_in <= 0x39) out += (mschar_in - 0x30) << 4;
    else if(mschar_in >= 0x41 && mschar_in <= 0x46) out += (mschar_in - 0x37) << 4;
    else if(mschar_in >= 0x61 && mschar_in <= 0x66) out += (mschar_in - 0x57) << 4;
    if(lschar_in >= 0x30 && lschar_in <= 0x39) out += (lschar_in - 0x30);
    else if(lschar_in >= 0x41 && lschar_in <= 0x46) out += (lschar_in - 0x37);
    else if(lschar_in >= 0x61 && lschar_in <= 0x66) out += (lschar_in - 0x57);
    return out;
}

void htoa(char * mschar_out, char * lschar_out, char in){
    *mschar_out = (in & 0xF0) >> 4;
    *lschar_out = in & 0x0F;
    if(*mschar_out < 0x0A) *mschar_out = *mschar_out + 0x30;
    else *mschar_out = *mschar_out + 0x57;
    if(*lschar_out < 0x0A) *lschar_out = *lschar_out + 0x30;
    else *lschar_out = *lschar_out + 0x57;
}

char b64toa(char in){
    char out = 0x00;
    if(in < 0x1A) out += in + 0x41;
    else if(in < 0x34) out += in + 0x47;
    else if(in < 0x3E) out += in - 0x04;
    else if(in == 0x3E) out += 0x2B;
    else if(in == 0x3F) out += 0x2F;
    return out;
}

char htob64(char mostschar_in, char midschar_in, char leastschar_in, uint8_t quad_index){
    char out = 0x00;
    switch(quad_index) {
        case 0:
        default:
            out += mostschar_in >> 2; // just lop off two LSBs
            break;
        case 1:
            out += ((mostschar_in & 0x03) << 4) + ((midschar_in & 0xF0) >> 4);
            break;
        case 2:
            out += ((midschar_in & 0x0F) << 2) + ((leastschar_in & 0xC0) >> 6);
            //std::cout << (int)out << std::endl;
            break;
        case 3:
            out += leastschar_in & 0x3F; // just lop off two MSBs
            break;
    }
    return out;
}