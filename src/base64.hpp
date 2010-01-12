/////////////////////BASE64.HPP/////////////////////
#ifndef __ENCODING_BASE64_HPP__
#define __ENCODING_BASE64_HPP__

#include <iostream>

/// Base64 alphabet
static const std::string b64table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class Base64
{
private :
/// Filling character
static const char fillchar = '=';

// The masks
static const uint32_t mask1 = 0xFC000000;
static const uint32_t mask2 = 0x03F00000;
static const uint32_t mask3 = 0x000FC000;
static const uint32_t mask4 = 0x00003F00;

typedef union
{
uint32_t l ;
char c[4];
}un32;

public:
static std::string encode(const std::string & data);
static std::string decode(const std::string & data);
};
#endif
//////////////////////////////////////////////////// 
