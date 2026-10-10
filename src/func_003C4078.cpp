typedef int s32;

struct Value {
    s32 type;
    s32 data[3];
};

extern "C" void func_00476A98(Value *, s32);
extern "C" void func_00476768(Value *, Value *);
extern "C" void func_004768C0(Value *);

extern "C" Value *func_003C4078(Value *ret, s32 arg) {
    Value t;
    t.type = 1;
    func_00476A98(&t, arg);
    func_00476768(ret, &t);
    func_004768C0(&t);
    return ret;
}
