#include "utl/utl.h"

int main()
{
    utl::svector<uint8_t, 4> vec;

    vec.push_back(0x54);
    vec.push_back(0x01);
    vec.push_back(0x00);
    vec.push_back(0x69);

    for (auto &x : vec) 
        utl::log_bits(&x, sizeof(x) * 8 - 0, 0);

    vec.erase(&vec[2]);

    for (auto &x : vec) 
        utl::log_bits(&x, sizeof(x) * 8 - 0, 0);
}
