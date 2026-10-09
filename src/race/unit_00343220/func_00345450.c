struct In { char pad[0x466]; signed char state; signed char next; };
struct Obj { char pad[0x14]; char sub[0xF0]; struct In in; };
extern int func_00463C28(void *, int, int);
int func_00345450(struct Obj *o)
{
    struct In *in = &o->in;
    if (in->state == 4) return 0;
    if (!func_00463C28(o->sub, 3, 1)) return 0;
    in->next = 4;
    return 1;
}
