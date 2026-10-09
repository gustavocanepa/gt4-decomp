typedef int s32;

extern "C" s32 func_00206868(s32 arg0);
extern "C" s32 func_0025C300(s32 arg0);
extern "C" s32 func_00265D98(s32 arg0);
extern "C" s32 func_002662A0(s32 arg0);
extern "C" void func_00266378(s32 arg0, s32 arg1);

extern "C" void func_00200F68(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = func_00206868(arg0);
    if (var_s0 != 0) {
        do {
            if ((func_00265D98(var_s0) == 0) && (func_002662A0(var_s0) != 0)) {
                func_00266378(var_s0, arg1);
            }
            var_s0 = func_0025C300(var_s0);
        } while (var_s0 != 0);
    }
}
