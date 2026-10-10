typedef int s32;
typedef unsigned short u16;
typedef float f32;

struct Key_0042A560 {
    s32 m0;
    f32 time;
    char pad[0x18];
};

struct Track_0042A560 {
    u16 count;
    Key_0042A560 *keys;
};

extern "C" s32 func_0042A510(Track_0042A560 *track, s32 lo, s32 hi, f32 t);
extern "C" s32 func_0042A560(Track_0042A560 *track, f32 t) {
    s32 r;
    if (t <= track->keys[0].time) {
        r = 0;
    } else if (track->keys[track->count - 1].time <= t) {
        r = track->count - 1;
    } else {
        r = func_0042A510(track, 0, track->count - 1, t);
    }
    return r;
}
