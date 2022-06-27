#include "utl/utl.h"

// struct Ctor {
// private:
//     Ctor()
//     {
//         printf("ctor \n");
//     }
// };

int main()
{
    utl::svector<int, 5> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);

    for (auto &x : vec)
        printf("%d ", x);

    return 0;
}
