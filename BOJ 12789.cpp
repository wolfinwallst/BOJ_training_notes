#include <iostream> // #12789 도키도키 간식드리미_스택
#include <stack>
using namespace std;

int main() {
    int N, order = 1;
    cin >> N;
    stack<int> stk;

    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        
        if(x == order) order++; // 순서가 맞다면 다음 순서로
        else stk.push(x);       // 안 맞으면 스택에 쌓고

        while(!stk.empty() && stk.top()==order) { // 스택 맨 위가 현재 순서이면
            stk.pop();
            order++;            // 다음 순서로
        }
    }

    if(stk.empty()) cout << "Nice";
    else cout << "Sad";
}