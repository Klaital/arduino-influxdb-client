#ifndef ARDUINO

#include <gtest/gtest.h>
#include "influxdb.h"

TEST(InfluxTest, FieldCat)
{
    char buf[128] = "";
    Influx::Field f;

    f.set("room", "kitchen");
    f.cat(buf, "");
    EXPECT_STREQ("room=kitchen", buf);

    Influx::Field f2;
    f2.set("temp", 34.5);
    buf[0] = '\0';
    f2.cat(buf);
    EXPECT_STREQ("temp", f2.key);
    EXPECT_STREQ("34.500000", f2.val);
    EXPECT_STREQ(",temp=34.500000", buf);

    f.cat(buf);
    EXPECT_STREQ(",temp=34.500000,room=kitchen", buf);
}

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

TEST(InfluxTest, UpdateField)
{
    char buf[256] = "";
    Influx::Point p;

    p.set_measurement("home");
    p.set_tag("room", "kitchen");
    p.set_field("temp", 21.1);
    p.set_field("co", "0i");

    p.timestamp = 1641024000;
    p.cat(buf);

    p.set_field("temp", 68.8);
    buf[0] = '\0';
    p.cat(buf);
    EXPECT_STREQ("home,room=kitchen temp=68.800003,co=0i 1641024000\n", buf);
}

#endif
