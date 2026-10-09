extern "C" void *func_0033B800(void *arg0);
extern "C" char RaceSolitaireEntry__vtable[];

extern "C" void RaceSolitaireEntry__structor_0(void *arg0)
{
    func_0033B800(arg0);
    *(int *)((char *)arg0 + 0x58) = 0;
    *(int *)((char *)arg0 + 0x54) = 0;
    *(void **)((char *)arg0 + 0x20) = RaceSolitaireEntry__vtable;
}
