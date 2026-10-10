extern void RaceDisplayObjectBase__selectTexture(void *str, void *buf);
extern char D_006A1568[];

void RaceShiftTimingLampDisplay__init_texset(void *buf)
{
    RaceDisplayObjectBase__selectTexture(buf, D_006A1568);
}
