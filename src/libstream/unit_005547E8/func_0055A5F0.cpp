/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Under the pool lock, takes a free record of the 48-entry table D_00650500 (used == 0, set up by
   func_0055A3A0); when none is free, recycles the one with the smallest age below 'limit'
   (func_0055A340 then func_0055A3A0). Returns the record or 0. */
typedef int s32;
struct Rec { char pad0[0x14]; s32 used; char pad18[0xC]; s32 age; char pad28[0xC]; };
extern Rec D_00650500[48];
extern char D_00655340[];
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0055A3A0(Rec *);
extern "C" void func_0055A340(Rec *, s32);
extern "C" Rec *func_0055A5F0(s32 limit) {
    Rec *found = 0;
    Rec *tbl = D_00650500;
    func_00576100(D_00655340);
    s32 i = 0;
    Rec *p = tbl;
    while (i < 48) {
        i++;
        if (p->used == 0) {
            func_0055A3A0(p);
            found = p;
            break;
        }
        p++;
    }
    if (!found) {
        p = tbl;
        s32 best = limit;
        for (s32 n = 47; n >= 0; n--, p++) {
            if (p->age < best) {
                best = p->age;
                found = p;
            }
        }
        if (found) {
            func_0055A340(found, 0);
            func_0055A3A0(found);
        }
    }
    func_00576140(D_00655340);
    return found;
}
