/*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int min = 0x3f3f3f3f;
#define ff(a, b, c, d) for(int a=b; a<c; a+=d)

int maps[5][5];
int dis[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
struct node{
    int x, y, pre;
}q[50];
int front=0, rear=0;
bool vis[5][5];

void bfs() {
    q[0].x=0;
    q[0].y=0;
    q[0].pre=-1;
    rear++;
    vis[0][0] = 1;

    while(front < rear) {
        ff(i, 0, 4, 1) {
            int newx = q[front].x + dis[i][0];
            int newy = q[front].y + dis[i][1];
            if(newx<0 || newx>=5 || newy<0 || newy>=5
               || maps[newx][newy]==1 || vis[newx][newy] == true)
                continue;

            q[rear].x = newx;
            q[rear].y = newy;
            q[rear].pre = front;
            rear++;
            vis[newx][newy] = true;
            if(newx==4 && newy==4)
                return ;
        }
        front++;
    }
}

void out(node now) {
    if(now.pre==-1)
        cout<<"("<<now.x<<", "<<now.y<<")"<<endl;
    else{
        out(q[now.pre]);
        cout<<"("<<now.x<<", "<<now.y<<")"<<endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ff(i, 0, 5, 1)
        ff(j, 0, 5, 1)
            cin >> maps[i][j];
    bfs();
    out(q[rear-1]);
    return 0;
}

