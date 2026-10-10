struct func_0034AC48_Flags {
    int a;
    int b;
};

extern "C" void func_0034AC48(unsigned int k, func_0034AC48_Flags *f) {
    f->a = 0;
    f->b = 0;
    switch (k) {
    case 0:
    case 7:
        f->b = 1;
        return;
    case 1:
        f->a = 1;
        return;
    case 2: case 3: case 4: case 5: case 6: case 8: case 9: case 10:
        f->a = 1;
        f->b = 1;
        return;
    }
}
