typedef int s32;

struct Obj {
    s32 unk0;
    char pad4[0x280 - 0x4];
    s32 unk280;
    s32 unk284;
    char pad288[0x28C - 0x288];
    s32 unk28C;
    s32 unk290;
    s32 unk294;
};

extern "C" void func_00556D30(struct Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk280 = 0;
    arg0->unk284 = 0;
    arg0->unk290 = 0;
    arg0->unk294 = 0;
    arg0->unk28C = 0;
}
