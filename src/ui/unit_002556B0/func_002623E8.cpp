typedef int s32;

struct Obj002676A8;

extern "C" void func_00261FB8(s32 arg0, s32 arg1);
extern "C" void func_002676A8(struct Obj002676A8 *arg0, s32 arg1);

extern "C" void func_002623E8(void *arg0, s32 arg1) {
    func_00261FB8(arg1, (s32)((char *)arg0 + 0x34));
    func_002676A8((struct Obj002676A8 *)arg0, 2);
}
