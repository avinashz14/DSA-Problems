class Solution {
public:
    struct Trie {
    
        Trie* child[2];
        Trie()
        {
            child[0]=NULL;
            child[1]=NULL;
        }
    };
    
    Trie* insert(Trie* node, int num)
    {
        
       
        for(int i=31; i>=0; i--)
        {
             int bit = ((num>>i)&1);
            if(node->child[bit]==NULL)
            {
                node->child[bit] = new Trie();
            }
            node = node->child[bit];
        }
        
        return node;
        
    }
    
    int queryXor(Trie* node, int num)
    {
        int res = 0;
        
        for(int i=31; i>=0; i--)
        {
            int bit = ((num>>i)&1);
            if(node->child[bit^1])
            {
                res=res|(1<<i);
                node= node->child[bit^1];
            }
            else 
                node = node->child[bit];
        }
        
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        Trie* node = new Trie();
        
        int maxXor=0;
        int j=0;
        for(auto &a: nums)
        {   
            if(j!=0)
            {
                int curXor = queryXor(node, a);
                maxXor= max(maxXor, curXor);
            }
            insert(node, a);
            j++;
        }
        return maxXor;
    }
};