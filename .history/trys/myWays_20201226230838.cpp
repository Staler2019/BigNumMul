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

string del(string s1, string s2) { return add(s1, s2, -1); }

string mul(string s1, string s2) {
    int len = equal_length(s1, s2);

    // base case
    if (len == 0) return 0;
    if (len == 1) return (s1[0] - '0') * (s2[0] - '0');

    int mid = len / 2;
    int digit = len - mid - 1;
}

#define digit 500
int main() {
    string s1, s2, ans;
    ifstream in("../tests/" + to_string(digit) + ".in");  // read file
    getline(in, s1);
    getline(in, s2);

    ans = mul(s1,s2);
    cout << ans << endl;

    return 0;
}