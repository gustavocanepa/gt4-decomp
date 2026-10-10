typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern char D_0069F318[];
extern "C" void func_0045B4D8(void *, void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8u(void *, s32);
extern "C" void GT4Model__BinStreamWriter__writeArray(void *, void *, s32);
extern "C" void func_0045B548(void *, void *);

extern "C" void func_0033ADE8(s32 *arg0, void *arg1) {
    s32 buf0[4];
    func_0045B4D8(buf0, arg1, &D_0069F318);
    GT4Model__BinStreamWriter__write8u(arg1, 0x1);
    GT4Model__BinStreamWriter__writeArray(arg1, arg0, 0x24);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x24, 0x10);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x34, 0x4);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x38, 0x4);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x3c, 0x4);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x40, 0x4);
    func_0045B548(buf0, arg1);
}
