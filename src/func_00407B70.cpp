typedef int s32;

struct List;

struct Tmp {
    s32 w[4];
};

extern "C" s32 func_00407B10(List *, s32);
extern "C" void func_00407A40(Tmp *, s32);
extern "C" s32 func_003AEAE8(Tmp *);

extern "C" s32 func_00407B70(List *list, s32 index) {
    s32 n = func_00407B10(list, index);
    if (n < 0)
        return 0;
    Tmp t;
    func_00407A40(&t, n % 13);
    return func_003AEAE8(&t);
}
