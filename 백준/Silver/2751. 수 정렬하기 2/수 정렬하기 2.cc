#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> numbers;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        numbers.push_back(c);
    }
    sort(numbers.begin(), numbers.end());

    for(int i=0;i<n;i++) cout << numbers[i] << "\n";
}