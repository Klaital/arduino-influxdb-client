#ifndef ARDUINO

#include <gtest/gtest.h>
#include "influxdb.h"
#include "point.h"

TEST(InfluxTest, GenerateHttpRequest)
{
    char buf[2048] = "";
    Influx::InfluxDbClient influx("klaital.com:8086", "myorg", "mybucket", "mytoken");
    Influx::Point p1;
    p1.set_measurement("home");
    p1.set_tag("room", "kitchen");
    p1.set_field("temp", "21.1");
    p1.set_field("co", "0i");
    p1.timestamp = 1641024000;
    
    influx.to_http_request(buf, p1);
    EXPECT_STREQ("POST /api/v2/write?org=myorg&bucket=mybucket&precision=ns HTTP/1.1\nHost: klaital.com:8086\nAuthorization: token mytoken\nUser-Agent: arduino\nContent-Type: text/plain\nAccept: application/json\nContent-Length: 45\n\nhome,room=kitchen temp=21.1,co=0i 1641024000\n", buf);
}
#endif
