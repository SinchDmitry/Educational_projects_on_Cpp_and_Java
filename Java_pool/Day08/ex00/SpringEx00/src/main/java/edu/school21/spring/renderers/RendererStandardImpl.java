package edu.school21.spring.renderers;

import edu.school21.spring.preprocessor.PreProcessor;

public class RendererStandardImpl implements Renderer {
    private final PreProcessor p;

    public RendererStandardImpl(PreProcessor p) {
        this.p = p;
    }

    @Override
    public void printToConsole(String text) {
        System.out.println(p.translate(text));
    }
}
