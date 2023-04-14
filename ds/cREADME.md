# 数据结构

[toc]

## 引言

### 数据结构概念

相互之间存在一定关系的数据元素的集合，包括 **逻辑结构** 和 **存储结构**。

逻辑结构包括集合结构、线性结构、树结构、图结构；存储结构包括顺序存储结构和链式存储结构。

### 抽象数据类型

数据模型（结构） 及定义在该模型上的一组操作。

### 算法

求解特定问题的指令的有限序列。

**时间复杂度**  以基本语句的执行次数衡量。

## 线性表

### 顺序表

用一段连续的存储单元依次存储元素的线性表。

**随机存取结构**(random access)  确定基地址后，计算任一元素地址的时间相等。

#### 优缺点

- 优点
  - 查找速度快
- 缺点
  - 插入和删除需移动大量元素
  - 表的容量难以确定
  - 造成存储空间碎片

### 单链表

用一组任意存储单元存放元素的，每个结点只有一个指针域的线性表。是顺序存储结构 (sequential access).

#### 优缺点

- 优点
  - 插入和删除操作方便
- 缺点
  - 存储空间利用率较低

#### 双链表与循环链表

每个结点有前驱和后继两个指针域的线性表为 **双链表**，尾指针指向头节点的单链表为 **循环单链表**，**循环双链表** 头节点的前驱指针指向终端节点，终端节点的后继指针指向头节点。

### 顺序表 OR 单链表

- 查找需求频繁，插入和删除操作较少时顺序表更优。
- 线性表中元素数目不定或变动较大时，链表更优。
### 扩展

静态链表和顺序表的动态分配。

静态单链表 (static linked list) 的实现是以数组元素下标模拟链表指针，顺序表的动态分配是以更大空间的数组存储旧表及新插入元素。

## 文件列表

| FileName | Info. | Tag(s) | Lang. |
| :--- | :--- | :--- | :--- |
| [singlyLinkList] | singly linked list | List, | cpp |
| [seqList] | sequential list | List, | h |
| [doubleLinkList] | double linked list | List, | h |
| [cir_singlyLinkList] | circular singly linked list | List, | h |
| [cir_doubleLinkList] | circular double linked list | List, | h |
| [staticLinkList] | static linked list | List, | h |
| [dyn_seqList] | dynamic allocation for sequential list | List, | h |
| [JosephRing] | JosephRing: circular singly linked list | List, | cpp |
| [JosephRing_a] | J.. | List, | cpp |
| [Polynomial] | A(x) + B(x) | List, | cpp |
| [Polynomial_a] | A.. | List, | cpp |
| [seqStack] | sequential stack | Stack, List, | h|
| [linkStack] | linked stack | Stack, List, | h |
| [seqQueue] | sequential queue | Queue, List, | h |
| [seqQueue_2end] | double-ended sequential queue | Queue, List, | h |
| [linkQueue] | linked queue | Queue, List, | h |
| **[u]**[linkQueue_2end] | double-ended linked queue | Queue, List, | h |
| [March] | march parenthese | Stack, List, | cpp |
| [exprCal_a] | calculator of expression | Stack, List, | cpp |
| [playCards] | send cards | String, | cpp |
| [Queen] | queen problem | Array, | cpp |
| [BiTree] | binary tree creating & (non) traversing | Binary Tree, | h |
| [unionFind] | union & find set | Tree, | h |
| [MGraph] | adjacency matrix undirected graph | Graph, | h |
| [ALGraph] | adjacency list graph | Graph, | h |
| [EdgeGraph] | edge set array : kruskal | Graph, Kruskal | h |
| [MGraph_k] | Kruskal: finding minimal spanning tree | Graph, Kruskal, | h |
| [MGraph_kd] | Dijkstra: finding the shortest path | Graph, Dijkstra, | h |
| [Sort] | Sort Method based on comparing | Sort, | h |
| [RadixSort] | radix sort | Sort, | h |
| [AovGraph] | activity of vertex network: topological sort | Graph, TopSort, | h |

[AovGraph]: ./AovGraph.h
[RadixSort]: ./RadixSort.h
[Sort]: ./Sort.h
[MGraph_k]: ./MGraph_k.h
[MGraph_kd]: ./MGraph_kd.h
[EdgeGraph]: ./EdgeGraph.h
[ALGraph]: ./ALGraph.h
[MGraph]: ./MGraph.h
[unionFind]: ./unionFind.h
[BiTree]: ./BiTree.h
[Queen]: ./Queen.cpp
[playCards]: ./playCards.cpp
[exprCal_a]: ./exprCal_a.cpp
[March]: ./March.cpp
[linkQueue_2end]: ./linkQueue_2end.h
[linkQueue]: ./linkQueue.h
[seqQueue_2end]: ./seqQueue_2end.h
[seqQueue]: ./seqQueue.h
[linkStack]: ./linkStack.h
[seqStack]: ./seqStack.h
[Polynomial_a]: ./Polynomial_a.cpp
[Polynomial]: ./Polynomial.cpp
[JosephRing_a]: ./JosephRing_a.cpp
[JosephRing]: ./JosephRing.cpp
[dyn_seqList]: ./dyn_seqList.h
[staticLinkList]: ./staticLinkList.h
[cir_doubleLinkList]: ./cir_doubleLinkList.h
[cir_singlyLinkList]: ./cir_singlyLinkList.h
[doubleLinkList]: ./doubleLinkList.h
[seqList]: ./seqList.h
[singlyLinkList]: ./singlyLinkList.cpp
