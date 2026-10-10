struct Obj;

extern "C" void RaceTireWearDisplay__setTireWearColor(Obj *arg0);

extern "C" void RaceSimplePanel__setTireWearColor(char *arg0) {
    RaceTireWearDisplay__setTireWearColor((Obj *)(arg0 + 0xD0));
}
