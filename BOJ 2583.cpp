#include <iostream> // #2583 영역 구하기_DFS
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;

int m, n, k, cnt, box[MAX][MAX];
vector<int> v_cnt;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

void DFS(int x, int y);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> m >> n >> k;

    for(int i=0; i<k; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for(int i=lx; i<rx; i++) {  // 좌하단 (lx, ly)~우상단 (rx, ry) 1로
            for(int j=ly; j<ry; j++)
                box[j][i] = 1;
        }
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(box[i][j]==0) {
                cnt=0;
                DFS(i, j);
                v_cnt.push_back(cnt);
            }
        }
    }
    int v_cnt_size = v_cnt.size();
    cout << v_cnt_size << '\n';

    sort(v_cnt.begin(), v_cnt.end());
    for(int i=0; i<v_cnt_size; i++)
        cout << v_cnt[i] << ' ';
        
    return 0;
}

void DFS(int x, int y) {
    box[x][y] = 1;
    cnt++;

    for(int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        
        if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if(box[nx][ny]==0)
            DFS(nx, ny);
    }

    return;
}
/*
직전 코드에서 visit을 없애고, box[m-j-1][i] = 1을 box[i][j] = 1로 바꿔도 됨
*/

/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> // #2583 영역 구하기_BFS
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 101;

int m, n, k, cnt, box[MAX][MAX];
vector<int> v_cnt;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

void BFS(int x, int y);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> m >> n >> k;

    for(int i=0; i<k; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for(int i=lx; i<rx; i++) {  // 좌하단 (lx, ly)~우상단 (rx, ry) 1로
            for(int j=ly; j<ry; j++) {
                box[m-j-1][i] = 1;  // [j][i]로 바꿔도 됨
            }
        }
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(box[i][j]==0) {
                cnt = 1;
                BFS(i, j);
                v_cnt.push_back(cnt);
            }
        }
    }
    int v_cnt_size = v_cnt.size();
    cout << v_cnt_size << '\n';

    sort(v_cnt.begin(), v_cnt.end());
    for(int i=0; i<v_cnt_size; i++)
        cout << v_cnt[i] << ' ';
        
    return 0;
}

void BFS(int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    box[x][y] = 1;

    while(!que.empty()) {
        x = que.front().first, y = que.front().second;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
        
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(box[nx][ny]==0) {
                box[nx][ny] = 1;
                cnt++;
                que.push({nx, ny});
                }
            }
    }
    
    return;
}