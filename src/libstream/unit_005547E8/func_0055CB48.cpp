/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Under the pool lock, sets entry 'which' of o (or both entries when which is 2) to the packed
   4-byte value *v (an unaligned copy) and marks it set. */
typedef int s32;
typedef unsigned char u8;
struct Val { u8 b[4]; };
struct Ent { s32 flag; Val v; char pad[0x1C]; };
struct Obj { char pad[0x20]; Ent ent[2]; };
extern char D_00655340[];
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0055CB48(Obj *o, s32 which, Val *v) {
    func_00576100(D_00655340);
    if (which != 2) {
        Ent *e = &o->ent[which];
        e->v = *v;
        e->flag = 1;
    } else {
        for (s32 i = 0; i < 2; i++) {
            Ent *e = &o->ent[i];
            e->v = *v;
            e->flag = 1;
        }
    }
    func_00576140(D_00655340);
}
