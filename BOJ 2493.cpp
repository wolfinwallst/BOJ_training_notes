#include <iostream> // #2493 탑_스택
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

    // stk:= 확인한 탑들 중 가장 가까운, 높이가 높은 후보 탑들을 쌓은 스택
    stack<pair<int, int>> stk; // 쌍은 idx, h 꼴
    for(int i=1; i<=n; i++) {
		int h;
		cin >> h;
		
		while(!stk.empty()) {
			if(h < stk.top().second) {
				cout << stk.top().first << ' ';
				break;
			}
			stk.pop();
		}
		
		if(stk.empty())
            cout << '0' << ' ';
		
		stk.push(make_pair(i, h));
	}
    while(!stk.empty()) {
        cout << stk.top().second << ' ';
        stk.pop();
    }
	return 0;
}