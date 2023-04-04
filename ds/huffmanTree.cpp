/********************************************* 
   对应教材5.7.1，哈夫曼算法建立最优二叉树 
**********************************************/
#include <iostream>
using namespace std;

struct ElemType                        
{
  int weight;                  //假定权值为整数
  int parent, lchild, rchild;       //游标
};

class HuffmanTree
{
public:
	HuffmanTree(int w[ ], int n);
	HuffmanTree( );
	void Print( );
private:
	ElemType *huffTree;
	int num;
	void Select(int n, int &i1, int &i2);
};

void HuffmanTree :: Select(int n, int &i1, int &i2)
{
	int i = 0, temp;
	for ( ; i < n; i++)
		if (huffTree[i].parent == -1) {i1 = i; break;}
	for (i = i + 1; i < n; i++)
		if (huffTree[i].parent == -1) {i2 = i;break;}	
	if (huffTree[i1].weight > huffTree[i2].weight)
	{
		temp = i1; i1 = i2;i2 = temp;
	}
	for (i = i + 1; i < n; i++)
	{
		if (huffTree[i].parent == -1)
		{
			if (huffTree[i].weight < huffTree[i1].weight)
			{
				i2 = i1; i1 = i;
			}
			else if (huffTree[i].weight < huffTree[i2].weight)
			{
				i2 = i;
			}
		}
	}	
}

HuffmanTree :: HuffmanTree(int w[ ], int n) 
{
	int i, k, i1, i2;
	huffTree = new ElemType [2*n-1];
	num = n;
	for (i = 0; i < 2*num-1; i++)         //初始化，所有结点均没有双亲和孩子
	{
		huffTree[i].parent = -1;
		huffTree[i].lchild = huffTree[i].rchild = -1;
 	}
  	for (i = 0; i < num; i++)             //存储叶子结点的权值
    	huffTree[i].weight = w[i];
  	for (k = num; k < 2*num-1; k++)        //n-1次合并
  	{      
    	Select(k, i1, i2);        //权值最小的根结点下标为i1和i2
		huffTree[k].weight = huffTree[i1].weight + huffTree[i2].weight;
    	huffTree[i1].parent = k; huffTree[i2].parent = k; 
    	huffTree[k].lchild = i1; huffTree[k].rchild = i2;
  	}
}

void HuffmanTree :: Print( )
{
	int i, k;
	cout << "每个叶子到根结点的路径是:" << endl; 
	for (i = 0; i < num; i++)
	{
		cout << huffTree[i].weight;
		k = huffTree[i].parent;
		while (k != -1)
		{
			cout << "-->" << huffTree[k].weight;
			k = huffTree[k].parent;
		}
		cout << endl;
	}
}
int main( )
{
	int w[] = {2, 3, 4, 5};
	HuffmanTree T{w, 4};
	T.Print();
	return 0;
}
