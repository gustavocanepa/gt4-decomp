extern "C" void AutomaticFader__update(void *arg0);

extern "C" void RaceMusicDisplay__virtual_09(char *arg0) {
    AutomaticFader__update(arg0 + 0x28);
}
