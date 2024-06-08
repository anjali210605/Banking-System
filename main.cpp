#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
class snode{

private:
unsigned int accno;
int cbalance=1000;
snode *next;

public:
    snode(){
      accno=-1;;
      next=nullptr;
}
    snode(int d){
      accno=d;
      next=nullptr;
    }
 friend class sll;
 friend class dll;
};

class dnode{

private:
int accno;
char type;
int t_no;
dnode *next;
dnode *prev;

public:
    dnode(){
     accno=-1;
      next=nullptr;
      prev=nullptr;
}
    dnode(int d,char x,int t){
      this->accno=d;
      this->type=x;
      this->t_no=t;
      this->next=nullptr;
      this->prev=nullptr;
    }

   friend class dll;
   friend class sll;
};


class sll{

private:
snode *first;
snode *last;
int len1;

public:
sll(){
    first= new snode;
    last= new snode;
  first=nullptr;
  last=nullptr;
  len1=0;
}

// void sinsert(unsigned int d){
//   snode *toaddNode= new snode;
//   snode*temp;
//   assert(toaddNode->data==d);
//   if(first==nullptr){
//     first=toaddNode;
//     len1++;
//   } else {
//     snode *temp=first;
//     temp=first;
//     while(temp->next!=nullptr){
//     temp=temp->next;
//       temp->next=toaddNode;
//       len1++;
//     }
//   }
// }
 void M();
  void VX(int);
  void GX(int);
void sinsert(unsigned int);
snode *getfirst();
void printslllist();
};

void sll::sinsert(unsigned int x) {
  snode *toinsert = new snode;
  toinsert->accno = x;
  if (first == nullptr) {
    first = last = toinsert;
    len1++;
  } else {
    last->next = toinsert;
    last = toinsert;
    len1++;
  }
}
snode *sll::getfirst() { return first; }

void sll::printslllist() {
  snode *temp = first;
  while (temp != nullptr) {
    cout << temp->accno << " " << temp->cbalance << '\n';
    temp = temp->next;
  }
}

void sll::GX(int k) {
  int t1 = 0;
  snode *temp = first;
  while (temp != nullptr) {
    if (temp->cbalance >= k) {
      t1++;
    }
    temp = temp->next;
  }
  cout<< t1 << endl;
}

void sll::VX(int k) {
  snode *temp = first;
  while (temp != nullptr) {
    if (temp->accno == k) {
      cout << temp->cbalance << '\n';
    }
    temp = temp->next;
  }
}

void sll::M() {
  snode *temp = first;
  int max = first->cbalance;
  vector<int> result;
  while (temp != nullptr) {
    if (temp->cbalance > max) {
      max = temp->cbalance;
    }
    temp = temp->next;
  }
  snode *temp1 = first;
  while (temp1 != nullptr) {
    if (temp1->cbalance == max) {
      result.push_back(temp1->accno);
      //cout<<temp1->accno<<endl;
    }
    temp1 = temp1->next;
  }
  sort(result.begin(), result.end());
  for (int i = 0; i <= result.size() - 1; i++) {
    cout << result[i] << " ";
  }
  cout << '\n';
}


class dll{

private:
dnode *head;
dnode *tail;
dnode *cursor;
unsigned int len2;

public:
dll(){
  head= new dnode;
  tail= new dnode;
  
  head->next=tail;
  head->prev=nullptr;
  tail->prev=head;
  tail->next=nullptr;
  cursor=head;
  len2=0;
}


void dinsert(int,char,int,sll);
void printdlllist();
  void FX(int, sll *);
  void RY(int, sll *);
  friend class sll;
  void ITK(int, int, char, int, sll *);
  void DAM(int, int, sll *);
  void processallafterc(sll *);
  void SY(int, sll *);
};

void dll::dinsert(int accno,char t,int x,sll list){
 int n=0;
  snode *temp=(list).getfirst();
  while(temp!=nullptr){
if(temp->accno==accno){
    n++;
}
  temp=temp->next;
  }
 if(n==0){
    return;
 }
  dnode *toinsert=new dnode;
toinsert->accno=accno;
toinsert->type=t;
toinsert->t_no=x;

toinsert->prev=tail->prev;
toinsert->next=tail;
(tail->prev)->next=toinsert;
tail->prev=toinsert;
}

void dll::printdlllist() {
  dnode *temp = head->next;
  while (temp->next != nullptr) {
    cout << temp->accno << " " << temp->type << " " << temp->t_no << endl;
    temp = temp->next;
  }
}

void dll::FX(int k, sll *list) {

  if (cursor == tail->prev || cursor == tail)
    return;
  cursor = cursor->next;
  for (int i = 1; i <= k; i++) {
    snode *temp = list->getfirst();
    while (cursor->accno != temp->accno) {
      temp = temp->next;
    }
    if (cursor->type == 'D') {
      temp->cbalance += cursor->t_no;
    } else {
      temp->cbalance -= cursor->t_no;
    }
    if (cursor->next == tail) {
      break;
    } else {
      if (i != k) {
        cursor = cursor->next;
      }
    }
  }
}

int main() {
  int n;
  cin>>n;
   sll acclist;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    (acclist).sinsert(a);
  }
  int m;
  cin>>m;
  dll translist;
  for(int i=0;i<n;i++){
    int b,d;
   char c;
    cin>>b>>c>>d;
    (translist).dinsert(b,c,d,acclist);
  }

  
  


  
    return 0;
  
}