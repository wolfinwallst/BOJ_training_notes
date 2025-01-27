#include <iostream> // # 17609 회문_문자열 & 구현
#include <string>
using namespace std;

int isPaldrm(string s, int l, int r, bool canRemove);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        cout << isPaldrm(s, 0, s.size()-1, true) << '\n';
    }

    return 0;    
}

// canRemove로 문자 제거 기회를 1번만 허용
int isPaldrm(string s, int l, int r, bool canRemove) {
    while(l < r) {
        if(s[l] != s[r]) {
            if(canRemove) { // true이면 문자 1회 제거 가능
                if(!isPaldrm(s, l+1, r, false) || !isPaldrm(s, l, r-1, false))
                    return 1; // 유사회문
            }
            
            return 2; // 둘 다 아님
        }
        l++, r--;
    }

    return 0; // 회문
}
/////////////////////////////////////////////////////////////////////
#include <iostream> //#17609 회문_문자열 & 구현
#include <string>
using namespace std;

int isPaldrm(string &s);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << isPaldrm(s) << '\n';
    }

    return 0;    
}

int isPaldrm(string &s) {
    int l = 0, r = s.size() - 1;

    while(l < r) {
        if(s[l] != s[r]) {
            int l1 = l + 1, r1 = r;   // 왼쪽 문자 제거 시
            int l2 = l, r2 = r - 1;   // 오른쪽 문자 제거 시
            
            while(l1 < r1 && s[l1] == s[r1]) l1++, r1--;
            while(l2 < r2 && s[l2] == s[r2]) l2++, r2--;
            
            if(l1 >= r1 || l2 >= r2) return 1; // 유사회문
            return 2; // 회문도 유사회문도 아님
        }
        l++, r--;
    }
    return 0; // 회문
}