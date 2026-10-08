typedef int s32;

struct Struct_00156700;

extern "C" void func_00156700(struct Struct_00156700 *arg0);

struct Obj00156748 {
    char pad[0x54];
    s32 unk54;
};

extern "C" void func_00156748(struct Obj00156748 *arg0, s32 arg1) {
    arg0->unk54 = arg1;
    func_00156700((struct Struct_00156700 *)arg0);
}
