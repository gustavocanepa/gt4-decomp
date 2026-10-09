typedef int s32;

struct Obj;

struct S005CBC98 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_00435E20(Obj *arg0);

extern "C" void func_005CBCB8(struct S005CBC98 *arg0) {
    func_00435E20((Obj *)(arg0->unk10 + 0x11C8));
}
