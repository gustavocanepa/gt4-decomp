typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x3C];
    s32 unk3C;
};

extern "C" void RaceDisplay__virtual_17(Obj *arg0, u8 arg1) {
    arg0->unk3C = (arg0->unk3C & ~0xFF) | arg1;
}
