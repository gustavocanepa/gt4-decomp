#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00435D10(s8 *);
void func_004363A0(s8 *);
void func_00438B80(void *);
void func_00438F38(void *);
void func_00439618(void *);
void func_004397A0(void *);
s32 func_0043A3F8(s8 *);
void func_0043D938(void *);
extern char D_00687B60[];
void func_00436278(s8 *arg0) {
    func_0043A3F8(arg0);
    *(s32 *)arg0 = (s32)D_00687B60;
    func_00435D10(arg0 + 0x11C8);
    func_0043D938(arg0 + 0x11D0);
    func_00438B80(arg0 + 0x1344);
    func_00439618(arg0 + 0x13F4);
    func_004397A0(arg0 + 0x1650);
    func_00438F38(arg0 + 0x16A4);
    func_004363A0(arg0);
}
