/*************************************************************************
	> File Name: 505-最大整数.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月13日 星期三 16时05分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
#define MAX_N 100000
string arr[MAX_N+2];

bool cmp(const string i, const string j) {
    return (i + j) > (j + i);
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
