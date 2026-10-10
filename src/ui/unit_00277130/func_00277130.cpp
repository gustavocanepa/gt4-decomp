/* compiler: ee-gcc2.96-as2004 */
struct Hdr {
    int m0;
    int m4;
    short w;
    short h;
    int mC;
    unsigned char m10;
} __attribute__((packed));

struct Img {
    Hdr *hdr;
    int m4;
    int size;
    int w;
    int h;
    int m14;
};

extern "C" void func_00277130(Img *o, Hdr *p) {
    o->hdr = p;
    o->w = p->w;
    o->h = p->h;
    o->m4 = p->m4;
    o->size = o->w * o->h * 4;
    o->m14 = p->m10;
}
