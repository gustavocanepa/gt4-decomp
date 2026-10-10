struct Params {
    int w[11];
};

struct Data {
    char pad0[0x24];
    Params params;
};

struct Obj {
    char pad0[0x10];
    Data *data;
};

extern "C" void func_005CBE70(Obj *self, const Params *p) {
    self->data->params = *p;
}
