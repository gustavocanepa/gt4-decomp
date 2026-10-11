typedef int s32;
extern "C" {
void memcpy(s32 a, s32 b, s32 c);
void func_0057B410(void *a, s32 b);
}
extern "C" void func_00613D90(char *arg0, s32 arg1) {
    s32 t = *(s32 *)(arg0 + 0x10);
    memcpy(*(s32 *)(arg0 + 0xC) + *(s32 *)arg0 * t, arg1, t);
    func_0057B410(arg0, 1);
}
