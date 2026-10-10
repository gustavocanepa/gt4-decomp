typedef int s32;
typedef float f32;

extern "C" void Pitmen__StatusTeam__clear(char *arg0) {
    *(s32 *)(arg0 + 0x0) = 0;
    *(f32 *)(arg0 + 0x38) = 1.0f;
    *(s32 *)(arg0 + 0x4) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x3C) = 0;
}
