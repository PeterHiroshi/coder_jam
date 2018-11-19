//
// Created by 清水ヒロシ on 2018/11/19.
//
// from ALDS1_1_A: Insertion Sort
//

#include <iostream>

using namespace std;

void insertSort();
void traceBuffer(const int *buffer, int len);

int main()
{
    insertSort();
    return 0;
}

void insertSort()
{
    int N;
    cin >> N;
    auto *buffer = new int[N];
    for (int i=0; i<N; ++i) {
        cin >> *(buffer + i);
    }
    // input first line
    traceBuffer(buffer, N);
    // perform sort and input other lines
    int j;
    int key;
    for (int i=1; i<N; ++i) {
        key = buffer[i];
        j = i - 1;
        while ((j >= 0) && (buffer[j] > key)) {
            buffer[j+1] = buffer[j];
            j --;
        }
        buffer[j+1] = key;
        traceBuffer(buffer, N);
    }
    delete[] buffer;
}

void traceBuffer(const int *buffer, int len)
{
    for (int i=0; i<len; ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << *(buffer + i);
    }
    cout << endl;
}