int func_00377A28(float x) {
    int i = (int)(x * 5.0f);
    if (i < 1) i = 0;
    if (i >= 4) i = 4;
    return ((signed char *)0x6211A0)[i];
}
