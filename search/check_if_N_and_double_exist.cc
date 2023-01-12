#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool checkIfExist(vector<int>& arr) 
    {
        int arrSize = arr.size();
        unordered_map<int, int> map;

        for(int i = 0; i < arrSize; i++)
        {
            map[arr[i]] = i;
        }

        for(int i = 0; i < arrSize; i++)
        {
            int doub = arr[i] * 2;
            auto iter = map.find(doub);
            if(iter != map.end() && iter->second != i) // This second expression is crucial for corner case 0.
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {3,1,7,11}; 
    cout << Solution::checkIfExist(arr) << endl;

    vector<int> arr2 = {-2,0,10,-19,4,6,-8}; 
    cout << Solution::checkIfExist(arr2) << endl;

    return 0;
}
