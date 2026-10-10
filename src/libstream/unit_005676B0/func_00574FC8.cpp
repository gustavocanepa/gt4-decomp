typedef int s32;

struct Pair {
    s32 a;
    s32 b;
    Pair() : a(0), b(0) {}
};

/* The base class; its constructor is func_005787A0. */
struct func_005787A0 {
    char pad[0x38];
    func_005787A0();
};

struct func_00574FC8 : func_005787A0 {
    Pair m38;
    s32 m40;
    s32 m44;
    Pair m48;
    func_00574FC8(s32 v);
};

func_00574FC8::func_00574FC8(s32 v) : m40(v), m44(0) {
}
