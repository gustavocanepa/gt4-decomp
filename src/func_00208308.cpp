typedef int s32;

extern "C" s32 func_00206868(void);
extern "C" s32 func_0025C300(s32 arg0);
extern "C" s32 func_00265D98(s32 arg0);

extern "C" s32 func_00208308(void)
{
    s32 var_s0;

    var_s0 = func_00206868();
    if (var_s0 != 0)
    {
        do
        {
            if (func_00265D98(var_s0) == 0)
            {
                return var_s0;
            }
            var_s0 = func_0025C300(var_s0);
        } while (var_s0 != 0);
    }
    return 0;
}
