typedef int s32;
typedef unsigned char u8;

extern "C" void func_0030BB18(void *arg0);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

struct Handle {
    void *p;
    Handle() { func_0030BB18(this); }
    void *get() const { return p; }
    ~Handle() { func_00309378(this, 2); }
    Handle &operator=(const Handle &rhs) {
        if (this != &rhs) {
            void *np = rhs.p;
            if (np != 0) {
                func_003285A8(np);
            }
            if (p != 0) {
                func_003285F8(p);
            }
            p = np;
        }
        return *this;
    }
};

struct Handle16 {
    void *p;
    char pad[0xC];
};

struct Self {
    char pad0[0xF0];
    u8 *flags;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self, struct Handle16 *out, s32 n, struct Handle *args);
};

struct VObj {
    char pad0[4];
    struct VEntry *vtbl;
};

extern "C" s32 func_00206880(struct Self *arg0);
extern "C" void *func_00206868(struct Self *arg0);
extern "C" void *func_0025C300(void *arg0);
extern "C" void free(void *arg0);
extern "C" u8 *malloc(s32 arg0);
extern "C" void func_00309348(struct Handle16 *arg0, void **arg1);
extern "C" void func_002FE278(struct Handle16 *arg0, s32 arg1);
extern "C" void func_002FC870(struct Handle16 *arg0, s32 arg1);
extern "C" void func_002FE2E0(struct Handle16 *arg0);
extern "C" s32 func_002FE250(void *arg0);

extern "C" void func_002DC178(struct Self *self, struct VObj **arg1) {
    if (*arg1 != 0) {
        s32 n = func_00206880(self);
        if (n > 0) {
            void *old = self->flags;
            s32 i;
            s32 idx;
            void *node;
            if (old != 0) {
                self->flags = 0;
                free(old);
            }
            self->flags = malloc(n);
            for (i = 0; i < n; i++) {
                self->flags[i] = 0;
            }
            for (idx = 0, node = func_00206868(self); node != 0; node = func_0025C300(node), idx++) {
                Handle hs[2];
                Handle16 h;
                void *tmp;
                tmp = node;
                func_00309348(&h, &tmp);
                hs[0] = *(Handle *)&h;
                func_00309378(&h, 2);
                func_002FE278(&h, idx);
                hs[1] = *(Handle *)&h;
                func_002FC870(&h, 2);
                func_002FE2E0(&h);
                {
                    struct VObj *o = *arg1;
                    struct VEntry *e = (struct VEntry *)((char *)o->vtbl + 0xA8);
                    e->fn((char *)o + e->delta, &h, 2, hs);
                }
                self->flags[idx] = func_002FE250(((Handle *)&h)->get()) != 0;
                func_002FC870(&h, 2);
            }
        }
    }
}
