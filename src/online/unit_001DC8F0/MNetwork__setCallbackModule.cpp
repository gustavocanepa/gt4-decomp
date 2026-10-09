typedef int s32;

extern "C" void func_001DC650(s32 *arg0);
extern "C" void func_001DC5F8(s32 *arg0, s32 arg1);
extern "C" s32 *func_00304210(s32 *arg0, s32 *arg1);
extern "C" void func_003041B8(s32 *arg0, s32 arg1);

extern "C" void MNetwork__setCallbackModule(void *context, void *self, s32 argc, s32 *argv) {
    s32 network[4];
    s32 module[4];

    if (argc > 0) {
        if (*argv == 0) {
            func_001DC650(network);
            *(s32 *)(network[0] + 0x1BC) = 0;
            func_001DC5F8(network, 2);
        } else {
            func_001DC650(network);
            s32 object = network[0];
            s32 *pm = module;
            func_00304210(pm, argv);
            *(s32 *)(object + 0x1BC) = *pm;
            func_003041B8(pm, 2);
            func_001DC5F8(network, 2);
        }
    }
}
