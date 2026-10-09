void *hObject__structor_0(void *);
void *func_002273C8(void *);
void func_005A48D8(void *, int, int);

extern char mNetwork__vtable[];
extern void *D_00624978;

void mNetwork__structor_0(char *self) {
    hObject__structor_0(self);
    *(int *)(self + 0x18) = 1;
    *(char **)(self + 4) = mNetwork__vtable;
    *(int *)(self + 0x10) = 0;
    *(int *)(self + 0x14) = 0;
    *(int *)(self + 0x1C) = 0;
    *(int *)(self + 0x1B8) = 0;
    func_002273C8(self + 0x1C0);
    func_002273C8(self + 0x1C4);
    *(void **)(self + 0x1B4) = D_00624978;
    *(int *)(self + 0x30) = 0x275B;
    *(int *)(self + 0x1CC) = -1;
    *(char *)(self + 0x20) = 0;
    *(int *)(self + 0x1C8) = 0;
    func_005A48D8(self + 0x1D0, 0, 0x21);
}
