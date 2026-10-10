struct Val {
    int type;
};

extern "C" void func_00476B30(Val *v, int b);
extern "C" void func_004787B8(Val *v, int type) throw();
extern "C" float func_00477460(Val *v);

extern "C" void func_004788C0(Val *v) {
    if (v->type == 10)
        return func_00476B30(v, 1);
    func_004787B8(v, 10);
    func_00476B30(v, func_00477460(v) != 0.0f);
}
