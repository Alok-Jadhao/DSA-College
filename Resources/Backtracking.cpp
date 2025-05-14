#include<bits/stdc++.h>
using namespace std;

void printSubset(vector<int>& subset) {
    cout << "{ ";
    for(int num: subset) cout << num << " ";
    cout << "}" << endl;
}

void sumOfSubset(vector<int>& nums, vector<int>& subset, int n, int index, int currSum, int target) {
    if(currSum == target) {
        printSubset(subset);
        return;
    }

    if(index == n || currSum > target) return;

    subset.push_back(nums[index]);
    sumOfSubset(nums, subset, n, index+1, currSum + nums[index], target);

    subset.pop_back();
    sumOfSubset(nums, subset, n, index+1, currSum, target);
}

int main() {
    int n, m;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> weights(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
        cin >> weights[i];

    cout << "Enter the target sum: ";
    cin >> m;

    vector<int> subset;
    cout << "Subsets whose sum is " << m << ":" << endl;
    sumOfSubset(weights, subset, n, 0, 0, m);

    return 0;
}