#include "keyvalpair.h"

#include <stdio.h>
#include <cstring>

void Influx::KeyValPair::reset() {
    strcpy(this->key, "");
    strcpy(this->val, "");
}

void Influx::KeyValPair::set(const char* k, const char* v) {
    strcpy(this->key, k);
    strcpy(this->val, v);
}
void Influx::KeyValPair::set(const char* k, const int v) {
    strcpy(this->key, k);
    this->val[0] = '\0';
    sprintf(this->val, "%d", v);
}
void float_to_str(const float f, char *buf) {
    const char *tmp_sign = (f < 0.0f) ? "-" : "";
    float tmp_val = (f < 0) ? -f : f;
    int tmpInt = tmp_val; // extract the integer part
    int tmpDecimal = (tmp_val - tmpInt) * 10000.0; // extract 4 digits of the right-hand-side
    sprintf(buf, "%s%d.%d", tmp_sign, tmpInt, tmpDecimal);

}
void Influx::KeyValPair::set(const char* k, const float v) {
    strcpy(this->key, k);
    this->val[0] = '\0';
    float_to_str(v, this->val);
}
const char* Influx::KeyValPair::get_key() const {
    return this->key;
}

const char* Influx::KeyValPair::get_val() const {
    return this->val;
}

void Influx::KeyValPair::cat(char *buf, const char*prefix) const {
    strcat(buf, prefix);
    strcat(buf, this->key);
    strcat(buf, this->separator);
    strcat(buf, this->val);
}