/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00367EB8(f32 fparg0) {
    f32 var_f0;

    var_f0 = 0x1.8fd7060000000p+8f;
    if (!(fparg0 < 0x1.2c00000000000p+10f)) {
        if (fparg0 < 0x1.7700000000000p+10f) {
            return 0x1.d216e40000000p+18f / fparg0;
        }
        if (fparg0 < 0x1.70c0000000000p+12f) {
            return ((0x1.1000000000000p+6f - ((fparg0 - 0x1.7700000000000p+10f) * 0x1.9521be0000000p-10f)) * 0x1.6619980000000p+9f * 0x1.3999980000000p+3f) / fparg0;
        }
        if (fparg0 < 0x1.9640000000000p+12f) {
            return ((0x1.9640000000000p+12f - fparg0) / 0x1.2c00000000000p+9f) * 0x1.23380e0000000p+6f;
        }
        var_f0 = 0x0.0p+0f;
        /* Duplicate return node #0x1.4000000000000p+3 Try simplifying control flow for better match */
        return var_f0;
    }
    return var_f0;
}
