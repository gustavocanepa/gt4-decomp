extern "C" void func_00551D50(int id, char *buf, int size);
extern "C" void func_00566310(int id, char *buf, int size);
extern "C" unsigned int func_0057F260(const char *s);
extern "C" int func_0057DA20(char *buf, const char *fmt, ...);
extern "C" void func_005A6AB0(void *a, const char *s, void *b);
extern const char D_006C8DD0[];

extern "C" void func_00564A78(int code, void *a, void *b)
{
    char major[0x20];
    char minor[0x20];
    char text[0x40];
    func_00551D50((code >> 4) & 0xF, major, 0x20);
    func_00566310(code & 0xF, minor, 0x20);
    func_0057DA20(text, D_006C8DD0, func_0057F260(major), major, minor);
    func_005A6AB0(a, text, b);
}
