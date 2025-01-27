#include <iostream> // # 9086 문자열
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    while(t--) {
        string s;
        cin >> s;
        
        cout << s[0] << s[s.size()-1] << '\n';
        }

    return 0;
}
/*
size 대신 s.length() 도 가능
*/
///////////////////////////////////////////////////////////////////