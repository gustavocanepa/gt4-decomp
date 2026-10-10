struct Img { int m0; unsigned int *data; int compressed; };
extern "C" void func_001D3FE8(short *, short *, short *, short *, int);

extern "C" void func_001D3D70(Img *img, short *dst)
{
    if (img->compressed) {
        unsigned int *p = img->data;
        short *s = (short *)(p + 1);
        return func_001D3FE8(dst, dst + 0x1000, s, s + (*p >> 1), 0x40);
    }
    short *src = (short *)img->data;
    for (unsigned int y = 0; y < 0x40; y++) {
        for (unsigned int x = 0; x < 0x40; x++)
            *dst++ = *src++ | 0x8000;
        src += 0x40;
    }
}
