/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Steering demand from the current and wanted angle: sets the side/turn signs, the scale from
 * func_00351358 and the normalised output, clamped to [-1, 1] and faded out near the limit bytes
 * of the settings block.
 *
 * Declarations local to this file (no other source names them yet): Steer, Params and Input only
 * name the fields read here; Config overlays D_00620CD8 (func_00351358.cpp declares the same
 * global with its own field names) so that limit[] lands on +0xB4/+0xB5.
 */
typedef float f32; typedef int s32; typedef signed char s8; typedef unsigned char u8;

struct Steer {
    char pad0[0x20]; f32 current;
    char pad24[4]; f32 speed;
    char pad2C[0x38 - 0x2C]; f32 output; f32 scale;
    char pad40[4]; s8 side; s8 turn;
};
struct Params { char pad0[0xFC8]; f32 gain; };
struct Input { char pad0[0x1D8]; u8 direct; };
struct Config { u8 pad[0xB4]; u8 limit[2]; };

extern Config D_00620CD8;
extern "C" f32 func_00351358(s32 offset, f32 x);

extern "C" void func_003513F8(Steer *self, Params *params, Input *in, f32 target) {
    f32 scale = 1.0f;
    f32 v;
    self->side = 0;
    f32 current = self->current;
    if (in->direct) {
        v = target - current;
        if (0.0f <= current) {
            /* stores written in both arms: the compiler merges them after the constant */
            if (target <= current) {
                self->turn = 1;
                self->side = 1;
            } else {
                self->turn = -1;
                self->side = -1;
            }
        } else {
            /* the negation is written in each arm: with one shared `v = -v` before the test the
             * two arms end identically and both stores are merged, not only the last */
            if (current <= target) {
                v = -v;
                self->turn = -1;
                self->side = 1;
            } else {
                v = -v;
                self->turn = 1;
                self->side = -1;
            }
        }
        v *= params->gain;
        self->scale = scale;
        if (1.0f < v) {
            v = 1.0f;
        } else if (v < -1.0f) {
            v = -1.0f;
        }
        self->output = v;
        return;
    }
    if (-0x1.1c71c6p-6f < current && current < 0x1.1c71c6p-6f) {
        scale = func_00351358(0, self->speed);
        if (current < target) {
            self->turn = -1;
            v = 1.0f;
        } else if (target < current) {
            self->turn = 1;
            v = 1.0f;
        } else {
            self->turn = 0;
            v = 0.0f;
        }
        self->side = -1;
    } else {
        v = 0.0f;
        if (0.0f < current) {
            if (target <= current) {
                v = target - current;
                scale = func_00351358(1, self->speed);
                v *= scale;
                v /= current;
                self->turn = 1;
                self->side = 1;
            } else {
                scale = func_00351358(0, self->speed);
                if (!(target < 0x1.1c71c6p-6f && -0x1.1c71c6p-6f < target)) {
                    v = (target - current) * scale / target;
                }
                self->turn = -1;
                self->side = -1;
            }
        } else {
            if (current <= target) {
                v = target - current;
                scale = func_00351358(1, self->speed);
                v *= scale;
                v /= current;
                self->turn = -1;
                self->side = 1;
            } else {
                scale = func_00351358(0, self->speed);
                if (!(target < 0x1.1c71c6p-6f && -0x1.1c71c6p-6f < target)) {
                    v = (target - current) * scale / target;
                }
                self->turn = 1;
                self->side = -1;
            }
        }
    }
    self->scale = scale;
    if (1.0f < v) {
        v = 1.0f;
    } else if (v < -1.0f) {
        v = -1.0f;
    }
    if (self->side == 0) {
        v = 0.0f;
    } else {
        f32 x;
        u8 n;
        if (self->side < 0) {
            x = target;
            n = D_00620CD8.limit[0];
        } else {
            x = current;
            n = D_00620CD8.limit[1];
        }
        if (n != 0) {
            f32 range = (f32)n * 0x1.1c71c6p-2f;
            if (x < 0.0f) x = -x;
            if (x < range) v *= x / range;
        }
    }
    self->output = v;
}
