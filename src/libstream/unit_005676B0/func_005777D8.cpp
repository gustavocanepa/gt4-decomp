typedef int s32;

extern "C" s32 func_00577770(s32 arg0);
extern "C" void func_00577700(s32 arg0);

extern "C" s32 func_005777D8(s32 arg0) {
    s32 temp_s1 = func_00577770(arg0);
    func_00577700(arg0);
    return temp_s1;
}
