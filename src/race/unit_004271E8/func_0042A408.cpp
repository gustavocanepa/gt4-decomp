typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

struct Obj0042A408 {
    u16 unk0;
    char pad2[2];
    s32 unk4;
};

extern "C" u32 func_0042A408(struct Obj0042A408 *arg0, s32 arg1) {
    u32 temp_v0 = (u32)(arg1 + 0x20);
    u32 limit = (u32)(arg0->unk4 + (arg0->unk0 << 5));
    return (temp_v0 < limit) ? temp_v0 : 0U;
}
