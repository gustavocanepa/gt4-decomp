typedef int s32;
typedef char s8;

struct Obj00353EB8;

extern "C" s32 func_00353EB8(struct Obj00353EB8 *arg0);

extern "C" void func_0036D208(struct Obj00353EB8 *arg0, s32 arg1) {
    *(s8 *)func_00353EB8(arg0) = (s8)arg1;
}
