struct Obj {
    void *data;
};

extern "C" int func_00485F48(Obj *o, void *key);
extern "C" int func_00485FF0(Obj *o, int index, void *value);

extern "C" int func_00486028(Obj *o, void *key, void *value) {
    if (o->data == 0)
        return 0;
    return func_00485FF0(o, func_00485F48(o, key), value);
}
