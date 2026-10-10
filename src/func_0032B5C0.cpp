/* basic_string<char>() out of line: dat = nilRep.grab() (clone when selfish, else ++ref). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String {
    char *dat;
    String() __asm__("func_0032B5C0");
};

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

String::String() : dat(grab(&D_00659FA8)) {
}
