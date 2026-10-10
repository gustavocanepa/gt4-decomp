typedef struct { char b[9]; } Str9;
extern "C" Str9 D_00694D68;
extern "C" char D_00694D78[];
extern "C" int func_0057DA20(char *, const char *, ...);

struct Date {
    unsigned char pad[4];
    unsigned char m;
    unsigned char d;
    unsigned short y;
};

extern "C" void func_001CC1C8(char *obj, char *buf) {
    Date *d = (Date *)(obj + 0x10);
    if (d->y == 0) {
        *(Str9 *)buf = D_00694D68;
        return;
    }
    func_0057DA20(buf, D_00694D78, d->y - 2000, d->d, d->m);
}
