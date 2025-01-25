#include <iostream> // #1158 요세푸스 문제_큐
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    queue<int> que;
    for(int i=1; i<=n; i++) {
        que.push(i);
    }

    cout << "<";
    while(!que.empty()) {
        for(int i=0; i<k-1; i++) {
            que.push(que.front());
            que.pop();
        }

        if(que.size() > 1) { // 기존 코드의 jos 큐를 쓰지 않는 방법
            cout << que.front() << ", ";
            que.pop();
        }
        else {
            cout << que.front();
            que.pop();
        }

    }
    cout << ">";
    return 0;
}
//////////////////////////////////////////////////////////////////
#include <iostream> // #1158 요세푸스 문제_벡터
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        arr[i] = i+1;
    }

    int idx = 0;
    cout << "<";
    while(!arr.empty()) {
        idx = (idx+k-1) % arr.size();
        cout << arr[idx];
        arr.erase(arr.begin() + idx);

        if(!arr.empty()) {
            cout << ", ";
        }
    }
    cout << ">";
    return 0;
}
/*

*/