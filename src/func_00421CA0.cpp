typedef unsigned int u128 __attribute__((mode(TI)));

struct Mat {
    u128 row[4];
    Mat() {}
    Mat(const Mat &o) {
        row[0] = o.row[0];
        row[1] = o.row[1];
        row[2] = o.row[2];
        row[3] = o.row[3];
    }
};

extern "C" void func_004874F0(void *src, Mat *out);

extern "C" Mat func_00421CA0(void *src) {
    Mat m;
    func_004874F0(src, &m);
    return m;
}
