#include "types.h"
#include "gt4/mCarModelPS2.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004A7844(f32, f32, f32);               /* extern */
s32 func_004A7988(f32);                         /* extern */
s32 func_004A79B0(f32);                         /* extern */
s32 func_004A79D8(f32);                         /* extern */

void mCarModelPS2__virtual_55(void *arg0) {
    func_004A7844(((struct mCarModelPS2 *)arg0)->unk2C, ((struct mCarModelPS2 *)arg0)->unk30, ((struct mCarModelPS2 *)arg0)->unk34);
    func_004A79D8(((struct mCarModelPS2 *)arg0)->unk48);
    func_004A7988(((struct mCarModelPS2 *)arg0)->unk38);
    func_004A79B0(((struct mCarModelPS2 *)arg0)->unk44);
}
