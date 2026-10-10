/* A 0x2280-byte object; its constructor is func_005538F0. */
struct func_005538F0 {
    char data[0x2280];
    func_005538F0();
};
extern "C" void func_005537C8(func_005538F0 *self);
extern "C" func_005538F0 *D_0064CCAC;

extern "C" void func_00553698(void)
{
    if (!D_0064CCAC) {
        D_0064CCAC = new func_005538F0;
        func_005537C8(D_0064CCAC);
    }
}
