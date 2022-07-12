package ex01;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.sqrt;


public class TextCompare {
    private final Map<String, Integer> _inputFileParserFirst;
    private final Map<String, Integer> _inputFileParserSecond;
    private final Set<String>          _inputBothDict;

    public TextCompare() {
        _inputFileParserFirst = new HashMap<>();
        _inputFileParserSecond = new HashMap<>();
        _inputBothDict = new TreeSet<>();
    }

    private List<String[]> readFile(String path) {
        List<String[]> sum = new ArrayList<>();
        try (BufferedReader input = new BufferedReader(new FileReader(path))) {
            String line = null;
            while ((line = input.readLine()) != null) {
                String[] words = line.trim().replaceAll("[^a-zA-Zа-яА-я ]",
                        "").toLowerCase().split("\\s+");
                sum.add(words);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
//        for (int i = 0 ; i < words.length; ++i) {
//            System.out.println(words[i]);
//        }
        return sum;
    }

    public void createFileMap(String path, int numOfWord) {
        List<String[]> words = readFile(path);
        Map<String, Integer> dict = _inputFileParserFirst;
        if (numOfWord == 2) {
            dict = _inputFileParserSecond;
        }
        if (words.size() != 0) {
            for (String[] j : words) {
                for (String s : j) {
                    if (!Objects.equals(s, "\n") && !s.isEmpty()) {
                        dict.merge(s, 1, Integer::sum);
                    }
                }
            }
            System.out.println(dict);
        } else {
            System.exit(-1);
        }
    }

    public void createDictionary(String pathOne, String pathTwo) {
        createFileMap(pathOne, 1);
        createFileMap(pathTwo, 2);
        _inputBothDict.addAll(_inputFileParserFirst.keySet());
        _inputBothDict.addAll(_inputFileParserSecond.keySet());
        String outPath = "/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/src/ex01/dictionary.txt";
        try (BufferedWriter out = new BufferedWriter(new FileWriter(outPath))) {
            for (String j : _inputBothDict) {
                out.write(j);
                out.newLine();
            }
        } catch (IOException x) {
            System.err.println("Error : cannot crate file 'dictionary.txt'");
        }
    }

    private List<Integer> createNumVector(int numOfWord) {
        List<Integer> vector = null;
        if (numOfWord == 1) {
            vector = _inputBothDict.stream().map(i -> _inputFileParserFirst.getOrDefault(i, 0))
                    .collect(Collectors.toList());
        } else if (numOfWord == 2) {
            vector = _inputBothDict.stream().map(i -> _inputFileParserSecond.getOrDefault(i, 0))
                    .collect(Collectors.toList());
        }
        System.out.println(vector);
        return vector;
    }

    public double mathSimilarity() {
        List<Integer> firstWord = createNumVector(1);
        List<Integer> secondWord = createNumVector(2);

        double nom = 0;
        for (int i = 0; i < firstWord.size(); ++i) {
            nom += firstWord.get(i) * secondWord.get(i);
        }
        double denom = 0;
        double tmp = 0;
        for (Integer integer : firstWord) {
            tmp += integer * integer;
        }
        denom += sqrt(tmp);
        tmp = 0;
        for (Integer integer : secondWord) {
            tmp += integer * integer;
        }
        denom *= sqrt(tmp);
        return nom / denom;
    }
}
