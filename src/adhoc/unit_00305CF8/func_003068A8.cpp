typedef int s32;

extern "C" s32 HSymID__GetID(s32 arg0);
extern "C" void func_00306780(s32 arg0, s32 *arg1, s32 arg2);

extern "C" void func_003068A8(s32 arg0, s32 arg1, s32 arg2) {
    s32 local = HSymID__GetID(arg1);
    func_00306780(arg0, &local, arg2);
}
