/* compiler: ee-gcc2.96-no-strict-aliasing */
/* The AI driver's per-frame controller (inferred): picks the point to aim at on the racing line
 * (plus lateral offsets from the tuning block at 0x623E50), chooses forward or reverse with a hold
 * timer, steers with a PID-like controller, then sets throttle and brake from the speed mode.
 * Field meanings are inferred from use. */

struct Body {
    char pad0[0x32];
    unsigned char layout;
    char pad33[0x54 - 0x33];
    float maxSteer;
};
struct WheelSlot {
    float load;
    char pad4[0x59 - 0x4];
    unsigned char tire;
    char pad5A[0xEC - 0x5A];
};
struct CarState {
    float x, y;
    char pad8[0x18 - 0x8];
    float dirX, dirY;
    char pad20[0x90 - 0x20];
    WheelSlot wheels[4];
    unsigned char slot;
    char pad441[0x448 - 0x441];
    float dt;
    float damping;
    char pad450[0x466 - 0x450];
    signed char control;
    unsigned char phase;
    char pad468[0x46C - 0x468];
    float yawRate;
    float slip;
    char pad474[0x484 - 0x474];
    float steerRate;
    char pad488[0x4A4 - 0x488];
    float distance;
    char pad4A8[0x4AF - 0x4A8];
    signed char aggression;
    char pad4B0;
    unsigned char flags;
    char pad4B2[0x4BA - 0x4B2];
    unsigned short wait;
    unsigned char active;
    char pad4BD[0x520 - 0x4BD];
    unsigned char gear;
    char pad521;
    unsigned char reversing;
    char pad523[0x53C - 0x523];
    float speed;
    char pad540[0x544 - 0x540];
    float velX, velY;
    char pad54C[0x560 - 0x54C];
    float drive;
    char pad564[0x570 - 0x564];
    float yaw;
    char pad574[0x57C - 0x574];
    float curveLimit;
    char pad580[0x58C - 0x580];
    float lateralSlip;
    char pad590[0x61C - 0x590];
    float targetX, targetY;
};
struct Tire { char pad[0x34]; };
struct Car {
    char pad0[0x10];
    Body *body;
    char pad14[0x104 - 0x14];
    CarState state;
    char pad728[0x7B8 - 0x728];
    Tire tires[4];
};
struct Slot { char pad0[0xC]; char status[0x4F0 - 0xC]; };
struct Grid { Slot slots[6]; };
struct Rules { char pad0[0x42]; unsigned char limit[2]; char pad44[0x60 - 0x44]; };
struct Race {
    char pad0[0xCBE1];
    unsigned char finished;
    char padCBE2[0xDA6C - 0xCBE2];
    Grid grid;
    char padF80C[0xF818 - 0xF80C];
    Rules rules;
    short handicap[8];
};
struct Params {
    char pad0[0xC];
    float steerGain;
    float slipThrottle;
    float slipBrake;
    char pad18[0x5C - 0x18];
    float boost;
    float maxRate;
    float slowSpeed;
    int boostDelay;
    char pad6C[0x78 - 0x6C];
    unsigned char cornerBoost;
    char pad79[0x7C - 0x79];
    float cornerAngle;
    float cornerGain;
};
struct Driver {
    float history[5];
    char pad14[0x18 - 0x14];
    short timer;
    unsigned char launched;
    unsigned char direction;
    unsigned char line;
    unsigned char lineStart;
    unsigned char speedMode;
    char pad1F;
    unsigned char limited;
    unsigned char otherLine;
    unsigned short hold;
    float cruise;
    float cap;
    float lineBlend;
    float steer;
    float throttle;
    float brake;
    char pad3C[0x3E - 0x3C];
    unsigned char reverseLatch;
    char pad3F[0x43 - 0x3F];
    signed char tireState;
    char pad44[0x51 - 0x44];
    signed char rival;
    unsigned char countdown;
    char pad53;
    float offset;
    float gapLeft;
    float gapRight;
    char pad60[0x6B - 0x60];
    unsigned char directionHold;
    char pad6C[0xE4 - 0x6C];
    Race *race;
    Car *car;
    void *course;
};
struct Tuning {
    char pad0[0x2];
    unsigned char feedback;
    char pad3;
    unsigned char blendLimit;
    unsigned char offsets;
    char pad6[0x8 - 0x6];
    unsigned char slipLimit;
    char pad9[0x10 - 0x9];
    float kBase, kCurve, kHeading, kLateral, kYaw;
    char pad24[0x2C - 0x24];
    float kRate;
    float dBase, dCurve, dHeading, dLateral, dYaw;
    char pad44[0x5C - 0x44];
    float maxLateral;
    char pad60[0x74 - 0x60];
    float blendRate;
    float lineGain, pitGain;
    float offsetRate;
    float maxOffset;
    float slipMin, slipMax;
};
struct Info { unsigned char pad0; unsigned char count; char pad2[0x1C - 0x2]; unsigned char kind[4]; };
struct Axles { unsigned char pad0; unsigned char count; char pad2[0x3C - 0x2]; signed char used[4]; };
struct Grip { float value; char pad4[0xB8 - 0x4]; float limit; };
struct Rival { char pad0[0x640]; float speed; };
struct Record { char pad0[0x14]; float distance; };
struct View {
    unsigned char mode, stride;
    short unknown;
    int count;
    void *data;
    View(void *, int) __asm__("func_00469F08");
};

extern "C" Tuning D_00623E50;
extern "C" unsigned char D_00620DE7;
extern "C" void func_00464ED8(Driver *) throw();
extern "C" void func_00464C80(Driver *, float) throw();
extern "C" Params *func_00463BB8(Driver *) throw();
extern "C" float func_00463EA8(Driver *) throw();
extern "C" int func_00463E98(Driver *) throw();
extern "C" int func_0045CC40(char *);
extern "C" int func_0045CC48(char *);
extern "C" int func_0045CC50(char *);
extern "C" float func_0057D2B8(float);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D118(float, float);
extern "C" float func_0036CC40(float, float);
extern "C" float func_00464E88(Params *, float) throw();
extern "C" int func_00358418(Race *);
extern "C" float func_00464868(void *, CarState *, int, int, float, float *, float *) throw();
extern "C" float func_004649F0(void *, int, int, float *, float *, float *, float) throw();
extern "C" int func_0034C998(Race *);
extern "C" Info *func_00359538(Car *);
extern "C" int func_003F4EA0(Tire *);
extern "C" Axles *func_00359510(Body *);
extern "C" Grip *func_00360F80(Body *, int, int);
extern "C" void func_00464BB0(Driver *, float) throw();
extern "C" void func_00464770(Driver *, float, float) throw();
extern "C" Rival *func_0034C190(Race *, int);
extern "C" float func_0046A0B0(void *);
extern "C" Record *func_00469FC8(View *, int);
extern "C" void func_00469AE8(Driver *);
extern "C" float func_003F76E8(Car *, float);

static inline float fraction(unsigned long n) { return (float)(unsigned char)n * 0x1.111110p-5f; }
static inline WheelSlot *wheel(Car *car, int i) { return &car->state.wheels[i]; }
static inline float root(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float approach(float *value, float target, float dt, float rate) {
    float current = *value;
    float step = rate * dt;
    if (current < target) {
        float next = current + step;
        *value = next;
        current = target < next ? (*value = target) : next;
    } else if (target < current) {
        float next = current - step;
        *value = next;
        current = next < target ? (*value = target) : next;
    }
    return current;
}
static inline int axleCount(Axles *axles) { return axles->count; }
static inline int axleUsed(Axles *axles, int i) { return i < axleCount(axles) && axles->used[i] > 0; }

static inline bool isRight(Info *info, int i) { return info->kind[i] == 1; }
static inline int usedBelow(Axles *a, int i, short count) { return i < count && a->used[i] > 0; }
static inline bool isLeft(Info *info, int i) { return info->kind[i] == 0; }
extern "C" void func_00465078(Driver *self) {
    float x0, y0, x1, y1, x2, y2;
    Race *race;
    void *course;
    Params *params;
    int dir;
    int brake;
    float scale;
    float overshoot;
    int keep;
    int ahead, behind, beside;
    int sign;
    CarState *s;

    scale = 1.0f;
    s = &self->car->state;
    keep = 0;
    race = self->race;
    course = self->course;
    if ((unsigned)((unsigned char)s->control - 1) < 2) keep = s->active != 0;
    if (keep) scale = self->throttle;
    func_00464ED8(self);
    if (keep) self->throttle = scale;
    if (s->phase == 7) {
        func_00464C80(self, 0.0f);
        return;
    }

    float target = 5.0f;
    Grid *grid = &race->grid;
    params = func_00463BB8(self);
    scale = func_00463EA8(self);
    dir = 0;
    brake = 0;
    overshoot = 0.0f;
    ahead = func_0045CC40(grid->slots[s->slot].status);
    behind = func_0045CC48(grid->slots[s->slot].status);
    beside = func_0045CC50(grid->slots[s->slot].status);
    float negSin = -func_0057D2B8(s->yaw);
    float cosYaw = func_0057D1F0(s->yaw);
    unsigned char phase = s->phase;
    if (phase != 3) {
        if (phase == 4 && self->limited) {
            target = 10.0f;
            if (s->speed < 0x1.0aaaa8p+3f) target = 5.0f;
        } else if (func_00463E98(self)) {
            target = 40.0f;
            if (self->direction == 1) target = 10.0f;
        } else {
            target = func_00464E88(params, s->speed);
            int far = 1;
            if (self->launched) {
                far = 0;
                if (s->speed >= 0x1.0aaaa8p+3f) self->launched = 1;
            }
            if (far) {
                int gap = 5000 - func_00358418(race);
                short *h = race->handicap;
                gap += h[s->slot] * 1000;
                if (gap > 0) target += gap * 200.0f / 5000.0f;
            } else {
                int gap = 2000 - func_00358418(race);
                short *h = race->handicap;
                gap += h[s->slot] * 1000;
                if (gap > 0) target += gap * 40.0f / 2000.0f;
            }
            if (self->countdown) target += self->countdown * 0x1.555554p-2f;
        }
    }

    float offset = 0.0f;
    target = func_00464868(course, s, self->line, self->lineStart, target, &x0, &y0);
    if (self->lineBlend > 0.0f) {
        func_00464868(course, s, self->otherLine, self->lineStart, target, &x1, &y1);
        if (D_00623E50.blendLimit == 1) {
            float dx = x0 - x1;
            float dy = y0 - y1;
            float step = D_00623E50.blendRate * self->car->state.dt;
            float d = root(dx * dx + dy * dy);
            if (d < step) {
                self->lineBlend = 0.0f;
            } else {
                float blend = self->lineBlend - step / d;
                self->lineBlend = blend;
                if (blend < 0.0f) self->lineBlend = 0.0f;
            }
        }
        float blend = self->lineBlend;
        x0 += (x1 - x0) * blend;
        y0 += (y1 - y0) * blend;
    }
    if (D_00623E50.offsets && !func_00463E98(self)) {
        offset = 0.0f;
        if ((unsigned char)(D_00623E50.offsets & 1)) {
            func_00464868(course, s, self->line, self->lineStart, 0.0f, &y1, &x1);
            if (self->lineBlend != 0.0f) {
                func_00464868(course, s, self->otherLine, self->lineStart, 0.0f, &x2, &y2);
                float blend = self->lineBlend;
                y1 += (x2 - y1) * blend;
                x1 += (y2 - x1) * blend;
            }
            float along = func_0057D1F0(s->yaw) * y1;
            float side = along + func_0057D2B8(s->yaw) * x1;
            float gain = D_00623E50.lineGain;
            if ((unsigned char)(self->line - 3) < 2) gain = D_00623E50.pitGain;
            offset = gain * side + offset;
        }
        if ((D_00623E50.offsets & 2) && self->line != 4) {
            float push = 0.0f;
            if (self->gapLeft < 2.0f) push = (2.0f - self->gapLeft) + push;
            if (self->gapRight < 2.0f) push -= 2.0f - self->gapRight;
            offset += push;
        }
        if (!func_0034C998(self->race) && (D_00623E50.offsets & 4) && (!self->speedMode || !self->tireState)) {
            Car *car = self->car;
            int right = 0;
            int left = 0;
            int i = 0;
            Info *info = func_00359538(car);
            for (; i < info->count; i++) {
                if (func_003F4EA0(&car->tires[i])) {
                    if (isLeft(info, i)) left = 1;
                    else if (isRight(info, i)) right = 1;
                }
            }
            int side = left - right;
            if (side) offset += side * 0.5f;
        }
        float limit = D_00623E50.maxOffset;
        if (D_00623E50.slipLimit) {
            float slip = s->lateralSlip;
            if (slip < 0.0f) slip = -slip;
            if (D_00623E50.slipMax <= slip) limit = 0.0f;
            else if (D_00623E50.slipMin < slip)
                limit = (D_00623E50.slipMax - slip) / (D_00623E50.slipMax - D_00623E50.slipMin);
        }
        if (offset < -limit) offset = -limit;
        else if (limit < offset) offset = limit;
        offset = approach(&self->offset, offset, self->car->state.dt, D_00623E50.offsetRate);
        x0 += offset * s->dirX;
        y0 += offset * s->dirY;
    }
    s->targetX = s->x + x0;
    s->targetY = s->y + y0;
    if (s->control == 0 && (s->phase == 0 || s->wait != 0)) return;
    if (keep) return;

    float steer;
    float angle, absAngle, limitAngle;
    /* Forward/reverse decision; while the hold timer runs, the previous direction stays. */
    do {
        angle = func_0036CC40(func_0057D118(-x0, y0), s->yaw);
        absAngle = angle;
        if (angle < 0.0f) absAngle = -angle;
        limitAngle = 0x1.0c1520p+0f;
        if (self->direction == 1) {
            float speed = s->speed;
            if (0.0f <= speed) limitAngle = 0x1.657182p-3f;
            else if (-0x1.0aaaa8p+3f < speed) limitAngle = 0x1.657182p-3f - speed * 0x1.becde2p-1f / 0x1.0aaaa8p+3f;
        }
        if (self->direction == 1) {
            dir = -1;
        } else if (absAngle < limitAngle || self->direction == 2) {
            if (s->speed > -0x1.1c71c6p-1f) {
                dir = 1;
                if (s->speed < 0.0f && s->reversing == 0) brake = 1;
            } else {
                brake = 1;
            }
        } else if (s->speed > 0x1.1c71c6p-1f) {
            brake = 1;
        } else {
            dir = -1;
        }
        if (self->directionHold) {
            self->directionHold--;
            break;
        }
        {
            int previous = self->direction;
            switch (previous) {
            case 1:
                if (absAngle < limitAngle) {
                    if (s->speed > 0x1.aaaaa8p-1f) self->direction = 0;
                    else self->direction = 2;
                } else if (beside) {
                    self->direction = 2;
                }
                break;
            case 2:
                if (absAngle < 0x1.657182p-1f && s->speed > 0x1.0aaaa8p+3f) {
                    self->direction = 0;
                } else if (behind) {
                    float heading = func_0036CC40(func_004649F0(course, self->line, self->lineStart, &y2, &x2, &y1, s->distance), s->yaw);
                    if (heading < 0.0f) heading = -heading;
                    if (heading > 0x1.0c1520p+0f) {
                        self->direction = 1;
                    } else {
                        float speed = s->speed;
                        if (speed < 0x1.1c71c6p-2f && speed > -0x1.1c71c6p-2f) self->direction = 1;
                        else if (ahead) self->direction = 1;
                        else if (absAngle > 0x1.0c1520p+0f) self->direction = 1;
                    }
                }
                break;
            default:
                if (limitAngle <= absAngle) self->direction = 2;
                else if (ahead) self->direction = 1;
                else if (behind && s->speed < 0x1.1c71c6p-2f && s->speed > -0x1.1c71c6p-2f) self->direction = 1;
                else if (beside && absAngle > 0x1.921fb2p-1f) self->direction = 2;
                break;
            }
            if (self->car->body->layout == 4 && self->direction == 1) self->direction = 2;
            if (previous != self->direction) self->directionHold = 180;
        }
    } while (0);

    sign = 0;
    int assisted = D_00623E50.feedback < 2;
    if (func_00463E98(self)) assisted = 1;
    if (s->speed > 0x1.1c71c6p-1f) sign = 1;
    else if (s->speed < -0x1.1c71c6p-1f) sign = -1;
    if (sign == 0) {
        steer = 0.0f;
    } else if (dir == 1) {
        /* Driving forward: steer toward the target within the axles' steering lock. */
            steer = 0.0f;
            int i = 0;
            int n = 0;
            Body *body = self->car->body;
            float lock = 0.0f;
            Axles *axles = func_00359510(body);
            for (; i < axles->count; i++) {
                if (axleUsed(axles, i)) {
                    n++;
                    lock += func_00360F80(body, i, wheel(self->car, i)->tire)->limit;
                }
            }
            if (n) lock /= n;
            int m = 0;
            float base = 0.0f;
            float sum = 0.0f;
            Axles *loads = func_00359510(self->car->body);
            int count = loads->count;
            for (int i = 0; i < count; i++, count = loads->count) {
                if (usedBelow(loads, i, count)) {
                    m++;
                    sum += wheel(self->car, i)->load;
                }
            }
            if (m) base += sum / m;
            if (func_00463E98(self)) {
                if (angle > 0x1.657182p+0f) steer = lock;
                else if (angle < -0x1.657182p+0f) steer = -lock;
            }
            if (steer == 0.0f) {
                float vx = s->velX;
                float vy = s->velY;
                float velocity = root(vx * vx + vy * vy);
                float dist2 = x0 * x0 + y0 * y0;
                float sn, cs;
                if (velocity < 0x1.638e36p+0f) {
                    sn = negSin;
                    cs = cosYaw;
                } else {
                    float course_angle = func_0057D118(-vx, vy);
                    sn = -func_0057D2B8(course_angle);
                    cs = func_0057D1F0(course_angle);
                }
                float curve = velocity * -2.0f * (cs * x0 - sn * y0) / dist2;
                if (s->speed < 0.0f) curve = -curve;
                float curveLimit = s->curveLimit;
                float gain = params->steerGain;
                if (D_00623E50.feedback) {
                    float ratio = -(s->yawRate - lock) / lock;
                    if (ratio > 1.0f) ratio = 1.0f;
                    else if (ratio < -1.0f) ratio = -1.0f;
                    gain *= ratio;
                    if (!assisted) {
                        float acc = 0.0f;
                        float error, change;
                        error = base - self->steer;
                        change = error - self->history[0];
                        acc -= D_00623E50.dBase * s->damping * change;
                        float dt = self->car->state.dt;
                        self->history[0] = error;
                        acc += D_00623E50.kBase * error;
                        error = curve - curveLimit;
                        change = error - self->history[1];
                        acc += D_00623E50.dCurve * s->damping * change;
                        self->history[1] = error;
                        if ((curve > 0.0f && curveLimit < curve) || (curve < 0.0f && curve < curveLimit))
                            acc += D_00623E50.kCurve * error * gain;
                        float heading = func_004649F0(course, self->line, self->lineStart, &y2, &x2, &y1, s->distance);
                        float headingError = func_0036CC40(heading, func_0057D118(-s->velX, s->velY));
                        float yawError = func_0036CC40(heading, s->yaw);
                        float dx = s->x - y2;
                        float lateral = dx * func_0057D1F0(heading);
                        float dy = s->y - x2;
                        lateral += dy * func_0057D2B8(heading);
                        float maxLateral = D_00623E50.maxLateral;
                        if (lateral > maxLateral) lateral = maxLateral;
                        else if (lateral < -maxLateral) lateral = -maxLateral;
                        error = headingError;
                        change = error - self->history[2];
                        acc += D_00623E50.dHeading * s->damping * change;
                        self->history[2] = error;
                        acc += D_00623E50.kHeading * error;
                        error = lateral;
                        change = error - self->history[3];
                        acc -= D_00623E50.dLateral * s->damping * change;
                        self->history[3] = error;
                        acc += D_00623E50.kLateral * error * lock;
                        error = yawError;
                        change = error - self->history[4];
                        acc -= D_00623E50.dYaw * s->damping * change;
                        self->history[4] = error;
                        acc -= D_00623E50.kYaw * error;
                        float rate = s->steerRate;
                        acc -= D_00623E50.kRate * rate;
                        rate += acc * dt;
                        float maxRate = func_00463BB8(self)->maxRate;
                        if (rate > maxRate) rate = maxRate;
                        else if (rate < -maxRate) rate = -maxRate;
                        float next = self->steer + rate * dt;
                        self->steer = next;
                        if (next > 0x1.921fb2p-1f) {
                            self->steer = 0x1.921fb2p-1f;
                            rate = 0.0f;
                        } else if (next < -0x1.921fb2p-1f) {
                            self->steer = -0x1.921fb2p-1f;
                            rate = 0.0f;
                        }
                        s->steerRate = rate;
                    }
                }
                if (curve > 0.0f) {
                    if (curveLimit < curve) {
                        steer += (curve - curveLimit) * gain;
                        if (lock < steer) {
                            overshoot = steer / lock;
                            if (!func_0034C998(race)) steer = lock;
                        }
                    }
                } else if (curve < 0.0f && curve < curveLimit) {
                    float low = -lock;
                    steer -= (curveLimit - curve) * gain;
                    if (steer < low) {
                        overshoot = -steer / lock;
                        if (!func_0034C998(race)) steer = low;
                    }
                }
            }
            steer += base;
            if (steer > 0x1.921fb2p-1f) steer = 0x1.921fb2p-1f;
            else if (steer < -0x1.921fb2p-1f) steer = -0x1.921fb2p-1f;
            if (sign == -1) steer = -steer;
        } else {
            if (angle < -0x1.657182p-2f) steer = -0x1.0c1520p-1f;
            else if (angle > 0x1.657182p-2f) steer = 0x1.0c1520p-1f;
            else steer = angle * 0x1.7ffffcp+0f;
            if (sign == -1) steer = -steer;
    }
    float maxSteer = self->car->body->maxSteer;
    if (steer > maxSteer) steer = maxSteer;
    else if (steer < -maxSteer) steer = -maxSteer;

    unsigned char state = s->phase;
    if (state == 6) {
        func_00464C80(self, steer);
        return;
    }
    if ((unsigned)((unsigned char)s->control - 1) < 2 || state != 0) {
        if (assisted) func_00464BB0(self, steer);
    }
    if (dir == 1) {
        if (brake == 1) self->brake = 0.09f;
        float cruise, cap;
        int mode;
        unsigned char line = self->line;
        self->limited = 0;
        if (line == 4) {
            cruise = 0x1.bc71c4p+2f;
            mode = 3;
            self->limited = 1;
            cap = cruise;
        } else if (line != 3) {
            signed char rival = self->rival;
            cruise = self->cruise;
            cap = self->cap;
            mode = self->speedMode;
            if (rival != -1 && self->timer < 120) {
                float speed = func_0034C190(self->race, rival)->speed;
                switch (self->tireState) {
                case 1:
                case 2:
                    speed -= 0x1.638e36p+2f;
                    break;
                case 3:
                case 4:
                case 5:
                    speed -= 0x1.638e36p+1f;
                default:
                    speed -= 0x1.638e36p+0f;
                    break;
                }
                if (speed < 0x1.0aaaa8p+3f) speed = 0x1.0aaaa8p+3f;
                mode = 4;
                if (speed < cap) cap = speed;
            }
            if (self->direction == 2) cruise = 0x1.bc71c4p+3f;
        } else {
            float length = func_0046A0B0(course);
            View view(self->course, 4);
            float distance = s->distance;
            int count = view.count;
            if (distance < length * 0.5f) distance += length;
            if (distance < func_00469FC8(&view, 1)->distance) {
                cruise = self->cruise;
                mode = self->speedMode;
                cap = self->cap;
            } else if (distance < func_00469FC8(&view, 2)->distance) {
                cruise = self->cruise;
                mode = self->speedMode;
                cap = self->cap;
            } else if (distance < func_00469FC8(&view, count - 3)->distance) {
                mode = 1;
                cruise = params->slowSpeed + 0x1.1c71c6p-1f;
                self->limited = 1;
                if (self->cruise < cruise) {
                    self->limited = 0;
                    cruise = self->cruise;
                    mode = self->speedMode;
                }
                cap = params->slowSpeed + 0x1.1c71c6p-1f;
                if (self->cap < cap) cap = self->cap;
            } else {
                cruise = self->cruise;
                cap = self->cap;
                mode = self->speedMode;
            }
        }
        if (self->direction == 2) {
            func_00464770(self, cruise, -0.5f);
            self->hold = 0;
        } else {
            switch (mode) {
            case 3:
                func_00464770(self, cap, -2.0f);
                self->hold = 0;
                break;
            case 4:
                func_00464770(self, cap, -1.0f);
                self->hold++;
                break;
            case 1:
            case 2: {
                float speed = cruise;
                if (!(s->flags & 0x10) && self->hold >= params->boostDelay) {
                    speed += params->boost;
                    if (params->cornerBoost) {
                        float a = angle;
                        if (a < 0.0f) a = -a;
                        float corner = params->cornerAngle;
                        if (a < corner) speed += params->cornerGain * (corner - a) / corner;
                    }
                }
                func_00464770(self, speed, -0.5f);
                if (self->tireState == 0) {
                    Car *car = self->car;
                    int i = 0;
                    float sum = 0.0f;
                    Body *body = car->body;
                    Axles *axles = func_00359510(body);
                    for (i = 0; i < axles->count; i++)
                        sum += func_00360F80(body, i, car->state.wheels[i].tire)->value;
                    sum /= axles->count;
                    float ratio = car->state.drive / sum;
                    if (ratio < 0.0f) ratio = -ratio;
                    if (ratio > 0x1.ccccccp-1f) self->tireState = 5;
                    else if (ratio > 0.5f) self->tireState = mode == 1 ? 4 : 3;
                }
                self->hold++;
                break;
            }
            case 0:
                self->hold = 0;
                self->throttle = 1.0f;
                break;
            }
            if (self->hold > 6000) self->hold = 6000;
        }
        self->throttle *= scale;
        if (func_00358418(race) > s->aggression * 100 + 5000 && race->finished == 0) func_00469AE8(self);
    } else {
        if (dir == -1) {
            self->reverseLatch = 1;
            self->throttle = 1.0f;
        } else {
            self->throttle = 0.0f;
        }
        if (brake == 0) self->brake = 0.0f;
        else self->brake = 1.0f;
        self->hold = 0;
    }
    unsigned char sliding = D_00620DE7;
    if (sliding) overshoot = s->slip;
    if (overshoot > 0.0f && s->gear >= 2) {
        float excess = overshoot - 1.0f;
        if (sliding) excess = overshoot;
        float cut = 1.0f - params->slipThrottle * excess;
        if (cut < 0.0f) cut = 0.0f;
        self->throttle *= cut;
        excess *= params->slipBrake;
        float pressure = self->brake + excess;
        self->brake = pressure;
        if (pressure > 1.0f) self->brake = 1.0f;
    }
    if (s->phase == 5) {
        Rules *rules = &self->race->rules;
        float speed = 0x1.638e36p+4f;
        float factor = 1.0f;
        unsigned char *countdown = &self->countdown;
        int limit = rules->limit[0];
        if (s->control == 2) limit = rules->limit[1];
        if (limit > 80) limit = 0;
        int n = *countdown;
        if (limit) speed = limit * 0x1.1c71c6p-2f;
        if ((unsigned char)n) {
            if (!limit) {
                speed = s->speed - 0x1.1c71c6p-2f;
                if ((unsigned char)n < 30) factor = fraction(n);
            }
            *countdown = (unsigned char)n - 1;
        }
        float t = func_003F76E8(self->car, speed) * factor;
        if (t < self->throttle) self->throttle = t;
    }
}
