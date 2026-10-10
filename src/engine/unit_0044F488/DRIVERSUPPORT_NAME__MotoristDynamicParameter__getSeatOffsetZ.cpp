typedef float f32;

struct Obj { char pad[0x54]; f32 unk54; };

extern "C" f32 DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatOffsetZ(Obj *arg0) {
    return arg0->unk54;
}
