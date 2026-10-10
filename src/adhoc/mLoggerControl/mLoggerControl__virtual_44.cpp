typedef int s32;

extern char D_0083F6B8[];

extern "C" void hObject__send(s32 arg0, void *arg1, void *arg2);

extern "C" void mLoggerControl__virtual_44(void *arg0, void *arg1, s32 *arg2) {
    hObject__send(*arg2, arg1, D_0083F6B8);
}
