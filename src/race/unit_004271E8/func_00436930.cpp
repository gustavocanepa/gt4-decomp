typedef int s32;

struct Pair {
    s32 a;
    s32 b;
};

extern Pair D_00622DC0[4];

extern "C" s32 func_00436930(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_00622DC0[i].a == a && D_00622DC0[i].b == b) {
            return i;
        }
    }
    return 0;
}
