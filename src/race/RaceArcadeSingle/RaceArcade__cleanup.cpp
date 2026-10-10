typedef int s32;

struct Obj;

extern "C" void RaceBasic__cleanup(Obj *arg0);
extern "C" void func_0038B7C0(Obj *arg0, s32 arg1);
extern "C" void func_0038B8D8(Obj *arg0, s32 arg1);
extern "C" void func_0038B990(Obj *arg0, s32 arg1);
extern "C" void func_0038BA90(Obj *arg0, s32 arg1);
extern "C" void func_0038BAB0(Obj *arg0, s32 arg1);

extern "C" void RaceArcade__cleanup(Obj *arg0) {
    Obj *s0 = arg0;
    RaceBasic__cleanup(arg0);
    func_0038B7C0(s0, 0);
    func_0038B8D8(s0, 0);
    func_0038BAB0(s0, 0);
    func_0038B990(s0, 0);
    func_0038BA90(s0, 0);
}
