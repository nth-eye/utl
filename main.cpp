#include "utl/utl.h"

int main()
{
    utl::ring<int, 4> ring;

    for (size_t i = 0; i < ring.capacity() + 8; ++i) 
        ring.put(i);
        
    for (auto it : ring)
        printf("%d ", it);

    return 0;
}
