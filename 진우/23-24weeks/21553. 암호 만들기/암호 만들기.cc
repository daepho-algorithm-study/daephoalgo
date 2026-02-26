#include <iostream>  
#include <string>    

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
                                      
    cin.tie(nullptr);                 
                                      

    string A; 
    cin >> A;  

    string P;  
    cin >> P;  

    cout << P << "\n";  // P를 출력
                        // 현재 코드에서는 P를 그대로 B로 출력하는 간단한 방식
                        // (조건을 만족하는 B 중 하나로 P 자체를 선택한 경우)

    return 0; 
}
