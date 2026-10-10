extern "C" void PauseBase__cleanup();
extern "C" void PhotoPause__deleteAnimInst(void *arg0);

extern "C" void PhotoPause__cleanup(void *arg0) {
    void *s0 = arg0;
    PauseBase__cleanup();
    PhotoPause__deleteAnimInst(s0);
}
