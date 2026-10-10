struct Node { void *unk0; };
struct Obj { char pad[4]; void *unk4; void *unk8; };

extern "C" void ParticleManager__remove(Obj *arg0, Node *arg1, void **arg2) {
    void *v0 = arg1->unk0;
    if (arg2 != 0) {
        *arg2 = v0;
    } else {
        arg0->unk4 = v0;
    }
    arg1->unk0 = arg0->unk8;
    arg0->unk8 = arg1;
}
