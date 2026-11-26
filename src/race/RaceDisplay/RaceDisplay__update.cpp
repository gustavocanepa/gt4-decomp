/* compiler: ee-gcc2.96-no-strict-aliasing */
/* RaceDisplay::update(float) (GT HD name; vtable slot 1). The in-race HUD's per-frame update:
 * initialises the display on first use, fades the tooltip with the race monitor (+0xC), rebuilds
 * the information message when the monitor's message changes, refreshes the time/lap/rank
 * elements and the race events queued on the organisation (events 10 and 9), feeds the meter
 * panel at +0x14 (speed, temperature, rpm, gear, boost, odometer, tire-wear colours by drive
 * layout, and the energyMonitor energy/charge values of the Toyota Prius panel), the energy monitor at
 * +0x3B4C (func_00368420's flag byte, see func_00368628) and updates the message, icon, logo,
 * tooltip and music elements. Field names other than the GT HD ones are inferred from the code.
 * The panel's byte fields are written through small inline setters taking an int, as retail's
 * word loads of the colour tables show; tooltip's address is formed in several places and gcse
 * merges it into the spilled pointer retail keeps at sp+0x20. */
#include "types.h"

union Flags {
    u32 word;
    u8 byte[4];
};

class PanelBase {
public:
    char pad0[0x14];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void update(f32 dt);                    /* 9 */
    virtual void slot10();
    virtual void slot11();
    virtual void setTemperature(f32 v);             /* 12 */
    virtual void slot13();
    virtual void setSpeed(f32 v);                   /* 14 */
    virtual void slot15();
    virtual void slot16();
    virtual void setRpm(f32 v);                     /* 17 */
    virtual void setGear(s32 v);                    /* 18 */
    virtual void setShift(s32 v);                   /* 19 */
    virtual void slot20(s32 v);                     /* 20 */
    virtual void setLamp(s32 v);                    /* 21 */
    virtual void slot22();
    virtual void setMode(s32 v);                    /* 23 */
    virtual void setFlag(s32 v);                    /* 24 */
    virtual void slot25();
    virtual void setBoost(f32 v);                   /* 26 */
    virtual void setOdometer(u32 v);                /* 27 */
    virtual void setTireWearAvailable(s32 v);       /* 28 */
    virtual void setTireColor(s32 i, u8 r, u8 g, u8 b); /* 29 */
    virtual void setEnergy0(f32 v);                 /* 30 */
    virtual void setEnergy1(f32 v);                 /* 31 */
    virtual void setCharge1(f32 v);                 /* 32 */
    virtual void setCharge0(f32 v);                 /* 33 */
    virtual void setFuel(f32 v);                    /* 34 */
    virtual void setConsumption(f32 v);             /* 35 */
};

class Panel : public PanelBase {
public:
    Flags flags18;
    Flags flags1C;
    s8 b20;
    s8 b21;
    s8 b22;
    char pad23;
    f32 f24;
    f32 f28;

    void setF24(f32 v) { f24 = v; }
    void setF28(f32 v) { f28 = v; }
    void setTireMode(s32 v) { flags18.word = (flags18.word & 0xFFFF00FF) | (v << 8); }
    void setBoostCount(s32 v) { flags18.word = (flags18.word & 0xFFFFFF) | (v << 24); }
    void setCharging(s32 v) { flags1C.word = (flags1C.word & ~0xFF) | v; }
    void setWearColor(s32 c) { flags1C.byte[3] = c; }
    void setWearPeakColor(s32 c) { flags1C.byte[2] = c; }
    void setGauge20(s32 c) { b20 = c; }
    void setGauge21(s32 c) { b21 = c; }
    void setGauge22(s32 c) { b22 = c; }
};

struct Monitor {
    char pad0[0x28];
    s32 mode;
    char pad2C[4];
    s32 active;
    char pad34[0x84 - 0x34];
    f32 rate;
    char pad88[0xA8 - 0x88];
    Flags flagsA8;
};

struct Car14 { char pad0[0x40]; s8 b40; s8 b41; };

struct Automobile {
    char pad0[0x14];
    Car14 c14;
    char pad56[0x624 - 0x56];
    u8 m624;
    char pad625[0x6C8 - 0x625];
    f32 m6C8;
    char pad6CC[0x6DC - 0x6CC];
    char odo[4];
};

struct Entry { char pad0[0x18]; Automobile *car; };
struct EntryList { char pad0[8]; Entry **entries; };
struct Queue { char pad[4]; };

struct Organization {
    char pad0[0x60];
    EntryList *list;
    char pad64[0xC4 - 0x64];
    s32 mC4;
    f32 mC8;
    char padCC[0xF4 - 0xCC];
    Queue queue;
    char padF8[0x906 - 0xF8];
    u8 nEvents;
    char pad907[0x916 - 0x907];
    u8 m916;
    char pad917[0x920 - 0x917];
    f32 m920;
    char pad924[0x968 - 0x924];
    s32 m968;

    s32 activeCount() const { return m916; }
};

struct Fader { f32 value; };
struct Msg { char pad[0xC]; f32 alpha; char pad10[0x150 - 0x10]; };
struct Tip {
    char pad[0xC];
    f32 alpha;
    void setAlpha(f32 a) { alpha = a; }
};
struct Gauge { char pad0[0xC]; f32 alpha; char pad10[0xC]; f32 angle; };
struct Hybrid { char pad0[0x20]; f32 level; Flags flags; };
struct Lamp { Flags flags; char pad4[0x1C]; f32 a; f32 b; };
struct Global { char pad[0x39DF4]; s32 m39DF4; };

class RaceDisplayVBase {
public:
    virtual void cleanup();
    virtual void update(f32 dt);
    virtual void render(void *);
    virtual void DMAsafe();
    virtual void setOrganization(void *);
    virtual void setRaceMonitor(void *);
    virtual void setRaceMode(s32);
    virtual void setRunMode(s32);
    virtual void initialize();                                  /* 8 */
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void update_rank(f32 dt, Organization &org);        /* 25 */
    virtual void update_automobile_message(Automobile &car);    /* 26 */
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35();
    virtual void onRaceEvent10(Organization &org);                  /* 36 */
    virtual void onRaceEvent9(Organization &org);                   /* 37 */
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52();
    virtual void clear();                                       /* 53 */
};

class RaceDisplay : public RaceDisplayVBase {
public:
    virtual void cleanup();     /* defined elsewhere: the vtable is the original's data */
    virtual void update(f32 dt);
    bool isReplay() const { return m20 >= 2; }

    Organization *org;
    char pad8[4];
    Monitor *monitor;
    char *tireWear;
    Panel *panel;
    char pad18[8];
    u32 m20;
    char pad24[0x2E - 0x24];
    s8 carIndex;
    char pad2F;
    s8 m30;
    char pad31[2];
    u8 m33;
    char pad34[0x3E - 0x34];
    u8 initialized;
    u8 m3F;
    Flags flags40;
    Flags flags44;
    char m48[4];
    s32 m4C;
    char pad50[0xBC - 0x50];
    Fader fader;
    char padC0[0x10E4 - 0xC0];
    Gauge slipGauge;
    char pad1104[0x1300 - 0x1104];
    char lapCount[0x1584 - 0x1300];
    s32 m1584;
    char pad1588[0x1740 - 0x1588];
    f32 m1740;
    char pad1744[0x17B0 - 0x1744];
    f32 m17B0;
    char pad17B4[4];
    f32 m17B8;
    char pad17BC[0x228C - 0x17BC];
    Msg message;
    char pad23DC[0x2D78 - 0x23DC];
    Lamp energyLamp;
    char pad2DA0[0x2DA0 - 0x2D78 - sizeof(Lamp)];
    Tip tooltip;
    char pad2DB0[0x3B4C - 0x2DB0];
    Hybrid energyMonitor;
};

extern Global *D_00622F4C;
extern char PDISTD__UNIT_MANAGER[];
extern const s32 D_006A0690[];
extern const s32 D_006A06A0[];

extern "C" {
void func_0039BBE0();
void func_0039BCA8(RaceDisplay *);
void func_0039BD50(RaceDisplay *);
void func_0039CDA8(RaceDisplay *, s32, f32);
void func_0039E9B0(RaceDisplay *);
void func_0039EC40(RaceDisplay *);
void func_0039ECD0(RaceDisplay *, Entry *);
void func_0039EE78(RaceDisplay *);
s8 func_0039F0C0(RaceDisplay *, s32);
void RaceDisplayGeneralTimeEvent__structor_2(RaceDisplay *, Organization *, s32);
void RaceDisplayGeneralTimeEvent__structor_3(RaceDisplay *, Organization *, s32);
void RaceDisplayLapDiffEvent__structor_1(RaceDisplay *, Organization *, s32);
void RaceDisplayTimeDiffEvent__structor_1(RaceDisplay *, Organization *, s32);
void func_003A0600(RaceDisplay *, Organization *, s32);
void func_003A06B0(RaceDisplay *, Organization *);
void func_003A0900(RaceDisplay *, Organization *);
void func_003A1330(RaceDisplay *);
s32 RaceDisplay__is_play_mode(RaceDisplay *);
void GTMiniLogo__update(void *);
void RaceMessageDisplay__update(void *, f32);
void RaceMessageDisplay__setMessage(void *, s32, f32, f32);
void RaceEventDisplay__clear(void *, f32);
void RaceEventDisplay__update(void *, f32);
void RaceCarIconDisplay__update(void *, f32);
void AutomaticFader__update(Fader *, f32);
void func_003AA850(Hybrid *, s32);
void func_003AA8D0(Hybrid *, s32);
void func_003AA9B8(Hybrid *, s32);
void func_003AAA38(Hybrid *, s32);
void RaceRichCountDisplay__setCount(void *, s32);
void RaceTooltipDisplay__update(Tip *, f32);
void RaceMusicDisplay__virtual_09(void *, f32);
s32 RaceEventQueue__get(Queue *, s32, void *, s32);
s32 RaceEventQueue__check(Queue *, s32, void *, s32);
void func_003BEE58(void *, f32);
s32 func_003D8B48(Monitor *);
void func_003DD7D8(f32 *, f32);
u32 func_003434C8(void *);
s32 Automobile__GetExplicitCurrentLap(Automobile *);
s32 func_00343BE0(Automobile *);
s32 func_00344630(Automobile *);
s32 func_00344638(Automobile *);
s32 func_00344640(Automobile *);
s32 func_00344658(Automobile *);
f32 func_00344680(Automobile *, void *);
f32 func_00344698(Automobile *);
f32 func_003446A0(Automobile *);
f32 func_003446B0(Automobile *);
void Automobile__GetTireWearGaugeColor(Automobile *, s32, u8 *, u8 *, u8 *);
f32 func_003451B0(Automobile *);
s32 func_003451D8(Automobile *);
s32 func_00350F30(Automobile *);
s32 func_00354E38(Automobile *);
f32 func_00354E58(Automobile *);
f32 func_00354E60(Automobile *);
s32 func_00354E68(Automobile *);
f32 func_00354E98(Automobile *);
f32 func_00354EA8(Automobile *);
u8 *func_00359538(Automobile *);
s32 func_0035BEB0(Automobile *);
s32 TireWearParameters__isAvailable(void *);
s32 func_003683A8(Automobile *);
void func_00368420(Automobile *, s8 *);
s32 func_00368498(Automobile *);
s32 func_003684E8(Automobile *);
f32 ToyotaPrius_GetGasConsumption(Automobile *);
s32 func_003F3758(Automobile *);
f32 func_00472940(char *, f32);
}

void RaceDisplay::update(f32 dt) {
    Organization *org;
    s32 index;
    Entry *entry;
    Automobile *car;

    if (!initialized) {
        initialize();
    } else if (m3F) {
        func_0039BBE0();
    }
    func_0039EC40(this);
    if (!flags40.byte[0]) {
        flags40.word = (flags40.word & ~0xFF) | 1;
        func_0039BD50(this);
    }
    Fader *fader = &this->fader;
    if (monitor) {
        monitor->rate = fader->value;
        s32 mode = monitor->mode;
        if (monitor->active) {
            switch (mode) {
            case 0:
                func_0039CDA8(this, 0, 0.25f);
                clear();
                break;
            case 1:
                break;
            case 2:
                func_0039CDA8(this, 1, 0.25f);
                clear();
                break;
            }
        }
        tooltip.setAlpha(monitor->mode == 1 ? 1.0f : monitor->rate);
    }

    if (flags44.byte[0]) {
        flags44.word &= ~0xFF;
        RaceEventDisplay__clear((char *)this + 0x2F2C, 0.1f);
        RaceMessageDisplay__setMessage((char *)this + 0x2DDC, m4C, 0.0f, 0.0f);
        if (!m4C && monitor) {
            RaceMessageDisplay__setMessage((char *)this + 0x2DDC, func_003D8B48(monitor), 0.0f, 0.0f);
        }
    } else if (!m4C && monitor) {
        s32 changed = 1;
        if (monitor->flagsA8.byte[1]) {
            monitor->flagsA8.word &= 0xFFFF00FF;
        } else {
            changed = 0;
        }
        if (changed) {
            RaceEventDisplay__clear((char *)this + 0x2F2C, 0.1f);
            RaceMessageDisplay__setMessage((char *)this + 0x2DDC, func_003D8B48(monitor), 0.0f, 0.0f);
        }
    }

    org = this->org;
    index = carIndex;
    RaceDisplayGeneralTimeEvent__structor_2(this, org, index);
    m1584 = org->m968;
    RaceDisplayGeneralTimeEvent__structor_3(this, org, index);
    if (RaceDisplay__is_play_mode(this)) {
        flags44.byte[3] <<= 1;
        if (org->activeCount() > 0) {
            flags44.byte[3] |= 1;
        }
        if (flags44.byte[3] == 1) {
            func_003A1330(this);
        }
    }
    RaceDisplayLapDiffEvent__structor_1(this, org, index);
    RaceDisplayTimeDiffEvent__structor_1(this, org, index);
    func_003A0600(this, org, index);
    func_003A06B0(this, org);
    func_003A0900(this, org);
    func_0039E9B0(this);
    {
        void *event;
        s32 i;
        s32 n = org->nEvents;
        for (i = 0; i < n; i++) {
            if (RaceEventQueue__check(&org->queue, 10, &event, i)) {
                onRaceEvent10(*org);
            }
        }
        if (RaceEventQueue__get(&org->queue, 9, 0, 0)) {
            onRaceEvent9(*org);
        }
    }
    if (m33 != D_00622F4C->m39DF4) {
        func_0039BCA8(this);
    }
    entry = org->list->entries[carIndex];
    car = entry->car;
    if (!org->mC4 || (s32)org->mC8 >= 60) {
        update_automobile_message(*car);
    }
    {
        Msg *m = &message;
        RaceMessageDisplay__update(m, dt);
        m->alpha = fader->value;
    }
    update_rank(dt, *org);
    RaceRichCountDisplay__setCount(lapCount, Automobile__GetExplicitCurrentLap(car));
    func_0039ECD0(this, entry);
    AutomaticFader__update(fader, dt);
    if (panel) {
        s32 wear;
        Car14 *c14 = &car->c14;
        panel->update(dt);
        panel->setSpeed((f32)func_00350F30(car));
        panel->setTemperature(func_00472940(PDISTD__UNIT_MANAGER, car->m6C8));
        panel->setRpm(func_003446B0(car));
        panel->setGear(car->m624);
        panel->setMode(c14->b40);
        panel->setShift(func_00343BE0(car));
        panel->setLamp(func_003F3758(car) != 0);
        { s32 f = c14->b41 != 0; panel->setFlag(f); }
        panel->setBoost(-func_003451B0(car) * 0x1.a1f58ep-4f);
        panel->setF24(func_00344698(car));
        panel->setF28(func_003446A0(car));
        {
            s32 odo = func_003434C8(car->odo) / 10;
            panel->setOdometer(odo > 999999 ? 999999 : odo);
        }
        func_00344658(car);
        wear = func_00344630(car);
        panel->setWearColor(D_006A0690[wear]);
        if (wear < func_00344638(car)) {
            wear = func_00344638(car);
        }
        panel->setWearPeakColor(D_006A0690[wear]);
        panel->setGauge20(D_006A06A0[func_00344640(car)]);
        panel->setGauge21(func_00354E68(car) ? 3 : 0);
        panel->setGauge22(D_006A06A0[func_00344658(car)]);
        if (func_003451D8(car)) {
            s32 tires;
            s32 boost;
            f32 charge;
            panel->setTireMode(1);
            tires = TireWearParameters__isAvailable(tireWear + 4);
            panel->setTireWearAvailable(tires);
            if (tires) {
                s32 i;
                switch (*func_00359538(car)) {
                case 0: {
                    u8 r, g, b;
                    for (i = 0; i < 4; i++) {
                        Automobile__GetTireWearGaugeColor(car, i, &r, &g, &b);
                        panel->setTireColor(i, r, g, b);
                    }
                    break;
                }
                case 2: {
                    u8 r, g, b;
                    for (i = 0; i < 4; i++) {
                        Automobile__GetTireWearGaugeColor(car, i < 2 ? 0 : i - 1, &r, &g, &b);
                        panel->setTireColor(i, r, g, b);
                    }
                    break;
                }
                case 3: {
                    u8 r, g, b;
                    for (i = 0; i < 4; i++) {
                        Automobile__GetTireWearGaugeColor(car, i < 3 ? i : 2, &r, &g, &b);
                        panel->setTireColor(i, r, g, b);
                    }
                    break;
                }
                case 1: {
                    u8 r, g, b;
                    for (i = 0; i < 4; i++) {
                        Automobile__GetTireWearGaugeColor(car, i >> 1, &r, &g, &b);
                        panel->setTireColor(i, r, g, b);
                    }
                    break;
                }
                }
            }
            boost = func_00354E38(car);
            panel->setBoostCount(boost);
            if (boost) {
                panel->setEnergy0(func_00354E60(car));
                panel->setEnergy1(func_00354E58(car));
            }
            charge = func_00354E98(car);
            {
                s32 on = 1;
                if (!(charge > 0.0f)) {
                    on = 0;
                }
                panel->setCharging(on);
                if (on) {
                    panel->setCharge0(charge);
                    panel->setCharge1(func_00354EA8(car));
                }
            }
        } else {
            panel->setTireMode(0);
            panel->setTireWearAvailable(0);
            panel->setBoostCount(0);
            panel->setCharging(0);
        }
        panel->setFuel((f32)func_003684E8(car) * 0.1f);
        panel->setConsumption(ToyotaPrius_GetGasConsumption(car));
    }
    {
        Lamp *lamp = &energyLamp;
        s32 on;
        func_003DD7D8(&m17B8, car->m6C8);
        m1740 = org->m920;
        m17B0 = m17B8;
        on = func_0035BEB0(car) == 1;
        lamp->flags.word = (lamp->flags.word & ~0xFF) | on;
        if (on) {
            lamp->a = func_00354E60(car);
            lamp->b = func_00354E58(car);
        }
    }
    {
        f32 slip = func_00344680(car, m48);
        if (slip != 0.0f) {
            flags44.word = (flags44.word & 0xFF00FFFF) | 0x10000;
        }
        Gauge *g = &slipGauge;
        g->angle = slip * -90.0f;
        g->alpha = fader->value;
    }
    if (func_003683A8(car)) {
        {
            Hybrid *h = &energyMonitor;
            s8 state[4];
            h->flags.word = (h->flags.word & ~0xFF) | 1;
            func_00368420(car, state);
            func_003AA850(h, state[0]);
            func_003AA8D0(h, state[1]);
            func_003AA9B8(h, state[2]);
            func_003AAA38(h, state[3]);
            h->level = (f32)func_00368498(car) * 0.125f;
        }
    }
    RaceMessageDisplay__update((char *)this + 0x23DC, dt);
    RaceMessageDisplay__update((char *)this + 0x291C, dt);
    func_003BEE58((char *)this + 0x1108, dt);
    if (dt > 0.0f) {
        RaceCarIconDisplay__update((char *)this + 0x2D14, dt);
        GTMiniLogo__update((char *)this + 0x1170);
        RaceEventDisplay__update((char *)this + 0x17BC, dt);
        RaceMessageDisplay__update((char *)this + 0x252C, dt);
        RaceMessageDisplay__update((char *)this + 0x267C, dt);
        RaceMessageDisplay__update((char *)this + 0x27CC, dt);
        RaceMessageDisplay__update((char *)this + 0x2A6C, dt);
        RaceMessageDisplay__update((char *)this + 0x2BBC, dt);
        RaceMessageDisplay__update((char *)this + 0x11B0, dt);
    }
    RaceTooltipDisplay__update(&tooltip, dt);
    RaceMusicDisplay__virtual_09((char *)this + 0x3EEC, dt);
    if (isReplay()) {
        func_0039EE78(this);
    }
    m30 = func_0039F0C0(this, 1);
}
