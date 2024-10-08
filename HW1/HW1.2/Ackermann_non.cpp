#include <iostream>
#include <stack>
using namespace std;


struct State {
    int m;
    int n;
};

int ackermann_non_recursive(int m, int n) {
    stack<State> stk; 
    stk.push({m, n});

    while (!stk.empty()) {
        State top = stk.top(); 
        stk.pop();

        m = top.m;
        n = top.n;

        if (m == 0) {
            n += 1;
        } else if (n == 0) {
            stk.push({m - 1, 1});
        } else {
            stk.push({m - 1, -1}); 
            stk.push({m, n - 1});
            continue;
        }

        if (!stk.empty() && stk.top().n == -1) {
            m = stk.top().m;
            stk.pop();
            stk.push({m, n});
        }
    }

    return n;
}

int main() {
    int m, n;
    cout << "Enter values for m and n: ";
    cin >> m >> n;
    cout << "Ackermann non-recursive(" << m << ", " << n << ") = " << ackermann_non_recursive(m, n) << endl;
    return 0;
}

