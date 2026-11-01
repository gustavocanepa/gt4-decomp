/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Filter mask setter: stores the mask in the target under the D_00655340 section and, with
   'notify', sends a kind-2 request through func_0055D2C0; with no target it goes to func_0055C928.
   The kind comes in as a parameter of the inline set_(): a literal 2 swaps $v0/$v1. */
typedef unsigned long u64;

struct Target {
    int pad0[4];
    int mask;
};

struct Req {
    int m0;
    int pad4[3];
    int kind;
    int pad14[2];
    struct Target *target;
    int pad20[4];
    unsigned int flags;
    int pad34[3];
};

struct Section { int depth; int previouslyEnabled; };

extern struct Section D_00655340;
extern char SDDRV__VoiceSystem__master_[];
extern u64 D_006C8BD0;
extern void func_00576100(struct Section *s);
extern void func_00576140(struct Section *s);
extern void func_0055C928(void *o, int index, int value, int notify);
extern void func_0055CFE8(struct Req *r, u64 key);
extern void func_0055D2C0(struct Req *r, int a, int b);

static inline void set_(int kind, int mask, int notify, struct Target *target) {
    struct Req r;
    if (target != 0) {
        func_00576100(&D_00655340);
        target->mask = mask;
        if (notify) {
            func_0055CFE8(&r, D_006C8BD0);
            r.target = target;
            r.kind = kind;
            r.flags |= 9;
            func_0055D2C0(&r, 0, mask);
        }
        func_00576140(&D_00655340);
    } else {
        func_0055C928(SDDRV__VoiceSystem__master_, kind, mask, notify);
    }
}

void func_0055C398(int mask, int notify, struct Target *target) {
    set_(2, mask, notify, target);
}
