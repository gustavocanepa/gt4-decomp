typedef unsigned char u8;

struct Obj {
    char pad[0xCBDD];
    u8 unkCBDD;
};

extern "C" u8 DynamicsConductor__getCourseType(Obj *arg0) {
    u8 var_v0 = 0;

    if (arg0->unkCBDD == 0xFF) {
        return var_v0;
    }
    var_v0 = arg0->unkCBDD;
    return var_v0;
}
