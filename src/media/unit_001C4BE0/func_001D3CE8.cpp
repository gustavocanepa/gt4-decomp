struct Image {
    int unk0;
    unsigned int *data;
    int compressed;
};

extern "C" void func_001D3FE8(short *dst, short *end, void *src, void *srcEnd, int flags);

extern "C" void func_001D3CE8(Image *img, short *dst) {
    if (img->compressed != 0) {
        unsigned int *p = img->data;
        unsigned int *src = p + 1;
        func_001D3FE8(dst, dst + 0x4000, src, (char *)src + (*p >> 1) * 2, 0);
        return;
    }
    unsigned short *src = (unsigned short *)img->data;
    short *out = dst;
    unsigned int i = 0;
    do {
        int v = *src | ~0x7FFF;
        src++;
        i++;
        *out = v;
        out++;
    } while (i < 0x4000);
}
