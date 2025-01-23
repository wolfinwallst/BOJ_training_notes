#include <iostream> // #2023 신기한 소수_소수, 백트래킹
#include <algorithm>
using namespace std;

bool isPrime(int num);
void bt(int depth, int num);

int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int first_digits[] = {2, 3, 5, 7}; // 한 자리 수는 소수만
    cin >> n;
    
    for(int i=0; i<4; i++)
        bt(1, first_digits[i]);
    
    return 0;
}

void bt(int depth, int num) { // 백트래킹
    if(!isPrime(num)) return;

    if(depth == n) { // 소수이면서 n자리
        cout << num << '\n';
        return;
    }

    for(int i=1; i<=9; i+=2) { // i=0은 할 필요 없고 홀수만 탐색해도 충분
        bt(depth + 1, num*10 + i);
    }

    return;
}

bool isPrime(int num) {
    for(int i=2; i*i<=num; i++){
        if(num%i == 0)
            return false;
    }

    return true;
}