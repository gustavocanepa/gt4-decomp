struct Packer {
    char pad[0x90C];
    int runs[24];
    int used;
    int pending;
    int index;
    int pad978[2];
    int total;
};

extern "C" void func_00494A28(Packer *p);

extern "C" void func_004949A0(Packer *p) {
    if (p->pending == 0)
        return;
    if (p->pending < 3) {
        p->pending = 0;
        p->used = 0;
        return;
    }
    p->runs[p->index] = p->pending;
    p->index++;
    p->total += p->pending - 2;
    p->pending = 0;
    if (0x40 - p->used < 3)
        func_00494A28(p);
}
