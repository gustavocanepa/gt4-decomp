struct BigBits {
    unsigned char *data;
    int len;
};

extern "C" BigBits *func_0044C040(BigBits *b) {
    if (b->len == 0) {
        return b;
    }
    int carry = 0;
    for (int i = b->len - 1; i >= 0; i--) {
        unsigned char c = b->data[i];
        b->data[i] = carry | (c >> 1);
        carry = (c << 7) & 0x80;
    }
    return b;
}
