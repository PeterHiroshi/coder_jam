//
// Created by 清水ヒロシ on 2018/11/20.
//
// from ALDS1_2_B: Selection Sort
//

#include <iostream>
#include <vector>

using namespace std;

void selectionSort();
void traceArr(const vector<int> &arr);

int main()
{
    selectionSort();
    return 0;
}

void selectionSort()
{
    int N;
    cin >> N;
    vector<int> arr(static_cast<unsigned long>(N));
    for (int i=0; i<N; ++i) {
        cin >> arr[i];
    }
    int swapTime = 0;
    int min_idx;
    int tmp;
    for (int i=0; i<arr.size()-1; ++i) {
        min_idx = i;
        for (int j=i+1; j<arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            tmp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = tmp;
            swapTime ++;
        }
    }
    traceArr(arr);
    cout << swapTime << endl;
}

void traceArr(const vector<int> &arr)
{
    for (int i=0; i<arr.size(); ++i) {
        if (i) {
            cout << " ";
        }
        cout << arr[i];
    }
    cout << endl;
}