typedef int s32;

struct Obj;

extern "C" s32 func_00435E08(struct Obj *arg0);

extern "C" s32 func_00602018(char *arg0) {
    return func_00435E08((struct Obj *)(arg0 + 0x11C8));
}
