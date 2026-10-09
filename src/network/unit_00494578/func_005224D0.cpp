typedef int s32;

struct __attribute__((aligned(8))) S { s32 lo; s32 hi; };

extern "C" s32 func_005224D0(S arg0) {
    return *(s32 *)&arg0 == 0;
}
