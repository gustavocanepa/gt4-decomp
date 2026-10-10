class ResultBase {
public:
    virtual void v1();
};

class PropNameSearcher__vtable : public ResultBase {
public:
    int value;
    PropNameSearcher__vtable() : value(0) {}
};

struct Key {
    int a;
    int b;
    int c;
    int d;
};

struct Slot {
    char pad0[0x38C4];
    int id;
    char pad1[0x4360 - 0x38C4 - 4];
    int result;
};

struct Owner {
    char pad[0x38C4];
    Slot slots[6];
};

extern "C" void func_00427820(Key *k);
extern "C" void GT4_Motion__MotionSetPlayer__set(Key *k, int a, int b);
extern "C" int func_003CC8E8(Owner *o);
extern "C" int Pitmen__getMotion(Owner *o);
extern "C" int func_00429640(Key *k, int id, PropNameSearcher__vtable *out);

extern "C" void PropNameSearcher__structor_0(Owner *o)
{
    Key k;
    func_00427820(&k);
    int a = func_003CC8E8(o);
    GT4_Motion__MotionSetPlayer__set(&k, a, Pitmen__getMotion(o));
    Slot *sl = (Slot *)o;
    for (int i = 0; i < 6; i++, sl = (Slot *)((char *)sl + 0xAA4)) {
        PropNameSearcher__vtable r;
        func_00429640(&k, sl->id, &r);
        sl->result = r.value;
    }
}
