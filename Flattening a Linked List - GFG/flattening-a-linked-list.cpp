//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    


Node* merge(Node* left,Node* right){
        Node* head=NULL,*temp;
        while(left!=NULL && right!=NULL){
            Node* newNode=new Node(INT_MIN);
            if(left->data<right->data){
                newNode->data=left->data;
                left=left->bottom;
            }
            else{
                newNode->data=right->data;
                right=right->bottom;
            }
                
            
            if(head==NULL){
                head=newNode;
                temp=head;
            }else{
                temp->bottom=newNode;
                temp=temp->bottom;
            }
        }
        while(left!=NULL){
            Node* newNode=new Node(INT_MIN);
            newNode->data=left->data;
            left=left->bottom;
            temp->bottom=newNode;
            temp=temp->bottom;
        }
        while(right!=NULL){
            Node* newNode=new Node(INT_MIN);
            newNode->data=right->data;
            right=right->bottom;
            temp->bottom=newNode;
            temp=temp->bottom;
        }
        return head;
    }
    Node* getMid(Node* head){
        Node *slow=head,*fast=head;
        while(fast && fast->bottom!=NULL){
            slow=slow->bottom;
            fast=fast->bottom->bottom;
        }
        
        return slow;
    }
    Node* mergeSort(Node* head){
        if(!head)
            return NULL;
        if(!head->bottom)
            return head;
        Node* temp=head,*mid;
        mid=getMid(head);
        while(temp->bottom!=mid){
            temp=temp->bottom;
        }
        temp->bottom=NULL;
        Node* left=mergeSort(head);
        Node* right=mergeSort(mid);
        return merge(left,right);
    }

Node *flatten(Node *root){
   Node* cur=root,*nxt=root->next;
   while(nxt){
       while(cur->bottom){
           cur=cur->bottom;
       }
       cur->bottom=nxt;
       cur=nxt;
       nxt=nxt->next;
   }
   Node* last=root;
   while(last->bottom){
       last=last->bottom;
   }
//   cout<<last->data;
   return mergeSort(root);
}

