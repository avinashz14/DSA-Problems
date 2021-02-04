/*

Solution using Binary Trie understandable and easy implementation  
@nithost_16

*/
class Solution {
public:
    
    // Created a trie structure with 2 child same as name suggest (0th child for 0's and 1th for 1's bit)
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
        
       // Number is represented as 32 bit and  0ᵗʰ bit signifies least significatent bit of the number
       // and 31ᵗʰ bit MSB 

        for(int i=31; i>=0; i--)
        {
            // bit represent bit(0 or 1's) at  iᵗʰ position in num 
             int bit = ((num>>i)&1);

             //if in node exist at cur position then must create new one
            if(node->child[bit]==NULL)
            {
                node->child[bit] = new Trie();
            }
            //  and then follow the path  
            node = node->child[bit];
        }
        
        return node;
        
    }
    
    // in Query part we try to get as close as possible to opposite bits than num has 
    // e.g   num = 9 (1001) opposite bits num= 6 (0110) this will give us maxXor 
    //for sake of simplicity i taked 4 bits only (actual is 32 bits)
    int queryXor(Trie* node, int num)
    {
        int res = 0;
        
        for(int i=31; i>=0; i--)
        {
            int bit = ((num>>i)&1);
            //try to go opposite bit side if not null 
            if(node->child[bit^1])
            {
                res=res|(1<<i); // increase res with pow(2, i) 
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
            // at j==0 Trie is empty so query process is not possible 
            if(j!=0)
            {
                int curXor = queryXor(node, a);
                maxXor= max(maxXor, curXor); // take max from cur and max Xor
            }
            insert(node, a);
            j++;
        }
        return maxXor;
    }
};

