typedef int s32;

extern char D_00687C00;

extern "C" void func_00438A90(s32 *arg0) {
    register s32 v1 asm("$3") = (s32)&D_00687C00;
    *arg0 = v1;
}
