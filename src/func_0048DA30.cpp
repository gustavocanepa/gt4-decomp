struct Mat {
    char pad[0x20];
    float w;
};

extern "C" void func_0048D680(Mat *out, int row, Mat *a, Mat *b);

extern "C" void func_0048DA30(Mat *out, Mat *a, Mat *b) {
    func_0048D680(out, 0, a, b);
    func_0048D680(out, 1, a, b);
    out->w = a->w + b->w;
}
