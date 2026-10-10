extern "C" void hObject__cleanup();
extern "C" void hModule__clearModuleValue(void *arg0);

extern "C" void hModule__cleanup(void *arg0) {
    void *s0 = arg0;
    hObject__cleanup();
    hModule__clearModuleValue(s0);
}
