union S_unk4 {
    int i;
    float f;
};

struct S {
    int unk0;
    S_unk4 unk4;
};

extern "C" float func_00477460(S *arg0) {
    float var_f0;
    int temp_v1;

    temp_v1 = arg0->unk0;
    switch (temp_v1) {
    case 6:
        return arg0->unk4.f;
    default:
        var_f0 = 0.0f;
        if (temp_v1 == 5) {
            var_f0 = 1.0f;
            if (arg0->unk4.i == 0) {
                var_f0 = 0.0f;
            }
        }
        break;
    }
    return var_f0;
}
