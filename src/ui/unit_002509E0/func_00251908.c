#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00251908_arg0 {
    char pad0[0xE0];
    u32 unkE0;
};

f32 func_00251908(struct func_00251908_arg0 *arg0) {
    return (f32)arg0->unkE0 / 60.0f;
}
