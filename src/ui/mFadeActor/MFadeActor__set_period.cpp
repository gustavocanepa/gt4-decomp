typedef int s32;
typedef float f32;

struct Obj;
struct Struct_0020C290;

extern "C" void func_0020B340(void *arg0, int arg1);
extern "C" void func_0020B398(void *arg0, void *arg1);
extern "C" void func_0020C2B0(struct Struct_0020C290 *arg0, f32 fparg0);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F7BC0(void *arg0, void *arg1);
extern "C" float func_002F9158(struct Obj *arg0);

extern "C" void MFadeActor__set_period(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0 = arg3;

    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_0020B398(buf0, (void *)arg1);
        s32 *p1 = buf1;
        func_002F7BC0(p1, (void *)s0);
        s32 base0 = buf0[0];
        f32 result = func_002F9158((struct Obj *)p1[0]);
        func_0020C2B0((struct Struct_0020C290 *)base0, result);
        func_002F7B68(p1, 2);
        func_0020B340(buf0, 2);
    }
}
