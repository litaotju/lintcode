/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/heapify
@Language: C++
@Datetime: 16-07-28 16:01
*/


void print_v(const vector<int> &A){
	for(auto &v:A){
		cout <<v<<" ";
	}
    cout<<endl;
}

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        if(A.empty())
            return;
        for(int root = A.size()/2-1; root >=0; root--){
            heapify(A, root);
            //cout<<root<<endl;
            //print_v(A);
        }
    }
    
private:
    void heapify(vector<int> &A, int root){
        while(root<A.size()){
            int small = root;
            //左儿子比较小
            if( root*2+1 < A.size() && A[root]>A[root*2+1]){
                small = root*2 + 1;
            }
            //右儿子比较小
            if(root*2+2 < A.size() && A[small]>A[root*2+2]){
                small = root *2 +2;
            }
            //和小的更换
            if(small != root){
                swap(A[small], A[root]);
                root = small;
            }else{
                break;
            }
        }
    }
    
private:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};
