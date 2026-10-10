typedef int s32;

struct Obj {
    char pad[4];
    char sign;
    char text[0xAF];
    s32 dirty;
};

extern "C" void func_003E0198(char *, s32);

extern "C" void func_003E0278(Obj *o, s32 value, s32 positive) {
    func_003E0198(o->text, value);
    o->sign = positive ? '+' : ' ';
    o->dirty = 1;
}
