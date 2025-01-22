#include <iostream> // #2559 수열_연속 합_슬라이딩 윈도우 O(n)
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int arr[n], sum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];

        if(i < k) sum += arr[i]; // maxSum 초기화 O(k)
    }

    int maxSum = sum;
    for(int i=0; i<n-k; i++) { // 슬라이딩 윈도우 of size k
        sum += arr[i+k] - arr[i]; // 각 O(1)
        maxSum = max(maxSum, sum);
    }
    
    cout << maxSum;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
#include <iostream> // #2559 수열_연속 합_투 포인터 O(n)
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int arr[n], sum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];

        if(i < k) sum += arr[i]; // maxSum 초기화 O(k)
    }

    int maxSum = sum, l=0, r=k-1;
    while(r < n-1) { // 투 포인터지만 사실상 슬라이딩 윈도우
        sum += arr[++r] - arr[l++]; // r+1번 원소는 더하고, 기존 l번은 제외
        maxSum = max(maxSum, sum);
    }
    
    cout << maxSum;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
#include <iostream> // #2559 수열_연속 합_누적 합 알고리즘
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int arr[n+1], preSum[n+1]; // 누적 합 배열 preSum[i]:=arr[0~i]의 누적합
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        preSum[i] = preSum[i-1] + arr[i];
    }
    
    int maxSum = -1*MAX*100-1; // (조건상 나올 수 있는 최소값) - 1
    for(int i=k; i<=n; i++) {
        maxSum = max(maxSum, preSum[i] - preSum[i-k]);
    }
    
    cout << maxSum;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
#include <iostream> // #2559 수열_연속 합_누적 합 알고리즘
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n+1), preSum(n+1); // 누적 합 배열 preSum[i]:=arr[0~i]의 누적합
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        preSum[i] = preSum[i-1] + arr[i];
    }
    
    int maxSum = -1*MAX*100-1; // (조건상 나올 수 있는 최소값) - 1
    for(int i=k; i<=n; i++) {
        maxSum = max(maxSum, preSum[i] - preSum[i-k]);
    }
    
    cout << maxSum;
    return 0;
}