#ifndef ARDUINO_CLIENT_INFLUXDB_H
#define ARDUINO_CLIENT_INFLUXDB_H

#ifndef INFLUX_POINT_MAX_TAGS_LEN
#define INFLUX_POINT_MAX_TAGS_LEN 128
#endif
#ifndef INFLUX_POINT_MAX_TAGS
#define INFLUX_POINT_MAX_TAGS 8
#endif

#include <cstring>

namespace Influx {
class Field {
public:
    char key[32] = "";
    char val[64] = "";

    void set(const char *k, const char *v);
    void set(const char *k, const float v);

    // append the string representation of this field to the given buffer. Terminate with \0 char.
    void cat(char *buf, const char* prefix=",") const;
};
class Point {
    Field tags[INFLUX_POINT_MAX_TAGS];
    size_t tag_count = 0;
    char measurement[16] = "";
    Field fields[INFLUX_POINT_MAX_TAGS];
    size_t field_count = 0;
    
public:
    Point() = default;

    // append the string representation of this point to the given buffer, including newline. Terminate with \0 character.
    void cat(char *buf) const;
    // add or overwrite a tag
    void set_tag(const char* k, const char* v);
    // add or overwrite a field
    void set_field(const char* k, const char* v);
    void set_field(const char* k, const float v);
    // configure the measurement
    void set_measurement(const char* m);
    // configure the timestamp
    unsigned long timestamp = 0;
};
}


#endif
