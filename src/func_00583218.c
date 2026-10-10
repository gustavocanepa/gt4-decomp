/* compiler: ee-gcc2.9-991111 */
typedef struct {
    unsigned char trycount;
    unsigned char spindlctrl;
    unsigned char datapattern;
    unsigned char pad;
} ReadMode;

extern int D_00657A7C;
extern int D_00657A78;
extern ReadMode D_00875858;

int func_005835B0(unsigned int lsn, unsigned int sectors, void *buf, int cmd, ReadMode *mode);

int func_00583218(unsigned int lsn, unsigned int sectors, void *buf, int pattern)
{
    D_00657A7C = 0;
    D_00875858.datapattern = pattern;
    switch (pattern) {
    case 0:
        D_00657A78 = 0x930;
        break;
    case 1:
        D_00657A78 = 0x940;
        break;
    case 2:
        D_00657A78 = 0x990;
        break;
    default:
        D_00657A78 = 0x930;
        break;
    }
    return func_005835B0(lsn, sectors, buf, 5, &D_00875858);
}
