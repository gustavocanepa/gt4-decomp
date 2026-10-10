typedef int s32;

struct Result { s32 pad[4]; void *p; s32 pad14[3]; };
extern void *D_006186FC;
extern s32 D_00618708;
void func_004AE230(struct Result *, s32, s32);
void func_00498B28(void *);

void func_00108EE8(void) {
    void **pg = &D_006186FC;
    if (*pg == 0) {
        struct Result r;
        func_004AE230(&r, D_00618708, 1);
        *pg = r.p;
        func_00498B28(r.p);
    }
}
