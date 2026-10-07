typedef unsigned short u16;

struct Inner { char pad[0x16]; u16 unk16; };
struct Obj { char pad0[0x4]; Inner *inner; };

extern "C" u16 func_0042A0C0(Obj *arg0) {
    return arg0->inner->unk16;
}
