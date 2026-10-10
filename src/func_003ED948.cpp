extern "C" int D_00621F74;
extern "C" void *func_00578CB0(int addr);
extern "C" void func_003ED6B8(void *p, int addr);

extern "C" void func_003ED948(int slot) {
    int addr = slot * 0x96000 + 0x100;
    D_00621F74 = slot;
    func_003ED6B8(func_00578CB0(addr), addr);
}
