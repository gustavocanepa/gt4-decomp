typedef float f32;

struct Obj;

extern "C" char *func_0038D0C0(Obj *arg0);

extern "C" f32 NormalCarGeometry__GetBackmirrorPosition_X(Obj *arg0) {
    return *(f32 *)(func_0038D0C0(arg0) + 0x88);
}
