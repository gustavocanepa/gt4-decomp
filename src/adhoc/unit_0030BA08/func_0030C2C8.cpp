/* compiler: ee-gcc2.96-no-strict-aliasing */
/* A counted pair of words and an empty string (basic_string's default constructor: nilRep.grab()). */
typedef int s32;

struct Rep {
    s32 len;
    s32 res;
    s32 ref;
    s32 selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
};

extern "C" char *func_005C2560(Rep *r);
extern Rep D_00659FA8;

inline char *Rep::grab() {
    if (selfish)
        return func_005C2560(this);
    ++ref;
    return data();
}

struct String {
    char *dat;
    String() : dat(D_00659FA8.grab()) {}
};

struct func_0030C2C8 {
    s32 m0;
    s32 m4;
    String str;
    func_0030C2C8();
};

func_0030C2C8::func_0030C2C8() : m0(0), m4(1) {
}
