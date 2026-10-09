extern "C" void *RaceValueDisplayBase__structor_1(void *arg0);
extern "C" char RaceGasMileageDisplay__vtable[];

extern "C" void RaceGasMileageDisplay__structor_0(void *arg0)
{
    RaceValueDisplayBase__structor_1(arg0);
    *(int *)((char *)arg0 + 0x68) = 0;
    *(void **)((char *)arg0 + 0x14) = RaceGasMileageDisplay__vtable;
}
