struct func_0051EE70_Peer {
    unsigned int id;
    char pad4[0x84 - 0x4];
    int user;
    char pad88[0x94 - 0x88];
    void (*onState)(int user, int state);
};

extern "C" int func_0051DCF8(unsigned int id);

extern "C" int func_0051EE70(func_0051EE70_Peer *peer, int code, unsigned char *data, int len) {
    int state;
    unsigned int id;
    if (len == 0) return 0xCB20;
    switch (*data) {
    case 0: state = 0; break;
    case 1: state = 1; break;
    case 2: state = 2; break;
    case 3: state = 3; break;
    case 4: state = 4; break;
    default: return 0xCB20;
    }
    if (peer->onState != 0) {
        id = peer->id;
        peer->onState(peer->user, state);
        if (func_0051DCF8(id) == 0) return 0xCB23;
    }
    return 0;
}
