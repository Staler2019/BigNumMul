int* mulSplit(int start, int end){

}

string mul(int start, int end) {
    int len = end - start;
    if (len == 0) return "0";
    if (len == 1)
        return to_string((array1[start] - '0') * (array2[start] - '0'));

    int mid = len >> 1; // 右傾(右數多)
    int digits = len - mid;

    string p1= mul(start, start + mid);
    string p2= mul(start + mid, end);
    string p3= mulSplit(start,end);
}