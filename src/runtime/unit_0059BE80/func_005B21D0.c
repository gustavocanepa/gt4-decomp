/* compiler: ee-gcc2.9-991111 */
typedef struct Slot {
    int unk0;
    int flags;
    int unk8;
    int unkC;
} Slot;

extern int D_00658348;
extern Slot D_008897C0[32];
extern void func_005B20E0(void);
extern int func_005ADCE0(int sema);
extern int func_005ADCC0(int sema);

Slot *func_005B21D0(void)
{
    Slot *s;

    func_005B20E0();
    func_005ADCE0(D_00658348);
    for (s = D_008897C0; s < D_008897C0 + 32; s++) {
        if (s->flags == 0) {
            s->flags = 0x10000000;
            func_005ADCC0(D_00658348);
            return s;
        }
    }
    func_005ADCC0(D_00658348);
    return 0;
}
