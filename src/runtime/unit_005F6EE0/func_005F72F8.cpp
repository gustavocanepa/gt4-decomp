typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 CourseData__getRunway(s32 arg0);

extern "C" s32 func_005F72F8(Obj *arg0)
{
    return CourseData__getRunway(arg0->unk4);
}
