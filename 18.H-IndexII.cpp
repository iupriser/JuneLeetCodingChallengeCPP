
//NON-OPTIMAL METHOD
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low=0,high=n,mid;
        int res;
        
        while(low<=high)
        {
            mid = low+(high-low)/2;
            int ub = lower_bound(citations.begin(),citations.end(),mid) - citations.begin();
            
            if(n-ub >= mid)
            {
                res = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return res;
    }
};

//OPTIMAL METHOD
/*
class Solution {
public:
    int hIndex(vector<int>& citations) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        
        int n = citations.size();
        int low=0,high=n-1,mid;
        
        while(low<=high)
        {
            mid = low+(high-low)/2;
            if(citations[mid]==(n-mid))
                return citations[mid];
            else if(citations[mid]>(n-mid))
                high = mid-1;
            else
                low = mid+1;
        }
        return n-low;
    }
};

*/
