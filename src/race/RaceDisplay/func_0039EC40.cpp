struct ObjBase {
    virtual ~ObjBase();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void refresh();
};

struct Obj : ObjBase {
    char pad4[0x20];
    int arg24;
    char pad28[6];
    signed char mode2E;
    char pad2F;
    union {
        unsigned int word;
        unsigned char bytes[4];
    } flags;
};

extern "C" void func_003A1638(Obj *o, int arg);
extern "C" void func_0039D218(Obj *o, int mode);
extern "C" void func_0039CFD8(Obj *o);

extern "C" void func_0039EC40(Obj *o) {
    if (o->flags.bytes[1] == 0)
        return;
    o->flags.word &= 0xFFFF00FF;
    func_003A1638(o, o->arg24);
    func_0039D218(o, o->mode2E);
    if (o->flags.bytes[2]) {
        o->flags.word &= 0xFF00FFFF;
        o->refresh();
        func_0039CFD8(o);
    }
}
