typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x4];
    u32 unk4;
};

extern "C" s32 MTRGeometry__getSeatZ(Obj *arg0, s32 arg1);

extern "C" s32 MTRGeometry__GetSeatPosition_Z(Obj *arg0) {
    return MTRGeometry__getSeatZ(arg0, arg0->unk4 < 1);
}
