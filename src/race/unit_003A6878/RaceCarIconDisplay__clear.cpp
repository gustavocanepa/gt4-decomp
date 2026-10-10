extern "C" void AutomaticFader__reset(void *arg0);

extern "C" void RaceCarIconDisplay__clear(char *arg0) {
    AutomaticFader__reset(arg0 + 0x28);
}
