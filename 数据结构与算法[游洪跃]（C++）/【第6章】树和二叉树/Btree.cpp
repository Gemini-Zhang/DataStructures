#include<iostream>
using namespace std;
// �����������
struct BinTreeNode
{
// ���ݳ�Ա:
 double data;  // ������
 BinTreeNode *leftChild; // ����ָ����
 BinTreeNode *rightChild; // �Һ���ָ����
 BinTreeNode(){ leftChild = rightChild = NULL;};  // �޲����Ĺ��캯�� 
 BinTreeNode(double &val,BinTreeNode *lChild = NULL, BinTreeNode *rChild = NULL);
};

BinTreeNode::BinTreeNode(double &val, BinTreeNode *lChild,BinTreeNode *rChild)
{ 
 data = val;     // ����Ԫ��ֵ
 leftChild = lChild;   // ����
 rightChild = rChild;  // �Һ���
}
//�ڵ��࣬�����ݳ�ԱΪ����ڵ����͵�ָ��
struct Node 
{
BinTreeNode *data;  // ������
Node *next;  // ָ����
Node(){ next = NULL;};   
Node( BinTreeNode *item, Node *link = NULL){  data = item;   next = link;};
};
//�����࣬��Ϊ��α����ĸ������ݽṹ��
class LinkQueue 
{
protected:
 Node *front, *rear;    
public:
 LinkQueue(){rear = front = new Node; };  
 void OutQueue(BinTreeNode * &e);  // ���Ӳ���
    void InQueue(BinTreeNode * &e);   // ��Ӳ���
 bool Empty(){return front==rear;};
};

void LinkQueue::OutQueue(BinTreeNode * &e)
{  Node *tmpPtr = front->next; 
  e = tmpPtr->data;      
  front->next = tmpPtr->next;   
  if (rear == tmpPtr)
  { 
   rear = front;
  }
  delete tmpPtr;      
}

void LinkQueue::InQueue(BinTreeNode * &e)
{
 Node *tmpPtr = new Node(e); 
 rear->next = tmpPtr;       
 rear = tmpPtr;         
}
// ��������
class BinaryTree
{
protected:
 BinTreeNode *root;
// ��������:
 void DestroyHelp(BinTreeNode  * &r);     
 void PreOrderHelp(BinTreeNode  *r) const ; 
 void InOrderHelp(BinTreeNode  *r) const ; 
 void PostOrderHelp(BinTreeNode  *r) const ;
    int HeightHelp(const BinTreeNode  *r) const; 
 int NodeCountHelp(const BinTreeNode  *r) const;
 int leafNodeCountHelp(const BinTreeNode  *r) const;

public:
 BinaryTree();          
 virtual ~BinaryTree();        
 BinTreeNode  *GetRoot() const;     
 void InOrder() const; 
 void PreOrder() const;
 void PostOrder() const; 
 void LevelOrder() const; 
 int NodeCount() const;        
 int leafNodeCount() const;
 void InsertLeftChild(BinTreeNode  *cur,  double &e);
 void InsertRightChild(BinTreeNode  *cur,  double &e);
 int Height() const;          
 BinaryTree( double &e); 
 BinTreeNode *Maketree(double &e,BinTreeNode  *left,BinTreeNode  *right)
 {root=new BinTreeNode(e,left,right);
 return root;
 }
};
 
BinaryTree ::BinaryTree()
{
 root = NULL;
}
 
BinaryTree ::~BinaryTree()
{
 DestroyHelp(root);
}

 
BinTreeNode  *BinaryTree ::GetRoot() const
{
 return root;
}

void BinaryTree ::PreOrderHelp(BinTreeNode  *r) const

{
 if (r != NULL) 
 {
  cout<<(r->data)<<"  ";    
  PreOrderHelp(r->leftChild); 
  PreOrderHelp(r->rightChild); 
 }
}
 
void BinaryTree ::PreOrder() const
{
 PreOrderHelp(root); 
} 

void BinaryTree ::InOrderHelp(BinTreeNode  *r) const
{
 if (r != NULL) 
 {
  InOrderHelp(r->leftChild); 
  cout<<(r->data)<<"  "; 
  InOrderHelp(r->rightChild); 
 }
}
 
void BinaryTree ::InOrder() const
{
 InOrderHelp(root); 
} 
 
void BinaryTree ::PostOrderHelp(BinTreeNode  *r) const
{
 if (r != NULL) 
 {
  PostOrderHelp(r->leftChild); 
  PostOrderHelp(r->rightChild);
  cout<<(r->data)<<"  ";    
 }
}
 
void BinaryTree ::PostOrder() const
{
 PostOrderHelp(root); 
} 

void BinaryTree ::LevelOrder() const
{
 LinkQueue q; // ����
 BinTreeNode  *t = root;  // �Ӹ���㿪ʼ���в�α���
 
 if (t != NULL) q.InQueue(t);  
 while (!q.Empty())
 { q.OutQueue(t);     
  cout<<(t->data)<<"  ";
  if (t->leftChild != NULL)  
   q.InQueue(t->leftChild); 
  if (t->rightChild != NULL)   
   q.InQueue(t->rightChild);  
 }
}
 
int BinaryTree ::HeightHelp(const BinTreeNode  *r) const
{
 if(r == NULL)
 { return 0;
 }
 else
 { int lHeight, rHeight;
  lHeight = HeightHelp(r->leftChild);  // �������ĸ�
  rHeight = HeightHelp(r->rightChild); // �������ĸ�
  return (lHeight > rHeight ? lHeight : rHeight) + 1;
 }
}
 
int BinaryTree ::Height() const
{
 return HeightHelp(root);
}

 
BinaryTree ::BinaryTree( double &e)
{
 root = new BinTreeNode (e);
}
 
int BinaryTree ::NodeCountHelp(const BinTreeNode  *r) const
{
 if (r ==NULL) return 0;  
 else return NodeCountHelp(r->leftChild) + NodeCountHelp(r->rightChild) + 1;
}
 
int BinaryTree ::NodeCount() const
{
 return NodeCountHelp(root);
}
int BinaryTree ::leafNodeCountHelp(const BinTreeNode  *r) const
{ int lt,rt;
 if (r==NULL) return 0;  
 else if(r->leftChild==NULL &&r->rightChild==NULL)
  return 1;
 else 
 {lt=leafNodeCountHelp(r->leftChild);
 rt=leafNodeCountHelp(r->leftChild);
 return lt+rt;}
}
 
int BinaryTree ::leafNodeCount() const
{
 return leafNodeCountHelp(root);
}

 
void BinaryTree ::InsertLeftChild(BinTreeNode  *cur,  double &e)
{
 if (cur == NULL)
 {
  return;
 }
 else 
 { // ��������
  BinTreeNode  *child =  new BinTreeNode (e);
  if (cur->leftChild != NULL)
  {child->leftChild = cur->leftChild;
  }
  cur->leftChild = child;    
  return;
 }
}

 
void BinaryTree ::InsertRightChild(BinTreeNode  *cur,  double &e)
{
 if (cur == NULL)
 { return;
 }
 else
 { // �����Һ���
  BinTreeNode  *child =  new BinTreeNode (e);
  if (cur->rightChild != NULL)
  { child->rightChild = cur->rightChild;
  }
  cur->rightChild = child;     
  return;
 }
}
 
void BinaryTree ::DestroyHelp(BinTreeNode  *&r)
{
 if(r != NULL)
 { DestroyHelp(r->leftChild);  // ����������
  DestroyHelp(r->rightChild);  // ����������
  delete r;      // ���ٸ����
  r = NULL;
 }
}

int main(void)
{       double e;
  //BinTreeNode *cur;
  BinTreeNode*a,*b,*c,*d,*f;
  BinaryTree bt;
  cout<<"������a������ֵ";
  cin>>e;
  a=bt.Maketree(e,NULL,NULL);
  cout<<"������b������ֵ";
  cin>>e;
  b=bt.Maketree(e,NULL,NULL);
  cout<<"������b������ֵ";
  cin>>e;
  c=bt.Maketree(e,NULL,NULL);
  cout<<"������d������ֵ";
  cin>>e;
  d=bt.Maketree(e,a,b);
  cout<<"������f������ֵ";
  cin>>e;
  f=bt.Maketree(e,c,d);
  /*cout<<"��������ڵ����ֵ:";
  cin>>e;
  cur = new BinTreeNode(e);
  BinaryTree bt(e);  // ����������
  cur = bt.GetRoot();
  cout<<"��������ڵ����ӵ���ֵ:";
   cin>>e;
  bt.InsertLeftChild(cur, e);
  cout<<"��������ڵ��Һ��ӵ���ֵ:";
  cin>>e;
  bt.InsertRightChild(cur, e);
  cout<<"��������ڵ����ӵ����ӵ���ֵ:";
   cin>>e;
  bt.InsertLeftChild(cur->leftChild, e);
  cout<<"��������ڵ��Һ��ӵ����ӵ���ֵ:";
  cin>>e;
  bt.InsertLeftChild(cur->rightChild, e);
  cout<<"��������ڵ��Һ��ӵ��Һ��ӵ���ֵ:"; 
  cin>>e;
  bt.InsertRightChild(cur->rightChild,e);*/
  cout << "�������:" << endl;
  bt.PreOrder();
  cout<<endl;
  system("PAUSE");   

  cout << "�������:" << endl;
  bt.InOrder();
  cout<<endl;
  system("PAUSE");   

  cout << "�������:" << endl;
  bt.PostOrder();
  cout<<endl;
  system("PAUSE");   

  cout << "��α���:" << endl;
  bt.LevelOrder();
  cout<<endl;
 /* system("PAUSE");   
  cout<<"���ĸ߶�Ϊ"<<bt.Height()<<endl;
  cout<<"���нڵ���Ϊ"<<bt.NodeCount()<<endl;
  cout<<"����Ҷ�ӽڵ���Ϊ"<<bt.leafNodeCount()<<endl;
  */
 return 0;      
}

