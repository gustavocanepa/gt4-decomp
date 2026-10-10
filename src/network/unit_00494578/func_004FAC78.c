typedef int s32;
void func_004F9C78(char *a, s32 b);
void func_004FAC78(char *arg0, char *arg1) {
    s32 t;
    s32 a = *(s32 *)(arg0 + 0xFD0);
    s32 b = *(s32 *)(arg0 + 0xA40);
    s32 c = *(s32 *)(arg1 + 4);
    *(s32 *)(arg0 + 0xFD0) = a + 1;
    *(s32 *)(arg0 + 0xA40) = b - 1;
    func_004F9C78(arg0, c);
    t = *(s32 *)(arg0 + 0xA40);
    *(s32 *)(arg0 + 0xA34) = 0;
    *(s32 *)(arg0 + 0xA10) = t;
    *(s32 *)(arg0 + 0x724) = t;
}
