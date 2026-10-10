typedef int s32;

struct Value {
    s32 type;
    s32 data[3];
};

extern "C" void func_00477208(Value *, s32);
extern "C" void func_00476768(Value *, Value *);
extern "C" void func_004768C0(Value *);

extern "C" Value *func_00480A28(Value *ret, s32 arg) {
    Value t;
    t.type = 1;
    func_00477208(&t, arg);
    func_00476768(ret, &t);
    func_004768C0(&t);
    return ret;
}
