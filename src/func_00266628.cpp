typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x98];
    u32 unk98;
};

extern "C" s32 func_00266628(Obj *arg0, s32 arg1) {
    u32 t = (arg0->unk98 >> 8) & 0xF;
    return (t & arg1) != 0;
}
