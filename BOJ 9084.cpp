#include <iostream> // #9084 동전_0-1 배낭 문제
#include <algorithm>
using namespace std;
#define MAX 10001

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n;

        int unit[n+1], dp[MAX]={0, }; // dp[i] := i원을 만드는 경우의 수
        for(int i=1; i<=n; i++)
            cin >> unit[i];

        cin >> m;
        dp[0] = 1; // base case
        for(int i=1; i<=n; i++) {
            for(int j=unit[i]; j<=m; j++) {
                dp[j] += dp[j - unit[i]];
            }
        }
        cout << dp[m] << '\n';
    }

    return 0;
}
/*
unit과 dp를 저런 식으로 선언하면, memset으로 매번 초기화할 필요 없음
*/