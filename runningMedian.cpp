#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main(void) {
    vector<int> numbs = {10,5,2,3,0,12,18,20,22};

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    vector<float> med;
    med.push_back(numbs[0]);
    float median = numbs[0];

    max_heap.push(numbs[0]);
    for (int i = 1; i < numbs.size(); i++) {
        int newNumber = numbs[i];

        if ( max_heap.size() > min_heap.size() ) {
            if (newNumber > median) {
                min_heap.push(newNumber);
            }
            else {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(newNumber);
            }
            median = (max_heap.top() + min_heap.top()) / 2.0;
            med.push_back(median);
        }
        else if ( max_heap.size() < min_heap.size() ) {
            if (newNumber > median) {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(newNumber);
            }
            else {
                max_heap.push(newNumber);
            }
            median = (max_heap.top() + min_heap.top()) / 2.0;
            med.push_back(median);
        }
        else {
            if (newNumber > median) {
                min_heap.push(newNumber);
                median = min_heap.top();
                med.push_back(median);
            }
            else {
                max_heap.push(newNumber);
                median = max_heap.top();
                med.push_back(median);
            }
        }

    }

    for (auto n: med) cout << n << " ";
    cout << endl;
    cout << "med.length(): " << med.size() << endl;


    return 0;
}