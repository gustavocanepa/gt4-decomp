/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

/* RaceSimplePanel::RaceSimplePanel(): the base panel, fourteen display
 * members, then their alignment, colours and visibility. */

struct RaceDisplayObjectBase {
    bool visible : 8;
    void setVisible(bool v) { visible = v; }
    void setSize(s32 w, s32 h) __asm__("func_003AEC90");
    void setAlignment(s32 h, s32 v) __asm__("func_003AECA0");
};

struct RaceTexturePanel {
    char data[0x1C];
    RaceTexturePanel() __asm__("func_003A5288");
};
struct RaceDigitalSpeedmeter : RaceDisplayObjectBase {
    char data[0x34];
    RaceDigitalSpeedmeter() __asm__("func_003A3F10");
};
struct RaceFuelMeter : RaceDisplayObjectBase {
    char pad4[0x18];
    u32 color;
    char pad20[0x8];
    RaceFuelMeter() __asm__("func_003A5760");
    void setColor(u32 c) { color = c; }
};
struct RaceTireWearDisplay : RaceDisplayObjectBase {
    char data[0x2C];
    RaceTireWearDisplay() __asm__("func_003A5F70");
};
struct RaceBattleTachometer : RaceDisplayObjectBase {
    char data[0x20];
    RaceBattleTachometer() __asm__("func_003EC900");
};
struct RaceShiftPositionDisplay : RaceDisplayObjectBase {
    char data[0x54];
    RaceShiftPositionDisplay() __asm__("func_003A6CE0");
};
struct RaceSuggestedGearDisplay : RaceDisplayObjectBase {
    char data[0x54];
    RaceSuggestedGearDisplay() __asm__("func_003A6FA8");
};
struct RaceShiftTimingLampDisplay : RaceDisplayObjectBase {
    char data[0x38];
    RaceShiftTimingLampDisplay() __asm__("func_003A7268");
};
struct RaceABMonitor : RaceDisplayObjectBase {
    char data[0x7C];
    RaceABMonitor() __asm__("func_003A53F0");
};
struct RaceSideGravityMeter : RaceDisplayObjectBase {
    char data[0x28];
    RaceSideGravityMeter() __asm__("func_003AB1F0");
};
struct RaceIndicator : RaceDisplayObjectBase {
    char pad4[0x34];
    u32 color;
    char pad3C[0x8];
    RaceIndicator() __asm__("func_003A6B70");
    void setColor(u32 c) { color = c; }
};

struct RacePanelBase {
    char pad0[0x14];
    virtual ~RacePanelBase();
};
struct RacePanel : RacePanelBase {
    char pad18[0x14];
    RacePanel() __asm__("func_003A73F8");
    virtual ~RacePanel();
};

struct RaceSimplePanel : RacePanel {
    RaceTexturePanel texture;
    RaceDigitalSpeedmeter speed;
    RaceFuelMeter fuel;
    RaceFuelMeter nos;
    RaceTireWearDisplay tires;
    RaceBattleTachometer tacho;
    RaceShiftPositionDisplay gear;
    RaceSuggestedGearDisplay suggestedGear;
    RaceShiftTimingLampDisplay shiftLamp;
    RaceABMonitor pedals;
    RaceSideGravityMeter sideG;
    RaceIndicator asmLamp;
    RaceIndicator tcsLamp;
    RaceIndicator brakeLamp;
    bool active : 8;
    RaceSimplePanel() __asm__("func_003A7538");
    virtual ~RaceSimplePanel();
};

RaceSimplePanel::RaceSimplePanel() {
    tacho.setSize(0x30, 0x18);
    speed.setAlignment(1, 1);
    fuel.setAlignment(0, 1);
    nos.setAlignment(0, 1);
    nos.setColor(0x800000F0);
    tires.setAlignment(0, 1);
    tacho.setAlignment(1, 1);
    gear.setAlignment(1, 0);
    suggestedGear.setVisible(true);
    suggestedGear.setAlignment(1, 0);
    shiftLamp.setAlignment(1, 0);
    pedals.setAlignment(0, 1);
    sideG.setVisible(true);
    sideG.setAlignment(2, 1);
    brakeLamp.setAlignment(2, 1);
    brakeLamp.setColor(0x800000C8);
    asmLamp.setAlignment(2, 1);
    asmLamp.setColor(0x80E3B896);
    tcsLamp.setAlignment(2, 1);
    tcsLamp.setColor(0x800000C8);
    active = false;
}
