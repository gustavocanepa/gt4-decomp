typedef short s16;
typedef int s32;

struct Obj_003F7160;

extern "C" void func_003F7150(s16 *arg0, s16 arg1);
extern "C" s32 func_003F7160(struct Obj_003F7160 *arg0, s16 arg1);

extern "C" s32 func_003F7170(struct Obj_003F7160 *arg0) {
    struct Obj_003F7160 *s0 = arg0;

    func_003F7150((s16 *)s0, 1);
    return func_003F7160(s0, 1);
}
