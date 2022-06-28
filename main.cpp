#include "utl/utl.h"

struct Ctor {
    Ctor(int) {}
    Ctor()
    {
        printf("ctor \n");
    }
};

constexpr auto test_ce_vector()
{
    utl::ce_svector<int, 5> vec = {};

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);

    return vec;
}

int main()
{
    constexpr auto vec = test_ce_vector();

    for (const auto &x : vec)
        printf("%d ", x);

    return 0;
}
