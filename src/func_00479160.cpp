typedef int s32;

extern "C" void func_00479160(int *arg0, s32 arg1)
{
    int temp_v0;

    arg0 = (int *)((char *)arg0 + 0xC);
    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        *arg0 = temp_v0 + arg1;
    }
}
