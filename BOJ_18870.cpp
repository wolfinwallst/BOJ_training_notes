#include <iostream> // #18870 좌표 압축_정렬
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> copy_v(n); // copy_v로 복사
    copy(v.begin(), v.end(), copy_v.begin());
    sort(copy_v.begin(), copy_v.end());
    copy_v.erase(unique(copy_v.begin(), copy_v.end()), copy_v.end()); // 중복 제거

    for (int i = 0; i < n; i++)
    {
        int len = lower_bound(copy_v.begin(), copy_v.end(), v[i]) - copy_v.begin();
        cout << len << ' ';
    }

    return 0;
}
/* 벡터 v로 입력받고, 복사본 copy_v을 만든 후, 정렬 & 중복 제거 후
lower_bound(,,v[i])-copy_v.begin() 을 출력
*/