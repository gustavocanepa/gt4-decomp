struct Obj {
    char pad[0x1003E];
    short frames;
};

extern "C" int func_003FA228(Obj *o);

extern "C" int func_003FA2B0(Obj *o) {
    if (o->frames == 0)
        return -1;
    int t = func_003FA228(o);
    if (t == 0)
        return -1;
    return t - o->frames / 60;
}
