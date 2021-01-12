//============================================================================
// Name        : KaratsubaMultiplication.cpp
// Author      : Evin Ugur (http://evinugur.com)
// Version     : 1.0
// Copyright   : Copyright 2015. You can use this code however and wherever you
// want no strings attached Description : C++ Functions to Perform Karatsbuba
// Multiplications
//============================================================================

#include <math.h>

#include <chrono>
#include <iostream>
// #include "KaratsubaMultiplication.h"
using namespace std;

int getLength(long long value) {
    int counter = 0;
    while (value != 0) {
        counter++;
        value /= 10;
    }
    return counter;
}

long long multiply(long long x, long long y) {
    int xLength = getLength(x);
    int yLength = getLength(y);

    // the bigger of the two lengths
    int N = (int)(fmax(xLength, yLength));

    // if the max length is small it's faster to just flat out multiply the two
    // nums
    if (N < 10) return x * y;

    // max length divided and rounded up
    N = (N / 2) + (N % 2);

    long long multiplier = pow(10, N);

    long long b = x / multiplier;
    long long a = x - (b * multiplier);
    long long d = y / multiplier;
    long long c = y - (d * N);

    long long z0 = multiply(a, c);
    long long z1 = multiply(a + b, c + d);
    long long z2 = multiply(b, d);

    return z0 + ((z1 - z0 - z2) * multiplier) +
           (z2 * (long long)(pow(10, 2 * N)));
}

// C++ example (uses cout...)
// (this code works in straight C too though if you use a different main
// function)
int main() {
    // two numbers
    long long a = 2406994;
    long long b = 2328563;
    long long ans = 0;

    int testCnt;
    auto start = chrono::high_resolution_clock::now();  // start timing
    for (testCnt = 0; testCnt < 200; testCnt++)         // 100次乘法
        ans = multiply(a, b);
    auto end = chrono::high_resolution_clock::now();  // timing end
    t = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() /
        testCnt;

    cout << t << endl;
    return 0;
}
