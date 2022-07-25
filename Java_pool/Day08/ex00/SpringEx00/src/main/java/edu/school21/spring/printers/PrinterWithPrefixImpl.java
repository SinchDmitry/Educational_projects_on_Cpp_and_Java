package edu.school21.spring.printers;

import edu.school21.spring.renderers.Renderer;

public class PrinterWithPrefixImpl implements Printer {
    private final Renderer render;
    private String prefix;

    public PrinterWithPrefixImpl(Renderer render, String prefix) {
        this.render = render;
        this.prefix = prefix;
    }

    public PrinterWithPrefixImpl(Renderer render) {
        this.render = render;
        this.prefix = "";
    }

    @Override
    public void print(String text) {
        render.printToConsole(prefix + " " + text);
    }

    public void setPrefix(String prefix) {
        this.prefix = prefix;
    }
}
