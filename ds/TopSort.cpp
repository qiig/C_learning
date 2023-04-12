/********************************** 
   对应教材6.6.1节，拓扑排序算法 
***********************************/
#include <iostream>
using namespace std;

struct EdgeNode       //定义边表结点
{
  int adjvex;         //邻接点域
  EdgeNode *next;
};

template <class DataType>
struct VertexNode     //定义顶点表结点
{
  int in;
  DataType vertex;
  EdgeNode *firstEdge;
};

const int MaxSize = 10;                  //图的最多顶点数
template <class DataType>
class ALGraph
{
public:
	ALGraph(DataType a[ ], int n, int e);   //构造函数，建立n个顶点e条边的图
   	~ALGraph( );                            //析构函数，释放邻接表各边表结点的存储空间
	void TopSort( );
private:
   	VertexNode<DataType> adjlist[MaxSize];          //存放顶点表的数组
   	int vertexNum, edgeNum;                       //图的顶点数和边数
};

template <class DataType>
ALGraph<DataType> :: ALGraph(DataType a[ ], int n, int e)
{
	int i, j, k;
	EdgeNode *s = nullptr;
	vertexNum = n; edgeNum = e;
	for (i = 0; i < vertexNum; i++)     //输入顶点信息，初始化顶点表
	{ 
		adjlist[i].vertex = a[i];
	 	adjlist[i].firstEdge = NULL;      
	}
	for (k = 0; k < edgeNum; k++)      //依次输入每一条边
	{ 
		cout << "输入边所依附的两个顶点的编号：";
	   	cin >> i >> j;                     //输入边所依附的两个顶点的编号
	   	s = new EdgeNode; s->adjvex = j;  //生成一个边表结点s
	   	s->next = adjlist[i].firstEdge;   //将结点s插入到第i个边表的表头
	   	adjlist[i].firstEdge = s;
	}
	for (i = 0; i < vertexNum; i++)
	{
		cout << "请依次输入每个顶点的入度：";   //简单起见，输入每个顶点的入度 
		cin >> adjlist[i].in;
	}
}

template <class DataType>
ALGraph<DataType> :: ~ALGraph( )
{
	EdgeNode *p = NULL, *q = NULL;
  	for (int i = 0; i < vertexNum; i++)
  	{
  		p = q = adjlist[i].firstEdge;
	  	while (p != NULL)
	  	{
	  		p = p->next;
	  		delete q; 
			q = p;
	  	}
  	}
}

template <class DataType>
void ALGraph<DataType> :: TopSort( )
{
	int i, j, k, count = 0;                    //累加器count初始化
	int S[MaxSize], top = -1;                //采用顺序栈并初始化
	EdgeNode *p = nullptr;
	for (i = 0; i < vertexNum; i++)           //扫描顶点表
		if (adjlist[i].in == 0) S[++top] = i;      //将入度为0的顶点压栈
		while (top != -1 )                   //当栈中还有入度为0的顶点时
		{
			j = S[top--];                        //从栈中取出入度为0的顶点
			cout << adjlist[j].vertex << "\t"; 
			count++;
  			p = adjlist[j].firstEdge;               //工作指针p初始化
    		while (p != nullptr)               //描顶点表，找出顶点j的所有出边
    		{
				k = p->adjvex;
      			adjlist[k].in--;            
      			if (adjlist[k].in == 0) S[++top] = k;    //将入度为0的顶点入栈
      			p = p->next;          
    		}
		}
	if (count < vertexNum )  cout << "有回路";
}

int main( )
{
	/*测试数据是图6-27，依次输入边是：
	(1 0)(1 3)(2 3)(2 0)(3 0)(3 5)(4 2)(4 3)(4 5)()*/ 
	char ch[ ] = {'A','B','C','D','E','F'};
	int i;
	ALGraph<char> ALG(ch, 6, 9);               //建立具有5个顶点6条边的有向图
	ALG.TopSort();
	return 0;
}
