typedef int s32;
extern char D_00845C28[];
extern char D_00845C30[];
extern char D_00845C38[];
extern char D_006A5138[];
extern char D_006A5180[];
extern char D_006A51F8[];
extern "C" void func_0057B198(void *, void *, s32);

extern "C" void func_0042F768(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0057B198(D_00845C28, D_006A5138, 5);
    if (prio == 0xFFFF && init == 1) func_0057B198(D_00845C30, D_006A5180, 5);
    if (prio == 0xFFFF && init == 1) func_0057B198(D_00845C38, D_006A51F8, 8);
}
