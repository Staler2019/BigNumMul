string mul(int start, int end) {
    int len = end - start;
    if (len == 0) return "0";
    if (len == 1)
        return to_string((array1[start] - '0') * (array2[start] - '0'));

    int mid = len >> 1;
    int digits = len - mid;

    int* p1= mul(start, start + mid);
    int* p2= mul(start + mid, end);
    int*p3= mul();
}