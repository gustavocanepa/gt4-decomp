struct Val {
    int type;
    int value;
};

struct Stack {
    char pad[8];
    Val *top;
};

extern "C" float func_00477460(Val *v);
extern "C" void func_00480FA0(Stack *s, int n);

static inline float sqrtf_(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" float func_0047C018(int argc, Stack *s)
{
    float x = argc ? func_00477460(s->top - 1) : 0.0f;
    func_00480FA0(s, argc);
    return sqrtf_(x);
}
