void func_00576090(void);
void func_00574D78(void *);
void func_004EFC30(void *);
void func_0060EA00(void *);
int func_004F8938(void *);
void func_0060EA50(void *);
void func_0060EAA0(void *);
void func_004F0320(void *);

extern char D_00689638[];
extern int D_00621FF0;

void func_004F01E8(char *self) {
    *(char **)(self + 0x3FAC) = D_00689638;
    func_00576090();
    func_00574D78(self + 8);
    *(int *)(self + 0x38) = 0;
    *(int *)(self + 0x3C) = 0;
    func_004EFC30(self + 0x40);
    *(int *)(self + 0x194) = 0;
    func_0060EA00(self + 0x198);
    *(int *)(self + 0x5A8) = 0;
    func_004F8938(self + 0xCD8);
    *(int *)(self + 0x30C0) = D_00621FF0;
    func_0060EA50(self + 0x39A4);
    func_0060EAA0(self + 0x3BF4);
    func_004F0320(self);
}
