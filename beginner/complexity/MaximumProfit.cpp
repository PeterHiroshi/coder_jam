//
// Created by Peter on 2018/11/19.
//
// from ALDS 1_1_D: Maximum Profit
//

#include <iostream>
#include <ctime>

using namespace std;

void drive_offline()
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

void drive_online()
{
    int n;
    cin >> n;
    int curr_val;
    int max_val = -1000000000;
    int min_val = -max_val;
    for (int i=0; i<n; ++i) {
        cin >> curr_val;
        if (i == 0) {
            min_val = curr_val;
        } else {
            max_val = max(max_val, curr_val-min_val);
            min_val = min(min_val, curr_val);
        }
    }
    cout << max_val << endl;
}

int main()
{
    clock_t start = clock();
    drive_offline();
    printf("costs:%.3fms\n", ((clock()-start)*1000)/(double)CLOCKS_PER_SEC);
    start = clock();
    drive_online();
    printf("costs:%.3fms\n", ((clock()-start)*1000)/(double)CLOCKS_PER_SEC);
    return 0;
}