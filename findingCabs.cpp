#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Cab {
public: 
    int x, y;

    Cab(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int dist() {
        return (this->x * this->x) + (this->y * this->y);
    }
};

class Compare {
public:
    bool operator()(Cab* A, Cab* B) {
        return A->dist() < B->dist();
    }
};

void nearestCabs(vector<Cab*> &cabs, int k) {
    priority_queue<Cab*, vector<Cab*>, Compare> cabs_heap(cabs.begin(), cabs.begin() + k);

    for (int i = k; i < cabs.size(); i++) {
        if ( cabs[i]->dist() < cabs_heap.top()->dist() ) {
            cabs_heap.pop();
            cabs_heap.push(cabs[i]);
        }
    }

    vector<Cab*> result;
    while ( !cabs_heap.empty() ) {
        result.push_back(cabs_heap.top());
        cabs_heap.pop();
    }
    reverse(result.begin(), result.end());

    for (auto cab: result) {
        cout << cab->x << " " << cab->y << endl;
    }

}

int main(void) {
    vector<pair<int,int>> positions = { {10,10}, {1,1}, {5,2}, {1,7}, {11,2}, {2,12} };

    vector<Cab*> cabs;
    for (auto p: positions) {
        Cab *newCab = new Cab(p.first, p.second);

        cabs.push_back(newCab);
    }

    nearestCabs(cabs, 3);

    return 0;
}