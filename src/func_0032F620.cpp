struct CameraManager;

/* vptr at 0x64; slot 25 is RaceBase::getGT4CameraManager(int). */
struct RaceSplitBattleBase {
    char pad0[0x64];
    virtual ~RaceSplitBattleBase();
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
    virtual CameraManager *getGT4CameraManager(int index);
};

extern "C" void func_003889E0(RaceSplitBattleBase *self);               /* RaceBase::initializeCamera() */
extern "C" void func_00372048(CameraManager *cm, int count);            /* CameraManager::initWindowMax(int) */
extern "C" void func_00372080(CameraManager *cm, int window);
extern "C" void func_003744C0(CameraManager *cm, int car);              /* CameraManager::setTargetCar(int) */

/* RaceSplitBattleBase::initializeCamera() */
extern "C" void func_0032F620(RaceSplitBattleBase *self) {
    func_003889E0(self);
    CameraManager *cm = self->getGT4CameraManager(0);
    func_00372048(cm, 2);
    for (int i = 1; i >= 0; i--) {
        func_00372080(cm, i);
        func_003744C0(cm, i);
    }
}
