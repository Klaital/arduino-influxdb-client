#include "influxdb.h"
#include <cstring>
#include <cstdio>
#include <WiFiNINA.h>
#include <Arduino.h>


Influx::InfluxDbClient::InfluxDbClient(
    WiFiClient &wifi,
    const char* host, const int port, const char *org, const char *bucket, const char *token)
{
    this->client = new HttpClient(wifi, host, port);
    strcpy(this->host, host);
    strcpy(this->org, org);
    strcpy(this->bucket, bucket);
    strcpy(this->token, token);
}


int Influx::InfluxDbClient::send(const Point &p) {
    client->beginRequest();
    char urlbuf[128] = "";
    sprintf(urlbuf, "/api/v2/write?org=%s&bucket=%s&precision=s", this->org, this->bucket);
    char authbuf[134] = "";
    sprintf(authbuf, "Token %s", this->token);
    char bodybuf[1024] = "";
    p.cat(bodybuf);
    client->post(urlbuf);
    client->sendHeader("Content-Length", strlen(bodybuf));
    client->sendHeader("Authorization", authbuf);
    client->sendHeader("Content-Type", "text/plain");
    client->beginBody();
    client->print(bodybuf);
    client->endRequest();
    Serial.print("Sent ");
    Serial.print(strlen(bodybuf));
    Serial.print(" bytes to influx: ");
    Serial.println(bodybuf);

    return client->responseStatusCode();
}
