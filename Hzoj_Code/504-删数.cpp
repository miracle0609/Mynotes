/*************************************************************************
	> File Name: 504-删数.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月13日 星期三 15时45分56秒
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
string s;
int main() {
    int t;
    cin >> s >>t;
    while(t) {
        int i;
        for(i = 0; i < s.size() - 1 && s[i] <= s[i + 1]; i++);
        s.erase(i, 1);
        t--;
    }
    if(s.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int i;
    for(i = 0; i < s.size(); i++) {
        if(s[i] !='0')break;
    }
    cout << s.substr(i) << endl;
    return 0;
}
