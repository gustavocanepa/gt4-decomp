typedef int s32;

struct Obj_003BE0F0 {
    char pad0[0x6C];
    s32 unk6C;
};

extern "C" void func_00388880(struct Obj_003BE0F0 *arg0);
extern "C" void func_00394A98(void *arg0, s32 arg1);

extern "C" void func_003BE0F0(struct Obj_003BE0F0 *arg0) {
    func_00388880(arg0);

    func_00394A98((char *)arg0 + 0xF140, arg0->unk6C);
}
