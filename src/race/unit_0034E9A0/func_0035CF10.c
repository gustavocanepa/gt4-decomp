#include "types.h"
void *memcpy(void *, const void *, unsigned int);

u8 func_0035C7C8();                                 /* extern */

struct func_0035CF10_arg0 {
    char pad0[0x78E];
    u8 unk78E;
};

u8 func_0035CF10(struct func_0035CF10_arg0 *arg0) {
    u8 var_v0;

    var_v0 = func_0035C7C8();
    if (var_v0 != 0) {
        var_v0 = arg0->unk78E;
    }
    return var_v0;
}
