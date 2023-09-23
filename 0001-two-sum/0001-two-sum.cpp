struct IDNum
{
    bool operator<(const IDNum& other) const
    {
        return num<other.num;
    }

    int id;
    int num;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);

        vector<IDNum> cache;
        for(int i=0;i<nums.size();i++)
            cache.push_back({i, nums[i]});

        sort(cache.begin(), cache.end());

        for(int i=0;i<cache.size();i++)
        {
            int l = i + 1;
            int r = cache.size() - 1;
            while (l <= r)
            {
                int mid = (l + r)/2;
                
                if (cache[i].num + cache[mid].num > target) r = mid - 1;
                else if (cache[i].num + cache[mid].num < target) l = mid + 1;
                else
                {
                    ret[0] = cache[i].id;
                    ret[1] = cache[mid].id;
                    return ret;
                }
            }
        }

        return ret;
    }
};