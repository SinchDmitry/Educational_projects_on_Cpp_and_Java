package ex02;

public class ArrayThread extends Thread {
    private int[]   _array;
    private int     _id;
    private int     _start;
    private int     _finish;
    private int     _sum;

    public ArrayThread(int id, int[] array, int start, int finish) {
        _id = id;
        _array = array;
        _start = start;
        _finish = finish;
        _sum = 0;
    }

    public int getSum() {
        return _sum;
    }

    @Override
    public void run() {
        for (int i = _start; i < _finish; ++i) {
            synchronized (this) {
                _sum += _array[i];
            }
        }
        System.out.printf("Thread %d: from %d to %d sum is %d\n", _id, _start, (_finish - 1), _sum);
    }

}
