/* Despite its symbol name (PropNameSearcher::structor_0, which looks like a mislabel by the symbol tooling) the body sets up a motion key
 * with 00427820 and MotionSetPlayer::set from 003CC8E8 and Pitmen::getMotion, then for each of six slots (0xAA4 bytes apart, id at +0x38C4 of
 * the slot) looks up the slot's id with 00429640 and stores the found value at slot +0x4360. The Pitmen call suggests pit-crew motions
 * (inferred); the temporary object is a tiny class with a virtual method and an int, kept as the compiler needs it. */
class ResultBase {
public:
    virtual void v1();
};

class PropNameSearcher__vtable : public ResultBase {
public:
    int value;
    PropNameSearcher__vtable() : value(0) {}
    virtual void key(); /* declared only: the vtable stays the original's */
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

extern "C" void func_00427820(Key *key);
extern "C" void GT4_Motion__MotionSetPlayer__set(Key *key, int motionSet, int b);
extern "C" int func_003CC8E8(Owner *owner);
extern "C" int Pitmen__getMotion(Owner *owner);
extern "C" int func_00429640(Key *key, int id, PropNameSearcher__vtable *out);

extern "C" void PropNameSearcher__structor_0(Owner *owner)
{
    Key key;
    func_00427820(&key);
    int motionSet = func_003CC8E8(owner);
    GT4_Motion__MotionSetPlayer__set(&key, motionSet, Pitmen__getMotion(owner));
    Slot *slot = (Slot *)owner;
    for (int i = 0; i < 6; i++, slot = (Slot *)((char *)slot + 0xAA4)) {
        PropNameSearcher__vtable lookup;
        func_00429640(&key, slot->id, &lookup);
        slot->result = lookup.value;
    }
}
