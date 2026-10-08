typedef int s32;
typedef unsigned int u32;

struct Obj003A3620 {
    char pad[0x8];
    s32 unk8;
};

extern "C" s32 func_003A3620(struct Obj003A3620 *arg0) {
    s32 temp_a1 = arg0->unk8;

    return ((u32)(temp_a1 + 0x01FFFFFE) <= 0x03FFFFFCU) ? temp_a1 : 0x157529FF;
}
