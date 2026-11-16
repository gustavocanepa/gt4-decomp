/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK mBox__deepCopy();                            /* extern */
void *__dynamic_cast_2(s32, M2C_UNK, M2C_UNK, void *, M2C_UNK, void *); /* extern */

extern char mMBox__tf[];
extern char hObject__tf[];
void mMBox__deepCopy(void *arg0, void *arg1) {
    void *temp_v0;
    void *var_v1;

    mBox__deepCopy();
    var_v1 = NULL;
    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, void **, 4);
        var_v1 = __dynamic_cast_2(M2C_FIELD(temp_v0, s32 *, 4), (s32)mMBox__tf, 0, arg1 + M2C_FIELD(temp_v0, s16 *, 0), (s32)hObject__tf, arg1);
    }
    if (var_v1 != NULL) {
        M2C_FIELD(arg0, s32 *, 0xC0) = (s32) M2C_FIELD(var_v1, s32 *, 0xC0);
        M2C_FIELD(arg0, f32 *, 0xC4) = (f32) M2C_FIELD(var_v1, f32 *, 0xC4);
        M2C_FIELD(arg0, f32 *, 0xC8) = (f32) M2C_FIELD(var_v1, f32 *, 0xC8);
    }
}
