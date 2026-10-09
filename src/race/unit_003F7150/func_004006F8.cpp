typedef int s32;

struct Obj {
    char pad[0x3C];
    s32 unk3C;
    s32 unk40;
};

extern "C" char D_00686130[];

extern "C" void func_004006F8(Obj *arg0) {
    arg0->unk40 = (s32)D_00686130;
    arg0->unk3C = arg0->unk3C & 0xFFFF00FF;
}
