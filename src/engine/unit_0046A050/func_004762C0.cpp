typedef unsigned int size_t;
inline void *operator new(size_t, void *p) throw() { return p; }

struct Pair { int x; int y; };
struct Elem { int value; Pair pos; };

struct Vec;
extern "C" void func_00605BE0(Vec *v, Elem *pos, const Elem &x);

struct Vec {
    Elem *start;
    Elem *finish;
    Elem *eos;
    void push_back(const Elem &x) {
        if (finish != eos) {
            new (finish) Elem(x);
            ++finish;
        } else {
            func_00605BE0(this, finish, x);
        }
    }
};

struct Src { char pad0[0x64]; int base; };
struct Obj {
    Src *src;
    char pad4[0x48];
    Pair pos;
    char pad54[0x12C];
    Vec list;
};

extern "C" void func_004762C0(Obj *o, int k) {
    if (o->src == 0) {
        Elem e;
        e.value = o->src->base + k;
        e.pos = o->pos;
        o->list.push_back(e);
    }
}
