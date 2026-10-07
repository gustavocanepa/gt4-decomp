struct Vec4 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};

extern Vec4 D_008465C8;

extern "C" void func_00452A90(float fparg0, float fparg1, float fparg2, float fparg3) {
    D_008465C8.unk0 = fparg0;
    D_008465C8.unk4 = fparg1;
    D_008465C8.unk8 = fparg2;
    D_008465C8.unkC = fparg3;
}
