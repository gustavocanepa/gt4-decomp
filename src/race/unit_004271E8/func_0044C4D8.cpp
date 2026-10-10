struct Buf {
    unsigned char *data;
    unsigned int size;
};

extern "C" int func_0044C4D8(Buf *b) {
    if (b->size == 0)
        return 1;
    for (unsigned int i = 0; i < b->size; i++) {
        if (b->data[i] != 0)
            return 0;
    }
    return 1;
}
