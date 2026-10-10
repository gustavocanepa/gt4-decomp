typedef int s32;

struct Obj {
    char pad[0x68];
    s32 unk68;
};

extern "C" void GranTurismo4__GameObjectBase__start(Obj *arg0);

extern "C" void GranTurismo4__GameObjectPS2__start(Obj *arg0) {
    arg0->unk68 = 0;
    GranTurismo4__GameObjectBase__start(arg0);
}
