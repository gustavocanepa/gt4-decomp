/* compiler: ee-gcc2.9-991111 */
typedef struct {
    char pad0[0xC];
    int size;
    char pad10[0x20];
    int pos;
} File_0058A208;

extern File_0058A208 D_0087E1C0;

int func_0058A208(int fd, void *unused, int offset, int whence) {
    int base = 0;
    switch (whence) {
    case 0:
        base = 0;
        break;
    case 1:
        base = D_0087E1C0.pos;
        break;
    case 2:
        base = D_0087E1C0.size;
        break;
    }
    base += offset;
    if (D_0087E1C0.size < base) {
        base = D_0087E1C0.size;
    }
    D_0087E1C0.pos = base;
    return base;
}
