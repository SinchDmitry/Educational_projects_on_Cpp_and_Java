package ex00;

public class Program {
    public static void main(String[] args) {
        SignatureChecker a = new SignatureChecker();
        a.createMap();
        a.findSign("/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/en.subject.pdf");
        System.exit(0);
    }
}
