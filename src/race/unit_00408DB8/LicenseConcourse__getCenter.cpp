typedef int s32;
typedef float f32;

struct B { char pad[0x58]; f32 arr[1]; };

extern "C" f32 LicenseConcourse__getCenter(struct B *arg0, s32 arg1) {
    f32 *p = &arg0->arr[arg1];
    return *p;
}
