struct Obj;

extern "C" void Oscillator__setWaveform(Obj *arg0);

extern "C" void func_005F89E0(char *arg0) {
    Oscillator__setWaveform((Obj *)(arg0 + 0x44));
}
