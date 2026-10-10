extern "C" void Oscillator__update(void *arg0);

extern "C" void RaceIndicator__virtual_09(void *arg0) {
    Oscillator__update((char *) arg0 + 0x18);
}
