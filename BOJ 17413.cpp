#include <bits/stdc++.h> // #17413 단어 뒤집기 2_문자열+스택
using namespace std;

void printStk(stack<char> &stk);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s); // \n 전까지 계속 입력 받음

    stack<char> stk;
    bool tag = false;

    for(char ch : s) {
        if(ch == '<') {
            printStk(stk);
            tag = true;
            cout << ch;
        }
        else if(ch == '>') {
            tag = false;
            cout << ch;
        }
        else if(tag) {
            cout << ch;
        }
        else{
            if(ch == ' ') {
                printStk(stk);
                cout << ch;
            }
            else stk.push(ch);
        }
    }
    printStk(stk);

    return 0;
}

void printStk(stack<char> &stk) { //스택에 쌓인 문자를 역순으로 출력
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    return;
}