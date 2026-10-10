typedef unsigned char u8;
typedef int s32;
typedef float f32;
s32 Automobile__getDrawMode(void);
u8 *func_00359510(s32 a);
void func_00366718(char *arg0) {
    s32 i;
    char *e;
    char *s1;
    u8 *t;
    if (Automobile__getDrawMode() != 3) {
        s1 = arg0 + 0x104;
        t = func_00359510(*(s32 *)(arg0 + 0x10));
        i = 0;
        if (t[1] != 0) {
            e = arg0 + 0x164;
            do {
                *(s32 *)(e + 0xBC) = 0;
                i += 1;
                *(s32 *)(e + 0xB4) = 0;
                *(f32 *)(e + 0xB8) = 1.0f;
                e += 0xEC;
            } while (i < t[1]);
        }
        s1[0x605] = 0;
        s1[0x606] = 0;
        s1[0x604] = 0;
    }
}
