
struct Node
{
  struct Node *unk0;
  void *unk4;
};
struct Obj
{
  char pad0[4];
  struct Node *unk4;
};
extern void func_00326798(void *, int, int, int);
extern int *func_005DD830(void);
void func_005DD1F8(struct Obj *arg0)
{
  struct Node *v0 = arg0->unk4;
  struct Node *s1 = v0->unk0;
  if (s1 != v0)
  {
    do
    {
      struct Node *s0 = s1;
      s1 = s1->unk0;
      func_00326798(s0, 0xC, 4, *func_005DD830());
      v0 = arg0->unk4;
      s0 = s1;
    }
    while (s1 != v0);
  }
  v0->unk0 = v0;
  v0 = arg0->unk4;
  v0->unk4 = v0;
}
