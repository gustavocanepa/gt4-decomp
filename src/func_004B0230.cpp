typedef int s32;

struct Obj {
    char pad[0x3290];
    s32 unk3290;
};

extern "C" void func_004B0668(struct Obj *arg0);

extern "C" void func_004B0230(struct Obj *arg0) {
    arg0->unk3290 = 1;
    func_004B0668(arg0);
}
