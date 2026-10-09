extern "C" void *hObject__structor_0(void);
extern "C" void *func_00446F90(void *arg0);
extern "C" char mRaceData__vtable[];

extern "C" void *mRaceData__structor_0(void *arg0)
{
    hObject__structor_0();
    *(void **)((char *)arg0 + 4) = mRaceData__vtable;
    return func_00446F90((char *)arg0 + 0x10);
}
