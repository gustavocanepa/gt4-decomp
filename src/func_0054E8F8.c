typedef int s32;

struct Obj { char pad[0x320]; s32 f320; char pad324[0xC0]; s32 f3E4; };
void func_0054E8B0(struct Obj *);
void func_00574EB0(s32 *);

void func_0054E8F8(struct Obj *o) {
    while (func_00574EB0(&o->f320), o->f3E4 != 0)
        func_0054E8B0(o);
}
