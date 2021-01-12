#include <iostream>
#include <string>
#define MAX_LENGTH 500
using namespace std;

int array1[MAX_LENGTH];
int array2[MAX_LENGTH];
int product[MAX_LENGTH + MAX_LENGTH];
long long t, totalT;

string ans_string(int len) {
    int i = len * 2 - 1;
    string ans;

    if (product[i] == 0) i--;

    for (; i >= 0; i--) ans += to_string(product[i]); // +'0'
    return ans;
}

string add(int start, int end){
    int mid = (end - start) / 2 + start;
    int add[] = mid + 1;
    for (int i = end - mid; i >= 0;i) return ans_string
}

string del(int[] a,int[] b){
    return
}

string mul(int start, int end) {
    // if (start == end) return "";
    // if

    int mid = (end - start) / 2;
    // product = mul(start,mid)*digit^2 + [add(start,end)*add(start,end)-mul(start,mid)-mul(mid,end)] + mul(mid,end)
    int[] wy = mul(start, mid), xz = mul(mid, end);
    int[] wzxy =
        del(del(mul(add(start, end) /*w+x*/, add(start, end) /*y+z*/), wy), xz);

    return ans_string(len);
}

#define digit 500
int main() {
    string s1, s2, ans;
    ifstream in("../tests/" + to_string(digit) + ".in");  // read file
    getline(in, s1);
    getline(in, s2);

    for (int i = 0; i < digit; i++)  // string to int array
    {
        array1[i] = s1[digit - i - 1] - '0';
        array2[i] = s2[digit - i - 1] - '0';
    }
    // for (int i = 0; i < digit; i++)  // init product[]
    // {
    //     product[i] = 0;
    //     product[i + digit] = 0;
    // }
    ans = mul(0, digit);
    cout << ans << endl;

    return 0;
}