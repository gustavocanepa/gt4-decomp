struct Node {
    char pad[0x58];
    Node *unk58;
};

extern "C" Node *func_00608FB0(Node *arg0) {
    Node *var_v0;
    Node *temp_v1;

    var_v0 = arg0;
loop_1:
    temp_v1 = var_v0->unk58;
    if (temp_v1 != 0) {
        var_v0 = temp_v1;
        goto loop_1;
    }
    return var_v0;
}
