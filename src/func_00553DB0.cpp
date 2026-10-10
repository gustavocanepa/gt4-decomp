struct func_00553DB0_Msg {
    int index;
};

struct func_00553DB0_Handler {
    void (*fn)(void *arg, func_00553DB0_Msg *msg);
    void *arg;
};

struct func_00553DB0_Obj {
    char pad[0xA4];
    func_00553DB0_Handler handlers[1];
};

extern "C" void func_00553E38(func_00553DB0_Obj *self, func_00553DB0_Msg *msg);

extern "C" int func_00553DB0(func_00553DB0_Obj *self, int type, func_00553DB0_Msg *msg) {
    func_00553DB0_Handler *h = &self->handlers[msg->index];
    switch (type) {
    case 1:
    case 2:
    case 4:
        if (h->fn)
            func_00553E38(self, msg);
        break;
    case 3:
    case 5:
        if (h->fn)
            h->fn(h->arg, msg);
        break;
    }
    return 0;
}
