/*************************************************************************
	> File Name: 4779.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月27日 星期三 20时25分04秒
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
    int e, dis, next;
};

struct point {
    int now, dist;
    bool operator< (const point &b) const {
        return this->dist > b.dist;
    }
};
int n, m, s, cnt, ans[100005], head[100005];
node edge[200005];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f3f3f3f, sizeof(ans));
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i].e = b;
        edge[i].dis = c;
        edge[i].next = head[a];
        head[a] = i;
    }
    priority_queue<point>que;
    que.push({s, 0});
    while(!que.empty()) {
        point t = que.top();
        que.pop();
        if(ans[t.now] != 0x3f3f3f3f)continue;
        ans[t.now] = t.dist;
        for(int i = head[t.now]; i != -1; i = edge[i].next){
            if(ans[edge[i].e] == 0x3f3f3f3f) {
                que.push({edge[i].e, t.dist + edge[i].dis});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i!=1)cout << " ";
        cout << ans[i];
    }
    return 0;
}

