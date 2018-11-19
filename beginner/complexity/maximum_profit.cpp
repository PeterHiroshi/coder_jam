//
// Created by Peter on 2018/11/19.
//
// from ALDS 1_1_D: Maximum Profit
//

#include <iostream>
#include <ctime>

using namespace std;

void drive()
{
    int n;
    cin >> n;
    auto *buffer = new int[n];
    for (int i=0; i<n; ++i) {
        cin >> buffer[i];
    }
    int max_val = -1000000000;
    int min_val = buffer[0];
    for (int j=1; j<n; ++j) {
        max_val = max(max_val, buffer[j]-min_val);
        min_val = min(min_val, buffer[j]);
    }
    delete[] buffer;
    cout << max_val << endl;
}

int main()
{
    clock_t start = clock();
    drive();
    cout << "costs:" << ((clock()-start)*1000/(double)CLOCKS_PER_SEC) << "ms";
    return 0;
}
