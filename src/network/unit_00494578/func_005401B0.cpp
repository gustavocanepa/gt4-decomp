struct func_005401B0_Ctx {
    void *parser;
    int type;
    char pad8[0x210 - 0x8];
    unsigned int *flags;
};

extern "C" int func_00594470(const char *a, const char *b, int n);

extern "C" void func_005401B0(func_005401B0_Ctx *ctx, const char *name, int len) {
    unsigned int *flags = 0;
    int i = 0;
    const char *names[26] = {
        "SetConnectionType",
        "GetConnectionTypeInfo",
        "RequestConnection",
        "RequestTermination",
        "ForceTermination",
        "SetAutoDisconnectTime",
        "SetIdleDisconnectTime",
        "SetWarnDisconnectDelay",
        "GetStatusInfo",
        "GetAutoDisconnectTime",
        "GetIdleDisconnectTime",
        "GetWarnDisconnectDelay",
        "GetNATRSIPStatus",
        "GetGenericPortMappingEntry",
        "GetSpecificPortMappingEntry",
        "AddPortMapping",
        "DeletePortMapping",
        "GetExternalIPAddress",
        "ConfigureConnection",
        "GetLinkLayerMaxBitRates",
        "GetPPPEncryptionProtocol",
        "GetPPPCompressionProtocol",
        "GetPPPAuthenticationProtocol",
        "GetUserName",
        "GetPassword",
        0,
    };
    if (ctx->type == 8) flags = ctx->flags;
    else if (ctx->type == 7) flags = ctx->flags;
    for (; names[i] != 0; i++) {
        if (func_00594470(names[i], name, len) == 0) break;
    }
    switch (i) {
    case 0: *flags |= 0x1; break;
    case 1: *flags |= 0x2; break;
    case 2: *flags |= 0x4; break;
    case 3: *flags |= 0x8; break;
    case 4: *flags |= 0x10; break;
    case 5: *flags |= 0x20; break;
    case 6: *flags |= 0x40; break;
    case 7: *flags |= 0x80; break;
    case 8: *flags |= 0x100; break;
    case 9: *flags |= 0x200; break;
    case 10: *flags |= 0x400; break;
    case 11: *flags |= 0x800; break;
    case 12: *flags |= 0x1000; break;
    case 13: *flags |= 0x2000; break;
    case 14: *flags |= 0x4000; break;
    case 15: *flags |= 0x8000; break;
    case 16: *flags |= 0x10000; break;
    case 17: *flags |= 0x20000; break;
    case 18: *flags |= 0x40000; break;
    case 19: *flags |= 0x80000; break;
    case 20: *flags |= 0x100000; break;
    case 21: *flags |= 0x200000; break;
    case 22: *flags |= 0x400000; break;
    case 23: *flags |= 0x800000; break;
    case 24: *flags |= 0x1000000; break;
    }
}
