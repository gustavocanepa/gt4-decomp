#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_0057CC10(void **arg0) {
    void *temp_s0;

    temp_s0 = *arg0;
    if (temp_s0 != NULL) {
        func_0057CB80(arg0, temp_s0);
    }
    return temp_s0;
}
