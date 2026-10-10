#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0048EE00(s32 x) {
    if ((u32)x < 12) {
        switch (x) {
        case 0: case 8: case 10:
            return 0;
        }
        return 1;
    }
    return 2;
}
