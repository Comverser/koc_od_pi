#ifndef KOC_OD_PI_INTF_H
#define KOC_OD_PI_INTF_H

namespace koc_od_pi
{
    class intf
    {
    public:
        int setup();
        void ttl(int num);

    private:
        enum class ttl
        {
            strobe = 36,
            data0 = 33,
            data1 = 38,
            data2 = 35,
            data3 = 40,
            data4 = 37
        };
    };
}

#endif
