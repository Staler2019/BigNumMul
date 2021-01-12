/*******************************************************************************
 *   Date：      2021-01-12
 *   Author：    Staler2019
 *   Problem:    karatsuba
 *   Reference:  https://blog.csdn.net/SunnyYoona/article/details/43234889
 *******************************************************************************/
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
#define MAXLENGTH 505

int arr1[MAXLENGTH];
int arr2[MAXLENGTH];
int product[2 * MAXLENGTH];
int add1[MAXLENGTH];
int add2[MAXLENGTH];

/*
    目標 : 大數乘法 N^(log2 3) 盡量在200位內超車N^2，最好的情況是能在100位內超車

    O 使用宣告好的陣列，重複使用。
    X 禁止使用malloc
    ! 宣告Array的總長度需 < 5000

    input:
    10. 15. 20. 25. ...500位數

    步驟:
    1. 拿到兩數字，做前處理
     + 開始算時間
    2. for loop 200次(不斷重複call某一個計算func，回傳ans為string)
     + 結束時間
    3. 取平均

*/

// add[add_len]為-1預防無法使用add_len
int addTo(string &ans, string &element, int start, int len);
// Purpose: store to addiction
void karatsuba_add(int start, int len);
// Purpose:
// 1. store to product
// 2. return product
string mul(int start, int len);

int main() {
    ofstream out("./results/N^(log2 3).txt");
    string s1, s2, ans;
    int length;
    long long t;

    for (int digit = 10; digit <= 500; digit += 5)  // test 10 ~ 500位數
    {
        // 讀檔
        ifstream in("./tests/" + to_string(digit) + ".in");  // read file
        getline(in, s1);
        getline(in, s2);

        // 資料前處理(string to int[ ] or string to char [ ] or ...)
        for (int i = 0; i < digit; i++)  // string to int array
        {
            array1[i] = s1[digit - i - 1] - '0';
            array2[i] = s2[digit - i - 1] - '0';
        }
        // end資料前處理

        int testCnt;
        auto start = chrono::high_resolution_clock::now();  // start timing
        for (testCnt = 0; testCnt < 200; testCnt++)         // 200次乘法
        {
            ans = mul(/*參數*/);  // large number multiplication
        }
        auto end = chrono::high_resolution_clock::now();  // timing end
        t = chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                .count() /
            testCnt;  // average
        // cout << t << endl;
        out << t << endl;

        in.close();
    }

    return 0;
}

int addTo(string &ans, string &element, int start, int len) {
    int mid = len / 2;
    // add1, add2由前往後是尾部到頭
    int i = mid - 1, j = len - mid - 1, add_len = 0;
    int a, b, sum, carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        a = i >= 0 ? element[start + i] - '0' : 0;
        b = j >= 0 ? element[start + mid + j] - '0' : 0;
        // 按位相加並加上進位
        sum = a + b + carry;
        // 進位
        carry = sum / 10;
        ans[add_len] = sum % 10;
        --i;
        --j;
        add_len++;
    }
    ans[add_len] = -1; // 預防add_len沒用
    return add_len;
}

void karatsuba_add(int start, int len) {
    // hint
    // string x1 = substr(0,mid);
    // string x0 = substr(mid,len - mid);

    // hint
    // string y1 = substr(0,mid);
    // string y0 = substr(mid,len - mid);

    int mid = len / 2;
    // init add1, add2
    for (int i = 0; i < mid + 1; i++) add1[i] = add2[i] = 0;

    int len_1 = add_to(add1, arr1, start, len);
    int len_2 = add_to(add2, arr2, start, len);
    return
}

string mul(int start, int len) {
    if (len == 0) return "0";
    if (len == 1) return to_string(arr1[start] * arr2[start]);

    string ans;
    //運算
    int mid = len / 2;
    // hint
    // string x1 = substr(0,mid);
    // string x0 = substr(mid,len - mid);

    // hint
    // string y1 = substr(0,mid);
    // string y0 = substr(mid,len - mid);

    // string z0 = mul(mid,len-mid);
    // karatsuba_add
    // string z1 = KaratsubaMultiply(AddString(x1,x0),AddString(y1,y0)); // TODO
    // string z2 = mul(0,mid);
    return ans;
}