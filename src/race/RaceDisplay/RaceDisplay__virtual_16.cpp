typedef int s32;

struct Obj {
    char pad[0x40];
    s32 unk40;
};

extern "C" void RaceDisplay__virtual_16(Obj *arg0, s32 arg1) {
    arg0->unk40 = (arg0->unk40 & 0xFFFF00FF) | ((arg1 & 0xFF) << 8);
}
