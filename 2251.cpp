/*
Author: Yuki
GitHub: https://github.com/Yuki-14544869/
Blog:   https://yuki4294967295.cn/
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000") //手动扩栈
typedef long long LL;
#define INF = 0x3f3f3f3f;
#define eps 1e-10
#define ff(a, b, c, d) for (int a = b; a < c; a += d)
#define fff(a, b, c, d) for (int a = b; a >= c; a -= d)
#define mm(a, b) memset(a, b, sizeof a)
const double PIE = acos(-1.0);
void filein() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
}

const int N = 30+5;
int L, R, C;
char maps[N][N][N] = {'&'};
int sx, sy, sz, ex, ey, ez;
int dis[6][3] = {1,0,0, 0,1,0, 0,0,1,
                 -1,0,0, 0,-1,0, 0,0,-1};
bool vis[N][N][N] = {false};
typedef struct node {
    int x, y, z;
    int step;

    node(){}
    node(int _x, int _y, int _z, int _step):
            x(_x), y(_y), z(_z), step(_step) {}
};

bool check(int x, int y, int z) {
    if(x<0 || x>=L || y<0 || y>=R || z<0 || z>=C)
        return false;
    if(maps[x][y][z] == '#')
        return false;
    return !vis[x][y][z];
}

int bfs() {
    mm(vis, false);
    queue<node> q;
    q.push({sx, sy, sz, 0});
    vis[sx][sy][sz] = true;

    while(!q.empty()) {
        node now = q.front();
        q.pop();
        if(now.x==ex && now.y==ey && now.z==ez)
            return now.step;
        ff(i, 0, 6, 1) {
            int x = now.x+dis[i][0];
            int y = now.y+dis[i][1];
            int z = now.z+dis[i][2];
            if(!check(x, y, z))
                continue;
            vis[x][y][z] = true;
            q.push({x, y, z, now.step+1});
        }
    }
    return 0;
}

int main() {
    filein();
    while(cin >> L >> R >> C) {
        if(L==0 && R==0 && C==0)
            return 0;
        //cout << L << R << C << endl;
        mm(maps, '&');
        ff(i, 0, L, 1)
            ff(j, 0, R, 1)
                ff(k, 0, C, 1) {
                    cin >> maps[i][j][k];
                    if (maps[i][j][k] == 'S') {
                        sx = i;
                        sy = j;
                        sz = k;
                    } else if (maps[i][j][k] == 'E') {
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
//         ff(i, 0, L, 1) {
//             ff(j, 0, R, 1) {
//                 ff(k, 0, C, 1)
//                     cout << maps[i][j][k];
//                 cout << endl;
//             }
//             cout << endl << endl;
//         }
//
//         cout << sx << " " << sy << " " << sz << endl
//              << ex << " " << ey << " " << ez << endl;
        int key = bfs();
        if (key)
            cout << "Escaped in " << key << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }
    return 0;
}