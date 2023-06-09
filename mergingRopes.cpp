#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int mergeRopes(vector<int> &ropes) {
    priority_queue<int, vector<int>, greater<int>> min_heap(ropes.begin(), ropes.end());
    int cost = 0;

    while ( min_heap.size() > 1 ) {
        int top1 = min_heap.top();
        min_heap.pop();
        int top2 = min_heap.top();
        min_heap.pop();

        cost += top1 + top2;

        min_heap.push(top1 + top2);
    }
    // cost += min_heap.top();
    min_heap.pop();

    return cost;
}


int main(void) {
    vector<int> ropes = {4,3,2,6};

    cout << mergeRopes(ropes) << endl;


    return 0;
}