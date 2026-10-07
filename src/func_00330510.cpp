typedef unsigned int u32;

extern "C" void *func_005C1498(u32 arg0);
extern "C" void func_00330578(void *arg0);

extern "C" void *func_00330510(void) {
    void *temp_v0 = func_005C1498(0x2EC00);
    func_00330578(temp_v0);
    return temp_v0;
}
