#include <iostream> // #1966 프린터 큐_우선순위 큐
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for(int i=0; i<n; i++) {
            int imp;
            cin >> imp;
            q.push({i, imp}); // (인덱스, 중요도) 쌍
            pq.push(imp);
        }

        int cnt = 0;
        while(!q.empty()) {
            int idx = q.front().first;
            int imp = q.front().second;

            q.pop();
            if(pq.top() == imp) {
                pq.pop();
                cnt++;

                if(idx == m) {
                    cout << cnt << '\n';
                    break;
                }
            }
            else q.push({idx, imp});
        }
    }

    return 0;
}
///////////////////////////////////////////////////////////////////
#include <iostream> // #1966 프린터 큐_우선순위 큐
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for(int i=0; i<n; i++) {
            int imp;
            cin >> imp;
            q.push({i, imp}); // (인덱스, 중요도) 쌍
            pq.push(imp);
        }

        int cnt = 0;
        while(!q.empty()) {
            int idx = q.front().first;
            int imp = q.front().second;
            
            if(imp < pq.top()) { // q의 현재 중요도가 최대치가 아니라면 뒤로 이동
                q.push(q.front());
                q.pop();
            }
            else { // 최대치라면 카운트하고, m번째라면 출력
                q.pop();
                pq.pop();
                cnt++;

                if(idx == m) {
                    cout << cnt << '\n';
                    break;
                }
            }
        }
    }
    
    return 0;
}