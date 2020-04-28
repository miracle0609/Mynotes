/*************************************************************************
	> File Name: 42-钱币问题.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月28日 星期二 18时36分44秒
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
#define MAX_M 20
#define MAX_N 10000
int f[MAX_M + 5][MAX_N + 5];
int val[MAX_M + 5];
int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> val[i];
    for(int i = 1; i <= m; i++) {
        f[i][0] = 1;
        for(int j = 1; j <= n; j ++) {
            f[i][j] = f[i - 1][j];
            if(j >= val[i]) f[i][j] += f[i][j - val[i]];
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;
    return 0;
}
