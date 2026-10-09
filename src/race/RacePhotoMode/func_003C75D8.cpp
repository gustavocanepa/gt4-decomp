typedef int s32;

struct D { char pad[0x18]; s32 unk18; };
struct C { char pad[0x0]; D *unk0; };
struct B { char pad[0x8]; C *unk8; };
struct A { char pad[0x60]; B *unk60; };
struct Obj { char pad[0x6C]; A *unk6C; };

extern "C" s32 func_003C75D8(Obj *arg0) {
    return arg0->unk6C->unk60->unk8->unk0->unk18;
}
