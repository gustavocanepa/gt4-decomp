/* Splits a packed 64-bit pair (low word, high word) into two arguments for func_00443F00. */
typedef int s32;
typedef long s64;

void func_00443F00(void *arg0, s32 lo, s32 hi, s32 arg3);

void func_00443ED0(void *arg0, s64 pair, s32 arg2)
{
    func_00443F00(arg0, (s32)(pair & 0xFFFFFFFF), (s32)(pair >> 32), arg2);
}
