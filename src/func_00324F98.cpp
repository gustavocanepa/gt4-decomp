typedef int s32;

struct Tmp { s32 field0; char pad[0xC]; };

extern "C" void func_002ECDE0(Tmp *arg0);
extern "C" void func_002EB630(s32 *arg0, s32 arg1, s32 arg2);
extern "C" void func_002EA590(Tmp *arg0, s32 arg1);
extern "C" void func_002F2A08(s32 *arg0, s32 arg1);

extern "C" s32 func_00324F98(void) {
    s32 result;
    Tmp tmp;
    Tmp *p = &tmp;

    func_002ECDE0(p);
    s32 v = p->field0;
    func_002EB630(&result, v, 1);
    func_002EA590(p, 2);
    s32 r = result;
    func_002F2A08(&result, 2);
    return r;
}
