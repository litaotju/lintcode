/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/sort-integers-ii
@Language: C++
@Datetime: 16-07-29 13:09
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        if(A.empty())
            return;
        //build_heap(A, 0);
        sort(A.begin(), A.end());
        /*
        for(int start = 0 ; start < A.size(); start++){
            build_heap(A, start);
        }
        */
    }
    
private:
    void build_heap(vector<int> & A, int start){
        for(int root = (A.size()-start)/2-1 + start; root >= start; root--){
            heapify(A, start, root);
        }
    }
    
    void heapify(vector<int> & A, int start, int root){
        while(root < A.size()){
            int small = root;
        
            int leftChild = (root-start)*2+1+start;
            int rightChild = (root-start)*2+2+start;
        
            if(leftChild < A.size() && A[root] > A[leftChild])
                small = leftChild;
            if(rightChild < A.size() && A[small] > A[rightChild])
                small = rightChild;
                
            if(small!=root){
                int temp = A[root];
                A[root] = A[small];
                A[small] = temp;
                root = small;
            }else{
                break;
            }
        }
    }
};