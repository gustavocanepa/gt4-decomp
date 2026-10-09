struct Node {
    struct Node *next;
};

extern "C" void func_005FC150(struct Node **arg0, struct Node *arg1) {
    if (arg1 != 0) {
        arg1->next = *arg0;
        *arg0 = arg1;
    }
}
