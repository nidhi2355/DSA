/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));

        ListNode* temp= head;

        int left=0, right= n-1, top=0, bottom= m-1;

        while(temp){
            for(int j= left; j<=right and temp; j++){
                mat[top][j]= temp->val;
                temp= temp->next;
            }

            if(!temp) break;
            top++;

            for(int i= top; i<= bottom and temp; i++){
                mat[i][right]= temp->val;
                temp= temp->next;
            }

            if(!temp) break;
            right--;

            for(int j= right; j>=left and temp; j--){
                mat[bottom][j]= temp->val;
                temp= temp->next;
            }

            if(!temp) break;
            bottom--;

            for(int i= bottom; i>= top and temp; i--){
                mat[i][left]= temp->val;
                temp= temp->next;
            }
            if(!temp) break;
            left++;
        }

        return mat;
    }
};