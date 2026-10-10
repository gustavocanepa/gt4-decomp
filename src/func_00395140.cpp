typedef int s32;

struct Result {
    s32 error;
    s32 pad4[3];
    s32 value;
    s32 pad14[3];
};

struct Obj {
    char pad0[0x18];
    s32 busy;
};

extern "C" void func_004AE230(Result *out, s32 arg, s32 flag);
extern "C" void func_00395198(Obj *self, s32 value);

extern "C" s32 func_00395140(Obj *self, s32 arg) {
    if (self->busy != 0)
        return 0;
    Result r;
    func_004AE230(&r, arg, 1);
    if (r.error == 0) {
        func_00395198(self, r.value);
        return 1;
    }
    return 0;
}
