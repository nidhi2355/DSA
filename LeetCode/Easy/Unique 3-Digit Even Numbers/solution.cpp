class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {0};
        for (int digit : digits) {
            count[digit]++;
        }
        
        int validNumbers = 0;
        
        for (int i = 100; i <= 998; i += 2) {
            int currentCount[10] = {0};
            
            currentCount[i / 100]++;
            currentCount[(i / 10) % 10]++;
            currentCount[i % 10]++;
            
            bool isPossible = true;
            for (int j = 0; j < 10; ++j) {
                if (currentCount[j] > count[j]) {
                    isPossible = false;
                    break;
                }
            }
            
            if (isPossible) {
                validNumbers++;
            }
        }
        
        return validNumbers;
    }
};