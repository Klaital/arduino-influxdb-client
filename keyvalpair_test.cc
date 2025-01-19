#ifndef ARDUINO

#include <gtest/gtest.h>
#include "keyvalpair.h"

TEST(KeyValPairTest, SetReset)
{
    Influx::KeyValPair p;

    p.set("room", "kitchen");
    EXPECT_STREQ("room", p.get_key());
    EXPECT_STREQ("kitchen", p.get_val());

    p.reset();
    EXPECT_EQ(0, strlen(p.get_key()));
    EXPECT_EQ(0, strlen(p.get_val()));    
}

TEST(KeyValPairTest, SetInt)
{
    Influx::KeyValPair p;

    p.set("aqi", 37);
    EXPECT_STREQ("aqi", p.get_key());
    EXPECT_STREQ("37", p.get_val());    
}


TEST(KeyValPairTest, SetFloat)
{
    Influx::KeyValPair p;

    p.set("humidity", 57.3f);
    EXPECT_STREQ("57.2999", p.get_val());    
}

TEST(KeyValPairTest, CatPoints) 
{
    Influx::KeyValPair p;
    p.set("room", "kitchen");
    char buf[1024];
    buf[0] = '\0';
    p.cat(buf);
    EXPECT_STREQ("room=kitchen", buf);
    buf[0] = '\0';
    p.cat(buf,",");
    EXPECT_STREQ(",room=kitchen", buf);
}
#endif
