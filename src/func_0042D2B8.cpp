struct Obj {
    char pad[0xC];
    int slots[8];
    int busy;
};

extern "C" int func_0042CE98(unsigned char id);
extern "C" void func_004AB040(int h);

extern "C" void func_0042D2B8(Obj *o)
{
    if (o->busy == 0) {
        for (int i = 0; i < 8; i++) {
            if (o->slots[i] == 0)
                func_004AB040(func_0042CE98(i));
        }
    }
}
