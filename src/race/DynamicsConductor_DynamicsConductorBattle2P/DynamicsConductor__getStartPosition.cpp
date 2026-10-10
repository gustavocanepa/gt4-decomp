typedef short s16;

struct B0034D030 {
    char pad[0xF86C];
    s16 arr[1];
};

extern "C" s16 DynamicsConductor__getStartPosition(struct B0034D030 *arg0, int arg1) {
    return arg0->arr[arg1];
}
