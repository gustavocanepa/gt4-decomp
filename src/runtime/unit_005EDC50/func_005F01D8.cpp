typedef int s32;

struct Name { const char *name; };
struct Obj;
struct T { T *p; };

struct Vec {
    s32 pad0;
    T *start;
    T *finish;
    T *eos;
};

extern "C" void *memmove(void *dst, const void *src, s32 n);
extern "C" Name *func_005F0970(void);
extern "C" void *func_00326750(s32 size, s32 align, const char *name);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline T *value_type(T *const *) { return 0; }

static inline T *ucopy_aux(T *first, T *last, T *result, T *) {
    s32 n = (char *)last - (char *)first;
    memmove(result, first, n);
    return (T *)((char *)result + n);
}

static inline T *ucopy(T *first, T *last, T *result) {
    return ucopy_aux(first, last, result, value_type(&result));
}

static inline void destroy_aux(T *, T *, T *) {}

static inline void destroy(T *first, T *last) {
    destroy_aux(first, last, value_type(&first));
}

inline void *operator new(unsigned int, void *p) throw() { return p; }

static inline void construct(T *p, const T &v) {
    new (p) T(v);
}

static inline void deallocate(T *p, s32 n) {
    if (p != 0) {
        func_00326798(p, n * sizeof(T), 4, func_005F0970()->name);
    }
}

static inline T *copy_backward(T *first, T *last, T *result) {
    s32 n = last - first;
    memmove(result - n, first, n * sizeof(T));
    return result - n;
}

extern "C" void func_005F01D8(Vec *v, T *pos, const T *x) {
    if (v->finish != v->eos) {
        construct(v->finish, *(v->finish - 1));
        ++v->finish;
        T *x_copy = x->p;
        copy_backward(pos, v->finish - 2, v->finish - 1);
        pos->p = x_copy;
    } else {
        s32 old_size = v->finish - v->start;
        s32 len = old_size != 0 ? 2 * old_size : 1;
        T *new_start = (T *)func_00326750(len * sizeof(T), 4, func_005F0970()->name);
        T *new_finish = ucopy(v->start, pos, new_start);
        construct(new_finish, *x);
        ++new_finish;
        new_finish = ucopy(pos, v->finish, new_finish);
        destroy(v->start, v->finish);
        deallocate(v->start, v->eos - v->start);
        v->start = new_start;
        v->finish = new_finish;
        v->eos = new_start + len;
    }
}
