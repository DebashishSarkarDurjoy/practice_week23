#include <iostream>
#include <queue>
#include <time.h>
#include <vector>

using namespace std;

void sortNumbers(vector<int> &numbers, vector<int> &result) {
    priority_queue< int > pq(numbers.begin(), numbers.begin() + numbers.size());

    while ( !pq.empty() ) {
        int top = pq.top();
        pq.pop();

        result.push_back(top);
    }    
    reverse(result.begin(), result.end());
}

int main(void) {
    srand(time(0));

    vector<int> numbers;
    for (int i = 0; i < 10; i++) {
        numbers.push_back(rand() % 10);
    }

    vector<int> result;
    sortNumbers(numbers, result);
    for (auto n: result) cout << n << " ";
    cout << endl;

    return 0;
}


