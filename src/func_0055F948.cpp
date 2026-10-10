struct Owner {
    virtual void v00(); virtual void v01();
    virtual void v02(void *item);
};
struct MenuControl {
    Owner *owner;
    char pad[0xC8];
    void *item;
};

extern "C" void MenuControl__virtual_02(MenuControl *self)
{
    if (self->owner && self->item) {
        self->owner->v02(self->item);
        self->item = 0;
    }
}
