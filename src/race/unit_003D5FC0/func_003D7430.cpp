typedef float f32;

struct Obj5 { char pad[0x58]; f32 unk58; };
struct Obj4 { char pad[0x80]; Obj5 *unk80; };
struct Obj3 { char pad[4]; Obj4 *unk4; };
struct Obj2 { char pad[8]; Obj3 *unk8; };
struct Obj1 { char pad[4]; Obj2 *unk4; };

extern "C" f32 func_003D7430(Obj1 *arg0) {
    return arg0->unk4->unk8->unk4->unk80->unk58;
}
