typedef int s32;

extern void func_00502380(s32);
extern s32 func_005030C8(void);

void func_00503240(void)
{
    s32 temp_v0;

    temp_v0 = func_005030C8();
    if (temp_v0 != 0) {
        func_00502380(temp_v0);
    }
}
