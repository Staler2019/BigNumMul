#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#define MAX_LENGTH 500

using namespace std;
int array1[MAX_LENGTH];
int array2[MAX_LENGTH];
int product[MAX_LENGTH + MAX_LENGTH];
long long t, totalT;

// TAG: 助教
// product[](int)裡的數字削去頭為0(只有一個數字)，之後將product[]倒過來便轉程string(size:= len*2-1 or len*2-2)
string ans_string(int len);
// TAG: 助教
// 1. 初始化可能用的的product
// 2. 傳統對位乘法
// 3. 針對超過10的數字處理及進位
string mul(int len);
// TAG: Staler2019
// 對輸入的string，如果頭是0將其切掉
string cut_zero(string s);
// TAG: Staler2019
// 對輸入的string，加上需求量的0
string give_digits(string s, int n);
// TAG: Staler2019
// 讓兩string的長度相同(較長的為主)
int equal_length(string &s1, string &s2);
// TAG: Staler2019
// string1 + status*string2
string add(string s1, string s2, int status = 1);
// TAG: Staler2019
// add(string1, string2, -1)
string del(string s1, string s2);
// TAG: Staler2019
//
string mul(string s1, string s2);

#define digit 500
int main() {
    string s1, s2, ans1, ans2;
    // ofstream out("result.txt");

    // ifstream in("./tests/" + to_string(digit) + ".in");  // read file
    // getline(in, s1);
    // getline(in, s2);
    while (cin >> s1 >> s2) {
        for (int i = 0; i < digit; i++)  // string to int array
        {
            array1[i] = s1[digit - i - 1] - '0';
            array2[i] = s2[digit - i - 1] - '0';
        }

        ans1 = mul(digit);
        ans2 = mul(s1, s2);
        cout << ans1 << endl;
        cout << ans2 << endl;
    }

    return 0;
}

string ans_string(int len) {
    int i = len * 2 - 1;
    string ans;

    if (product[i] == 0) i--;

    for (; i >= 0; i--) ans += to_string(product[i]);
    return ans;
}

string mul(int len) {
    for (int i = 0; i < len; i++)  // init
    {
        product[i] = 0;
        product[i + len] = 0;
    }
    for (int i = 0; i < len; i++)  // cal
    {
        for (int j = 0; j < len; j++) {
            if (array2[j] == 0) continue;
            product[i + j] += array1[i] * array2[j];
        }
    }
    for (int i = 0; i < 2 * len - 1; i++)  // carry
    {
        product[i + 1] += product[i] / 10;
        product[i] %= 10;
    }

    return ans_string(len);
}

string cut_zero(string s) {
    int i = 0;
    while (s[i] == '0') i++;
    if (i == s.length()) i--;
    return s.substr(i, s.size());
}

string give_digits(string s, int n) {
    for (int i = 0; i < n; i++) s += '0';
    return s;
}

int equal_length(string &s1, string &s2) {
    int len1 = s1.size(), len2 = s2.size();
    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; ++i) s1 = '0' + s1;
        return len2;
    } else if (len1 > len2) {
        for (int i = 0; i < len1 - len2; ++i) s2 = '0' + s2;
    }
    return len1;
}

string add(string s1, string s2, int status = 1) {
    string ans;
    int carry = 0;
    int len = equal_length(s1, s2);
    for (int i = len - 1; i >= 0; i--) {
        int first = s1[i] - '0';
        int second = s2[i] - '0';

        int sum = first + status * second + carry;
        if (sum > 9)
            carry = 1;
        else if (sum < 0)
            carry = -1;
        sum = (sum + 10) % 10 + '0';
        ans = (char)sum + ans;
    }
    if (carry == 1) ans = '1' + ans;
    return ans;
}

string del(string s1, string s2) { return add(s1, s2, -1); }

string mul(string s1, string s2) { //TODO
    // cerr << "---belows are test---" << endl;
    int len = equal_length(s1, s2);
    // cerr << s1 << " " << s2 << endl;

    // base case
    if (len == 0) return "0";
    if (len == 1) return to_string((s1[0] - '0') * (s2[0] - '0'));

    int mid = len >> 1;  // /2
    int digits = len - mid;
    string w = s1.substr(0, mid);
    string x = s1.substr(mid, digits);
    string y = s2.substr(0, mid);
    string z = s2.substr(mid, digits);
    // cerr << w << " " << x << " " << y << " " << z << endl;

    string p1 = mul(w, y);
    string p2 = mul(x, z);
    string p3 = mul(add(w, x), add(y, z));
    // cerr << p1 << " " << p2 << " " << p3 << endl;
    // cerr << give_digits(p1, digits << 1) << endl
    // << give_digits(del(del(p3, p1), p2), digits) << endl
    // << p2 << endl;

    return cut_zero(add(add(give_digits(p1, digits << 1),
                            give_digits(del(del(p3, p1), p2), digits)),
                        p2));
}
