// Code-A1 (Fibonacci)

#include <iostream>
using namespace std;

int recursiveSteps = 0;
int iterativeSteps = 0;

// Recursive function for Fibonacci
int fibRecursive(int n) {
    recursiveSteps++;
    if (n <= 1)
        return n;  
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Non-recursive (Iterative) Fibonacci
void fibIterative(int n) {
    if (n <= 0)
        return;
    int prev = 0, curr = 1, next;
    cout << prev << " ";
    if (n == 1)
        return;

    cout << curr << " ";
    for (int i = 2; i < n; i++) {
        next = prev + curr;
        cout << next << " ";
        prev = curr;
        curr = next;
        iterativeSteps++;
    }
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "\nFibonacci Series using Recursion: ";
    for (int i = 0; i < n; i++) {
        cout << fibRecursive(i) << " ";
    }
    cout << "\nTotal Recursive Steps: " << recursiveSteps;

    cout << "\n\nFibonacci Series using Iteration: ";
    fibIterative(n);
    cout << "\nTotal Iterative Steps: " << iterativeSteps;

    cout << endl;
    return 0;
}

// SAMPLE OUTOUT
/*
* Enter the number of terms: 5
* 
* Fibonacci Series using Recursion: 0 1 1 2 3 
* Total Recursive Steps: 19
* 
* Fibonacci Series using Iteration: 0 1 1 2 3 
* Total Iterative Steps: 3
*/
