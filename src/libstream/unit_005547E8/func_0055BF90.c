typedef int s32;

struct Obj { char pad[0x234]; s32 f234; };
extern char D_00655340[];
void func_00576100(void *);
void func_00576140(void *);

s32 func_0055BF90(struct Obj *o) {
    s32 *p = &o->f234;
    s32 r;
    func_00576100(D_00655340);
    r = *p;
    func_00576140(D_00655340);
    return r;
}
