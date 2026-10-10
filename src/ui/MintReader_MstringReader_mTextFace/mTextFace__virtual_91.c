#include "types.h"
#include "gt4/mTextFace.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_002452A8(void *, void *, void *);
void *func_0025BF60(void *);
void mSceneViewFace__virtual_91(void *);
struct mTextFace__virtual_91_temp_v0 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
};

void mTextFace__virtual_91(void *arg0) {
    struct mTextFace__virtual_91_temp_v0 *temp_v0;
    mSceneViewFace__virtual_91(arg0);
    if (((struct mTextFace *)arg0)->unk114 != 0) {
        ((struct mTextFace *)arg0)->unk114 = 0;
        func_002452A8(arg0, (s8 *)arg0 + 0x118, (s8 *)arg0 + 0x11C);
    }
    temp_v0 = func_0025BF60(arg0);
    temp_v0->unk8 = (f32) ((struct mTextFace *)arg0)->unk118;
    temp_v0->unkC = (f32) ((struct mTextFace *)arg0)->unk11C;
}
