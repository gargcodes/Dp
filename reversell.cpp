class node{
    public :
    int data;
    node* next;
    node(){
        this->data=0;
        this->next=nullptr;
    } 
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
int findlength(node* &head){
    int p=0;
    node* temp=head;
    while(temp!=nullptr){
        temp=temp->next;
        p++;
    }
    return p;
}
node* reverseloop(node* &head,int k){
    if(head==nullptr){
        cout<<"LL is Empty "<<endl;
        return nullptr;
    }
    int len=findlength(head);
    if(k>len){
        cout<<"Enter Correct Value "<<endl;
        return head;
    }
    node* pre=nullptr;
    node* cur=head;
    node* forw;
    int i=0;
    while(cur!=nullptr && i<k){
        forw=cur->next;
        cur->next=pre;
        pre=cur;
        cur=forw;
        i++;
    }
    if(forw!=nullptr){
        head->next=reverseloop(forw,k);
    }
        return pre;
}
void print(node* &head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node* first=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    node* fourth=new node(40);
    node* fifth=new node(50);
    node* sixth=new node(60);
    node* head=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=nullptr; 
    print(head);
    cout<<endl;
    cout<<"Reverse LL BY Loop : "<<endl;
    int k=4;
    head=reverseloop(head,k);
    print(head);
    return 0;
}
