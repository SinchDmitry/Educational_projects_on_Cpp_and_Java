package edu.school21.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvFileSource;
import org.junit.jupiter.params.provider.ValueSource;

public class NumberWorkerTest {

    NumberWorker worker;

    @BeforeEach
    void beforeTests () {
        worker = new NumberWorker();
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 3, 5, 7, 223, 607, 1741, 3929, 7919})
    void isPrimeForPrimes(int number) {
        Assertions.assertTrue(worker.isPrime(number));
    }

    @ParameterizedTest
    @ValueSource(ints = {4, 6, 9, 21, 42, 611, 753, 2291, 3763, 7917, Integer.MAX_VALUE})
    void isPrimeForNotPrimes(int number) {
        Assertions.assertFalse(worker.isPrime(number));
    }

    @ParameterizedTest
    @ValueSource(ints = {Integer.MIN_VALUE, -46809321, -12345, -999, -42, -1, 0, 1})
    void isPrimeForIncorrectNumbers(int number) {
        Assertions.assertThrows(NumberWorker.IllegalNumberException.class, () -> worker.isPrime(number));
    }

    @ParameterizedTest
    @CsvFileSource(resources = {"/data.csv"})
    void digitsSum(int number, int expectedResult) {
        Assertions.assertEquals(expectedResult, worker.digitsSum(number));
    }
}
