struct S_0060EC60 { unsigned int unk0; char pad4[4]; int unk8; };

extern "C" void func_0060F3A0(S_0060EC60 *arg0, int arg1) {
    unsigned int v0;
    int a2;
    int lt16;
    unsigned int sub;

    v0 = arg0->unk0;
    a2 = arg0->unk8;
    v0 = v0 + arg1;
    lt16 = (v0 < 0x10U);
    sub = v0 - 0x10U;
    v0 = lt16 ? v0 : sub;
    a2 = a2 + arg1;
    arg0->unk8 = a2;
    arg0->unk0 = v0;
}
