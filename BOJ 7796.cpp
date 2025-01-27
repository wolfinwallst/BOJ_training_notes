#include <iostream> // # 7796 먹을 것인가 먹힐 것인가_STL 활용
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int j=0; j<m; j++)
            cin >> b[j];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int cnt = 0;
        for(int x :a) {
            auto iter = lower_bound(b.begin(), b.end(), x) - b.begin();
            cnt += (int)iter;
        }
        cout << cnt << '\n';
    }

    return 0;
}
/*
            int len = lower_bound(b.begin(), b.end(), x) - b.begin();
            cnt += len;
        로 바꿔도 됨
        아니면 아래처럼
            cnt += b.end() - upper_bound(b.begin(), b.end(), x);
*/
//////////////////////////////////////////////////////////////////////
#include <iostream> // # 7796 먹을 것인가 먹힐 것인가_이분탐색
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int j=0; j<m; j++)
            cin >> b[j];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int cnt = 0;
        for(int i=0; i<n; i++) {
            int l=0, r=m-1; // 이분 탐색으로 B에서 A[i]보다 작은 개수 카운팅
            while(l <= r) {
                int mid = (l+r)/2;

                if(b[mid] >= a[i]) r = mid-1;
                else if(b[mid] < a[i]) l = mid+1;
            }

            cnt += l; // l은 A[i]보다 작은 B의 원소 개수
        }
        cout << cnt << '\n';
    }

    return 0;
}
//////////////////////////////////////////////////////////////////////
#include <iostream> // # 7796 먹을 것인가 먹힐 것인가_투 포인터
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int j=0; j<m; j++)
            cin >> b[j];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int cnt = 0;
        for(int i=0, j=0; i<n && j<m; i++) { // 투 포인터
            if(a[i] > b[j])
                cnt += m-j;
            else
                j++, i--;
        }
        
        cout << cnt << '\n';
    }

    return 0;
}