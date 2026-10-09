struct Obj {
    char pad[0xBC];
    float unkBC;
};

extern "C" float func_00200ED8(struct Obj *arg0) {
    return arg0->unkBC;
}
