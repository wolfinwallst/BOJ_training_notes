#include <iostream> // #1535 안녕_ 0-1 배낭 문제
#include <algorithm>
using namespace std;
#define MAX 21

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    int L[MAX], J[MAX];
    for(int i=1; i<=n; i++)
        cin >> L[i];
    for(int i=1; i<=n; i++)
        cin >> J[i];

    int dp[101] = {0, }; // dp[j]:= 체력 j일 때 가능한 최대 기쁨 합
    for(int i=1; i<=n; i++) {
        for(int j=100; j>L[i]; j--) {
                dp[j] = max(dp[j], dp[j-L[i]] + J[i]);
        }
    }

    cout << dp[100];
    return 0;
}
/*
dp를 전역 함수로 선언하면 0으로 자동 초기화 되지만
main 함수 내에서 선언시 위처럼 초기화 안하면 쓰레기 값이 들어간다. 
*/