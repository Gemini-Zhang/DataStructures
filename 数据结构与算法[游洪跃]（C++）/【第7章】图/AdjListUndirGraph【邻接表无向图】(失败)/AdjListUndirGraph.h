/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : main.cpp                                                     *
*  Description: �ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph����ͷ�ļ�                               *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

#ifndef ADJLISTUNDIRGRAPH_H_INCLUDED
#define ADJLISTUNDIRGRAPH_H_INCLUDED



#include <stdexcept>
#include <iomanip>
#include <list>
#include <cstring>
#include <queue>
#include "AdjListGraphVertexNode.h"
/*
/// ����һ�����ʱ�ʶö�ٱ���
#ifndef ISVISITED_DEFINE_INCLUDE
#define ISVISITED_DEFINE_INCLUDE
// 0��ʾδ������, 1��ʶ���ʹ���
typedef enum{UNVISITED = 0, VISITED = 1}IsVisited;
#endif
*/
// �궨���˱�ʶ��Ϣ
#ifndef ISVISITED_DEFINE_INCLUDE
#define ISVISITED_DEFINE_INCLUDE
// 0��ʾδ������, 1��ʶ���ʹ���

#define UNVISITED  false
#define   VISITED  true

#endif


/// �ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph��������
template <class ElemType>
class AdjListUndirGraph
{
    /*===========================��PUBLIC�������ӿڡ�============================*/
public :      // �����ӿ�
    // �ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph������Ա����
    AdjListUndirGraph( );         // Ĭ�Ϲ��캯��ģ��

    AdjListUndirGraph(ElemType *vertex, int vexNum);  // ���춥������Ϊvertex, �������ΪvexNum������ͼ

    AdjListUndirGraph(int vexNum);                    // ���춥�����ΪvexNum������ͼ

    AdjListUndirGraph(const AdjListUndirGraph<ElemType> &copy); // ���ƹ��캯��

    AdjListUndirGraph<ElemType>& operator=(const AdjListUndirGraph<ElemType> &copy);    // ���ظ�ֵ���������

    ~AdjListUndirGraph( );                            // ��������

    // �ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph������Ա����
    int GetVertex(ElemType &elem);      // ��ȡ��ǰ������Ϣ��ԭͼ�е�λ��

    void ShowMarix( );      // ��ʾͼ���ڽӾ�����Ϣ

    void SetGraph(ElemType *vertexs, int edge);            // �޸�ͼ�Ķ������ͱ���

    ElemType GetVertexElem(int vertex);                       // �󶥵��Ԫ��ֵ

    bool SetElem(int vertex, const ElemType elem);      // ���ö����Ԫ��ֵ

    int GetVertexCount( );               // ��ȡ�������Ŀ

    int GetEdgeCount( );                // ��ȡ�ߵ���Ŀ

    int FirstAdjVertex(int vertex);     // ��ȡ����vertex�ĵ�һ���ڽӵ�

    int NextAdjVertex(int vertex1, int vertex2);    // ���ض���vertex1�����vertex2����һ���ڽӵ�

    bool InsertEdge(int &vertex1, int &vertex2);            // ����vertex1��vertex2�ı�

    bool DeleteEdge(int vertex1, int vertex2);          // ɾ��vertex1��vertex2�ı�

    bool GetVisited(int vertex);                         // ���ض���vertex�ķ��ʱ�ʶ��Ϣ

    void SetVisited(int vertex, bool isVisited);        // ���ö���vertex�ķ�����Ϣ

    void DFSTraverse(void (*Visit)(ElemType &));      // �����������

    void BFSTraverse(void (*Visit)(ElemType &));      // �����������

    void DFSTraverse(int vertex, void (*Visit)(ElemType &));      // �����������

    void BFSTraverse(int vertex, void (*Visit)(ElemType &));      // �����������
    /*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
    /*=========================��PROTECTED��������Ա��===========================*/
protected ://summit, peak, apex, zenith, acme, vertex
    // �ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph���ݳ�Ա
    int m_vertexSize;                       // �������
    int m_edgeSize;                      // ����
    AdjListGraphVertexNode<ElemType> *m_vertexTable;        // �����ڽӱ�
    mutable bool *m_visited;              // ���ڱ�ʶ��ǰ�����Ƿ񱻷���

    // �ڽӾ�������ͼ��AdjListUndirGraph��������ģ��
    void DestroyGraph( );                // ��������ͼ, �ͷ�����ͼ�Ŀռ�

    void DFS(int vertex, void (* Visit)(ElemType &));     // �Ӷ���vertex�������������������

    void BFS(int veretx, void (* Visit)(ElemType &));     // �Ӷ���vertex�������й����������
};



/**�ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph��������ģ��[ʵ��]***********************************
    void DestroyGraph( );                // ��������ͼ, �ͷ�����ͼ�Ŀռ�
    void BFS(int vertex, void (* Visit)(const ElemType &));     // �Ӷ���vertex�������������������
    void DFS(int veretx, void (* Visit)(const ElemType &));     // �Ӷ���vertex�������й����������
***********************************[ʵ��]�ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph��������ģ��**/
//// �������ƣ�void DestroyGraph( );
//// �����������������ͼ, �ͷ�����ͼ�Ŀռ�
//template <class ElemType>
//void AdjListUndirGraph<ElemType>::CreateGraph(int vertexNum)
//{
//#ifdef DEBUG    // ��׮������Ϣ
//std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
//#endif
//    // ����ʵ�ֲ���
//	if (vertexNum < 0)
//	{
//        throw std::out_of_range("������Ŀ����Ϊ����\n");;// �׳��쳣
//	}
//
//	this->m_vertexSize = vertexNum;			// ������ΪvertexNum
//	this->m_edgeSize = 0;							// ��ʼ������Ϊ0
//
//    // ���ٶ������ݵ�����, ���ǲ���Ҫ��ʼ��
//	this->m_elems = new ElemType[vertexNum];
//
//
//	int v/*ѭ��������Ϣ*/,u/*ѭ������Ϣ*/;
//
//	this->m_visited = new bool[vertexNum];				// ���ɱ�־����
//	for (v = 0; v < vertexNum; v++)
//	{	// ��ʼ����־����
//		this->m_visited[v] = UNVISITED;
//	}
//
//	this->m_matrix = (int **)new int *[vertexNum];  // ��������ͼ�ڽӾ���
//	for (v = 0; v < vertexNum; v++)     // Ϊÿ��������ڽ���Ϣ
//	{
//		this->m_matrix[v] = new int[vertexNum];
//	}
//
//	for (u = 0; u < vertexNum; u++)            // ѭ��ÿ����
//	{
//		for (v = 0; v < vertexNum; v++)        // ѭ��ÿ������
//		{
//			this->m_matrix[u][v] = 0;             // ��ʼ��Ϊ0
//		}
//	}
//}



// �������ƣ�void DestroyGraph( );
// �����������������ͼ, �ͷ�����ͼ�Ŀռ�
template <class ElemType>
void AdjListUndirGraph<ElemType>::DestroyGraph( )
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if(this->m_visited != NULL)
    {   // ɾ�����ʱ�ʶ��Ŀռ�
        delete[] this->m_visited;
    }
	for(int vex = 0; vex < this->m_vertexSize; vex++)       // ѭ��ÿ������
	{
		if(this->m_vertexTable[vex].m_adjLink != NULL)      // �����ǰ������ڽӱ���Ϣ��������Ϣ��Ϊ��
        {
            delete this->m_vertexTable[vex].m_adjLink;      // ɾ�����ڽӱ���Ϣ
        }
	}
}

// �������ƣ�void DFS(int veretx, void (* Visit)(const ElemType &));
// ����������Ӷ���vertex����������ȶ���������
template <class ElemType>
void AdjListUndirGraph<ElemType>::DFS(int vertex, void (* Visit)(ElemType &))     // �Ӷ���vertex�������������������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    //this->SetVisited(vertex, VISITED);      // ��veretx���ʱ�ʶ��ʶΪ�ѷ���
    /*�������ȼ���*/this->m_visited[vertex] = VISITED;

    //ElemType elem = this->GetVertexElem(vertex);        // ��ȡ��ǰ��vertex������Ķ�������
    //std::cout <<this->m_vertexTable[vertex].m_data;
    (* Visit)(this->m_vertexTable[vertex].m_data);            // ��Visit������ǰ������Ϣ

    int vexTemp;
    for(vexTemp = this->FirstAdjVertex(vertex);    /*��ǰ����ĵ�һ���ڽӵ㿪ʼ����*/
            vexTemp != -1/*��ѯ�����ڽӵ�ʱ�᷵��-1*/;
            vexTemp = this->NextAdjVertex(vertex, vexTemp))
    {
        //if(this->GetVisited() == UNVISITED) // ֻҪ��ǰ�㻹δ������
        if(this->m_visited[vexTemp] == UNVISITED)
        {
            system("pause");
            DFS(vexTemp, Visit);        // �ݹ����vexTemp
        }
    }
}


// �������ƣ�void BFS(int veretx, void (* Visit)(const ElemType &));
// ����������Ӷ���vertex�������й����������
template <class ElemType>
void AdjListUndirGraph<ElemType>::BFS(int vertex, void (* Visit)(ElemType &))     // �Ӷ���vertex�������й����������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    //this->SetVisited(vertex, VISITED);      // ��veretx���ʱ�ʶ��ʶΪ�ѷ���
    /*�������ȼ���*/this->m_visited[vertex] = VISITED;

    //ElemType elem = this->GetVertexElem(vertex);        // ��ȡ��ǰ��vertex������Ķ�������

    (* Visit)(this->m_vertexTable[vertex].m_data);            // ��Visit������ǰ������Ϣ


    std::queue<int> myQueue;           // һ������
    int vex, vexTemp;
    myQueue.push(vertex);

    while(!myQueue.empty())
    {
        vex = myQueue.front( );
        myQueue.pop( );

        for(vexTemp = this->FirstAdjVertex(vex);        // �ӵ�ǰ���ĵĵ�һ���ڽӵ㿪ʼ
            vexTemp != -1;      // ���û���ڽӵ���ֹͣ
            vexTemp = this->NextAdjVertex(vex, vexTemp))    // Ѱ����һ���ڽӵ�
        {
            if(this->m_visited[vexTemp] == UNVISITED)
            {
                this->m_visited[vexTemp] = VISITED;

                (* Visit)(this->m_vertexTable[vertex].m_data);      // ���ʵ�ǰ����

                myQueue.push(vexTemp);            // ����ǰ�������
            }
        }

    }
}

/**�ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph������Ա����[ʵ��]***********************************
    AdjListUndirGraph( );         // Ĭ�Ϲ��캯��ģ��
    AdjListUndirGraph(ElemType *vertex, int vexNum);  // ���춥������Ϊvertex, �������ΪvexNum������ͼ
    AdjListUndirGraph(int vexNum);                    // ���춥�����ΪvexNum������ͼ
    AdjListUndirGraph(const AdjListUndirGraph<ElemType> &copy); // ���ƹ��캯��
    AdjListUndirGraph<ElemType>& operator=(const AdjListUndirGraph<ElemType> &copy);    // ���ظ�ֵ���������
    ~AdjListUndirGraph( );                            // ��������
***********************************[ʵ��]�ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph������Ա����**/
// �������ƣ�AdjListUndirGraph( );         // Ĭ�Ϲ��캯��ģ��
// �������������춥������Ϊvertex, �������ΪvexNum������ͼ
template <class ElemType>
AdjListUndirGraph<ElemType>::AdjListUndirGraph( )         // Ĭ�Ϲ��캯��ģ��
{
    this->m_vertexSize = 0;
    this->m_edgeSize = 0;

    this->m_vertexTable = NULL;
    this->m_visited = 0;
}


// �������ƣ�AdjListUndirGraph(ElemType *vertex, int vexNum);
// �������������춥������Ϊvertex, �������ΪvexNum������ͼ
template <class ElemType>
AdjListUndirGraph<ElemType>::AdjListUndirGraph(ElemType *vertexs, int vertexNum)  // ���춥������Ϊvertex, �������ΪvexNum������ͼ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
	if(vertexNum < 0 || vertexs == NULL)       // �������Ϸ�
	{
	    throw std::out_of_range("��������Ϊ��\n");
	}

	this->m_vertexSize = vertexNum;		// ������ΪvertexNum
	this->m_edgeSize = 0;				// ����Ϊ0

	this->m_visited = new bool[vertexNum];      // ���ٷ�����Ϣ��ʶ����

	int vex;									// ��ʱ����
	for(vex = 0; vex < this->m_vertexSize; vex++)       // ѭ�����ж���
	{
		this->m_visited[vex] = UNVISITED;   // ÿ������ķ�����Ϣ��Ϊδ����
	}

	this->m_vertexTable = new AdjListGraphVertexNode<ElemType>[this->m_vertexSize];    // �����ڽӱ�
	for (vex = 0; vex < this->m_vertexSize; vex++)      // ѭ��ÿ������
	{
		this->m_vertexTable[vex].m_data = vertexs[vex];     // �����ڽӱ��������Ϊ��������
	}
}

// �������ƣ�AdjListUndirGraph(int vexNum);
// �������������춥�����ΪvexNum������ͼ
template <class ElemType>
AdjListUndirGraph<ElemType>::AdjListUndirGraph(int vertexNum)                    // ���춥�����ΪvexNum������ͼ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
	if(vertexNum < 0)       // �������Ϸ�
	{
	    throw std::out_of_range("��������Ϊ��\n");
	}

	this->m_vertexSize = vertexNum;		// ������ΪvertexNum
	this->m_edgeSize = 0;				// ����Ϊ0

	this->m_visited = new bool[vertexNum];      // ���ٷ�����Ϣ��ʶ����

	int vex;									// ��ʱ����
	for(vex = 0; vex < this->m_vertexSize; vex++)       // ѭ�����ж���
	{
		this->m_visited[vex] = UNVISITED;   // ÿ������ķ�����Ϣ��Ϊδ����
	}

	this->m_vertexTable = new AdjListGraphVertexNode<ElemType>[this->m_vertexSize];// �����ڽӱ���ϢΪ��
}


// �������ƣ�AdjListUndirGraph(const AdjListUndirGraph<ElemType> &copy);
// ������������ƹ��캯��
template <class ElemType>
AdjListUndirGraph<ElemType>::AdjListUndirGraph(const AdjListUndirGraph<ElemType> &copy) // ���ƹ��캯��
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
	this->m_vertexSize = copy.m_vertexSize;		// ������ΪvertexNum
	this->m_edgeSize = copy.m_edgeSize;				// ����Ϊ0

	this->m_visited = new bool[this->m_vertexSize];      // ���ٷ�����Ϣ��ʶ����


	for(int vex = 0; vex < this->m_vertexSize; vex++)       // ѭ�����ж���
	{
		this->m_visited[vex] = copy.m_visited[vex];   // ÿ������ķ�����Ϣ��Ϊδ����
	}

	this->m_vertexTable = new AdjListGraphVertexNode<ElemType>[this->m_vertexSize];// �����ڽӱ�
	for (int vex = 0; vex < this->m_vertexSize; vex++)
	{	// �����ڽ�����
		//this->m_vertexSize[vex].m_data = copy.m_vertexSize[vex].m_data;	// ���ƶ�������
		//this->m_vertexSize[vex].m_adjLink = new LinkList<int>(*copy.m_vertexSize[vex].m_adjLink);
        this->m_vertexTable[vex] = copy.m_vertexTable[vex];
	}
}


// �������ƣ�AdjListUndirGraph<ElemType>& operator=(const AdjListUndirGraph<ElemType> &copy);
// ������������ظ�ֵ���������
template <class ElemType>
AdjListUndirGraph<ElemType>& AdjListUndirGraph<ElemType>::operator=(const AdjListUndirGraph<ElemType> &copy)    // ���ظ�ֵ���������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if(this == &copy)
    {
        return;
    }

	this->m_vertexSize = copy.m_vertexSize;		// ������ΪvertexNum
	this->m_edgeSize = copy.m_edgeSize;				// ����Ϊ0

	this->m_visited = new bool[this->m_vertexSize];      // ���ٷ�����Ϣ��ʶ����

	for(int vex = 0; vex < this->m_vertexSize; vex++)       // ѭ�����ж���
	{
		this->m_visited[vex] = copy.m_visited[vex];   // ÿ������ķ�����Ϣ��Ϊδ����
	}

	this->m_vertexTable = new AdjListGraphVertexNode<ElemType>[this->m_vertexSize];// �����ڽӱ�
	for (int vex = 0; vex < this->m_vertexSize; vex++)
	{	// �����ڽ�����
		//this->m_vertexSize[vex].m_data = copy.m_vertexSize[vex].m_data;	// ���ƶ�������
		//this->m_vertexSize[vex].m_adjLink = new LinkList<int>(*copy.m_vertexSize[vex].m_adjLink);
        // ���ϴ���ȼ���[���ڽ�����������˸�ֵ�����]
        this->m_vertexTable[vex] = copy.m_vertexTable[vex];
	}

	return (*this);
}


// �������ƣ�~AdjListUndirGraph( );
// �����������������
template <class ElemType>
AdjListUndirGraph<ElemType>::~AdjListUndirGraph( )                            // ��������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    this->DestroyGraph( );      // ������Ϣ���ٺ���
}


/**�ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph������Ա����[ʵ��]***********************************
    int GetVertex(ElemType &elem);      // ��ȡ��ǰ������Ϣ��ԭͼ�е�λ��
    void Showtarix( );      // ��ʾͼ���ڽӾ�����Ϣ
    bool SetGraph(int vertex, int edge);            // �޸�ͼ�Ķ������ͱ���
    ElemType GetElem(int vertex);                       // �󶥵��Ԫ��ֵ
    bool SetElem(int vertex, const ElemType elem);      // ���ö����Ԫ��ֵ
    int GetVertexCount( );               // ��ȡ�������Ŀ
    int GetEdgeCount( );                // ��ȡ�ߵ���Ŀ
    int FirstAdjVertex(int vertex);     // ��ȡ����vertex�ĵ�һ���ڽӵ�
    int NextAdjVertex(int vertex1, int vertex2);    // ���ض���vertex1�����vertex2����һ���ڽӵ�
    bool InsertEdge(int vertex1, int vertex2);            // ����vertex1��vertex2�ı�
    bool DeleteEdge(int vertex1, int vertex2);          // ɾ��vertex1��vertex2�ı�
    bool GetVisited(int vertex);                         // ���ض���vertex�ķ��ʱ�ʶ��Ϣ
    bool SetVisited(int vertex, bool isVisited);        // ���ö���vertex�ķ�����Ϣ
    void BFSTraverse(void (*Visit)(const ElemType &));      // �����������
    void DFSTraverse(void (*Visit)(const ElemType &));      // �����������
***********************************[ʵ��]�ڽӱ�����ͼ��AdjListUndirGraphAdjListUndirGraph������Ա����**/
//�������ƣ�int GetVertex(ElemType &elem);
//�����������ȡ��ǰ������Ϣ��ԭͼ�е�λ��
template <class ElemType>
int AdjListUndirGraph<ElemType>::GetVertex(ElemType &elem)      // ��ȡ��ǰ������Ϣ��ԭͼ�е�λ��
{
    int vex;
    for(vex = 0; vex < this->m_vertexSize; vex++)
    {
        if(this->m_vertexTable[vex].m_data == elem)        // �����ǰ�ڽӱ�Ķ������Ϣ����Ҫ��ѯ����Ϣ
        {
            return vex;         // �����±�Ҳ���ǵ�ǰ������ͼ��λ��
        }
    }

    return -1;          // ���Ҳ�������-1;
}

//�������ƣ�void Showtarix( );
//�����������ʾͼ���ڽӾ�����Ϣ
template <class ElemType>
void AdjListUndirGraph<ElemType>::ShowMarix( )      // ��ʾͼ���ڽӾ�����Ϣ
{
   /* for(int i = 0; i < this->m_vertexSize; i++)
    {
        std::cout <<this->m_vertexTable[i].m_adjLink->Length( );
    }*/
    int vex, i, j, len;
    int matrix[this->m_vertexSize][this->m_vertexSize];

    memset(matrix, 0, sizeof(&matrix[0][0])*m_vertexSize*m_vertexSize);
    for(i = 0; i < this->m_vertexSize; i++)     // ѭ��ÿ������
    {
        len = this->m_vertexTable[i].m_adjLink->Length( );
        std::cout <<"len = " <<len <<std::endl;
        for(j = 1; j <= len; j++)
        {
          //  system("pause");
            vex = this->m_vertexTable[i].m_adjLink->GetElem(j);

            std::cout <<"i = " <<i <<"j = " <<j <<"ȡ��Ԫ��" <<vex <<std::endl;
            matrix[i][vex] = 1;
        }
    }

    for(i = 0; i < m_vertexSize; i++)
    {
        for(j = 0; j < m_vertexSize; j++)
        {
            std::cout <<std::setw(4)<<matrix[i][j];
        }
        std::cout <<std::endl;
    }
}

//�������ƣ�bool SetGraph(int vertex, int edge);            // �޸�ͼ�Ķ������ͱ���
//����������޸�ͼ�Ķ������ͱ���
template <class ElemType>
void AdjListUndirGraph<ElemType>::SetGraph(ElemType *vertexs, int vertexNum)            // �޸�ͼ�Ķ������ͱ���
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if(vertexNum < 0 || vertexs == NULL)
    {
        throw std::out_of_range("��������Ϊ����\n");
    }

    this->DestroyGraph( ); // ��������ԭ�еĿռ�

    // ��ʼ�µĸ�ֵ
	this->m_vertexSize = vertexNum;		// ������ΪvertexNum
	this->m_edgeSize = 0;				// ����Ϊ0

	this->m_visited = new bool[vertexNum];      // ���ٷ�����Ϣ��ʶ����

	int vex;									// ��ʱ����
	for(vex = 0; vex < this->m_vertexSize; vex++)       // ѭ�����ж���
	{
		this->m_visited[vex] = UNVISITED;   // ÿ������ķ�����Ϣ��Ϊδ����
	}

	this->m_vertexTable = new AdjListGraphVertexNode<ElemType>[this->m_vertexSize];    // �����ڽӱ�
	for (vex = 0; vex < this->m_vertexSize; vex++)      // ѭ��ÿ������
	{
		this->m_vertexTable[vex].m_data = vertexs[vex];     // �����ڽӱ��������Ϊ��������
	}
}


// �������ƣ�ElemType GetElem(int vertex);
// ����������󶥵��Ԫ��ֵ
template <class ElemType>
ElemType AdjListUndirGraph<ElemType>::GetVertexElem(int vertex)                       // �󶥵��Ԫ��ֵ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if(vertex < 0 || vertex >= this->m_vertexSize)
    {
        throw std::out_of_range("���������������±�������Χ\n");
    }

    return this->m_vertexTable[vertex].m_data;
}

// �������ƣ�bool SetElem(int vertex, const ElemType elem);
// ��������� ���ö����Ԫ��ֵ
template <class ElemType>
bool AdjListUndirGraph<ElemType>::SetElem(int vertex, const ElemType elem)      // ���ö����Ԫ��ֵ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertex < 0 || vertex >= this->m_vertexSize)
    {
        // �������Ϸ�
        throw std::out_of_range("������Χ����ȷ\n");
    }

    this->m_vertexTable[vertex].m_data = elem;
}


// �������ƣ�int GetVertexCount( );
// ��������� ��ȡ�������Ŀ
template <class ElemType>
int AdjListUndirGraph<ElemType>::GetVertexCount( )               // ��ȡ�������Ŀ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    return this->m_vertexSize;
}

// �������ƣ�int GetEdgeCount( );
// ��������� ��ȡ�ߵ���Ŀ
template <class ElemType>
int AdjListUndirGraph<ElemType>::GetEdgeCount( )                // ��ȡ�ߵ���Ŀ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    return this->m_edgeSize;
}

// �������ƣ�int FirstAdjVertex(int vertex);
// ��������� ��ȡ����vertex�ĵ�һ���ڽӵ�
template <class ElemType>
int AdjListUndirGraph<ElemType>::FirstAdjVertex(int vertex)     // ��ȡ����vertex�ĵ�һ���ڽӵ�
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif

    // ����ʵ�ֲ���
    if(vertex < 0 || vertex >= this->m_vertexSize)
    {
        std:: out_of_range("���Ҳ�����ǰС��Ķ�����Ϣ\n");
    }

    if(this->m_vertexTable[vertex].m_adjLink == NULL)   // �����ǰ������ڽӱ���ϢΪ��
    {
        return -1;          // ����-1
    }
    else
    {
        return this->m_vertexTable[vertex].m_adjLink->GetElem(1);
    }
}

// �������ƣ�int NextAdjVertex(int vertex1, int vertex2);
// ��������� ���ض���vertex1�����vertex2����һ���ڽӵ�
template <class ElemType>
int AdjListUndirGraph<ElemType>::NextAdjVertex(int vertex1, int vertex2)    // ���ض���vertex1�����vertex2����һ���ڽӵ�
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertex1 < 0 || vertex1>= this->m_vertexSize)
    {
        throw std::out_of_range("��1����������������Χ!");// �׳��쳣
    }
    if (vertex2 < 0 || vertex2 >= this->m_vertexSize)
    {
        throw std::out_of_range("��2����������������Χ!");// �׳��쳣
    }

    if (vertex1 == vertex2)
    {
        throw std::out_of_range("�����������ܵ���!");				// �׳��쳣
    }

    if(this->m_vertexTable[vertex1].m_adjLink == NULL)   // �����ǰ������ڽӱ���ϢΪ��
    {
        return -1;          // ����-1
    }

	int vex = m_vertexTable[vertex1].m_adjLink->FindElem(vertex2);		// ȡ��vertex2��vertex1�ڽ������е�λ��
	if(vex < this->m_vertexTable[vertex1].m_adjLink->Length( )) // ��ѺƷ��ǰԪ�ػ��к��
	{	// ����ǰ��Ϣ������һ���ڽӵ�
		return this->m_vertexTable[vertex1].m_adjLink->GetElem(vex + 1);
	}
	else
	{
		return -1;      // ��������һ���ڽӵ�
	}
}

// �������ƣ�bool InsertEdge(int vertex1, int vertex2);
// ��������� ����vertex1��vertex2�ı�
template <class ElemType>
bool AdjListUndirGraph<ElemType>::InsertEdge(int &vertex1, int &vertex2)            // ����vertex1��vertex2�ı�
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if(vertex1 < 0 || vertex1 >= this->m_vertexSize)
    {
        throw std::out_of_range("��1����������������Χ!");// �׳��쳣
    }
    if(vertex2 < 0 || vertex2 >= this->m_vertexSize)
    {
        throw std::out_of_range("��2����������������Χ!");// �׳��쳣
    }
    //system("pause");
    if(vertex1 == vertex2)
    {
        throw std::out_of_range("�����������ܵ���!");				// �׳��쳣
    }

    int vex;
	// ����(vertex1, vertex2)�ı���Ϣ
	if(this->m_vertexTable[vertex1].m_adjLink == NULL) // �����ǰ�����������ϢΪ��, ���½�һ��������Ϣ
	{
		this->m_vertexTable[vertex1].m_adjLink = new LinkList<int>;
	}

    vex = this->m_vertexTable[vertex1].m_adjLink->FindElem(vertex2);// ����vertex2�ڶ���vertex1���ڽ������е�λ��
	if(vex == -1)      // ��������ڱ�(v1, v2)
	{
		this->m_vertexTable[vertex1].m_adjLink->Inlist(vertex2);				// �����
	  //  std::cout <<m_vertexTable[vertex1].m_data <<"  " <<m_vertexTable[vertex2].m_data <<std::endl;
	}
	else
	{
	    return false;
	   // std::cout <<"�ñ��Ѿ����������ظ�����" <<std::endl;
	}


	// ����(v2, v1)
	if(this->m_vertexTable[vertex2].m_adjLink == NULL) // �����ǰ�����������ϢΪ��, ���½�һ��������Ϣ
	{
		this->m_vertexTable[vertex2].m_adjLink = new LinkList<int>;
	}

	vex = this->m_vertexTable[vertex2].m_adjLink->FindElem(vertex1);// ����vertex2�ڶ���vertex1���ڽ������е�λ��

	if(vex == -1)      // ��������ڱ�(v1, v2)
	{
		this->m_vertexTable[vertex2].m_adjLink->Inlist(vertex1);				// �����										// ��������1
	  //  std::cout <<m_vertexTable[vertex2].m_data <<"  " <<m_vertexTable[vertex1].m_data <<std::endl;
	}

    this->m_edgeSize++;											// ��������1

    return true;
}

// �������ƣ�bool DeleteEdge(int vertex1, int vertex2);
// ��������� ɾ��vertex1��vertex2�ı�
template <class ElemType>
bool AdjListUndirGraph<ElemType>::DeleteEdge(int vertex1, int vertex2)          // ɾ��vertex1��vertex2�ı�
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertex1 < 0 || vertex1>= this->m_vertexSize)
    {
        throw std::out_of_range("��1����������������Χ!");
    }
    if (vertex2 < 0 || vertex2 >= this->m_vertexSize)
    {
        throw std::out_of_range("��2����������������Χ!");
    }

    if (vertex1 == vertex2)
    {
        throw std::out_of_range("�����������ܵ���!");
    }


    int vex;
    vex = this->m_vertexTable[vertex1].m_adjLink->FindElem(vertex1);	// ȡ��v2���ڽ������е�λ��
	if(vex != -1)   // ���ҵ�vertex1���ڽӱ��д�����vertex2�ı�
	{
		this->m_vertexTable[vertex1].m_adjLink->Delete(vex+1);		// ɾ��<v1, v2>
	}
	else
	{
	    std::cout <<"��ǰ�߲���ͼ��, �޷�����ɾ��" <<std::endl;
	    return false;
	}

    vex = this->m_vertexTable[vertex2].m_adjLink->FindElem(vertex1);	// ȡ��v2���ڽ������е�λ��
	if(vex != -1)   // ���ҵ�vertex1���ڽӱ��д�����vertex2�ı�
	{
		this->m_vertexTable[vertex1].m_adjLink->Delete(vex+1);		// ɾ��<v1, v2>
	}

    this->m_edgeSize--;									// �����Լ�1

    return true;
}


// �������ƣ�bool GetVisited(int vertex);
// ��������� ���ض���vertex�ķ��ʱ�ʶ��Ϣ
template <class ElemType>
bool AdjListUndirGraph<ElemType>::GetVisited(int vertex)                        // ���ض���vertex�ķ��ʱ�ʶ��Ϣ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertex < 0 || vertex >= this->m_vertexSize)
    {
        throw std::out_of_range("��������������Χ!");
    }

    return m_visited[vertex];
}


// �������ƣ�bool SetVisited(int vertex, bool isVisited);
// ��������� ���ö���vertex�ķ�����Ϣ
template <class ElemType>
void AdjListUndirGraph<ElemType>::SetVisited(int vertex, bool isVisited)        // ���ö���vertex�ķ�����Ϣ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertex < 0 || vertex >= this->m_vertexSize)
    {
        throw std::out_of_range("��������������Χ!");
    }

    this->m_visited[vertex] = VISITED;
}

// �������ƣ�void DFSTraverse(void (*Visit)(const ElemType &));
// ���������Ĭ�ϴӵ�0����㿪ʼ��������, �����������
template <class ElemType>
void AdjListUndirGraph<ElemType>::DFSTraverse(void (* Visit)(ElemType &))      // �����������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    int vex;      /*ѭ�����Ѷ���*/
    for(vex = 0; vex < this->m_vertexSize; vex++)
    {   // ��ÿ������ķ��ʱ�ʶ��δ����
        this->SetVisited(vex, UNVISITED);
        // this->m_visited[vertex] = UNVISITED;
    }
    DFS(0, Visit);             // �ӵ�һ�����㿪ʼ���ʷ���
}

// �������ƣ�void DFSTraverse(void (*Visit)(const ElemType &));
// ����������û�ѡ��Ӻ����ⶥ�㿪ʼ����, �����������
template <class ElemType>
void AdjListUndirGraph<ElemType>::DFSTraverse(int vertex, void (* Visit)(ElemType &))      // �����������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    int vex;      /*ѭ�����Ѷ���*/
    for(vex = 0; vex < this->m_vertexSize; vex++)
    {   // ��ÿ������ķ��ʱ�ʶ��δ����
        //this->SetVisited(vex, UNVISITED);
        this->m_visited[vex] = UNVISITED;
    }

    this->DFS(vertex, Visit);             // �ӵ�һ�����㿪ʼ���ʷ���
}


// �������ƣ�void BFSTraverse(void (*Visit)(const ElemType &));
// ��������������������
template <class ElemType>
void AdjListUndirGraph<ElemType>::BFSTraverse(void (*Visit)(ElemType &))      // �����������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    int vex;      /*ѭ�����Ѷ���*/
    for(vex = 0; vex < this->m_vertexSize; vex++)
    {   // ��ÿ������ķ��ʱ�ʶ��δ����
        this->SetVisited(vex, UNVISITED);
        // this->m_visited[vertex] = UNVISITED;
    }
    BFS(0, Visit);             // �ӵ�һ�����㿪ʼ���ʷ���
}



// �������ƣ�void BFSTraverse(void (*Visit)(const ElemType &));
// ��������������������
template <class ElemType>
void AdjListUndirGraph<ElemType>::BFSTraverse(int vertex, void (*Visit)(ElemType &))      // �����������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    int vex;      /*ѭ�����Ѷ���*/
    for(vex = 0; vex < this->m_vertexSize; vex++)
    {   // ��ÿ������ķ��ʱ�ʶ��δ����
        this->SetVisited(vex, UNVISITED);
        // this->m_visited[vertex] = UNVISITED;
    }
    BFS(vertex, Visit);             // �ӵ�һ�����㿪ʼ���ʷ���
}


#endif // AdjListUndirGraph_H_INCLUDED
