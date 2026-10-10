typedef int s32;

struct RaceData {
    char pad[0x64];
};

class Race : public RaceData {
public:
    virtual void virtual_1();
    virtual void virtual_2();
    virtual void virtual_3();
    virtual void virtual_4();
    virtual void virtual_5();
    virtual void virtual_6();
    virtual void virtual_7();
    virtual void virtual_8();
    virtual void virtual_9();
    virtual void virtual_10();
    virtual void virtual_11();
    virtual void virtual_12();
    virtual void virtual_13();
    virtual void virtual_14();
    virtual void virtual_15();
    virtual void virtual_16();
    virtual void virtual_17();
    virtual void virtual_18();
    virtual void virtual_19();
    virtual void virtual_20();
    virtual void virtual_21();
    virtual void virtual_22();
    virtual void virtual_23();
    virtual void virtual_24();
    virtual void virtual_25();
    virtual void virtual_26();
    virtual void virtual_27();
    virtual void virtual_28();
    virtual void virtual_29();
    virtual void virtual_30();
    virtual void virtual_31();
    virtual void virtual_32();
    virtual void virtual_33();
    virtual void virtual_34();
    virtual void virtual_35();
    virtual void virtual_36();
    virtual void virtual_37();
    virtual void virtual_38();
    virtual void virtual_39();
    virtual void virtual_40();
    virtual void virtual_41();
    virtual void virtual_42();
    virtual void virtual_43();
    virtual void virtual_44();
    virtual void virtual_45();
    virtual void virtual_46();
    virtual void virtual_47();
    virtual void virtual_48();
    virtual void virtual_49();
    virtual void virtual_50();
    virtual void virtual_51();
    virtual void virtual_52();
    virtual void virtual_53();
    virtual void virtual_54();
    virtual void virtual_55();
    virtual void virtual_56();
    virtual void virtual_57();
    virtual void virtual_58();
    virtual void virtual_59();
    virtual void virtual_60();
    virtual void virtual_61();
    virtual void virtual_62();
    virtual void loadReplayInputs(void *);  /* slot 62 */
    virtual void loadGhostInputs(void *);  /* slot 63 */
};

extern "C" void RaceSolitaire__loadReplaceData(Race *self, void *data);
extern "C" void RaceSolitaire__loadReplaceInputs(Race *self, void *data, bool b);

extern "C" void RaceSolitaire__loadTrackInputs_2(Race *self, s32 mode, void *data)
{
    if (mode == 0) {
        RaceSolitaire__loadReplaceData(self, data);
        RaceSolitaire__loadReplaceInputs(self, data, true);
        *(s32 *)((char *)self + 0xF0F8) = 1;
    } else {
        self->loadReplayInputs(data);
        self->loadGhostInputs(data);
    }
}
