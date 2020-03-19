/*************************************************************************
	> File Name: 535-瓷砖.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月19日 星期四 23时11分11秒
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
int n, m, sx, sy;
char mmap[50][50];

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int ans = 1;
void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(mmap[dx][dy] == '.') {
            mmap[dx][dy] = 0;
            dfs(dx, dy);
            ans++;
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == '@') {
                sx=i;
                sy=j;
            }
        }
    }
    /*
    for(int i = 1; i <= n; i++) {
        cin >> &(mmap[i][1]);
    }*/
    dfs(sx,sy);
    cout << ans << endl;
    return 0;
}

