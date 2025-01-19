#include "influxdb.h"
#include <cstring>
#include <cstdio>

Influx::InfluxDbClient::InfluxDbClient(const char* host, const char *org, const char *bucket, const char *token)
{
    strcpy(this->host, host);
    strcpy(this->org, org);
    strcpy(this->bucket, bucket);
    strcpy(this->token, token);
}

void Influx::InfluxDbClient::cat_http_preamble(char *buf, const size_t body_len) const {
    strcat(buf, "POST /api/v2/write?org=");
    strcat(buf, this->org);
    strcat(buf, "&bucket=");
    strcat(buf, this->bucket);
    strcat(buf, "&precision=ns HTTP/1.1\n");
    strcat(buf, "Host: ");
    strcat(buf, this->host); // TODO: strip the protocol portion
    strcat(buf, "\nAuthorization: token ");
    strcat(buf, this->token);
    strcat(buf, "\nUser-Agent: arduino");
    strcat(buf, "\nContent-Type: text/plain");
    strcat(buf, "\nAccept: application/json");
    char tmp[32];
    tmp[0] = '\0';
    sprintf(tmp, "%ld", body_len);
    strcat(buf, "\nContent-Length: ");
    strcat(buf, tmp);
    strcat(buf, "\n\n");
}

void Influx::InfluxDbClient::to_http_request(char *buf, const Point &p) const {
    // Compose the body portion first in order to calculate the content length header
    char body_buf[1024];
    body_buf[0] = '\0';
    p.cat(body_buf);
    this->cat_http_preamble(buf, strlen(body_buf));
    strcat(buf, body_buf);
}
