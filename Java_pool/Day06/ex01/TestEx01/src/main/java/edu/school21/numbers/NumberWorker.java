package edu.school21.numbers;

public class NumberWorker {
    public static class IllegalNumberException extends RuntimeException {
        public IllegalNumberException() {
        }
    }

    public boolean isPrime(int number) {
        if (number <= 1) {
            throw new IllegalNumberException();
        }
        if (number == 2 || number == 3)
            return true;
        else {
            for (int i = 2; i * i <= number; i++) {
                if (number % i == 0)
                    return false;
            }
        }
        return true;
    }

    public int digitsSum(int number) {
        long abs = Math.abs((long) number);
        int res = 0;

        while (abs != 0) {
            res += abs % 10;
            abs /= 10;
        }
        return res;
    }
}
