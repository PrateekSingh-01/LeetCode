class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

long long both = min(costBoth, cost1 + cost2);

long long common = min(need1, need2);

ans += common * both;

ans += (need1 - common) * min(cost1, costBoth);
ans += (need2 - common) * min(cost2, costBoth);

return ans;
    }
};