package edu.school21.spring.preprocessor;

public class PreProcessorToLowerImpl implements PreProcessor {
    @Override
    public String translate(String text) {
        return text.toLowerCase();
    }
}
