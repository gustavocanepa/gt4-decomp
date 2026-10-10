typedef int s32;

typedef struct Self { char *vtbl; s32 m4; s32 m8; char *mC; char m10[4]; } Self;
extern char D_00689418[];
extern char D_00851188[];
void func_004B3B88(void *);

void func_004B3790(Self *self) {
    self->vtbl = D_00689418;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = D_00851188;
    func_004B3B88(self->m10);
}
