#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;

// TC = 0(1)
struct Node* insert(int val) {
   struct Node* newNode = new Node();
   newNode->data = val;
   newNode->next = head;
   head = newNode;
   return head;
}

// TC = 0(N) N=length of linked list
struct Node* deleteByPosition(int position){
    if(!head) return NULL;
    struct Node* temp = head;
    if(position==0){
        head=temp->next;
        delete(temp);
        return head;
    }
    else{
        int i=1;
        while(temp!=NULL && i<position-1){
            temp=temp->next;
            i++;
        }
        if(!temp || !temp->next) return head;
        struct Node *next = temp->next->next;
        delete(temp->next);
        temp->next = next;
    }
    return head;
}

// TC = 0(N)
struct Node* deleteParticularValue(int val){
    if(!head) return NULL;
    if(!head->next && head->data == val) return NULL;

    struct Node *temp=head;
    while(head->data==val){
        head=head->next;
    }
    while(temp->next){
        if(temp->next->data==val){
            temp->next=temp->next->next;
        }
        else temp=temp->next;
    }
    return head;
}

// TC = 0(N)
struct Node* deleteSubseqNode(int val){
    if(!head || head->data==val) return NULL;
    struct Node* temp=head;
    struct Node *pre;
    while(temp->data!=val){
        pre=temp;
        temp=temp->next;
    }
    pre->next=NULL;
    return head;
}


// TC = 0(N)
int memorySpace(){
    if(!head) return 0;
    struct Node* t=head;
    int count=0;
    while(t){
       count++;
       t=t->next;
    }
    return count * sizeof(Node);
}

void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
   cout<<endl;
}
int main() {
  head = insert(3);
  head = insert(2);
  display();
  head = deleteParticularValue(3);
  display();
  cout<<memorySpace();
   
   return 0;
}