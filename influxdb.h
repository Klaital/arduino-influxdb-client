#ifndef ARDUINO_CLIENT_INFLUXDB_H
#define ARDUINO_CLIENT_INFLUXDB_H


#include "point.h"
#include <ArduinoHttpClient.h>
#include <WiFiNINA.h>

namespace Influx {
class InfluxDbClient {
    char host[128] = "";
    char org[64] = "";
    char token[128] = "";
    char bucket[64] = "";
    HttpClient *client;
public:
    InfluxDbClient(WiFiClient &wifi, const char* host, int port, const char* org, const char* bucket, const char* token);
    int send(const Point& p);
};
}
#endif
