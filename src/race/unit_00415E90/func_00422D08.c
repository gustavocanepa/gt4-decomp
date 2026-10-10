#include "types.h"

s32 func_00422D08(s32 a, s32 b) {
    if (b == 0) {
        return a;
    }
    return func_00422D08(b, a % b);
}
