#define pi pair<int,ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0)
         return NULL;

        priority_queue<pi, vector<pi> , greater<pi>> pq;

        for(int i=0;i<k;i++)
        {
            ListNode *cur = lists[i];

            if(cur != NULL)
             pq.push({cur->val, cur});
        }
         
        if(pq.size() == 0)
          return NULL;
        ListNode *head = new ListNode();
        ListNode *cur = head;
       
        while(!pq.empty())
        {
            int v = pq.top().first;
            ListNode* li = pq.top().second;
            pq.pop();

            if(li->next!=NULL)
            {
                pq.push({li->next->val, li->next });
            }
            cur->next = li;
            cur = cur->next;

        }

        cur->next = NULL;

        return head->next;
    }
};
