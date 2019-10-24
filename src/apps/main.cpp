#include "koc_od_pi_intf.h"
#include <iostream> // std::cout
#include <unistd.h> // sleep()

int main(void)
{
    koc_od_pi::intf object;

    if ( object.setup() )
    {
        std::cout << "error" << std::endl;
        return 1;
    }

    int num = 0;
    while (1)
    {
        if (num == 32)
        {
            num = 0;
        }
        object.ttl(num);
        sleep(5);
        num++;
    }

    return 0;

}
