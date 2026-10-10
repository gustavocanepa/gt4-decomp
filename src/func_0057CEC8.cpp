struct Obj {
    int pos;
    int f4;
    int size;
    int busy;
};

extern "C" bool func_0057CE78(Obj *o, int pos);

extern "C" bool func_0057CEC8(Obj *o) {
    if (o->busy != 0) {
        return false;
    }
    int next = o->pos + 1;
    if (next >= o->size) {
        return true;
    }
    return !func_0057CE78(o, next);
}
