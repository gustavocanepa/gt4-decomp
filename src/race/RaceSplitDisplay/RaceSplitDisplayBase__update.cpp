struct Part {
    virtual ~Part();
    virtual void update(float dt);
};

struct Owner {
    virtual ~Owner();
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
    virtual Part *getPart(int index);
};

extern "C" void RaceSplitDisplayBase__update(Owner *o, float dt) {
    for (int i = 0; i < 2; i++)
        o->getPart(i)->update(dt);
}
