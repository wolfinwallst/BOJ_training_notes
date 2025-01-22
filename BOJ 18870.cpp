#include <iostream> // #18870 좌표 압축_정렬
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    vector<int> copy_v = v; // v를 copy_v로 복사
    // vector<int> copy_v(v); // 이렇게 써도 가능
    // copy(v.begin(), v.end(), copy_v.begin()); // 이거 대신 위처럼 할 수도 있음
    sort(copy_v.begin(), copy_v.end());
    copy_v.erase(unique(copy_v.begin(), copy_v.end()), copy_v.end()); // 중복 제거
    
    for(int i=0; i<n; i++) {
        int len = lower_bound(copy_v.begin(), copy_v.end(), v[i]) 
                - copy_v.begin();
        cout << len << ' ';
    }
    
    return 0;
}
/*
벡터 v로 입력받고, 복사본 copy_v을 만든 후, 정렬 & 중복 제거 후
lower_bound(,,v[i])-copy_v.begin() 을 출력

erase(s, e)는 [s, e) 범위의 인자를 삭제 -> 벡터의 크기가 줄어들며, 이후의 요소들이 앞으로 당겨짐.

unique(s.begin(), s.end())는 연속된 중복을 제거, 실제 컨테이너 크기는 불변
중복이 제거된 후 "새로운 끝 위치"를 가리키는 반복자(iterator)를 반환함.
(즉, 중복이 제거된 요소의 개수보다 1 큰 위치를 반환)

따라서,
    copy_v.erase(unique(copy_v.begin(), copy_v.end()), copy_v.end());
를 통해 copy_v는 v의 원소들 중 중복을 제거한 상태가 된다. (미리 sort를 적용해서 정렬된 상태이긴 함)
*/