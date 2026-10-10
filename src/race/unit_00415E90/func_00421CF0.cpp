typedef int s32;

struct R { s32 w[9]; };
extern "C" void func_00421C58(R *, void *);
extern "C" void *func_005A4724(void *, const void *, s32);

extern "C" void func_00421CF0(void *self, void *out) {
    R t;
    func_00421C58(&t, self);
    func_005A4724(out, &t, 0x24);
}
