
typedef signed char s8;
typedef int s32;
struct Obj
{
  char pad[0x5A8];
  s32 unk5A8;
};
struct Something
{
  char pad[0x11C];
  s8 unk11C;
};
extern s32 func_004F6F10(s8 *arg0, s32 arg1, s32 arg2);
extern void func_004F1F70(struct Obj *arg0, s8 *arg1, s32 arg2)
{
  s32 s3 = 0;
  s32 s1 = 0;
  *arg1 = 0;
  while (s3 < 0x10)
  {
    s3 += 1;
    s32 tempv0 = arg0->unk5A8 + s1;
    s1 += 0x120;
    struct Something *s0 = (struct Something *) (tempv0 + 0x1D8);
    if (func_004F6F10(arg1, arg2, tempv0 + 0x1F4) != 0)
    {
      break;
    }
    if (s0->unk11C != 0)
    {
      break;
    }
    s0++;
    s0--;
  }

}
