/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Root { virtual void slot0(); };
struct Display : Root {
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
    virtual ~Display() throw();
    char data[0x3F2C];
};
struct Base {
    virtual ~Base() throw() __asm__("func_003A27C8");
};
struct RaceSplitDisplay__vtable : Base {
    int field4;
    Display displays[2];
    virtual void key(); /* declared only: the vtable stays the original's */
    virtual ~RaceSplitDisplay__vtable() __asm__("func_003A3070");
};
RaceSplitDisplay__vtable::~RaceSplitDisplay__vtable() {}
