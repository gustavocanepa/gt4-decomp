typedef int s32;

struct Obj { char pad[0x10]; s32 m10; };
struct Guard { Obj *p; s32 pad[3]; };

extern "C" void func_0016D848(Guard *);
extern "C" void func_0016D7F0(Guard *, s32);
extern "C" void func_00435710(s32);

extern "C" void MGarage__delAllCarExceptRidingCar(void) {
    Guard g;
    s32 v;
    func_0016D848(&g);
    v = g.p->m10;
    func_0016D7F0(&g, 2);
    func_00435710(v);
}
