struct Node {
    Node *next;
};

extern "C" Node *func_005FCAA0(Node **arg0) {
    Node *head = *arg0;
    if (head == 0) {
        return 0;
    }
    *arg0 = head->next;
    return head;
}
