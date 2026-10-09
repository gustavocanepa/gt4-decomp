typedef unsigned char u8;

struct Obj { char pad[0x1B8]; u8 unk1B8; };

extern "C" void func_003F16C0(Obj *arg0) {
    arg0->unk1B8 = (u8)(arg0->unk1B8 & 0xF0);
}
