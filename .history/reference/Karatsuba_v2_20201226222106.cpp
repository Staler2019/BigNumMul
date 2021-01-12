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
    string s1 = "15236173605659801775960835867957813003425431685158942049389032073071059078233912829811335268458267908104612497881448384980111086647516185810903321857294388309556457050598766197311267025918813532702511124356832954837348825194469562028203505145071184157682958172385374387663949374797510983917574480178016721188984012642732670965795214870067296485039418948446079705413839582113173920567808372721053639062248725936678638709874074742545185402323993875186923281539724719598324014784134107250433442539642462";
    string s2 = "35902796883815069076120809008356074207565987242950462668034453299971983835196386327104754485106876640953465507130445499090049904789634937606430120132165105246226804856073833509302066934799668024334807689987666663529535800019303501406951589706296387837878750071236864581107260384063572978165978162508430237840595481453761077097554184501070485386652679606762785409739157431081068554475720236447948489205976677505755791045505531736941893433112476801298501677610285024805397824047836569570862678171337931";
    cout << s1 << " multiplies " << s2 << " is " << Karatsuba_multiply(s1, s2) << endl;
    return 0;
}