#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578048();                            /* extern */

extern char D_00689918[];
struct func_005540E8_arg0 {
    char pad0[0x38];
    s32 unk38;
};

void func_005540E8(struct func_005540E8_arg0 *arg0) {
    func_00578048();
    arg0->unk38 = (s32)D_00689918;
}
