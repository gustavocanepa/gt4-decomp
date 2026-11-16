/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Dyn { VE *vt; };
struct Obj {
    char pad0[0x64]; char *vt;
    char pad68[0xCC8 - 0x68]; s32 cc8;
    char padCCC[0xE420 - 0xCCC]; Dyn *e420;
};
extern "C" void RaceDisplay__tf();
extern "C" void RaceDisplayBase__tf();
extern "C" void *__dynamic_cast_2(void *, void (*)(), int, char *, void (*)(), void *);
extern "C" s32 RaceInput__getButtons(void *);
extern "C" s32 RaceInput__getButtonDown(void *);
extern "C" s32 func_003A1F98(void *);
extern "C" void func_003A1F38(void *, s32);
static inline void *CALL0(Obj *o, int off) { VE *e = (VE *)(o->vt + off); return ((void *(*)(void *))e->fn)((char *)o + e->delta); }
extern "C" void RaceBasic__handle_command_in_pause(Obj *self) {
    if (self->cc8 == 0) {
        if (CALL0(self, 0xA8)) {
            void *pad = CALL0(self, 0x230);
            s32 k = 0x80;
            s32 r = RaceInput__getButtons(pad);
            if (r == k) {
                if (RaceInput__getButtonDown(pad) & r) {
                    Dyn *d = self->e420;
                    Dyn *res = 0;
                    if (d) {
                        VE *e = d->vt;
                        res = (Dyn *)__dynamic_cast_2(e->fn, RaceDisplay__tf, 0, (char *)d + e->delta, RaceDisplayBase__tf, d);
                    }
                    if (res) {
                        func_003A1F38(res, func_003A1F98(res) ^ 1);
                        VE *e = (VE *)((char *)res->vt + 0x10);
                        ((void (*)(void *, float))e->fn)((char *)res + e->delta, 0.0f);
                    }
                }
            }
        }
    }
}
