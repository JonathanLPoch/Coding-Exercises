#include <iostream>
#include <string>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* l = new ListNode((l1->val + l2->val)%10);
    ListNode* tempL = l;
    ListNode* temp1 = l1->next;
    ListNode* temp2 = l2->next;
    int carryOver = (l1->val + l2->val)/10;
    
    while(temp1 || temp2 || carryOver) {
      if(temp1 && temp2) {
        if(temp1->val + temp2->val + carryOver > 9) {
          tempL->next = new ListNode((temp1->val + temp2->val + carryOver)%10);
          carryOver = 1;
        } else {
          tempL->next = new ListNode(temp1->val + temp2->val + carryOver);
          carryOver = 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
      } else if(temp1 && !temp2) {
        if(temp1->val + carryOver > 9) {
          tempL->next = new ListNode((temp1->val + carryOver)%10);
          carryOver = 1;
        } else {
          tempL->next = new ListNode(temp1->val + carryOver);
          carryOver = 0;
        }
        temp1 = temp1->next;
      } else if(!temp1 && temp2) {
        if(temp2->val + carryOver > 9) {
          tempL->next = new ListNode((temp2->val + carryOver)%10);
          carryOver = 1;
        } else {
          tempL->next = new ListNode(temp2->val + carryOver);
          carryOver = 0;
        }
        temp2 = temp2->next;
      } else {
        tempL->next = new ListNode(carryOver);
        carryOver = 0;
      }
      tempL = tempL->next;
    }
    return l;
  }
  
  void print(ListNode *l) {
    ListNode *temp = l;
    while(temp) {
      cout << temp->val << " ";
      temp = temp->next;
    }
  }
};

int main() {
  Solution s;
  ListNode* l1 = new ListNode(9);
  l1 -> next = new ListNode(9);
  l1 -> next -> next = new ListNode(9);
  ListNode* l2 = new ListNode(9);
  l2 -> next = new ListNode(9);
  ListNode* sum = s.addTwoNumbers(l1, l2);
  s.print(sum);
}
