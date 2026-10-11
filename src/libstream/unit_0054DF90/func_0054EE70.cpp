extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005ADB90(...) throw();
s32 func_005ADBC0(...) throw();
s32 func_005ADCC0(...) throw();
s32 func_005ADCE0(...) throw();

struct func_0054EE70_arg0 {
    char pad0[0x3FC];
    s32 unk3FC;
    s32 unk400;
};

void func_0054EE70(char *arg0) {
    func_005ADCE0(((struct func_0054EE70_arg0 *)arg0)->unk400);
    ((struct func_0054EE70_arg0 *)arg0)->unk3FC = func_005ADB90();
    func_005ADCC0(((struct func_0054EE70_arg0 *)arg0)->unk400);
    func_005ADBC0();
}

}
