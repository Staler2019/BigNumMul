#include <iostream>
#include <string>
#define MAX_LENGTH 500
using namespace std;

int array1[MAX_LENGTH];
int array2[MAX_LENGTH];

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
    for (int i = len - 1; i >= 0;i--){
        int first = s1[i] - '0';
        int second = s2[i] - '0';

        int sum =
    } return ans;
}

string del(string &s1, string &s2) { return add(s1, s2, -1); }

string mul(int start, int end) {
    int mid = (end - start) / 2 + start;
    // product = mul(start,mid)*digit^2 +
    // [add(start,end)*add(start,end)-mul(start,mid)-mul(mid,end)] +
    // mul(mid,end)
    int[] wy = mul(start, mid), xz = mul(mid, end);
    int[] wzxy =
        del(del(mul(add(start, end) /*w+x*/, add(start, end) /*y+z*/), wy), xz);

    return ans_string(len);
}
void init_product(int digit) {
    for (int i = 0; i < digit; i++) product[i] = product[i + digit] = 0;
}
void string_to_int(string &str, int array[], int digit) {
    for (int i = 0; i < digit; i++) array[i] = str[digit - i - 1] - '0';
}

#define digit 500
int main() {
    string s1, s2, ans;
    ifstream in("../tests/" + to_string(digit) + ".in");  // read file
    getline(in, s1);
    getline(in, s2);

    string_to_int(s1, array1, digit);
    string_to_int(s2, array2, digit);
    init_product(digit);
    ans = mul(0, digit);
    cout << ans << endl;

    return 0;
}