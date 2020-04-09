/*************************************************************************
	> File Name: 531-奇怪的电视.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月08日 星期三 19时04分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct node {
    int status, step;
};

int n, num[21], arr[21][21], check[2200000];

void init() {
    int t = 1;
    for(int i = 0; i < 21; i++) {
        num[i] = t;
        t *= 2;
    }
}

int main() {
    init();
    cin >> n;
    int start_status = 0;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if(t == 1) start_status += num[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i][0];
        for(int j = 1; j <= arr[i][0]; j ++) {
            cin >> arr[i][j];
            arr[i][20] += num[arr[i][j]];
        }
    }
    queue<node>que;
    que.push({start_status, 0});
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        if(temp.status == 8) {
            cout << temp.step << endl;
            return 0;
        }
        for(int i= 1; i <= n; i++) {
            if((temp.status & num[i]) == 0) {
                int status_temp = temp.status + num[i];
                status_temp &= ~(arr[i][20]);
                if(!check[status_temp]) {
                    check[status_temp] = 1;
                    que.push({status_temp, temp.step + 1});
                }
            }
        }
    }
    return 0;
}
