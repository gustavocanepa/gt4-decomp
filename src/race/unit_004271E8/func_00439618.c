#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00687D50[];
s32 func_0043A3F8(s8 *);
void func_00560548(s8 *);
void func_00560560(s8 *);
void func_00439618(s8 *arg0) {
    s8 *temp_s1;
    temp_s1 = arg0 + 4;
    func_0043A3F8(arg0);
    *(s32 *)arg0 = (s32)D_00687D50;
    func_00560548(temp_s1);
    func_00560560(temp_s1);
}
