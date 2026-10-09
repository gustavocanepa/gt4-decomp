typedef unsigned int u32;
typedef signed char s8;

struct Obj {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
};

extern "C" void func_004C4B98(u32 arg0, Obj *arg1) {
    arg1->unk0 = (s8)(arg0 >> 0x18);
    arg1->unk1 = (s8)(arg0 >> 0x10);
    arg1->unk2 = (s8)(arg0 >> 8);
    arg1->unk3 = (s8)arg0;
}
