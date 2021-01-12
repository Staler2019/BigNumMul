//
//  main.cpp
//  multiply
//
//  Created by Longxiang Lyu on 5/23/16.
//  Copyright (c) 2016 Leo Lyu. All rights reserved.
//
// the karatsuba's algorithm only needs O(n^log3) bit operation to do the
// multiplication of two integers, which is better than O(n^2) solutions

#include <iostream>
#include <string>

using namespace std;

size_t equalizeLength(string &s1, string &s2)
{
    size_t len1 = s1.size(), len2 = s2.size();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; ++i)
            s1 = '0' + s1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; ++i)
            s2 = '0' + s2;
    }
    return len1;
}

string strAddition(string s1, string s2)
{
    string ret;
    int carry = 0;
    size_t len = equalizeLength(s1, s2);

    for (int i = len - 1; i >= 0; --i)
    {
        int firstBit = s1.at(i) - '0';
        int secondBit = s2.at(i) - '0';

        int sum = (firstBit ^ secondBit ^ carry) + '0';
        ret = static_cast<char>(sum) + ret;

        carry = (firstBit & secondBit) | (firstBit & carry) | (secondBit & carry);
    }
    if (carry)
        ret = '1' + ret;
    return ret;
}

long int Karatsuba_multiply(string s1, string s2)
{
    size_t len = equalizeLength(s1, s2);

    // base case
    if (len == 0) return 0;
    if (len == 1) return (s1[0] - '0') * (s2[0] - '0');

    size_t floor = len / 2;
    size_t ceil = len - floor;
    string a = s1.substr(0, floor);
    string b = s1.substr(floor, ceil);
    string c = s2.substr(0, floor);
    string d = s2.substr(floor, ceil);

    long int p1 = Karatsuba_multiply(a, c);
    long int p2 = Karatsuba_multiply(b, d);
    long int p3 = Karatsuba_multiply(strAddition(a, b), strAddition(c, d));

    return (1<<(2 * ceil)) * p1 + (1<<(ceil)) * (p3 - p1 - p2) + p2;
}

int main(int argc, const char * argv[]) {
    string s1 = "10101010";
    string s2 = "111101";
    cout << s1 << " multiplies " << s2 << " is " << Karatsuba_multiply(s1, s2) << endl;
    return 0;
}