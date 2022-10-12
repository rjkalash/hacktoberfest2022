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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1,*p2=l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr=dummy;
        while (p1!=nullptr && p2!=nullptr)
        {
            if(p1->val < p2->val ){
                ptr->next = p1;
                p1=p1->next;
            }
            else{
                ptr->next=p2;
                p2=p2->next;
            }
            ptr=ptr->next;
        }
        while (p1!=nullptr)
        {
            ptr->next = p1;
            p1=p1->next;
            ptr=ptr->next;
        }
        while (p2!=nullptr)
        {
            ptr->next=p2;
            p2=p2->next;
            ptr=ptr->next;
        }
        
        return dummy->next;
}
    class comp{
        public:
        bool operator()(const ListNode *p , const ListNode *q){
            return p->val > q->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode* , vector<ListNode*> , comp > pq;
        
        for(int i= 0; i < lists.size() ; i++ ){
            
            if(lists[i] != nullptr)
                pq.push( lists[i] );
        }
        ListNode *res = new ListNode(-1);
        ListNode *ptr =res;
        while(pq.size() ){
            auto it = pq.top();
            pq.pop();
            ptr->next = it;
            ptr =ptr->next;
            if(it->next != nullptr){
                pq.push(it->next);
            }
        }
        return res->next;
    }
};
