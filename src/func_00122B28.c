typedef int s32;

struct Obj { char pad[0x48]; s32 f48; char pad4C[0x254]; s32 f2A0; };
void func_00122FA8(struct Obj *);
void func_00574EB0(s32 *);

void func_00122B28(struct Obj *o) {
    while (func_00574EB0(&o->f48), o->f2A0 == 0)
        func_00122FA8(o);
}
