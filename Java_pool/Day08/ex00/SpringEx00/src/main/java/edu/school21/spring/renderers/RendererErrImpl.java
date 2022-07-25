package edu.school21.spring.renderers;

import edu.school21.spring.preprocessor.PreProcessor;

public class RendererErrImpl implements Renderer {
    private final PreProcessor p;

    public RendererErrImpl(PreProcessor p) {
        this.p = p;
    }

    @Override
    public void printToConsole(String text) {
        System.err.println(p.translate(text));
    }
}
