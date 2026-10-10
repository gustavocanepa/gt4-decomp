typedef int s32;

struct Res_001D1D38 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 pad[5];
};

extern "C" void func_005A609C(char *buf, void *src);
extern "C" void func_005A5DC8(char *buf, char *s);
extern "C" void func_004AE6B0(Res_001D1D38 *out, char *buf);

extern "C" s32 func_001D1D38(char *arg0, char *arg1) {
    char buf[0x80];
    Res_001D1D38 res;

    func_005A609C(buf, arg0 + 4);
    if (*arg1 != 0) {
        func_005A5DC8(buf, arg1 + 1);
    }
    func_004AE6B0(&res, buf);
    return res.unk8;
}
