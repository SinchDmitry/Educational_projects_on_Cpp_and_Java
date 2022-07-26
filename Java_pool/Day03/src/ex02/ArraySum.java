package ex02;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class ArraySum {

    private int     _size;
    private int     _threadCounter;
    private int     _startSum;
    private int[]   _array;

    public int[] get_array() {
        return _array;
    }


    public ArraySum(int size, int counter) {
        if (size != 0) {
            _size = size;
            _threadCounter = counter;
            Random r = new Random();
            _array = new int[size];
            for (int i = 0; i < _array.length; ++i) {
                _array[i] = r.nextInt(2000) - 1000;
            }
            _startSum = Arrays.stream(_array).sum();
            System.out.println("sum : " + _startSum);
        } else {
            System.err.println("Error : size of array cannot be 0");
            System.exit(-1);
        }
    }

    public void splitArray() {
        int patternSize = (int)Math.ceil((double)_size / _threadCounter);
        int[] startPoints = new int[_threadCounter];
        int tmpStep = 0;
        ArrayThread part = null;
        List<ArrayThread> listOfTreads = new ArrayList<>();
        for (int i = 0; i < _threadCounter; ++i) {
            if ((tmpStep + patternSize) > _size) {
                part = new ArrayThread(i + 1, _array, tmpStep, _size);
            } else {
                part = new ArrayThread(i + 1, _array, tmpStep, tmpStep + patternSize);
            }
            tmpStep += patternSize;
            part.start();
            try {
                Thread.sleep(2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            listOfTreads.add(part);
        }
        try {
            for (ArrayThread t : listOfTreads) {
                t.join();
            }
        } catch (InterruptedException e) {
            System.err.println("Error: Thread has been interrupted");
            return;
        }
        System.out.printf("Sum by threads: %d\n", listOfTreads.stream().mapToInt(ArrayThread::getSum).sum());
    }
}
