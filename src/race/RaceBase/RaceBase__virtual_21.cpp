typedef int s32;

struct Obj {
    char pad[0xD58];
    s32 unkD58;
    s32 unkD5C;
};

extern "C" void RaceBase__virtual_21(struct Obj *arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 == -1) {
        arg1 = 5;
    }
    temp_v0 = arg1 * 0x3C;
    arg0->unkD5C = temp_v0;
    arg0->unkD58 = temp_v0 + 1;
}
