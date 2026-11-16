typedef unsigned char u8;
typedef unsigned short u16;
struct Header {
    char pad0[4];
    u8 b4, b5, b6, b7, b8, b9;
    u16 hA, hC;
    u8 countE, countF;
    char pad10[8];
    u8 *data18;
    u8 *data1C;
};
u16 func_004BC8A0(struct Header *h) {
    int i;
    u16 sum;
    sum = 1;
    sum += h->b4;
    sum += h->b5;
    sum += h->b6;
    sum += h->b7;
    sum += h->b8;
    sum += h->b9;
    sum += (h->hA >> 8) + (h->hA & 0xFF);
    sum += (h->hC >> 8) + (h->hC & 0xFF);
    sum += h->countE;
    sum += h->countF;
    for (i = 0; i < h->countE; i++) sum += h->data18[i];
    for (i = 0; i < h->countF; i++) sum += h->data1C[i];
    return sum;
}
