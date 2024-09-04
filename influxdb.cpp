#include "influxdb.h"

#include <stdio.h>
#include <cstring>

void Influx::Field::set(const char*k, const char *v) 
{
    strcpy(this->key, k);
    strcpy(this->val, v);
}
void Influx::Field::set(const char *k, const float v)
{
    strcpy(this->key, k);
    sprintf(this->val, "%.6f", v);
}
void Influx::Field::cat(char *buf, const char* prefix) const
{
    if (prefix != nullptr) {
        strcat(buf, prefix);
    }
    strcat(buf, this->key);
    strcat(buf, "=");
    strcat(buf, this->val);
}

void Influx::Point::cat(char *buf) const 
{
    strcat(buf, this->measurement);
    for (size_t idx=0; idx < this->tag_count; idx++)
    {
        this->tags[idx].cat(buf);
    }
    bool first_field = true;
    for (size_t idx=0; idx < this->field_count; idx++)
    {
        if (first_field)
        {
            this->fields[idx].cat(buf, " ");
            first_field = false;
        }
        else 
        {
            this->fields[idx].cat(buf, ",");
        }
    }
    strcat(buf, " ");
    
    sprintf(buf+strlen(buf), "%ld", this->timestamp);
    strcat(buf, "\n");
}

void Influx::Point::set_tag(const char *k, const char *v)
{
    // Check if an existing tag has this key
    size_t idx = 0;
    bool found = false;
    for (idx = 0; idx < this->tag_count; idx++)
    {
        if (strcmp(this->tags[idx].key, k) == 0) 
        {
            found = true;
            break;
        }
    }
    if (!found) {
        idx = this->tag_count;
    }

    this->tags[idx].set(k, v);
    if (!found) {
        this->tag_count++;
    }
}

void Influx::Point::set_field(const char *k, const char *v)
{
    // Check if an existing tag has this key
    size_t idx = 0;
    bool found = false;
    for (idx = 0; idx < this->field_count; idx++)
    {
        if (strcmp(this->fields[idx].key, k) == 0) 
        {
            found = true;
            break;
        }
    }
    if (!found) {
        idx = this->field_count;
    }

    this->fields[idx].set(k, v);
    if (!found) {
        this->field_count++;
    }
}

void Influx::Point::set_field(const char *k, const float v)
{
    // Check if an existing tag has this key
    size_t idx = 0;
    bool found = false;
    for (idx = 0; idx < this->field_count; idx++)
    {
        if (strcmp(this->fields[idx].key, k) == 0) 
        {
            found = true;
            break;
        }
    }
    if (!found) {
        idx = this->field_count;
    }

    this->fields[idx].set(k, v);
    if (!found) {
        this->field_count++;
    }
}


void Influx::Point::set_measurement(const char *m)
{
    strcpy(this->measurement, m);
}
