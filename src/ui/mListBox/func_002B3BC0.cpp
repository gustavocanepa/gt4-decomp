/* mListBox: move the focus `count` selectable items forward (twin of func_002B3C88, which moves
   backward). Returns 1 when a new item got the focus. */
extern "C" int mListBox__getTotalItemCount(char *) throw();
extern "C" void mListBox__setFocusIndex(char *, int) throw();
extern "C" int func_002B5580(char *, int);

/* The wrap target comes from an inline: its arm is two insns until cse, so the wrap is only
   if-converted after the loop pass and its -1 stays a fresh register instead of the hoisted one. */
static inline int firstIndex() { return 0; }

extern "C" int func_002B3BC0(char *self, int count) {
    int index = *(int *)(self + 0x124);         /* focus index */
    if (index >= 0) {
        if (count > 0) {
            do {
                ++index;
                if (index == mListBox__getTotalItemCount(self)) {
                    if (*(int *)(self + 0x10C) != 0)    /* wrap-around enabled */
                        index = firstIndex();
                    else
                        index = -1;
                }
                if (index < 0) return 0;
                if (func_002B5580(self, index) == 0) {
                    --count;
                    if (index == *(int *)(self + 0x124)) index = -1;
                }
                if (index < 0) return 0;
            } while (count > 0);
        }
        if (index >= 0) { mListBox__setFocusIndex(self, index); return 1; }
    }
    return 0;
}
