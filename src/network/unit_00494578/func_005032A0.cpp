typedef int s32;

extern void func_004EFAA8(s32);
extern s32 func_005030C8(void);

void func_005032A0(void)
{
    s32 temp_v0;

    temp_v0 = func_005030C8();
    if (temp_v0 != 0) {
        func_004EFAA8(temp_v0);
    }
}
