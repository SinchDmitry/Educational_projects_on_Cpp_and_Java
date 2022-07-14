package ex02;

import java.util.Random;

public class ArraySum {

    private int     _size;
    private int     _threadCounter;
    private int[]   _array;

    public ArraySum(int size, int counter) {
        _size = size;
        _threadCounter = counter;
        Random r = new Random();
        int[] bigArray = new int[size];
        for (int i = 0; i < bigArray.length; ++i) {
            bigArray[i] = r.nextInt(2000) - 1000;
        }
//        for (int i : bigArray) {
//            i = r.nextInt(2000) - 1000;
//        }
        for (int j : bigArray) {
            System.out.println(j);
        }
    }

    public void splitArray() {
        
    }
}
