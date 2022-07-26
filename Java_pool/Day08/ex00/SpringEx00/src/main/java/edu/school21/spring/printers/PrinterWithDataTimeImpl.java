package edu.school21.spring.printers;

import edu.school21.spring.renderers.Renderer;

import java.time.LocalDateTime;

public class PrinterWithDataTimeImpl implements Printer {
    private final Renderer render;

    public PrinterWithDataTimeImpl(Renderer render) {
        this.render = render;
    }

    @Override
    public void print(String text) {
        render.printToConsole(text + " " +   LocalDateTime.now().toString());
    }
}
