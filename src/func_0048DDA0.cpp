typedef unsigned int u128 __attribute__((mode(TI)));

struct Mat {
    u128 row[3];
};

extern "C" void func_0048DDE0(Mat *self, Mat *m, void *arg);

extern "C" void func_0048DDA0(Mat *self, void *arg) {
    Mat tmp;
    tmp.row[0] = self->row[0];
    tmp.row[1] = self->row[1];
    tmp.row[2] = self->row[2];
    func_0048DDE0(self, &tmp, arg);
}
