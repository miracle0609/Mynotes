/*************************************************************************
	> File Name: 1.topo.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月22日 星期三 18时47分46秒
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

struct edge{
    int to, next;
};

struct my_int{
    int num;
    bool operator< (const my_int & b) const {
        return this->num > b.num;
    }
};
edge edg[400005];
int n, m, head[2005], in_degree[2005], out_degree[50];

int main() {
    ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }

    priority_queue<my_int>que;
    for(int i = 1; i <= n; i++) {
        if(in_degree[i] == 0) {
            que.push((my_int){i});
        }
    }
    int flag = 0;
    while(!que.empty()) {
        int temp = que.top().num;
        que.pop();
        if(flag == 1) {
            cout << " ";
        }
        cout << temp;
        flag = 1;
        for(int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            in_degree[e] --;
            if(in_degree[e] == 0) {
                que.push((my_int){e});
            }
        }
    }
    return 0;
}

