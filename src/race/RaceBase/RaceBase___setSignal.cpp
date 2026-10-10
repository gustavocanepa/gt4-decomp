typedef int s32;

struct Obj0038A098 {
    char pad[0xCE4];
    char pad2[0xD18 - 0xCE4];
    s32 unkD18;
};

extern "C" void func_00574F90(void *arg0);
extern "C" void GranTurismo4__GameObjectPS2__terminate(struct Obj0038A098 *arg0);

extern "C" void RaceBase___setSignal(struct Obj0038A098 *arg0, s32 arg1) {
    arg0->unkD18 = arg1;
    func_00574F90((char *)arg0 + 0xCE4);
    GranTurismo4__GameObjectPS2__terminate(arg0);
}
