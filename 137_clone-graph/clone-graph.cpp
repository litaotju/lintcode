/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/clone-graph
@Language: C++
@Datetime: 16-06-12 11:45
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     *
    */
     typedef UndirectedGraphNode * Node;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            // write your code here
            if(node==NULL)
                return NULL;
            map<UndirectedGraphNode*,UndirectedGraphNode*> colone;
            set<UndirectedGraphNode*> visited;
            queue<UndirectedGraphNode *> q;
    
            //复制第一个节点
            UndirectedGraphNode * newhead = new UndirectedGraphNode(node->label);
            colone[node] = newhead;
            q.push(node);
            visited.insert(node);
            
            //广度优先遍历旧图
            while(!q.empty()){
                UndirectedGraphNode * old = q.front();
                q.pop();
                if(colone.find(old)==colone.end())
                    colone[old] = new UndirectedGraphNode(old->label);
                UndirectedGraphNode * newer = colone[old];
                
                for(auto it = old->neighbors.begin(); it != old->neighbors.end(); it++){
                    if(colone.find(*it)==colone.end()){
                        colone[*it] = new UndirectedGraphNode((*it)->label);
                    }
                    newer->neighbors.push_back(colone[*it]);
                    if(visited.find(*it)==visited.end()){
                        visited.insert(*it);
                        q.push(*it);
                    }
                }
            }
            return newhead;
        }
};
