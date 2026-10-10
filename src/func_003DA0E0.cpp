extern "C" void func_004AA168(void);
extern "C" void func_004A2808(int mode, float value);
extern "C" void func_004A1638(int n);
extern "C" void func_004AB040(int n);
extern "C" void func_004A29A8(int n);
extern "C" void func_004A7CE0(int *a, int *b, int *c, int *d);
extern "C" void func_004A6290(int a, int b, int c, int d);

extern "C" void func_003DA0E0(float value)
{
    int r[4];
    func_004AA168();
    func_004A2808(0x21, value);
    func_004A1638(6);
    func_004AB040(5);
    func_004A29A8(0);
    func_004A7CE0(&r[0], &r[1], &r[2], &r[3]);
    func_004A6290(r[0], r[1], r[2], r[3]);
}
