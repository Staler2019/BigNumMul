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

string ans_string(int len) {
    int i = len * 2 - 1;
    string ans;

    if (product[i] == 0) i--;

    for (; i >= 0; i--) ans += to_string(product[i]);
    return ans;
}
void add(int start, int end) {
    // w+x: [start,mid)+[mid~end)
    // y+z: [start,mid)+[mid~end)
    int len = end - start;
    int half_len = len >> 1;
    int mid = half_len + start;

    // init addiction to zero
    for (int i = 0; i < half_len + 2; i++)
        add1[i] = add2[i] = 0;
    // end init addiction

    // cal
    for (int i = 0; i <half_len; i++) {
        // first two place give to carry and arr2[0] which could be
        add1[2 + (half_len- i)] += arr1[(mid-1)- i] + arr1[(end-1) - i]; // add1[]本身即存了carry
        add2[2 + (half_len- i)] += arr2[(mid-1)- i] + arr2[(end-1) - i];
        if (add1[2 + (half_len - i)] > 9) {
            // carry1 = 1;
            add1[2 + (half_len - i) - 1] =1;
            add1[2 + (half_len - i)] -= 10;
        }
        if (add2[2 + (half_len - i)] > 9) {
            // carry2 = 1;
            add2[2 + (half_len - i) - 1] =1;
            add2[2 + (half_len - i)] -= 10;
        }
    }
    if (!(len&1)) { // (mid+half_len==end-1) === len非奇數
        add1[1] += arr1[mid];
        add2[1] += arr2[mid];
        if (add1[1] > 9){ // carry=1
            add1[0] = 1;
            add1[1] -= 10;
        }
        if (add2[1] > 9){
            add2[0] = 1;
            add2[1] -= 10;
        }
    }

    /*
    add[]已自動進位不用carry控管
    add[0]可能為零在len是奇數時
    add[1]可能為零在len是偶數時
    ->讀取add[]時要注意
    */
    return;
}
string mul(int start, int end) {
    int len = end - start;
    int mid = (len >> 1) + start;  // 右傾字串: s=a+b(strlen(a)<=strlen(b))
    int digit = len - mid;

    if (digit == 0) return "0";
    if (digit == 1) return to_string(arr1[start] * arr2[start]);

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

    ans = mul(0, digit);  // large number multiplication
    cout << mul();

    in.close();
    return 0;
}