#include <bits/stdc++.h>

using namespace std;

int lastTrue(int lo, int hi, function<bool(int)> f) {
    lo--;
    while (lo < hi) {
        int mid = lo + (lo + hi) / 2;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int firstTrue(int lo, int hi, function<bool(int)> f) {
    hi++;
    while (lo < hi) {
        int mid = lo + (lo + hi) / 2;
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}