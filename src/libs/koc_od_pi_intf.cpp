#include "koc_od_pi_intf.h"
#include "wiringPi.h"

namespace koc_od_pi
{
    int intf::setup()
    {
        if (wiringPiSetupPhys() == -1)
        {
            return 1;
        }

        // pin mode settings
        pinMode(static_cast<int>(intf::ttl::strobe), OUTPUT);
        pinMode(static_cast<int>(intf::ttl::data0), OUTPUT);
        pinMode(static_cast<int>(intf::ttl::data1), OUTPUT);
        pinMode(static_cast<int>(intf::ttl::data2), OUTPUT);
        pinMode(static_cast<int>(intf::ttl::data3), OUTPUT);
        pinMode(static_cast<int>(intf::ttl::data4), OUTPUT);

        // init
        digitalWrite (static_cast<int>(intf::ttl::strobe), HIGH);
        digitalWrite (static_cast<int>(intf::ttl::data0), LOW);
        digitalWrite (static_cast<int>(intf::ttl::data1), LOW);
        digitalWrite (static_cast<int>(intf::ttl::data2), LOW);
        digitalWrite (static_cast<int>(intf::ttl::data3), LOW);
        digitalWrite (static_cast<int>(intf::ttl::data4), LOW);

        return 0;
    }

    void intf::ttl(int num)
    {
        // ttl
        digitalWrite (static_cast<int>(intf::ttl::data0), 00001 & (num>>0));
        digitalWrite (static_cast<int>(intf::ttl::data1), 00001 & (num>>1));
        digitalWrite (static_cast<int>(intf::ttl::data2), 00001 & (num>>2));
        digitalWrite (static_cast<int>(intf::ttl::data3), 00001 & (num>>3));
        digitalWrite (static_cast<int>(intf::ttl::data4), 00001 & (num>>4));
        // strobe
        digitalWrite (static_cast<int>(intf::ttl::strobe), LOW);
        digitalWrite (static_cast<int>(intf::ttl::strobe), HIGH);
    }
}
