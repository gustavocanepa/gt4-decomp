struct Bits {
    int f0;
    int f4;
    int pos;
    int left;
    int count;
};

extern "C" void func_0046F030(Bits *b, int n) {
    b->left -= n;
    while (b->left < -1) {
        b->pos++;
        b->count++;
        b->left += 8;
    }
}
