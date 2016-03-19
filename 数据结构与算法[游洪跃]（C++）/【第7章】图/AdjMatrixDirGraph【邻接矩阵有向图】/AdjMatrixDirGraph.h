/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : main.cpp                                                     *
*  Description: �ڽӾ�������ͼ��AdjMatrixDirGraph����ͷ�ļ�                               *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

#ifndef ADJMATRIXDIRGRAPH_H_INCLUDED
#define ADJMATRIXDIRGRAPH   _H_INCLUDED



#include <stdexcept>
#include <iomanip>
#include <queue>

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


/// �ڽӾ�������ͼ��AdjMatrixDirGraph��������
template <class ElemType>
class AdjMatrixDirGraph
{
    /*===========================��PUBLIC�������ӿڡ�============================*/
public :      // �����ӿ�
    // �ڽӾ�������ͼ��AdjMatrixDirGraph������Ա����
    AdjMatrixDirGraph( );         // Ĭ�Ϲ��캯��ģ��

    AdjMatrixDirGraph(ElemType *vertex, int vexNum);  // ���춥������Ϊvertex, �������ΪvexNum������ͼ

    AdjMatrixDirGraph(int vexNum);                    // ���춥�����ΪvexNum������ͼ

    AdjMatrixDirGraph(const AdjMatrixDirGraph<ElemType> &copy); // ���ƹ��캯��

    AdjMatrixDirGraph<ElemType>& operator=(const AdjMatrixDirGraph<ElemType> &copy);    // ���ظ�ֵ���������

    ~AdjMatrixDirGraph( );                            // ��������

    // �ڽӾ�������ͼ��AdjMatrixDirGraph������Ա����
    int GetVertex(ElemType &elem);      // ��ȡ��ǰ������Ϣ��ԭͼ�е�λ��

    void ShowMarix( );      // ��ʾͼ���ڽӾ�����Ϣ

    void SetGraph(ElemType *vertexs, int edge);            // �޸�ͼ�Ķ������ͱ���

    ElemType GetVertexElem(int vertex);                       // �󶥵��Ԫ��ֵ

    bool SetElem(int vertex, const ElemType elem);      // ���ö����Ԫ��ֵ

    int GetVertexCount( );               // ��ȡ�������Ŀ

    int GetEdgeCount( );                // ��ȡ�ߵ���Ŀ

    int FirstAdjVertex(int vertex);     // ��ȡ����vertex�ĵ�һ���ڽӵ�

    int NextAdjVertex(int vertex1, int vertex2);    // ���ض���vertex1�����vertex2����һ���ڽӵ�

    bool InsertEdge(int vertex1, int vertex2);            // ����vertex1��vertex2�ı�

    bool DeleteEdge(int vertex1, int vertex2);          // ɾ��vertex1��vertex2�ı�

    bool GetVisited(int vertex);                         // ���ض���vertex�ķ��ʱ�ʶ��Ϣ

    void SetVisited(int vertex, bool isVisited);        // ���ö���vertex�ķ�����Ϣ

    void DFSTraverse(void (*Visit)(const ElemType &));      // �����������

    void BFSTraverse(void (*Visit)(const ElemType &));      // �����������

    void DFSTraverse(int vertex, void (*Visit)(const ElemType &));      // �����������

    void BFSTraverse(int vertex, void (*Visit)(const ElemType &));      // �����������
    /*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
    /*=========================��PROTECTED��������Ա��===========================*/
protected ://summit, peak, apex, zenith, acme, vertex
    // �ڽӾ�������ͼ��AdjMatrixDirGraph���ݳ�Ա
    int m_vertexSize;                       // �������
    int m_edgeSize;                      // ����
    int **m_matrix;                     // �ڽӾ���
    ElemType *m_elems;                 // ����Ԫ��
    //mutable IsVisited *m_visited;
    mutable bool *m_visited;              // ���ڱ�ʶ��ǰ�����Ƿ񱻷���

    // �ڽӾ�������ͼ��AdjMatrixDirGraph��������ģ��
    void DestroyGraph( );                // ��������ͼ, �ͷ�����ͼ�Ŀռ�

    void DFS(int vertex, void (* Visit)(const ElemType &));     // �Ӷ���vertex�������������������

    void BFS(int veretx, void (* Visit)(const ElemType &));     // �Ӷ���vertex�������й����������
};



/**�ڽӾ�������ͼ��AdjMatrixDirGraph��������ģ��[ʵ��]***********************************
    void DestroyGraph( );                // ��������ͼ, �ͷ�����ͼ�Ŀռ�
    void BFS(int vertex, void (* Visit)(const ElemType &));     // �Ӷ���vertex�������������������
    void DFS(int veretx, void (* Visit)(const ElemType &));     // �Ӷ���vertex�������й����������
***********************************[ʵ��]�ڽӾ�������ͼ��AdjMatrixDirGraph��������ģ��**/
//// �������ƣ�void DestroyGraph( );
//// �����������������ͼ, �ͷ�����ͼ�Ŀռ�
//template <class ElemType>
//void AdjMatrixDirGraph<ElemType>::CreateGraph(int vertexNum)
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
void AdjMatrixDirGraph<ElemType>::DestroyGraph( )
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if(m_elems != NULL)
    {
        delete[] m_elems;          // ɾ��ͼ���ڽӾ���洢��Ϣ
    }
    m_elems = NULL;

    if(m_visited != NULL)
    {
        delete[] m_visited;         // ɾ��ͼ�Ķ�����ʱ�ʶ��Ϣ
    }
    m_visited = NULL;

    if(m_matrix != NULL)
    {
        for(int i = 0; i < this->m_vertexSize; i++)
        {
            delete[] m_matrix[i];       // ɾ����i������Ĵ洢��Ϣ
        }

        delete[] m_matrix;              // ɾ���ڽӾ���
        m_matrix = NULL;
    }
}

// �������ƣ�void DFS(int veretx, void (* Visit)(const ElemType &));
// ����������Ӷ���vertex����������ȶ���������
template <class ElemType>
void AdjMatrixDirGraph<ElemType>::DFS(int vertex, void (* Visit)(const ElemType &))     // �Ӷ���vertex�������������������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    this->SetVisited(vertex, VISITED);      // ��veretx���ʱ�ʶ��ʶΪ�ѷ���
    /*�������ȼ���*/this->m_visited[vertex] = VISITED;

    ElemType elem = this->GetVertexElem(vertex);        // ��ȡ��ǰ��vertex������Ķ�������
    (* Visit)(elem);            // ��Visit������ǰ������Ϣ

    int vexTemp;
    for(vexTemp = this->FirstAdjVertex(vertex);    /*��ǰ����ĵ�һ���ڽӵ㿪ʼ����*/
            vexTemp != -1/*��ѯ�����ڽӵ�ʱ�᷵��-1*/;
            vexTemp = this->NextAdjVertex(vertex, vexTemp))
    {
        //if(this->GetVisited() == UNVISITED) // ֻҪ��ǰ�㻹δ������
        if(this->m_visited[vexTemp] == UNVISITED)
        {
            DFS(vexTemp, Visit);        // �ݹ����vexTemp
        }
    }
}


// �������ƣ�void BFS(int veretx, void (* Visit)(const ElemType &));
// ����������Ӷ���vertex�������й����������
template <class ElemType>
void AdjMatrixDirGraph<ElemType>::BFS(int vertex, void (* Visit)(const ElemType &))     // �Ӷ���vertex�������й����������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    //this->SetVisited(vertex, VISITED);      // ��veretx���ʱ�ʶ��ʶΪ�ѷ���
    /*�������ȼ���*/this->m_visited[vertex] = VISITED;

    //ElemType elem = this->GetVertexElem(vertex);        // ��ȡ��ǰ��vertex������Ķ�������

    (* Visit)(this->m_elems[vertex]);            // ��Visit������ǰ������Ϣ


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

                (* Visit)(this->m_elems[vexTemp]);      // ���ʵ�ǰ����

                myQueue.push(vexTemp);            // ����ǰ�������
            }
        }

    }

}

/**�ڽӾ�������ͼ��AdjMatrixDirGraph������Ա����[ʵ��]***********************************
    AdjMatrixDirGraph( );         // Ĭ�Ϲ��캯��ģ��
    AdjMatrixDirGraph(ElemType *vertex, int vexNum);  // ���춥������Ϊvertex, �������ΪvexNum������ͼ
    AdjMatrixDirGraph(int vexNum);                    // ���춥�����ΪvexNum������ͼ
    AdjMatrixDirGraph(const AdjMatrixDirGraph<ElemType> &copy); // ���ƹ��캯��
    AdjMatrixDirGraph<ElemType>& operator=(const AdjMatrixDirGraph<ElemType> &copy);    // ���ظ�ֵ���������
    ~AdjMatrixDirGraph( );                            // ��������
***********************************[ʵ��]�ڽӾ�������ͼ��AdjMatrixDirGraph������Ա����**/
// �������ƣ�AdjMatrixDirGraph( );         // Ĭ�Ϲ��캯��ģ��
// �������������춥������Ϊvertex, �������ΪvexNum������ͼ
template <class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph( )         // Ĭ�Ϲ��캯��ģ��
{
    m_vertexSize = 0;                       // �������
    m_edgeSize = 0;                      // ����
    m_matrix = NULL;                     // �ڽӾ���
    m_elems = NULL;                 // ����Ԫ��
    m_visited = NULL;              // ���ڱ�ʶ��ǰ�����Ƿ񱻷���
}


// �������ƣ�AdjMatrixDirGraph(ElemType *vertex, int vexNum);
// �������������춥������Ϊvertex, �������ΪvexNum������ͼ
template <class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph(ElemType *vertexs, int vertexNum)  // ���춥������Ϊvertex, �������ΪvexNum������ͼ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertexNum < 0)
    {
        throw std::out_of_range("������Ŀ����Ϊ����\n");;// �׳��쳣
    }
    this->m_vertexSize = vertexNum;		// ������ΪvertexNum
    this->m_edgeSize = 0;				// ����Ϊ0

    this->m_elems = new ElemType[vertexNum];    // ���ٶ������ݱ�����
    this->m_visited = new bool[vertexNum];		// ���ٷ��ʱ�ʶ����

    int v/*ѭ��������Ϣ*/,u/*ѭ������Ϣ*/;

    for (v = 0; v < vertexNum; v++)     // ��ʼ��
    {
        // ѭ��ÿ������
        this->m_elems[v] = vertexs[v];          // �洢�������Ϣ
        this->m_visited[v] = UNVISITED;         // Ĭ��ÿ�������Ϊδ����
    }

    m_matrix = (int **)new int *[vertexNum];   // ���̵�ǰ����ͼ���ڽӾ���

    for (v = 0; v < vertexNum; v++)         // ѭ��ÿ������
    {
        // �����ڽӾ������
        this->m_matrix[v] = new int[vertexNum];
    }

    for (u = 0; u < vertexNum; u++)         // ѭ��ÿ����
    {
        for (v = 0; v < vertexNum; v++)        // ѭ��ÿ������
        {
            m_matrix[u][v] = 0;         // Ϊ�ڽӾ���Ԫ�ظ�ֵ
        }
    }
}

// �������ƣ�AdjMatrixDirGraph(int vexNum);
// �������������춥�����ΪvexNum������ͼ
template <class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph(int vertexNum)                    // ���춥�����ΪvexNum������ͼ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertexNum < 0)
    {
        throw std::out_of_range("������Ŀ����Ϊ����\n");;// �׳��쳣
    }

    this->m_vertexSize = vertexNum;			// ������ΪvertexNum
    this->m_edgeSize = 0;							// ��ʼ������Ϊ0

    // ���ٶ������ݵ�����, ���ǲ���Ҫ��ʼ��
    this->m_elems = new ElemType[vertexNum];


    int v/*ѭ��������Ϣ*/,u/*ѭ������Ϣ*/;

    this->m_visited = new bool[vertexNum];				// ���ɱ�־����
    for (v = 0; v < vertexNum; v++)
    {
        // ��ʼ����־����
        this->m_visited[v] = UNVISITED;
    }

    this->m_matrix = (int **)new int *[vertexNum];  // ��������ͼ�ڽӾ���
    for (v = 0; v < vertexNum; v++)     // Ϊÿ��������ڽ���Ϣ
    {
        this->m_matrix[v] = new int[vertexNum];
    }

    for (u = 0; u < vertexNum; u++)            // ѭ��ÿ����
    {
        for (v = 0; v < vertexNum; v++)        // ѭ��ÿ������
        {
            this->m_matrix[u][v] = 0;             // ��ʼ��Ϊ0
        }
    }
}


// �������ƣ�AdjMatrixDirGraph(const AdjMatrixDirGraph<ElemType> &copy);
// ������������ƹ��캯��
template <class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph(const AdjMatrixDirGraph<ElemType> &copy) // ���ƹ��캯��
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    this->m_vertexSize = copy.m_vertexSize;			// ������ΪvertexNum
    this->m_edgeSize = copy.m_edgeSize;							// ��ʼ������Ϊ0

    // ���ٶ������ݵ�����, ���ǲ���Ҫ��ʼ��
    this->m_elems = new ElemType[this->m_vertexSize];


    int v/*ѭ��������Ϣ*/,u/*ѭ������Ϣ*/;

    this->m_visited = new bool[this->m_vertexSize];				// ���ɱ�־����
    for (v = 0; v < this->m_vertexSize; v++)
    {
        // ��ʼ����־����
        this->m_visited[v] = UNVISITED;
    }

    this->m_matrix = (int **)new int *[this->m_vertexSize];  // ��������ͼ�ڽӾ���
    for (v = 0; v < this->m_vertexSize; v++)     // Ϊÿ��������ڽ���Ϣ
    {
        this->m_matrix[v] = new int[this->m_vertexSize];
    }

    for (u = 0; u < this->m_vertexSize; u++)            // ѭ��ÿ����
    {
        for (v = 0; v < this->m_vertexSize; v++)        // ѭ��ÿ������
        {
            this->m_matrix[u][v] = copy.m_matrix[u][v];             // ��ʼ��Ϊ0
        }
    }
}


// �������ƣ�AdjMatrixDirGraph<ElemType>& operator=(const AdjMatrixDirGraph<ElemType> &copy);
// ������������ظ�ֵ���������
template <class ElemType>
AdjMatrixDirGraph<ElemType>& AdjMatrixDirGraph<ElemType>::operator=(const AdjMatrixDirGraph<ElemType> &copy)    // ���ظ�ֵ���������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if(this == &copy)
    {
        return *this;
    }


    this->m_vertexSize = copy.m_vertexSize;			// ������ΪvertexNum
    this->m_edgeSize = copy.m_edgeSize;							// ��ʼ������Ϊ0

    // ���ٶ������ݵ�����, ���ǲ���Ҫ��ʼ��
    this->m_elems = new ElemType[this->m_vertexSize];


    int v/*ѭ��������Ϣ*/,u/*ѭ������Ϣ*/;

    this->m_visited = new bool[this->m_vertexSize];				// ���ɱ�־����
    for (v = 0; v < this->m_vertexSize; v++)
    {
        // ��ʼ����־����
        this->m_visited[v] = UNVISITED;
    }

    this->m_matrix = (int **)new int *[this->m_vertexSize];  // ��������ͼ�ڽӾ���
    for (v = 0; v < this->m_vertexSize; v++)     // Ϊÿ��������ڽ���Ϣ
    {
        this->m_matrix[v] = new int[this->m_vertexSize];
    }

    for (u = 0; u < this->m_vertexSize; u++)            // ѭ��ÿ����
    {
        for (v = 0; v < this->m_vertexSize; v++)        // ѭ��ÿ������
        {
            this->m_matrix[u][v] = copy.m_matrix[u][v];             // ��ʼ��Ϊ0
        }
    }

    return (*this);
}


// �������ƣ�~AdjMatrixDirGraph( );
// �����������������
template <class ElemType>
AdjMatrixDirGraph<ElemType>::~AdjMatrixDirGraph( )                            // ��������
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    this->DestroyGraph( );
}


/**�ڽӾ�������ͼ��AdjMatrixDirGraph������Ա����[ʵ��]***********************************
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
***********************************[ʵ��]�ڽӾ�������ͼ��AdjMatrixDirGraph������Ա����**/
//�������ƣ�int GetVertex(ElemType &elem);
//�����������ȡ��ǰ������Ϣ��ԭͼ�е�λ��
template <class ElemType>
int AdjMatrixDirGraph<ElemType>::GetVertex(ElemType &elem)      // ��ȡ��ǰ������Ϣ��ԭͼ�е�λ��
{
    for(int v = 0; v < this->m_vertexSize; v++)
    {
        if(elem == this->m_elems[v])
        {
            return v;
        }
    }
    return -1;
}



//�������ƣ�void Showtarix( );
//�����������ʾͼ���ڽӾ�����Ϣ
template <class ElemType>
void AdjMatrixDirGraph<ElemType>::ShowMarix( )      // ��ʾͼ���ڽӾ�����Ϣ
{
    std::cout <<"��ǰͼ�Ķ�����Ŀ" <<this->m_vertexSize <<", ����Ŀ" <<m_edgeSize <<std::endl;

    std::cout <<"ͼ���ڽӾ�����Ϣ" <<std::endl;
    for(int i = 0; i < this->m_vertexSize; i++)
    {
        for(int j = 0; j < this->m_vertexSize; j++)
        {
            std::cout <<std::setw(4)<<m_matrix[i][j];
        }
        std::cout <<std::endl;
    }
}


//�������ƣ�bool SetGraph(int vertex, int edge);            // �޸�ͼ�Ķ������ͱ���
//����������޸�ͼ�Ķ������ͱ���
template <class ElemType>
void AdjMatrixDirGraph<ElemType>::SetGraph(ElemType *vertexs, int vertexNum)            // �޸�ͼ�Ķ������ͱ���
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertexNum < 0)
    {
        throw std::out_of_range("������Ŀ����Ϊ����\n");;// �׳��쳣
    }
    this->m_vertexSize = vertexNum;		// ������ΪvertexNum
    this->m_edgeSize = 0;				// ����Ϊ0

    this->m_elems = new ElemType[vertexNum];    // ���ٶ������ݱ�����
    this->m_visited = new bool[vertexNum];		// ���ٷ��ʱ�ʶ����

    int v/*ѭ��������Ϣ*/,u/*ѭ������Ϣ*/;

    for (v = 0; v < vertexNum; v++)     // ��ʼ��
    {
        // ѭ��ÿ������
        this->m_elems[v] = vertexs[v];          // �洢�������Ϣ
        this->m_visited[v] = UNVISITED;         // Ĭ��ÿ�������Ϊδ����
    }

    this->m_matrix = (int **)new int *[vertexNum];   // ���̵�ǰ����ͼ���ڽӾ���

    for (v = 0; v < vertexNum; v++)         // ѭ��ÿ������
    {
        // �����ڽӾ������
        this->m_matrix[v] = new int[vertexNum];
    }

    for (u = 0; u < vertexNum; u++)         // ѭ��ÿ����
    {
        for (v = 0; v < vertexNum; v++)        // ѭ��ÿ������
        {
            m_matrix[u][v] = 0;         // Ϊ�ڽӾ���Ԫ�ظ�ֵ
        }
    }
}


// �������ƣ�ElemType GetElem(int vertex);
// ����������󶥵��Ԫ��ֵ
template <class ElemType>
ElemType AdjMatrixDirGraph<ElemType>::GetVertexElem(int vertex)                       // �󶥵��Ԫ��ֵ
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
    else
    {
        return this->m_elems[vertex];
    }

}

// �������ƣ�bool SetElem(int vertex, const ElemType elem);
// ��������� ���ö����Ԫ��ֵ
template <class ElemType>
bool AdjMatrixDirGraph<ElemType>::SetElem(int vertex, const ElemType elem)      // ���ö����Ԫ��ֵ
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
    else
    {
        this->m_elems[vertex] = elem;
    }
}


// �������ƣ�int GetVertexCount( );
// ��������� ��ȡ�������Ŀ
template <class ElemType>
int AdjMatrixDirGraph<ElemType>::GetVertexCount( )               // ��ȡ�������Ŀ
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
int AdjMatrixDirGraph<ElemType>::GetEdgeCount( )                // ��ȡ�ߵ���Ŀ
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
int AdjMatrixDirGraph<ElemType>::FirstAdjVertex(int vertex)     // ��ȡ����vertex�ĵ�һ���ڽӵ�
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertex < 0 || vertex >= this->m_vertexSize)
    {
        throw std::out_of_range("��������������Χ!");// �׳��쳣
    }

    for (int i = 0; i < this->m_vertexSize; i++)
    {   // �����ڽӵ�
        // ���ڽӾ����е�vertex+1�е�Ԫ�ر�ʶ��vertex����������Ĺ�ϵ
        if (m_matrix[vertex][i] != 0)       // ��һ����Ϊ0��Ԫ��, �������һ���ڽӵ�
        {
            return i;
        }
    }

    return -1;
}

// �������ƣ�int NextAdjVertex(int vertex1, int vertex2);
// ��������� ���ض���vertex1�����vertex2����һ���ڽӵ�
template <class ElemType>
int AdjMatrixDirGraph<ElemType>::NextAdjVertex(int vertex1, int vertex2)    // ���ض���vertex1�����vertex2����һ���ڽӵ�
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

    for (int i = vertex2 + 1/*�ӵ�veretx��Ԫ�ؿ�ʼ����*/; i < this->m_vertexSize; i++)
    {
        // �����ڽӵ�
        if (m_matrix[vertex1][i] != 0)
        {
            return i;
        }
    }

    return -1;									// ����-1��ʾ���ڽӵ�
}

// �������ƣ�bool InsertEdge(int vertex1, int vertex2);
// ��������� ����vertex1��vertex2�ı�
template <class ElemType>
bool AdjMatrixDirGraph<ElemType>::InsertEdge(int vertex1, int vertex2)            // ����vertex1��vertex2�ı�
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertex1 < 0 || vertex1 >= this->m_vertexSize)
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

    if(m_matrix[vertex1][vertex2] == 0)
    {
        // ԭ����ͼ�ޱ�(v1, v2),������������1
        this->m_edgeSize++;
        m_matrix[vertex1][vertex2] = 1;				// �޸�(vertex1, vertex2)��Ӧ���ڽӾ���Ԫ��ֵ
       // m_matrix[vertex2][vertex1] = 1;				// �޸�(vertex2, vertex1)��Ӧ���ڽӾ���Ԫ��ֵ

        return true;
    }
    else
    {
        #ifdef REMIND
        std::cout <<"����ͼ�иñ��Ѿ�����, ���������" <<std::endl;
        #endif
        return false;
    }
}

// �������ƣ�bool DeleteEdge(int vertex1, int vertex2);
// ��������� ɾ��vertex1��vertex2�ı�
template <class ElemType>
bool AdjMatrixDirGraph<ElemType>::DeleteEdge(int vertex1, int vertex2)          // ɾ��vertex1��vertex2�ı�
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

    if(m_matrix[vertex1][vertex2] != 0)
    {
        // ԭ����ͼ�ޱ�(v1, v2),ɾ��������Լ���1
        this->m_edgeSize--;

        m_matrix[vertex1][vertex2] = 0;				// ���(vertex1, vertex2)��Ӧ���ڽӾ���Ԫ��ֵ
       // m_matrix[vertex2][vertex1] = 0;				// ���(vertex2, vertex1)��Ӧ���ڽӾ���Ԫ��ֵ

        return true;
    }
    else
    {
        #ifdef REMIND
        std::cout <<"����ͼ�иñ߱��Ͳ�����, ������ɾ��" <<std::endl;
        #endif

        return false;
    }
}


// �������ƣ�bool GetVisited(int vertex);
// ��������� ���ض���vertex�ķ��ʱ�ʶ��Ϣ
template <class ElemType>
bool AdjMatrixDirGraph<ElemType>::GetVisited(int vertex)                        // ���ض���vertex�ķ��ʱ�ʶ��Ϣ
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
void AdjMatrixDirGraph<ElemType>::SetVisited(int vertex, bool isVisited)        // ���ö���vertex�ķ�����Ϣ
{
#ifdef DEBUG    // ��׮������Ϣ
    std::cout <<"FUN:"<<__func__  <<", LINE:" <<__LINE__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ�ֲ���
    if (vertex < 0 || vertex >= this->m_vertexSize)
    {
        throw std::out_of_range("��������������Χ!");
    }

    this->m_visited[vertex] = isVisited;
}

// �������ƣ�void DFSTraverse(void (*Visit)(const ElemType &));
// ���������Ĭ�ϴӵ�0����㿪ʼ��������, �����������
template <class ElemType>
void AdjMatrixDirGraph<ElemType>::DFSTraverse(void (* Visit)(const ElemType &))      // �����������
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
void AdjMatrixDirGraph<ElemType>::DFSTraverse(int vertex, void (* Visit)(const ElemType &))      // �����������
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
void AdjMatrixDirGraph<ElemType>::BFSTraverse(void (*Visit)(const ElemType &))      // �����������
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
void AdjMatrixDirGraph<ElemType>::BFSTraverse(int vertex, void (*Visit)(const ElemType &))      // �����������
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


#endif // AdjMatrixDirGraph_H_INCLUDED/**
