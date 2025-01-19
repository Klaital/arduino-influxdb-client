#ifndef ARDUINO_CLIENT_INFLUXDB_H
#define ARDUINO_CLIENT_INFLUXDB_H


#include "point.h"

namespace Influx {
class InfluxDbClient {
    char host[128] = "";
    char org[64] = "";
    char token[128] = "";
    char bucket[64] = "";
public:
    InfluxDbClient(const char* host, const char* org, const char* bucket, const char* token);
    void cat_http_preamble(char *buf, size_t body_len) const;
    void to_http_request(char* buf, const Point& p) const;
};
}
#endif
