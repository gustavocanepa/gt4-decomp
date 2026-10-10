struct func_00528160_Obj {
    char pad0[0x98];
    unsigned char *data;
    unsigned short count;
};

extern const unsigned char D_006C28B0[][3];
extern const unsigned char D_006C28B8[][3];
extern const unsigned char D_006C28C0[][3];
extern const unsigned char D_006C28D0[][3];
extern const unsigned char D_006C28E0[][3];
extern const unsigned char D_006C28F0[][3];
extern const unsigned char D_006C2908[][3];
extern const unsigned char D_006C2920[][3];
extern const unsigned char D_006C2938[][3];
extern const unsigned char D_006C2958[][3];
extern const unsigned char D_006C2978[][3];
extern const unsigned char D_006C29A0[][3];
extern const unsigned char D_006C29C8[][3];
extern const unsigned char D_006C29F0[][3];
extern const unsigned char D_006C2A20[][3];
extern const unsigned char D_006C2A50[][3];
extern const unsigned char D_006C2A80[][3];
extern const unsigned char D_006C2AB8[][3];
extern const unsigned char D_006C2AF0[][3];
extern const unsigned char D_006C2B30[][3];
extern const unsigned char D_006C2B70[][3];
extern const unsigned char D_006C2BB0[][3];
extern const unsigned char D_006C2BF8[][3];
extern const unsigned char D_006C2C40[][3];
extern const unsigned char D_006C2C88[][3];
extern const unsigned char D_006C2CD8[][3];
extern const unsigned char D_006C2D28[][3];
extern const unsigned char D_006C2D80[][3];
extern const unsigned char D_006C2DD8[][3];
extern const unsigned char D_006C2E30[][3];
extern const unsigned char D_006C2E90[][3];
extern const unsigned char D_006C2EF0[][3];

extern "C" int func_005280D8(func_00528160_Obj *self, unsigned int count);

extern "C" int func_00528160(func_00528160_Obj *self, unsigned int count, unsigned short index, const unsigned char **out) {
    int r = 0;
    if (count < index) return 2;
    switch (count) {
    case 0:
        r = 4;
        break;
    case 1:
        *out = D_006C28B0[index];
        break;
    case 2:
        *out = D_006C28B8[index];
        break;
    case 3:
        *out = D_006C28C0[index];
        break;
    case 4:
        *out = D_006C28D0[index];
        break;
    case 5:
        *out = D_006C28E0[index];
        break;
    case 6:
        *out = D_006C28F0[index];
        break;
    case 7:
        *out = D_006C2908[index];
        break;
    case 8:
        *out = D_006C2920[index];
        break;
    case 9:
        *out = D_006C2938[index];
        break;
    case 10:
        *out = D_006C2958[index];
        break;
    case 11:
        *out = D_006C2978[index];
        break;
    case 12:
        *out = D_006C29A0[index];
        break;
    case 13:
        *out = D_006C29C8[index];
        break;
    case 14:
        *out = D_006C29F0[index];
        break;
    case 15:
        *out = D_006C2A20[index];
        break;
    case 16:
        *out = D_006C2A50[index];
        break;
    case 17:
        *out = D_006C2A80[index];
        break;
    case 18:
        *out = D_006C2AB8[index];
        break;
    case 19:
        *out = D_006C2AF0[index];
        break;
    case 20:
        *out = D_006C2B30[index];
        break;
    case 21:
        *out = D_006C2B70[index];
        break;
    case 22:
        *out = D_006C2BB0[index];
        break;
    case 23:
        *out = D_006C2BF8[index];
        break;
    case 24:
        *out = D_006C2C40[index];
        break;
    case 25:
        *out = D_006C2C88[index];
        break;
    case 26:
        *out = D_006C2CD8[index];
        break;
    case 27:
        *out = D_006C2D28[index];
        break;
    case 28:
        *out = D_006C2D80[index];
        break;
    case 29:
        *out = D_006C2DD8[index];
        break;
    case 30:
        *out = D_006C2E30[index];
        break;
    case 31:
        *out = D_006C2E90[index];
        break;
    case 32:
        *out = D_006C2EF0[index];
        break;
    default:
        r = func_005280D8(self, count);
        *out = self->data + index * 3;
        break;
    }
    return r;
}
