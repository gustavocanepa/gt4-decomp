struct Mat3 {
    float m[9];
};

extern "C" void func_0048D700(Mat3 *r, int row, const Mat3 *a, const Mat3 *b);

extern "C" void func_0048DB10(Mat3 *r, const Mat3 *a, const Mat3 *b)
{
    func_0048D700(r, 0, a, b);
    func_0048D700(r, 1, a, b);
    r->m[8] = a->m[8] * b->m[8];
}
