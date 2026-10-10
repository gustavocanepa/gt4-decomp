typedef int s32;
void AutomobileControlRecord__Manager__load(char *a, char *b, s32 c);
void RaceSolitaire__loadDemoInputs(char *arg0, char *arg1) {
    char *s = arg0 + 0xE48C;
    AutomobileControlRecord__Manager__load(arg0 + 0xE560, arg1 + 0x1AA4, 1);
    *(s32 *)(s + 0x1D0) = 0;
}
