/* compiler: ee-gcc2.96-as2004 */
/* The base class, named after its constructor (RaceDisplayObjectBase__structor_0); its vptr sits after 0x14 bytes. */
struct RaceDisplayObjectBase__structor_0 {
    char pad[0x14];
    RaceDisplayObjectBase__structor_0();
    virtual ~RaceDisplayObjectBase__structor_0();
};

/* A member object, named after its constructor. */
struct func_003A9608 {
    func_003A9608();
    int m0;
};

/* Named after its vtable (0x0067E448) so that _vt$10D_0067E448 resolves. */
struct RaceMiniMap__vtable : RaceDisplayObjectBase__structor_0 {
    int m18;
    int slots[6];
    char pad[0xC];
    int m40;
    int m44;
    func_003A9608 m48;
    RaceMiniMap__vtable();
    virtual ~RaceMiniMap__vtable();
};

RaceMiniMap__vtable::RaceMiniMap__vtable()
{
    m18 = 0;
    for (int i = 5; i >= 0; i--)
        slots[i] = 0;
    m40 = 0;
    m44 = 0;
}
