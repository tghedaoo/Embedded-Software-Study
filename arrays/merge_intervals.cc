// Samsung flavour: insert interval in the list of intervals.
// https://leetcode.com/problems/insert-interval/description/
// leetcode: Merge Intervals. https://leetcode.com/problems/merge-intervals/solutions/127480/merge-intervals/
// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // Sorting to go sequentially and not check all intervals in the list O(n2))
        // Now its O(nlogn)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= end)
            {
                if(intervals[i][0] < start)
                {
                    start = intervals[i][0];
                }

                if(intervals[i][1] > end)
                {
                    end = intervals[i][1];
                }
            }
            else
            {
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start,end});
        return result;
    }
};