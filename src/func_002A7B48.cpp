typedef int s32;

extern s32 func_004B75D8(s32);
extern void func_004B8270(s32);

void func_002A7B48(s32 arg0)
{
    s32 temp_s0;
    
    temp_s0 = arg0 + 0x578;
    if (func_004B75D8(temp_s0) != 0) {
        func_004B8270(temp_s0);
    }
}
