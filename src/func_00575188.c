typedef int s32;

struct Pair { s32 a; s32 b; };
typedef struct Pair Pair; struct Obj { char pad[0x34]; Pair p; }; typedef struct Obj Obj;

int func_00574D78(Obj *); /* declared non-void: the next temporary takes $v1 */
static inline void clear(Pair *p) { p->a = 0; p->b = 0; }
void func_00575228(Obj *, s32);

void func_00575188(Obj *self, s32 x) {
    func_00574D78(self);
    clear(&self->p);
    func_00575228(self, x);
}
