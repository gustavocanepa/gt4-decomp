/* compiler: ee-gcc2.96-nsa-g */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK mWidget__deepCopy(void *);                            /* extern */
M2C_UNK func_003285A8(s32);                         /* extern */
M2C_UNK func_003285F8(s32);                         /* extern */
void *__dynamic_cast_2(s32, M2C_UNK, M2C_UNK, void *, M2C_UNK, void *); /* extern */

extern char mVirtualFace__tf[];
extern char hObject__tf[];
void mVirtualFace__deepCopy(void *arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_s0;
    void *temp_v0;
    void *var_v0;

    mWidget__deepCopy(arg0);
    var_v0 = NULL;
    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, void **, 4);
        var_v0 = __dynamic_cast_2(M2C_FIELD(temp_v0, s32 *, 4), (s32)mVirtualFace__tf, 0, arg1 + M2C_FIELD(temp_v0, s16 *, 0), (s32)hObject__tf, arg1);
    }
    if (var_v0 != NULL) {
        if ((arg0 + 0xA0) != (var_v0 + 0xA0)) {
            temp_s0 = M2C_FIELD(var_v0, s32 *, 0xA0);
            if (temp_s0 != 0) {
                func_003285A8(temp_s0);
            }
            temp_a0 = M2C_FIELD(arg0, s32 *, 0xA0);
            if (temp_a0 != 0) {
                func_003285F8(temp_a0);
            }
            M2C_FIELD(arg0, s32 *, 0xA0) = temp_s0;
        }
    }
}
