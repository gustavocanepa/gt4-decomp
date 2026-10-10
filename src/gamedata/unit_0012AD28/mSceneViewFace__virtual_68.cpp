extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void mTextFace__virtual_68(...) throw();
void func_00577F80(...) throw();

struct mSceneViewFace__virtual_68_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

void mSceneViewFace__virtual_68(char *arg0) {
    mTextFace__virtual_68();
    if (((struct mSceneViewFace__virtual_68_arg0 *)arg0)->unkA4 != 0) {
        do {
            func_00577F80();
        } while (((struct mSceneViewFace__virtual_68_arg0 *)arg0)->unkA4 != 0);
    }
}

}
