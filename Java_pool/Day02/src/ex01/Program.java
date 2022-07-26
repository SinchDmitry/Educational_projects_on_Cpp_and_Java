package ex01;

import java.io.IOException;

public class Program {
    public static void main(String[] args) throws IOException {
        TextCompare a = new TextCompare();
        String fileOne = "/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/src/ex00/Program.java";
        String fileTwo = "/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/src/ex01/test.txt";
        a.createDictionary(fileOne, fileTwo);
        System.out.println("Similarity of two files is : " + a.mathSimilarity() * 100 + " %");
    }
}
