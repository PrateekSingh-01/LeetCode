class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        sort(reservedSeats.begin(), reservedSeats.end());

        int ans = 0;
        int uniqueRows = 0;

        int i = 0;
        int m = reservedSeats.size();

        while (i < m) {

            int row = reservedSeats[i][0];
            uniqueRows++;

            bool left = true;  
            bool mid = true;    
            bool right = true; 

            int j = i;

            while (j < m && reservedSeats[j][0] == row) {

                int seat = reservedSeats[j][1];

                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    mid = false;

                if (seat >= 6 && seat <= 9)
                    right = false;

                j++;
            }

            if (left && right)
                ans += 2;
            else if (left || right || mid)
                ans += 1;

            i = j;
        }

        ans += 2 * (n - uniqueRows);

        return ans;
    }
};