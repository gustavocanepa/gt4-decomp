extern "C" void ResultArcade__cleanup();
extern "C" void ResultLicense__disableEffect(void *arg0);

extern "C" void ResultLicense__cleanup(void *arg0) {
    void *s0 = arg0;
    ResultArcade__cleanup();
    ResultLicense__disableEffect(s0);
}
