typedef int s32;

struct Obj003EF2D8 {
    char pad[0x2F8];
    s32 unk2F8;
};

extern "C" s32 func_003EF2D8(struct Obj003EF2D8 *arg0)
{
    s32 *p = (s32 *)((char *)arg0 + 0x480);
    s32 matches = 0;
    s32 i;

    for (i = 0; i < 5; i++) {
        s32 v = *p;
        p = (s32 *)((char *)p + 0x188);
        if (v >= arg0->unk2F8) {
            matches = matches + 1;
        }
    }
    return matches;
}
