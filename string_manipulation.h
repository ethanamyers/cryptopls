#ifndef CRYPTOPLS_STRING_MANIPULATION_H
#define CRYPTOPLS_STRING_MANIPULATION_H

#include <stdint.h>

char atoh(char mschar_in, char lschar_in);

void htoa(char * mschar_out, char * lschar_out, char in);

char b64toa(char in);

char htob64(char mostschar_in, char midschar_in, char leastschar_in, uint8_t quad_index);

#endif //CRYPTOPLS_STRING_MANIPULATION_H
