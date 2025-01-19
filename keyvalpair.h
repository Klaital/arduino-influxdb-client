namespace Influx {

#ifndef KEYVALPAIR_H
#define KEYVALPAIR_H

#ifndef KEYVALPAIR_MAX_KEY_LEN
#define KEYVALPAIR_MAX_KEY_LEN 32
#endif
#ifndef KEYVALPAIR_MAX_VAL_LEN
#define KEYVALPAIR_MAX_VAL_LEN 32
#endif

class KeyValPair {
    char key[KEYVALPAIR_MAX_KEY_LEN] = "";
    char val[KEYVALPAIR_MAX_VAL_LEN] = "";
    char separator[4] = "=";

public:
    void reset();
    void set(const char *k, const char *v);
    void set(const char *k, int v);
    void set(const char *k, float v);

    const char * get_key() const;
    const char * get_val() const ;

    void cat(char *buf, const char* prefix="") const;
};
}

#endif
