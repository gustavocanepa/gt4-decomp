typedef int s32;
typedef long long s64;

struct Obj {
    char pad[0xA0];
    s64 unkA0;
} __attribute__((aligned(8)));

extern char D_006235A8;

extern "C" s32 func_00443E60(void *arg0, s64 arg1);

extern "C" s32 func_004472A0(Obj *arg0) {
    return func_00443E60(&D_006235A8, arg0->unkA0);
}
