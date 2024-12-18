
 #include <iostream>
 using namespace std;

class node 
{
public:    
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
    node(int x, node *next) : val(x), next(next) {}
};
 
class Solution 
{
public:
    bool isPalindrome(node* head)
    {
        node* temp1 = head;
        node* temp2  = head;
        
        while(temp2 && temp2->next)
        {
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }

        temp2 = nullptr;  

        while(temp1)
        {
            node * temp = temp1->next;
            temp1->next = temp2;
            temp2 = temp1;
            temp1 = temp;
        } 

        node * first_half = head;
        node * second_half = temp2;

        while(first_half && second_half)
        {
            if(first_half->val != second_half->val)
            {
                return false;
            } 
            else 
            {
                first_half = first_half->next;
                second_half = second_half->next;
            }
        }
        return true;
    }
};    