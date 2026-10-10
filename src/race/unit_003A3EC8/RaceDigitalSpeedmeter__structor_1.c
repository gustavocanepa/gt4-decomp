
typedef struct Obj {
    char pad[0x14];
    void *vtable;
    short name[6];
    char pad2[4];
    int m28;
    unsigned int m2C;
} Obj;

extern char RaceDigitalSpeedmeter__vtable[];
extern Obj *RaceDisplayObjectBase__structor_0(Obj *o);
extern void RaceDigitalSpeedmeter__reset(Obj *o);
extern char *strcpy(char *dst, const char *src);

void RaceDigitalSpeedmeter__structor_1(Obj *o)
{
    RaceDisplayObjectBase__structor_0(o);
    o->vtable = RaceDigitalSpeedmeter__vtable;
    o->m2C = 0x80E3B896;
    o->m28 = 0;
    strcpy((char *)o->name, "GT4meter#1");
    RaceDigitalSpeedmeter__reset(o);
}
