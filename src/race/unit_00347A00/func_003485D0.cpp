/* compiler: ee-gcc2.96-nsa-as2004 */
/* Steering angle integrator: a spring towards `target`, damped, with an extra centring spring
 * while the wheel is on the far side of `center` and friction while it moves away from zero;
 * the rate is clamped to a speed-dependent limit and the angle snaps to the target once reached.
 *
 * Profile: the unit (func_00348850.cpp) is no-strict-aliasing; the later assembler is needed
 * here because gas 2.10 assembles the `l.s $f2, D_008435F0($3)` that directly follows another
 * `l.s` with a broken first word (lwc1 in place of the lui).
 *
 * Declarations that differ from the caller's (func_00348850.cpp): State here starts at the same
 * self + 0x104 but names only the three fields this function touches (angle = f468, rate = 0x484,
 * speed = f53C); Obj names only `dt` (the caller's `rate` at 0x54C).
 */
typedef float f32; typedef int s32;

struct State {
    char pad0[0x468]; f32 angle;
    char pad46C[0x484 - 0x46C]; f32 rate;
    char pad488[0x53C - 0x488]; f32 speed;
};
struct Obj {
    char pad0[0x54C]; f32 dt;
};

extern f32 D_00843598[];
extern f32 D_008435A0[];
extern f32 D_008435A8[];
extern f32 D_008435B0[];
extern f32 D_008435B8[][2];
extern f32 D_008435C8[][2];
extern f32 D_008435D8[][2];
extern s32 D_008435E8[];
extern f32 D_008435F0[];
extern f32 D_008435F8[];
extern f32 D_00843600[][2];
extern f32 D_00843610[][2];
extern f32 D_00843620[][2];

/* The state block is reached again through this accessor at the start of each arm: the pointer
 * is recomputed there, so gcse's single PRE pass does not merge the reload of the angle with the
 * first read (retail reloads it in both arms). */
static inline State *state(Obj *self) { return (State *)((char *)self + 0x104); }

extern "C" void func_003485D0(Obj *self, f32 target, s32 type, f32 center, s32 mode) {
    State *st = (State *)((char *)self + 0x104);
    f32 angle = st->angle;
    f32 gain = D_00843598[type];
    f32 rate = st->rate;
    f32 centerGain = D_008435A8[type];
    f32 damping = D_008435B0[type];
    f32 accel = (target - angle) * gain - rate * damping;
    f32 limit = D_008435B8[type][mode];
    f32 dt = self->dt;
    f32 fastLimit = D_00843600[type][mode];
    f32 friction = D_008435A0[type];
    if (centerGain != 0.0f
        && ((angle < target && angle < center) || (target < angle && center < angle))) {
        angle = state(self)->angle;
        accel += (center - angle) * centerGain;
        limit = D_008435D8[type][mode];
        fastLimit = D_00843620[type][mode];
    } else {
        f32 x;
        /* chained: x gets the loaded value and angle a copy of it, which keeps x a separate
         * register (retail's mov.s) that is then scaled in place */
        angle = x = state(self)->angle;
        if ((angle > 0.0f && target < angle) || (angle < 0.0f && angle < target)) {
            x *= friction;
            accel -= x;
            limit = D_008435C8[type][mode];
            fastLimit = D_00843610[type][mode];
        }
    }
    rate += accel * dt;
    if (D_008435E8[type] != 0) {
        f32 speed = st->speed;
        if (D_008435F0[type] < speed) {
            if (D_008435F8[type] <= speed) {
                limit = fastLimit;
            } else {
                limit += (fastLimit - limit) * (speed - D_008435F0[type]) / (D_008435F8[type] - D_008435F0[type]);
            }
        }
    }
    if (limit < rate) {
        rate = limit;
    } else if (rate < -limit) {
        rate = -limit;
    }
    f32 next = angle + rate * dt;
    if ((angle <= target && target <= next) || (target <= angle && next <= target)) {
        st->angle = target;
        st->rate = 0.0f;
    } else {
        st->angle = next;
        st->rate = rate;
    }
}
