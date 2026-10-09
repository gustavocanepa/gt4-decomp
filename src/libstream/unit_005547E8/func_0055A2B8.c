/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct { char b[24]; } Block24;

extern char D_00655340[];
extern void func_00576100(void *lock);
extern void func_00576140(void *lock);

void func_0055A2B8(char *obj, Block24 *src) {
    func_00576100(D_00655340);
    *(Block24 *)(obj + 0x1C) = *src;
    *(int *)(obj + 0x14) = 3;
    func_00576140(D_00655340);
}
