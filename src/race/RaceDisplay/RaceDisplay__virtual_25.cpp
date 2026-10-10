#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" {
s32 RaceRankDisplay__virtual_09(void *, f32);                 /* extern */
s32 func_003A3EC8(void *, s8, s32);         /* extern */

struct RaceDisplay__virtual_25_arg0 {
    char pad0[0x2E];
    s8 unk2E;
};
struct RaceDisplay__virtual_25_arg1 {
    char pad0[0x60];
    void *unk60;
};

void RaceDisplay__virtual_25(char *arg0, char *arg1, f32 fparg0) {
    char *temp_s0;

    temp_s0 = arg0 + 0x1398;
    func_003A3EC8(temp_s0, M2C_FIELD(M2C_FIELD(*(s32 *)((((struct RaceDisplay__virtual_25_arg0 *)arg0)->unk2E * 4) + M2C_FIELD(((struct RaceDisplay__virtual_25_arg1 *)arg1)->unk60, s32 *, 8)), void **, 0x18), s8 *, 0x5B3), 1);
    RaceRankDisplay__virtual_09(temp_s0, fparg0);
}

}
