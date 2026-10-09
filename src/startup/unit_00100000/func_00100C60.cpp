struct Vec3 {
    float unk0;
    float unk4;
    float unk8;
};

extern Vec3 D_00617A90;

extern "C" void func_00100C60(float fparg0, float fparg1, float fparg2) {
    D_00617A90.unk0 = fparg0;
    D_00617A90.unk4 = fparg1;
    D_00617A90.unk8 = fparg2;
}
