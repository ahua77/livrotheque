/////////////////////BASE64.CPP/////////////////////

#include "base64.hpp"

using namespace std;

string Base64::encode(const std::string & data)
{
const size_t trail = data.size()%3;
size_t sz = data.size()/3*4;
sz += (trail != 0) ? 4 : 0;

un32 b64;

string out;
out.resize(sz);

size_t i = 0, k = 0;

while(i < data.size()-trail)
{
b64.c[3] = data[i++];
b64.c[2] = data[i++];
b64.c[1] = data[i++];

out[k++] = b64table[static_cast <int> ((b64.l & mask1) >> 26)];
out[k++] = b64table[static_cast <int> ((b64.l & mask2) >> 20)];
out[k++] = b64table[static_cast <int> ((b64.l & mask3) >> 14)];
out[k++] = b64table[static_cast <int> ((b64.l & mask4) >> 8)];
}

b64.l = 0;

switch(trail)
{
case 1:
b64.c[3] = data[i++];
out[k++] = b64table[static_cast <int> ((b64.l & mask1) >> 26)];
out[k++] = b64table[static_cast <int> ((b64.l & mask2) >> 20)];
out[k++] = fillchar;
out[k++] = fillchar;
break;

case 2:
b64.c[3] = data[i++];
b64.c[2] = data[i++];
out[k++] = b64table[static_cast <int> ((b64.l & mask1) >> 26)];
out[k++] = b64table[static_cast <int> ((b64.l & mask2) >> 20)];
out[k++] = b64table[static_cast <int> ((b64.l & mask3) >> 14)];
out[k++] = fillchar;
break;
}

return out;
}


string Base64::decode(const std::string & data)
{
// Number of trailing '='
const size_t trail = (data[data.size()-1] == fillchar) ? ((data[data.size()-2] == fillchar) ? 2 : 1 ) : 0;
// Number of char to decode
const size_t szin = (trail == 0) ? data.size() : data.size()-4;
// Output string size
const size_t szout = szin/4*3+ ((trail == 0)? 0 : ((trail == 1) ? 3 : 2));
//const size_t szout = szin/4*3+ ((trail == 0)? 0 : ((trail == 1) ? 2 : 1));

un32 b64;

string out;
out.resize(szout);

size_t i = 0, k = 0;

while(i < szin)
{
b64.l = 0;
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 26;
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 20;
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 14;
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 8;

out[k++] = b64.c[3];
out[k++] = b64.c[2];
out[k++] = b64.c[1];
}

b64.l = 0;

switch(trail)
{
case 1:
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 26;
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 20;
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 14;

out[k++] = b64.c[3];
out[k++] = b64.c[2];
break;

case 2:
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 26;
b64.l += (static_cast < uint32_t > (b64table.find_first_of(data[i++])) ) << 20;

out[k++] = b64.c[3];
break;
}

return out;
}



////////////////////////////////////////////////////
