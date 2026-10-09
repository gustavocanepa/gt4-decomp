typedef int s32;
typedef float f32;

extern "C" void func_0045B268(s32 arg0, char *arg1, s32 arg2);

extern "C" f32 func_0045B200(s32 arg0) {
    f32 buf;
    func_0045B268(arg0, (char *)&buf, 4);
    return buf;
}
