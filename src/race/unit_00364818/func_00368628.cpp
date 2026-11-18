/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Engine/drivetrain step of the race car (unit 0x364818, called once per update by func_0036D818).
 * Inferred from the code only: it derives the drive-side angular speed from the gear ratios, runs a
 * three-state hysteresis on the record at car + 0x788 (mode from level * 8 + 0.5), computes the
 * drive torque from the accel curve (func_003685A0, func_00367FD8) or an assist torque when the
 * transmission type is 3 (func_003681E0), ramps the engine speed command (record + 0) toward its
 * target at 1047 or 524 rad/s^2 (5236 when starting from idle), sets the engine speed at +0x4FC of
 * the block at car + 0x104, integrates the 0..1 level at record + 4 from the power balance and
 * packs the state into the record's flag byte (bit 0, bits 1-2, bit 3, bits 4-5, as func_00368420
 * reads them). Returns the load torque plus the drive torque. Speeds are rad/s (0x1.acee9cp-4f is
 * pi/30, rpm to rad/s; w * 60 / 2pi back to rpm), 0x1.b7860ep-14f turns torque * rpm into power. */
#include "types.h"

struct Trans {
    char pad0[3];
    u8 ratioIndex;    /* 0x03 */
    char pad4[0x13 - 0x4];
    u8 type;          /* 0x13 */
    char pad14[0x40 - 0x14];
    f32 ratio[4];     /* 0x40 */
};

struct Spec {
    char pad0[0x202];
    u16 idleRpm;      /* 0x202 */
    char pad204[0x234 - 0x204];
    Trans trans;      /* 0x234 */
};

struct Drive {        /* the block at car + 0x104 */
    char pad0[0x488];
    f32 m488;
    f32 brakeInput;
    char pad490[4];
    f32 throttleInput;
    char pad498[0x4BC - 0x498];
    u8 m4BC;
    char pad4BD[3];
    f32 m4C0;
    char pad4C4[0x4E8 - 0x4C4];
    f32 m4E8;
    char pad4EC[0x4FC - 0x4EC];
    f32 engineW;      /* 0x4FC */
    char pad500[0x514 - 0x500];
    f32 m514;
    char pad518[0x520 - 0x518];
    u8 gear;
    char pad521[0x53C - 0x521];
    f32 speed;        /* 0x53C */
};

struct Record {       /* car + 0x788 */
    f32 targetW;
    f32 level;
    u8 flags;
    u8 mode;
};

struct Car {
    char pad0[0x10];
    Spec *spec;
    char pad14[0x54C - 0x14];
    f32 dt;           /* 0x54C */
    char pad550[0x630 - 0x550];
    f32 gearRatio[8]; /* 0x630 */
    char pad650[0x788 - 0x650];
    Record rec;       /* 0x788 */
};

extern "C" f32 func_003554A0(Car *car, f32 x);
extern "C" f32 func_00359568(const void *curve, f32 u);
extern "C" f32 func_00367FD8(Car *car, f32 w);
extern "C" f32 func_00368040(Car *car);
extern "C" f32 func_00368088(Car *car);
extern "C" f32 func_003680C0(Car *car);
extern "C" f32 func_003680F8(Car *car);
extern "C" f32 func_00368128(Car *car, f32 w, f32 p);
extern "C" f32 func_003681E0(f32 u, f32 x, f32 t);
extern "C" f32 func_003685A0(Drive *d, f32 a, f32 b);
extern const char D_00620CA0[];

static inline void setFlags(Record *r, u8 v) { r->flags = v; }

extern "C" f32 func_00368628(Car *car) {
    Drive *d = (Drive *)((char *)car + 0x104);
    Record *rec = &car->rec;
    Trans *tr = &car->spec->trans;
    f32 dt = car->dt;
    s32 reached = 0;
    s32 hold = 0;
    s32 stalled = 1;
    f32 idleW;
    f32 wheelW;
    s32 cut;
    f32 x;
    s32 engaged, low, kick;
    f32 kickTorque, kickExcess;
    f32 drive, accel;
    f32 torque, power;
    s32 locked, pos, neg, gauge;
    f32 scale, maxW, lo, mix, target;
    f32 cmd, upper, lower;
    s32 clipped;
    f32 w, rate;
    f32 load, out, extra, rest;
    f32 t;

    idleW = (f32)car->spec->idleRpm * 0x1.acee9cp-4f;
    if (d->m514 != 0.0f) {
        stalled = 0;
    }
    wheelW = car->gearRatio[tr->ratioIndex] * tr->ratio[d->gear];
    if (d->gear == 0) {
        wheelW = -wheelW;
    }
    cut = 0;
    if (stalled && d->brakeInput > 0x1.999998p-1f && d->m488 > 0.0f) {
        cut = 1;
    }

    x = rec->level * 8.0f + 0.5f;
    switch (rec->mode) {
    case 0:
        if (x < 0x1.8ccccc0000000p+2f) {
            rec->mode = 1;
        }
        break;
    case 1:
        if (x >= 0x1.b333320000000p+2f) {
            rec->mode = 0;
        } else if (x < 1.5f) {
            rec->mode = 2;
        }
        break;
    case 2:
        if (x >= 2.5f) {
            rec->mode = 1;
        }
        break;
    }
    engaged = rec->mode != 0;
    low = rec->mode == 2;

    kick = 0;
    if (tr->type == 3 && d->speed >= 0x1.c71c6ep-6f) {
        kick = 1;
    }
    if (d->gear == 0) {
        kick = 0;
    }
    kickTorque = 0.0f;
    kickExcess = 0.0f;
    if (kick) {
        kickTorque = func_003681E0(d->speed, d->throttleInput, 0x1.999998p-4f);
        if (kickTorque <= 0.0f) {
            kickExcess = 0.0f;
        } else {
            if (d->m4E8 * (d->engineW * 60.0f / 0x1.921fb4p+2f) * 0x1.b7860ep-14f < kickTorque) {
                f32 v = d->speed;
                f32 slip = 0.0f;
                if (!(v < 0.0f)) {
                    if (v < 0x1.638e36p+2f) {
                        slip = v * 0x1.200002p+2f;
                    } else {
                        slip = 25.0f;
                    }
                }
                kickExcess = kickTorque - slip;
                if (kickExcess < 0.0f) {
                    kickExcess = 0.0f;
                }
            } else {
                kickExcess = kickTorque;
            }
        }
    }

    accel = func_003685A0(d, d->throttleInput, d->speed);
    if (d->brakeInput > 0.0f && !stalled) {
        f32 a;
        drive = -d->brakeInput * 4.0f;
        a = wheelW;
        if (wheelW < 0.0f) {
            a = -wheelW;
        }
        a = a * 0x1.8723a6p-6f;
        if (a > 1.0f) {
            a = 1.0f;
        }
        drive *= a;
        if (drive < -1.0f) {
            drive = -1.0f;
        }
    } else {
        drive = accel;
        if (wheelW < 0.0f) {
            f32 k = (1.0f - wheelW / -0x1.a2e104p+7f) * 4.0f;
            if (k > 1.0f) {
                k = 1.0f;
            } else if (k < 0.0f) {
                k = 0.0f;
            }
            drive = accel * k;
        }
    }

    if (drive < 0.0f && wheelW < 0x1.acee9cp-4f && wheelW > -0x1.acee9cp-4f) {
        torque = 0.0f;
    } else {
        torque = func_00367FD8(car, wheelW) * drive;
    }
    if (cut) {
        torque = 0.0f;
    }
    if (d->m4BC) {
        torque = 0.0f;
    }
    if (kick) {
        torque = 0.0f;
    }
    power = torque * (wheelW * 60.0f / 0x1.921fb4p+2f) * 0x1.b7860ep-14f;
    if (wheelW < 0.0f) {
        power = -power;
    }

    locked = 0;
    pos = 0;
    if (!cut && torque > 0.0f) {
        pos = 1;
    }
    neg = 0;
    gauge = 0;
    if (torque < 0.0f) {
        neg = !stalled;
    }

    extra = 0.0f;
    maxW = func_00368040(car);
    lo = -0x1.a2e104p+6f;
    mix = 0.0f;
    scale = 0.0f;
    if (d->gear == 1) {
        scale = d->throttleInput;
    }
    target = maxW;
    if (cut) {
        locked = 1;
    } else {
        if (d->speed < 0.0f) {
            target = 0.0f;
        } else if (d->speed < 0x1.371c70p+4f && !kick && power < 10.0f) {
            target = 0.0f;
        } else if (kick) {
            target = func_00359568(D_00620CA0, kickExcess);
            if (maxW < target) {
                target = maxW;
            }
        } else {
            target = maxW * scale;
        }
    }
    if (d->speed >= 0x1.371c70p+4f && target < 0x1.a2e104p+6f) {
        target = 0x1.a2e104p+6f;
        if (!engaged) {
            lo = 0x1.a71158p+6f;
        } else {
            locked = 1;
            mix = target;
        }
    }
    if (target < idleW && !low) {
        target = 0.0f;
        if (d->m488 == 0.0f) {
            lo = 0x1.a71158p+6f;
        }
    }
    if (d->engineW < lo) {
        hold = 1;
    }
    if (engaged && !cut) {
        f32 base;
        mix = 0x1.a2e104p+7f;
        if (!low) {
            mix = 0x1.a2e104p+6f;
        }
        base = target;
        if (target < idleW) {
            locked = 1;
        }
        target += mix;
        if (maxW < target) {
            target = maxW;
            if (!low) {
                mix = target - base;
            }
        }
        hold = 0;
    }

    w = rec->targetW;
    cmd = target + (target - wheelW) * 2.5f;
    upper = func_00368088(car);
    lower = func_003680C0(car);
    clipped = 0;
    if (upper < cmd) {
        cmd = upper;
        clipped = 1;
    } else if (cmd < lower) {
        cmd = lower;
        clipped = 1;
    }
    t = d->engineW;
    if (clipped) {
        target = wheelW + (cmd - wheelW) / 3.5f;
        if (target < idleW) {
            target = 0.0f;
        }
        rate = 0.0f;
    } else {
        rate = 0.0f;
    }
    if (t < idleW && idleW <= target) {
        rate = 0x1.473fcap+12f;
    } else if (t <= idleW && target == 0.0f) {
        rate = 0x1.473fcap+12f;
    }
    if (w < cmd) {
        if (rate == 0.0f) {
            rate = 0x1.05cca2p+10f;
        }
        w += rate * dt;
        if (cmd < w) {
            w = cmd;
        }
    } else if (cmd < w) {
        if (rate == 0.0f) {
            rate = 0x1.05cca2p+9f;
        }
        w -= rate * dt;
        if (w < cmd) {
            w = cmd;
        }
    }
    rec->targetW = w;
    d->engineW = wheelW + (w - wheelW) / 3.5f;
    f32 maxRatio = 1.0f;
    if (idleW <= d->engineW) {
        reached = 1;
    }

    if (reached && !hold) {
        t = maxRatio;
        if (!kick) {
            t = target / 0x1.a2e104p+8f + 0.0f;
            if (t > maxRatio) {
                t = maxRatio;
            }
        }
        load = func_003554A0(car, t);
        if (!kick && accel * load < 0.0f) {
            load = 0.0f;
        }
        out = load * (d->engineW * 60.0f / 0x1.921fb4p+2f) * 0x1.b7860ep-14f;
    } else {
        load = 0.0f;
        out = load;
    }
    if (kick) {
        power = kickTorque - out;
    }
    d->m4C0 += func_00368128(car, d->engineW, out) * dt;

    extra = 0.0f;
    rest = extra;
    if (out > 0.0f) {
        if (locked) {
            if (kick) {
                extra = out;
                out = rest;
                load = 0.0f;
            } else {
                rest = load;
                load = 0.0f;
            }
        } else if (kick) {
            extra = out * mix / d->engineW;
            if (out < extra) {
                extra = out;
            } else if (extra < rest) {
                extra = 0.0f;
            }
            out -= extra;
        } else {
            rest = load * mix / d->engineW;
            if (load < rest) {
                rest = load;
            } else if (rest < extra) {
                rest = 0.0f;
            }
            load -= rest;
            rest = rest + load / 3.5f;
        }
        if (kick) {
            power += extra;
        } else if (rest > 0.0f) {
            extra = rest * (d->engineW * 60.0f / 0x1.921fb4p+2f) * 0x1.b7860ep-14f;
        }
    }
    if (reached && !locked) {
        if (kick) {
            f32 rpm = wheelW * 60.0f / 0x1.921fb4p+2f;
            if (rpm < 100.0f) {
                load = 0.0f;
            } else {
                load = out / (rpm * 0x1.b7860ep-14f);
            }
        } else {
            load = load * 2.5f / 3.5f;
        }
    }
    if (kick) {
        if (extra > 0.0f) {
            gauge = 1;
        }
        if (kickTorque > 0.0f && out > 0.0f) {
            gauge = 1;
        }
    } else if (rest > 0.0f) {
        gauge = 1;
    }
    if (low && extra < power) {
        f32 r = extra / power;
        if (r < 0.0f) {
            r = -r;
        }
        torque *= r;
        power = extra;
    }
    if (kick) {
        f32 t = func_00367FD8(car, wheelW);
        f32 rpm = wheelW * 60.0f / 0x1.921fb4p+2f;
        f32 k = rpm * 0x1.b7860ep-14f;
        f32 m = t * k;
        if (m < 0.0f) {
            m = -m;
        }
        if (m < power) {
            power = m;
            torque = t;
        } else if (power < -m) {
            power = -m;
            torque = -t;
        } else if (rpm > -0x1.acee9cp-4f && rpm < 0x1.acee9cp-4f) {
            if (power >= 0.0f) {
                torque = t;
            } else {
                torque = -t;
            }
        } else {
            torque = power / k;
        }
    }
    extra -= power;
    extra = extra * 1000.0f / func_003680F8(car);
    extra = dt * extra / 23400.0f;
    rec->level += extra;
    if (rec->level > 1.0f) {
        rec->level = 1.0f;
    } else if (rec->level < 0.0f) {
        rec->level = 0.0f;
    }
    if (kick) {
        if (!cut && power > 0.0f) {
            pos = 1;
        }
        if (power < 0.0f && !stalled) {
            neg = 1;
        }
    }
    if (hold) {
        reached = 0;
    }
    rec->flags = 0;
    if (cut) {
        setFlags(rec, 1);
    } else if (reached && !locked && load > 0.0f && kickTorque > 0.0f) {
        setFlags(rec, 1);
        pos = 1;
    }
    if (cut) {
        rec->flags |= 4;
    } else if (pos) {
        rec->flags |= 4;
    } else if (neg && kickTorque < 0.0f) {
        rec->flags |= 2;
    }
    if (gauge || rec->mode) {
        rec->flags |= 8;
    }
    if (extra > 0.0f) {
        rec->flags |= 0x10;
    } else if (extra < 0.0f) {
        rec->flags |= 0x20;
    }
    return load + torque;
}
