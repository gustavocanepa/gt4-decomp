/* compiler: ee-gcc2.9-991111 */
typedef struct {
    int used;
    char pad[0x330];
} Slot;

extern int D_00657B10;
extern Slot D_0087FA80[16];

int func_0058EEB0(int index);

int func_0058ED40(void)
{
    int i;
    int r;

    D_00657B10 = 0;
    for (i = 0; i < 16; i++) {
        if (D_0087FA80[i].used) {
            r = func_0058EEB0(i);
            if (r < 0)
                return r;
        }
    }
    return 1;
}
