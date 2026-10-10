extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 AutomaticFader__oneshot(char *, f32, f32, f32, f32) throw();

struct func_003AE538_arg0 {
    char pad0[0x20];
    f32 unk20;
    f32 unk24;
};

void func_003AE538(char *arg0, f32 fparg0, f32 fparg1) {
    if (fparg0 == 0.0f) {
        AutomaticFader__oneshot(arg0 + 0x28, fparg1, -1.0f, ((struct func_003AE538_arg0 *)arg0)->unk20, ((struct func_003AE538_arg0 *)arg0)->unk24);
        return;
    }
    AutomaticFader__oneshot(arg0 + 0x28, fparg1, fparg0, ((struct func_003AE538_arg0 *)arg0)->unk20, ((struct func_003AE538_arg0 *)arg0)->unk24);
}

}
