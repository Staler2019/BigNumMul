#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#define _TEST_TIME

using namespace std;
#define MAXLENGTH 505

int arr1[MAXLENGTH];
int arr2[MAXLENGTH];
int product[2 * MAXLENGTH];
int addiction[2 * MAXLENGTH];

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

string ans_string(int len) {
    int i = len * 2 - 1;
    string ans;

    if (product[i] == 0) i--;

    for (; i >= 0; i--) ans += to_string(product[i]);
    return ans;
}
void add(int start,int end){

}
string mul(int start,int end) {
    int len = end - start;
    int mid = (len >> 1)+start; // 右傾字串: s=a+b(strlen(a)<=strlen(b))
    int digit = len - mid;

    if (len == 0) return "0";
    if(len==1)return arr
    return ans_string(len);
}

int main() {
    string s1, s2, ans;
#define digit 500
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

    ans = mul(0,digit);  // large number multiplication
    cout << mul();

    in.close();
    return 0;
}