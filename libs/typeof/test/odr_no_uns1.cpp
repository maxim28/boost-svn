#include "odr_no_uns1.hpp"
#include "odr_no_uns2.hpp"

void odr_no_uns1()
{
    odr_test_1 t1;
    odr_test_2 t2;
    BOOST_AUTO(v1, t1);
    BOOST_AUTO(v2, t2);
}

int main()
{
    return 0;
}
