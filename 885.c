/*
885. Boats to Save People

The i-th person has weight people[i], and each boat can carry a maximum weight of limit.
Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat_count = 0;
        sort(people.begin(), people.end(), std::greater<int>());
        int left = 0;
        int right = people.size()-1;
        while(left <= right){
            boat_count++;
            int boat_limit = limit - people[left];
            left++;
            if(boat_limit >= people[right]){
                right--;
            }
        }
        return boat_count;
    }
};
