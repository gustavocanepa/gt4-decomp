extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A98E8(char *, f32, f32, f32, f32) throw();

struct func_003AE538_arg0 {
    char pad0[0x20];
    f32 unk20;
    f32 unk24;
};

void func_003AE538(char *arg0, f32 fparg0, f32 fparg1) {
    if (fparg0 == 0.0f) {
        func_003A98E8(arg0 + 0x28, fparg1, -1.0f, ((struct func_003AE538_arg0 *)arg0)->unk20, ((struct func_003AE538_arg0 *)arg0)->unk24);
        return;
    }
    func_003A98E8(arg0 + 0x28, fparg1, fparg0, ((struct func_003AE538_arg0 *)arg0)->unk20, ((struct func_003AE538_arg0 *)arg0)->unk24);
}

}
