#ifndef ARDUINO

#include <gtest/gtest.h>
#include "point.h"

TEST(InfluxTest, PointCat)
{
    char buf[256] = "";
    Influx::Point p;

    p.set_measurement("home");
    p.set_tag("room", "kitchen");
    p.set_field("temp", "21.1");
    p.set_field("co", "0i");

    p.timestamp = 1641024000;
    p.cat(buf);

    EXPECT_STREQ("home,room=kitchen temp=21.1,co=0i 1641024000\n", buf);
}

#endif
