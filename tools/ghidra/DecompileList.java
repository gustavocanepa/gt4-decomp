// Decompile a list of functions with Ghidra's decompiler and write one C file per function.
// Run headless (tools/ghidra_drafts.py does it):
//   analyzeHeadless PROJ_DIR PROJ -process gt4.elf -noanalysis -scriptPath tools/ghidra
//                   -postScript DecompileList.java ADDR_LIST_FILE OUT_DIR
// ADDR_LIST_FILE: one hex address per line. OUT_DIR/ADDR.c gets the decompiler's C, or a
// one-line "// error: ..." when Ghidra could not decompile it.
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

import java.io.File;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.util.List;

public class DecompileList extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        List<String> lines = Files.readAllLines(new File(args[0]).toPath());
        File out = new File(args[1]);
        out.mkdirs();
        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.openProgram(currentProgram);
        for (String line : lines) {
            String hex = line.trim();
            if (hex.isEmpty()) continue;
            Address addr = toAddr(Long.parseLong(hex, 16));
            Function f = getFunctionAt(addr);
            if (f == null) {
                f = createFunction(addr, null);
            }
            String text;
            if (f == null) {
                text = "// error: no function at " + hex + "\n";
            } else {
                DecompileResults r = decomp.decompileFunction(f, 60, monitor);
                text = r.decompileCompleted() ? r.getDecompiledFunction().getC()
                                              : "// error: " + r.getErrorMessage() + "\n";
            }
            try (PrintWriter w = new PrintWriter(new File(out, String.format("%08x.c", Long.parseLong(hex, 16))))) {
                w.print(text);
            }
        }
        decomp.dispose();
    }
}
