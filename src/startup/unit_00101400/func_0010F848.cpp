typedef int s32;

struct Obj;

extern "C" void func_003C0C40(struct Obj *arg0, s32 arg1, s32 arg2);
extern "C" void *D_00622F4C;

extern "C" void func_0010F848(struct Obj *arg0) {
    s32 v = *(s32 *)((char *)D_00622F4C + 0x39D78);
    func_003C0C40(arg0, v ^ 1, 0);
}
