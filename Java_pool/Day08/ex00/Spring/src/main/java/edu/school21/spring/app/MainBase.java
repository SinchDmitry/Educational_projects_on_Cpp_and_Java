package edu.school21.spring.app;

import edu.school21.spring.preprocessor.PreProcessor;
import edu.school21.spring.preprocessor.PreProcessorToUpperImpl;
import edu.school21.spring.printers.PrinterWithPrefixImpl;
import edu.school21.spring.renderers.Renderer;
import edu.school21.spring.renderers.RendererErrImpl;

public class MainBase {
    public static void main(String[] args) {
        PreProcessor preProcessor = new PreProcessorToUpperImpl();
        Renderer render = new RendererErrImpl(preProcessor);
        PrinterWithPrefixImpl printer = new PrinterWithPrefixImpl(render);
        printer.setPrefix("Prefix");
        printer.print("Hello!");
    }
}
