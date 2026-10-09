typedef int s32;

struct Obj { char pad[0x12]; unsigned char unk12; };

extern "C" s32 func_004489A0(Obj *arg0, s32 arg1) {
    return ((s32)arg0->unk12 >> arg1) & 1;
}
