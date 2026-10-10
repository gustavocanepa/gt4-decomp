/* compiler: ee-gcc2.96-stl */
/* for_each(begin, end, mem_fun_ref(D_006AD480)) through the out-of-line instantiation
   func_00605480; the member-pointer constant {0, -1, func_00479128}
   is named by its retail address (D_006AD480) so that no .rodata relocation stays in the object. */
template <class _Arg, class _Result> struct unary_function {
    typedef _Arg argument_type;
    typedef _Result result_type;
};

template <class _Ret, class _Tp> class mem_fun_ref_t : public unary_function<_Tp, _Ret> {
public:
    explicit mem_fun_ref_t(_Ret (_Tp::*__pf)()) : _M_f(__pf) {}
    _Ret operator()(_Tp &__r) const { return (__r.*_M_f)(); }
private:
    _Ret (_Tp::*_M_f)();
};

template <class _Ret, class _Tp> inline mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)())
{
    return mem_fun_ref_t<_Ret, _Tp>(__f);
}

struct Elem {
    int m0;
    int m4;
    int m8;
    int mC;
    void update() __asm__("func_00479128");
};

extern void (Elem::*const D_006AD480)();

extern "C" mem_fun_ref_t<void, Elem> func_00605480(Elem *first, Elem *last, mem_fun_ref_t<void, Elem> f);

struct Group {
    Elem *items;
    int count;
    Elem *begin() { return items; }
    Elem *end() { return items + count; }
};

struct Obj {
    char pad0[0xB0];
    Group group;
};

extern "C" void func_00474228(Obj *o) {
    func_00605480(o->group.begin(), o->group.end(), mem_fun_ref(D_006AD480));
}
