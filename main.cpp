#include <chrono>
#include <iostream>
#include <string>
#include "circular_list.h"

#define MAX_SIZE 1048576
using namespace std;

#define CASE_11
int main(int argc, char *[]) {
  chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    CirculaList<int> list(MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) list.Push(i);

    int b = 0;

    for (int i = MAX_SIZE - 1; i >= 0; i--) {
      list.At(i, b);
      // cout << std::to_string(b) << " ";
    }
    // cout << '\n';

    for (int i = 0; i < MAX_SIZE; i++) list.Pop(b);
 
  chrono::steady_clock::time_point end = chrono::steady_clock::now();

  cout << "Time difference = "
       << chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
       << endl;
}
