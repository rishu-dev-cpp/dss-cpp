#include <bits/stdc++.h>
using namespace std;
vector<int> nums; 
vector<int> subset;
void findSubsets(int index) {
    if (index == nums.size()) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
        return;
    }
    // Choice 1: Include the current element
    subset.push_back(nums[index]);
    findSubsets(index + 1);
    // Choice 2: Exclude the current element (Backtrack)
    subset.pop_back();
    findSubsets(index + 1);
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }
    cout << "\nAll possible subsets:\n";
    findSubsets(0); // Start recursion from the first index
    return 0;
}