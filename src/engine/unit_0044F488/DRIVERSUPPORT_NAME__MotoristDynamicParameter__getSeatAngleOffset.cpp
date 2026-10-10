typedef float f32;

struct Obj { char pad[0x50]; f32 unk50; };

extern "C" f32 DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatAngleOffset(Obj *arg0) {
    return arg0->unk50;
}
