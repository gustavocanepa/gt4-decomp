typedef int s32;
typedef float f32;

struct Val {
    s32 type;
    f32 v;
    Val(f32 x) {
        type = 6;
        v = x;
    }
};

extern char D_006AD870[];
extern "C" void func_0057D9C0(void *);

extern "C" Val func_0047AD58(void) {
    func_0057D9C0(D_006AD870);
    return Val(100.0f);
}
