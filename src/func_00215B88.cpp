typedef int s32;
typedef float f32;

struct Obj;

extern "C" f32 func_002317C8(struct Obj *arg0);
extern "C" s32 func_00202EA8(s32 arg0, f32 arg1);
extern "C" void func_004AA168(s32 arg0);

extern "C" void func_00215B88(struct Obj *arg0, s32 arg1) {
    s32 s0 = arg1;
    f32 f = func_002317C8(arg0);

    func_004AA168(func_00202EA8(s0, f));
}
