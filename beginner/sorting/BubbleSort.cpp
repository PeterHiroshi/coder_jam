//
// Created by 清水ヒロシ on 2018/11/20.
//
// from ALDS1_2_A: Bubble Sort
//

#include <iostream>

using namespace std;

void traceArr(int *arr, int n)
{
    for (int i=0; i<n; ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << arr[i];
    }
    cout << endl;
}

void bubbleSort()
{
    int N;
    cin >> N;
    auto *arr = new int[N];
    for (int i=0; i<N; ++i) {
        cin >> *(arr + i);
    }
    int swapTime = 0;
    int tmp;
    for (int i=0; i<N-1; ++i) {
        for (int j=N-1; j>=i+1; --j) {
            if (arr[j] < arr[j-1]) {
                tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
                swapTime ++;
            }
        }
    }
    traceArr(arr, N);
    cout << swapTime << endl;
    delete[] arr;
}

int main()
{
    bubbleSort();
    return 0;
}