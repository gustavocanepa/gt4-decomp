typedef int s32;

struct Obj002A37B8 {
    char pad0[0xBC];
    s32 unkBC;
};

extern "C" void func_002106E0(s32 arg0, s32 *arg1);

extern "C" s32 func_002A37B8(s32 arg0, struct Obj002A37B8 *arg1) {
    s32 buf[1];

    buf[0] = arg1->unkBC;
    func_002106E0(arg0, buf);
    return arg0;
}
