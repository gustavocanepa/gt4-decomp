typedef int s32;
typedef unsigned short u16;

extern "C" void func_0045B268(s32 arg0, char *arg1, s32 arg2);

extern "C" u16 func_0045B140(s32 arg0) {
    u16 local;
    func_0045B268(arg0, (char *)&local, 2);
    return local;
}
