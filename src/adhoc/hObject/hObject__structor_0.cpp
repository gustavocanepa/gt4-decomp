extern "C" void *RefCounter__structor_0(void *arg0);
extern "C" char hObject__vtable[];

extern "C" void hObject__structor_0(void *arg0)
{
    RefCounter__structor_0(arg0);
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = hObject__vtable;
}
