typedef int s32;

/* The base class; its constructor is func_00574D78. */
struct func_00574D78 {
    char pad[0x30];
    func_00574D78();
};

struct Pair {
    s32 a;
    s32 b;
    Pair() : a(0), b(0) {}
};

/* Named after its own constructor. */
struct func_00575130 : func_00574D78 {
    s32 m30;
    Pair m34;
    s32 m3C;
    s32 m40;
    s32 m44;
    s32 m48;
    s32 m4C;
    s32 m50;
    s32 m54;
    func_00575130();
};

func_00575130::func_00575130() : m30(-1) {
    m48 = 2;
    m3C = 0;
    m40 = 0;
    m44 = 0;
    m4C = 0;
    m50 = 0;
    m54 = 0;
}
