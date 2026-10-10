/* Splits a packed 64-bit pair (low word, high word) into two arguments for SPEC_DATABASE__DatabaseStorage__getRow_2. */
typedef int s32;
typedef long s64;

void SPEC_DATABASE__DatabaseStorage__getRow_2(void *arg0, s32 lo, s32 hi, s32 arg3);

void SPEC_DATABASE__DatabaseStorage__getRow(void *arg0, s64 pair, s32 arg2)
{
    SPEC_DATABASE__DatabaseStorage__getRow_2(arg0, (s32)(pair & 0xFFFFFFFF), (s32)(pair >> 32), arg2);
}
