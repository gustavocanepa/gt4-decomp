typedef int s32;

extern char HSymbol__OP_MOD[];

extern "C" void hObject__send(s32 arg0, void *arg1, void *arg2);

extern "C" void mLoggerControl__virtual_33(void *arg0, void *arg1, s32 *arg2) {
    hObject__send(*arg2, arg1, HSymbol__OP_MOD);
}
