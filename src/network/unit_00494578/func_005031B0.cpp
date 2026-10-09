typedef int s32;

extern void func_00501C68(s32);
extern s32 func_005030C8(void);

void func_005031B0(void)
{
    s32 temp_v0;

    temp_v0 = func_005030C8();
    if (temp_v0 != 0) {
        func_00501C68(temp_v0);
    }
}
