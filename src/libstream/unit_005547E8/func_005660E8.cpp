struct func_005660E8_Block {
    int w[9];
};

struct func_005660E8_Obj {
    int count[2];
    int handle[2];
    char pad10[0x1C - 0x10];
    void (*onSend)(int user);
    int sendUser;
    void (*onWrite)(int user);
    int writeUser;
    char pad2C[0x6C - 0x2C];
    func_005660E8_Block block[2];
};

struct func_005660E8_Msg {
    int pad0;
    int type;
    int index;
    char padC[0x18 - 0xC];
    int size;
    func_005660E8_Block data;
};

extern "C" void *func_005A48D8(void *dst, int c, unsigned int n);
extern "C" void func_00554E88(int handle, void *data, int size, int flag);
extern "C" int func_00565C30(func_005660E8_Obj *self, int index, void *data, int size, int a, int b);

extern "C" int func_005660E8(func_005660E8_Obj *self, func_005660E8_Msg *msg) {
    int ret = 0;
    int index = msg->index;
    switch (msg->type) {
    case 2:
        self->count[index]++;
        func_005A48D8((void *)(index * 0x24 + (int)self + 0x6C), 0, 0x24);
        break;
    case 1:
        self->count[index]++;
        self->block[index] = msg->data;
        break;
    case 3:
    case 4:
        break;
    case 5:
        func_00554E88(self->handle[index], &msg->data, msg->size, 1);
        if (self->onSend != 0) self->onSend(self->sendUser);
        break;
    case 6:
        ret = func_00565C30(self, index, 0, 0, 4, 1);
        if (self->onWrite != 0) self->onWrite(self->writeUser);
        break;
    }
    return ret;
}
