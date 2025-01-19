#ifndef INFLUX_POINT_H
#define INFLUX_POINT_H

#ifndef INFLUX_POINT_MAX_TAGS_LEN
#define INFLUX_POINT_MAX_TAGS_LEN 128
#endif
#ifndef INFLUX_POINT_MAX_TAGS
#define INFLUX_POINT_MAX_TAGS 8
#endif

#include "keyvalpair.h"
#include <cstring>

namespace Influx {
class Point {
    KeyValPair tags[INFLUX_POINT_MAX_TAGS];
    size_t tag_count = 0;
    char measurement[16] = "";
    KeyValPair fields[INFLUX_POINT_MAX_TAGS];
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
    void set_field(const char* k, const int v);
    // configure the measurement
    void set_measurement(const char* m);
    // configure the timestamp
    unsigned long timestamp = 0;
};
}


#endif
