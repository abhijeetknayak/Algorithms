#include <iostream>

using namespace std;

int numStepsBottomUp(int n) 
{
    int arr[n + 1] = {1, 0};

    for (int idx = 0; idx < n; idx++) 
    {
        for (int k = 1; k <= 3; k++)
        {
            int new_idx = idx + k;
            if (new_idx <= n) arr[new_idx] += arr[idx];
        }
    }

    return arr[n];

}

int numStepsTopDown(int n, int memo[])
{
    if (n < 0) return 0;
    else if (n == 0) return 1;
    else if (memo[n] > -1) return memo[n];
    else {
        memo[n] = numStepsTopDown(n - 1, memo) + numStepsTopDown(n - 2, memo) + numStepsTopDown(n - 3, memo);
        return memo[n];    
    }
}
int main()
{
    int n = 0;
    cout << "Enter total  number of steps (n): ";
    cin >> n;

    int num_steps = numStepsBottomUp(n);
    cout << "For n = " << n << ": Number of ways to reach last step: " << num_steps << endl;  

    int memo[n + 1] = {-1};
    for (int i = 0; i < n + 1; i++) memo[i] = -1;
    num_steps = numStepsTopDown(n, memo);  
    cout << "For n = " << n << ": Number of ways to reach last step: " << num_steps << endl; 
}

