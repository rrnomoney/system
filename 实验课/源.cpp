#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

// ��������
double binaryToDecimal(const char* s);
double octalToDecimal(const char* s);
double hexToDecimal(const char* s);
void decimalToBase(int x, int r);

int main() {
    char s[100];  // ����һ���ַ��������洢������ַ���
    int x, r;

    // ������תʮ���Ʋ���
    printf("������һ������������");
    scanf("%s", s);  // ʹ�� scanf ����������ַ���
    double result = binaryToDecimal(s);  // ���ú������ж�����תʮ����
    printf("������ %s ��Ӧ��ʮ�������ǣ�%lf\n", s, result);  // ������

    // �˽���תʮ���Ʋ���
    printf("������һ���˽�������");
    scanf("%s", s);  // ����˽����ַ���
    result = octalToDecimal(s);  // ���ú������а˽���תʮ����
    printf("�˽��� %s ��Ӧ��ʮ�������ǣ�%lf\n", s, result);  // ������

    // ʮ������תʮ���Ʋ���
    printf("������һ��ʮ����������");
    scanf("%s", s);  // ����ʮ�������ַ���
    result = hexToDecimal(s);  // ���ú�������ʮ������תʮ����
    printf("ʮ������ %s ��Ӧ��ʮ�������ǣ�%lf\n", s, result);  // ������

    // ʮ����ת������Ʋ���
    printf("������һ��ʮ��������");
    scanf("%d", &x);
    printf("������Ŀ����ƣ�");
    scanf("%d", &r);
    printf("ʮ���� %d ��Ӧ�� %d �������ǣ�", x, r);
    decimalToBase(x, r);  // ���ú�������ʮ����ת r ����

    return 0;
}

// ���������ַ���ת��Ϊʮ���Ƶĺ���
double binaryToDecimal(const char* s) {
    int len = strlen(s);  // ��ȡ�ַ�������  
    int n = 0;  // �洢ת�����ʮ������
    for (int i = 0; i < len ; ++i) {
        if (s[i] == '1') {
            n += pow(2, len - i - 1);
        }
    }
    return n;
}

// ���˽����ַ���ת��Ϊʮ���Ƶĺ���
double octalToDecimal(const char* s) {
    int len = strlen(s);
    double n = 0.0;

    // ����������
    for (int i = 0; i < len; ++i) {
        if (s[i] >= '0' && s[i] <= '7') {
            n = n * 8 + (s[i] - '0');
        }
    }

    return n;
}

// ��ʮ�������ַ���ת��Ϊʮ���Ƶĺ���
double hexToDecimal(const char* s) {
    int len = strlen(s);
    double n = 0.0;

    // ����������
    for (int i = 0; i < len; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = n * 16 + (s[i] - '0');
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            n = n * 16 + (s[i] - 'A' + 10);
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            n = n * 16 + (s[i] - 'a' + 10);
        }
    }

    return n;
}

// ��ʮ������ת��Ϊ r ���Ƶĺ���
void decimalToBase(int x, int r) {
    int h[1000];  // ���ڴ洢ת����ĸ�λ��ֵ
    int j = 0;  // ����������ʼ��Ϊ 0

    // ��ʮ������ת��Ϊ r ����
    while (x) {
        h[j++] = x % r;  // ��������������
        x /= r;  // ������
    }

    // ����������飬�õ���ȷ�� r ���Ʊ�ʾ
    for (int i = j - 1; i >= 0; --i) {
        // ��� r ���� 10����ת��Ϊ��Ӧ�ַ����
        if (h[i] >= 10) {
            printf("%c", 'A' + (h[i] - 10));
        }
        else {
            printf("%d", h[i]);
        }
    }
    printf("\n");
}



















//#include <stdio.h>
//#include <stdlib.h>
//#define max_size 100
//
//typedef struct {
//    int key;
//    int otherinfo;
//} redtype;
//
//typedef struct {
//    redtype r[max_size + 1];
//    int length;
//} sqlist;
//
//void insertsort(sqlist& L) {
//    for (int i = 2; i <= L.length; i++) {
//        if (L.r[i].key < L.r[i - 1].key) {
//            L.r[0] = L.r[i];
//            int j;
//            for (j = i - 1; j >= 0 && L.r[0].key < L.r[j].key; j--) {
//                L.r[j + 1] = L.r[j];
//            }
//            L.r[j + 1] = L.r[0];
//        }
//    }
//}
//
//void bubblesort(sqlist& L) {
//    for (int i = 1; i < L.length; i++) {
//        for (int j = 1; j <= L.length - i; j++) {
//            if (L.r[j].key > L.r[j + 1].key) {
//                redtype temp = L.r[j];
//                L.r[j] = L.r[j + 1];
//                L.r[j + 1] = temp;
//            }
//        }
//    }
//}
//
//void selectsort(sqlist& L) {
//    redtype t;
//    for (int i = 1; i < L.length; i++) {
//        int k = i;
//        for (int j = i + 1; j <= L.length; j++) {
//            if (L.r[j].key < L.r[k].key)
//                k = j;
//        }
//
//        if (k != i) {
//            t = L.r[i];
//            L.r[i] = L.r[k];
//            L.r[k] = t;
//        }
//    }
//}
//
//int partition(sqlist& L, int low, int high) {
//    int pivotkey = L.r[low].key;
//    while (low < high) {
//        while (low < high && L.r[high].key >= pivotkey)
//            high--;
//        L.r[low] = L.r[high];
//        while (low < high && L.r[low].key <= pivotkey)
//            low++;
//        L.r[high] = L.r[low];
//    }
//    L.r[low].key = pivotkey;
//    return low;
//}
//
//void quicksort(sqlist& L, int low, int high) {
//    if (low < high) {
//        int pivotloc = partition(L, low, high);
//        quicksort(L, low, pivotloc - 1);
//        quicksort(L, pivotloc + 1, high);
//    }
//}
//
//int main() {
//    int n;
//    printf("������ѧ��������");
//    scanf("%d", &n);
//
//    // ����ѧ������
//    sqlist students;
//    students.length = n;
//
//    // ����ѧ����Ϣ
//    for (int i = 1; i <= n; i++) {
//        printf("������� %d ��ѧ���ķ�����", i);
//        scanf("%d", &students.r[i].key);
//    }
//
//    // ����ֱ�Ӳ���������
//    insertsort(students);
//
//    // ���������ѧ����Ϣ
//    printf("\n�������������к��ѧ����Ϣ��ֱ�Ӳ������򣩣�\n");
//    for (int i = 1; i <= n; i++) {
//        printf("������%d\n", students.r[i].key);
//    }
//
//    // ����ð��������
//    bubblesort(students);
//    printf("\n�������������к��ѧ����Ϣ��ð�����򣩣�\n");
//    for (int i = 1; i <= n; i++) {
//        printf("������%d\n", students.r[i].key);
//    }
//
//    // ����ѡ��������
//    selectsort(students);
//    printf("\n�������������к��ѧ����Ϣ��ѡ�����򣩣�\n");
//    for (int i = 1; i <= n; i++) {
//        printf("������%d\n", students.r[i].key);
//    }
//
//    // ���ÿ���������
//    quicksort(students, 1, n);
//    printf("\n�������������к��ѧ����Ϣ���������򣩣�\n");
//    for (int i = 1; i <= n; i++) {
//        printf("������%d\n", students.r[i].key);
//    }
//
//    return 0;
//}




//
//#include <stdio.h>
//
//#define MAX_SIZE 100
//
//// ˳�����
//int sequential_search(int table[], int n, int key) {
//    for (int i = 0; i < n; i++) {
//        if (table[i] == key) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//// ���ֲ���
//int binary_search(int table[], int n, int key) {
//    int low = 0;
//    int high = n - 1;
//    while (low <= high) {
//        int mid = (low + high) / 2;
//        if (table[mid] == key) {
//            return mid;
//        }
//        else if (table[mid] < key) {
//            low = mid + 1;
//        }
//        else {
//            high = mid - 1;
//        }
//    }
//    return -1;
//}
//
//int main() {
//    int choice, n, key, result;
//    printf("��ѡ����Ҳ�����\n");
//    printf("1. ˳�����\n");
//    printf("2. ���ֲ���\n");
//    printf("3. �˳�\n");
//
//    while (1) {
//        printf("������ѡ���ţ�");
//        scanf("%d", &choice);
//
//        if (choice == 1) {
//            printf("��������ұ�ı�n��������100����");
//            scanf("%d", &n);
//            if (n > MAX_SIZE) {
//                printf("������������ƣ��������룺");
//                continue;
//            }
//            int table[MAX_SIZE];
//            printf("������%d���ؼ���ֵ��\n", n);
//            for (int i = 0; i < n; i++) {
//                scanf("%d", &table[i]);
//            }
//            printf("������Ҫ���ҵĹؼ�ֵ��");
//            scanf("%d", &key);
//            result = sequential_search(table, n, key);
//            if (result != -1) {
//                printf("�ҵ��ؼ�ֵ %d��λ�ڱ�������λ�� %d��\n", key, result);
//            }
//            else {
//                printf("δ�ҵ��ؼ�ֵ %d��\n", key);
//            }
//        }
//        else if (choice == 2) {
//            printf("��������ұ�ı�n��������100����");
//            scanf("%d", &n);
//            if (n > MAX_SIZE) {
//                printf("������������ƣ��������룺");
//                continue;
//            }
//            int table[MAX_SIZE];
//            printf("������%d�����������еĹؼ���ֵ��\n", n);
//            for (int i = 0; i < n; i++) {
//                scanf("%d", &table[i]);
//            }
//            printf("������Ҫ���ҵĹؼ�ֵ��");
//            scanf("%d", &key);
//            result = binary_search(table, n, key);
//            if (result != -1) {
//                printf("�ҵ��ؼ�ֵ %d��λ�ڱ�������λ�� %d��\n", key, result);
//            }
//            else {
//                printf("δ�ҵ��ؼ�ֵ %d��\n", key);
//            }
//        }
//        else if (choice == 3) {
//            printf("��лʹ�ã��ټ���\n");
//            break;
//        }
//        else {
//            printf("��Чѡ�������ѡ��\n");
//        }
//    }
//
//    return 0;
//}




//#include<stdio.h>
//#include<stdlib.h>
//#define MVNum 100
//#define MAX_QUEUE_SIZE 100
//#define ok 1
//
//typedef struct ArcNode {
//    int adjvex;
//    struct ArcNode* nextarc;
//    int info;
//} ArcNode;
//
//typedef struct VNode {
//    int data;
//    ArcNode* firstarc;
//} VNode, AdjList[MVNum];
//
//typedef struct {
//    AdjList vertices;
//    int vexnum, arcnum;
//} ALGraph;
//
//// ��λ�����ڶ��������е�λ��
//int locateVex(ALGraph G, int v) {
//    for (int i = 0; i < G.vexnum; i++) {
//        if (G.vertices[i].data == v) {
//            return i;
//        }
//    }
//    return -1; // δ�ҵ�
//}
//
//int creat(ALGraph& G) {
//    int v1, v2;
//    int i, j;
//    ArcNode* p1, * p2;
//
//    scanf("%d %d", &G.vexnum, &G.arcnum);
//
//    for (i = 0; i < G.vexnum; i++) {
//        scanf("%d", &G.vertices[i].data);
//        G.vertices[i].firstarc = NULL;
//    }
//
//    for (int k = 0; k < G.arcnum; k++) {
//        scanf("%d %d", &v1, &v2);
//        i = locateVex(G, v1);
//        j = locateVex(G, v2);
//
//        // �����ڴ沢��ӱ� v1->v2
//        p1 = (ArcNode*)malloc(sizeof(ArcNode));
//        p1->adjvex = j;
//        p1->nextarc = G.vertices[i].firstarc;
//        G.vertices[i].firstarc = p1;
//
//        // �����ڴ沢��ӱ� v2->v1
//        p2 = (ArcNode*)malloc(sizeof(ArcNode));
//        p2->adjvex = i;
//        p2->nextarc = G.vertices[j].firstarc;
//        G.vertices[j].firstarc = p2;
//    }
//    return ok;
//}
//int visited[MVNum];
//
//// ��ʼ�����ʱ������
//void initVisited() {
//    for (int i = 0; i < MVNum; i++) {
//        visited[i] = 0;
//    }
//}
//
//// ���������������
//void DFS(ALGraph* G, int v) {
//    visited[v] = 1;
//    printf("%d ", G->vertices[v].data);
//
//    ArcNode* p = G->vertices[v].firstarc;
//    while (p != NULL) {
//        if (!visited[p->adjvex]) {
//            DFS(G, p->adjvex);
//        }
//        p = p->nextarc;
//    }
//}
//
//// ���������������
//void BFS(ALGraph* G, int v) {
//    int queue[MAX_QUEUE_SIZE];
//    int front = 0, rear = 0;
//
//    printf("%d ", G->vertices[v].data);
//    visited[v] = 1;
//    queue[rear++] = v;
//
//    while (front != rear) {
//        int w = queue[front++];
//        ArcNode* p = G->vertices[w].firstarc;
//        while (p != NULL) {
//            if (!visited[p->adjvex]) {
//                printf("%d ", G->vertices[p->adjvex].data);
//                visited[p->adjvex] = 1;
//                queue[rear++] = p->adjvex;
//            }
//            p = p->nextarc;
//        }
//    }
//}
//
//
//
//   
//int main() {
//    ALGraph G;
//    creat(G);
//    initVisited();
//    // ���Դ�ӡ�ڽӱ�
//    for (int i = 0; i < G.vexnum; i++) {
//        printf("%d -> ", G.vertices[i].data);
//        ArcNode* temp = G.vertices[i].firstarc;
//        while (temp) {
//            printf("%d ", G.vertices[temp->adjvex].data);
//            temp = temp->nextarc;
//        }
//        printf("\n");
//    }
//    printf("Depth First Search (DFS) sequence: ");
//    for (int i = 0; i < G.vexnum; i++) {
//        if (!visited[i]) {
//            DFS(&G, i);
//        }
//    }
//
//    printf("\n");
//
//    initVisited();
//
//    printf("Breadth First Search (BFS) sequence: ");
//    for (int i = 0; i < G.vexnum; i++) {
//        if (!visited[i]) {
//            BFS(&G, i);
//        }
//    }
//
//    printf("\n");
//    return 0;
//}

//<stdio.h>
//#include<stdlib.h>
//#defin#includee MAX_STACK_SIZE 100
//typedef struct BitNode {
//	char val;
//	struct BitNode* left, * right;
//
//}BitNode,*BiTree;
//BiTree creatTree()
//{
//	BitNode* T;
//	char ch;
//	scanf("%c", &ch);//ͨ�������ch�Ƿ��ǡ�#�����жϸýڵ��Ƿ��к��ӽڵ�
//
//	if (ch == '#') //'#'��������ǿս��
//	{
//		//��ʱΪ�ս��
//		return NULL;
//	}
//	else
//	{
//		//��Ϊ��
//		T = (BitNode*)malloc(sizeof(BitNode));
//		T->val = ch;
//		//�������������߼�һ�£����еݹ�
//		T->left = creatTree();
//		//�������������߼�һ�£����еݹ�
//		T->right = creatTree();
//		return T;
//
//	}
//}
//void preOrderTraverse(BiTree T) {
//	if (T) {
//		printf("%c", T->val);
//		preOrderTraverse(T->left);
//		preOrderTraverse(T->right);
//	}
//}
//
//void InOrderTraverse(BiTree T) {
//	if (T) {
//		InOrderTraverse(T->left);
//		printf("%c", T->val);
//		InOrderTraverse(T->right);
//	}
//}
//void afterOrderTraverse(BiTree T) {
//	if (T) {
//		afterOrderTraverse(T->left);	
//		afterOrderTraverse(T->right);
//		printf("%c", T->val);
//	}
//}
//typedef struct {
//    BiTree data[MAX_STACK_SIZE];
//    int top;
//} Stack;
//
//// ����һ����ջ
//void initStack(Stack* stack) {
//    stack->top = -1;
//}
//
//// ��ջ
//void push(Stack* stack, BiTree node) {
//    if (stack->top < MAX_STACK_SIZE - 1) {
//        stack->data[++stack->top] = node;
//    }
//}
//
//// ��ջ
//BiTree pop(Stack* stack) {
//    if (stack->top != -1) {
//        return stack->data[stack->top--];
//    }
//    return NULL;
//}
//
//// �ǵݹ��������
//void nonRecursivePreOrderTraverse(BiTree root) {
//    if (root == NULL) return;
//
//    Stack stack;
//    initStack(&stack);
//    BiTree p = root;
//
//    while (p != NULL || stack.top != -1) {
//        while (p != NULL) {
//            printf("%c", p->val);
//            push(&stack, p);
//            p = p->left;
//        }
//        if (stack.top != -1) {
//            p = pop(&stack);
//            p = p->right;
//        }
//    }
//}
//
//// �ǵݹ��������
//void nonRecursiveInOrderTraverse(BiTree root) {
//    if (root == NULL) return;
//
//    Stack stack;
//    initStack(&stack);
//    BiTree p = root;
//
//    while (p != NULL || stack.top != -1) {
//        while (p != NULL) {
//            push(&stack, p);
//            p = p->left;
//        }
//        if (stack.top != -1) {
//            p = pop(&stack);
//            printf("%c", p->val);
//            p = p->right;
//        }
//    }
//}
//
//// �ǵݹ�������
//void nonRecursiveAfterOrderTraverse(BiTree root) {
//    if (root == NULL) return;
//
//    Stack stack;
//    initStack(&stack);
//    BiTree p = root;
//    BiTree lastVisited = NULL;
//
//    while (p != NULL || stack.top != -1) {
//        while (p != NULL) {
//            push(&stack, p);
//            p = p->left;
//        }
//        p = stack.data[stack.top];
//        if (p->right == NULL || p->right == lastVisited) {
//            printf("%c", p->val);
//            lastVisited = p;
//            pop(&stack);
//            p = NULL;
//        }
//        else {
//            p = p->right;
//        }
//    }
//}
//
//int main() {
//	// ����������
//	printf("�������ַ��Թ����������������Һ��ӷֱ���#��ʾ:");
//	BiTree root = creatTree();
//
//	// �������
//	printf("Preorder traversal: ");
//	preOrderTraverse(root); 
//    printf("\n");
//    nonRecursivePreOrderTraverse(root);
//	printf("\n");
//
//	// �������
//	printf("Inorder traversal: ");
//	InOrderTraverse(root);
//    printf("\n");
//    nonRecursiveInOrderTraverse(root);
//	printf("\n");
//
//	// �������
//	printf("Postorder traversal: ");
//	afterOrderTraverse(root);
//    printf("\n");
//    nonRecursiveAfterOrderTraverse(root);
//	printf("\n");
//	return 0;
//} 
//
//
//
////
////#define MAXSIZE 100
////#define OVERFLOW -1
////#define OK 1
////#define ERROR -1
////
////typedef struct queue {
////	int* base;
////	int front;
////	int rear;
////	int length;                               // Add a length field
////} SqQueue;
////
////int InitQueue(SqQueue& Q) {
////	Q.base = (int*)malloc(MAXSIZE * sizeof(int));
////	if (Q.base == NULL) exit(OVERFLOW);
////	Q.front = Q.rear = 0;
////	Q.length = 0;                            // Initialize length to 0
////	return OK;
////}
////
////int EnQueue(SqQueue& Q, int e) {
////	if ((Q.rear + 1) % MAXSIZE == Q.front)
////		return ERROR;
////	Q.base[Q.rear] = e;
////	Q.rear = (Q.rear + 1) % MAXSIZE;
////	Q.length++;                              // Update length
////	return OK;
////}
////
////void printQueue(SqQueue Q) {
//	for (int i = Q.front; i < Q.front + Q.length; i++) {
//		printf("%d ", Q.base[i % MAXSIZE]);
//	}
//}
//
//int DeQueue(SqQueue& Q, int& e) {
//	if (Q.front == Q.rear) 
//		return ERROR;
//	e = Q.base[Q.front];
//	Q.front = (Q.front + 1) % MAXSIZE;
//	Q.length--;
//	return OK;
//	
//}
//int GetHead(SqQueue Q) {
//	if (Q.front != Q.rear)
//		return Q.base[Q.front];
//}
//
//
//
//
////������
//typedef struct QNode {
//    int data;
//    struct QNode* next;
//} QNode,*QuePtr;
//
//typedef struct {
//    QuePtr front;
//    QuePtr rear;
//    int length;
//} LinkQueue;
//
//int InitQueue1(LinkQueue &Q) {
//    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
//    Q.front->next = NULL;
//    Q.length = 0;
//    return OK;
//}
//
//int EnQueue1(LinkQueue& Q, int e) {
//    QNode* newNode = (QNode*)malloc(sizeof(QNode));
//    if (!newNode) return ERROR;
//    newNode->data = e;
//    newNode->next = NULL;
//    Q.rear->next = newNode;
//    Q.rear = newNode;
//    Q.length++;
//    return OK;
//}
//
//void DeQueue1(LinkQueue& Q, int& e) {
//    if (Q.front == Q.rear) return ; // Empty queue
//    QNode* p = Q.front->next;
//    e = p->data;
//    Q.front->next = p->next;
//    if (Q.rear == p) Q.rear = Q.front; // If dequeue the last element
//    free(p);
//    Q.length--;
//    return ;
//}
//
//void printQueue1(LinkQueue& Q) {
//    QNode* p = Q.front->next;
//    while (p) {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//
//
//
//
//
//int main() {
//	int lengths;
//	int a;
//	SqQueue Q;
//	printf("������г��ȣ�");
//	scanf("%d", &lengths);
//	printf("����ֵ��");
//	InitQueue(Q); // Initialize the queue
//	for (int i = 0; i < lengths; i++) {
//		int numbers;
//		scanf("%d", &numbers);
//		EnQueue(Q, numbers);
//	}
//	printf("��������ǣ�");
//	printQueue(Q);
//	printf("\n");
//	printf("����Ԫ���ǣ�");
//	printf("%d\n",GetHead(Q));
//	printf("ʣ�µ�Ԫ���ǣ�");
//	if(DeQueue(Q, a))
//	   printQueue(Q);
//	printf("\n");
//	int lengths1;
//	int a1;
//	LinkQueue Q1;
//	printf("������г��ȣ�");
//	scanf("%d", &lengths);
//	printf("����ֵ��");
//	InitQueue1(Q1); // Initialize the queue
//	for (int i = 0; i < lengths; i++) {
//		int numbers;
//		scanf("%d", &numbers);
//		EnQueue1(Q1, numbers);
//	}
//	printf("��������ǣ�");
//	printQueue1(Q1);
//	printf("����Ԫ���ǣ�%d\n", Q1.front->next->data);
//	printf("ʣ�µ�Ԫ���ǣ�");
//	DeQueue1(Q1, a);
//	printQueue1(Q1);
//	return 0;
//	return 0;
//}






//#include<stdio.h>
//#include<stdlib.h>
//#define MAXSIZE 5
//#define OK 1
//#define ERROR -1
////˳��ջ
//typedef struct {
//    int* top;
//    int* base;
//    int stacksize;
//} Sqstack;
//
//int InitStack(Sqstack& S) {
//    S.base = (int*)malloc(MAXSIZE * sizeof(int));
//    if (!S.base)
//        return ERROR;
//    S.top = S.base;
//    S.stacksize = MAXSIZE;
//    return OK;
//}
//
//int Push(Sqstack& S, int e) {
//    if (S.top - S.base == MAXSIZE)
//        return ERROR;
//    *(S.top) = e;
//    S.top++;
//    return OK;
//}
//
//void Pop(Sqstack &S) {
//    printf("ջ��Ԫ��Ϊ: ");
//    while (S.top != S.base) {
//        printf("%d ", *(S.top - 1));
//        S.top--;
//    }
//    printf("\n");
//}
//
//int GetTop(Sqstack S) {
//    if (S.top != S.base)
//        return *(S.top - 1);
//}
//void PrintStack(Sqstack S) {
//    printf("ջ��Ԫ��Ϊ: ");
//    for (int* i = S.top - 1; i >= S.base; i--) {
//        printf("%d ", *i);
//    }
//    printf("\n");
//}
//
//
//
//
//
//
//
////��ջ
//typedef struct StacckNode{
//    int data;
//    struct StacckNode* next;
//}StackNode,*LinkStack;
//int InitLstack(LinkStack& S) {
//    S = NULL;
//    return OK;
//}
//int PushL(LinkStack& S, int e) {
//    StackNode* p = (StackNode*)malloc(sizeof(StackNode)); 
//    if (p == NULL) { 
//        return ERROR;
//    }
//    p->data = e; 
//    p->next = S; 
//    S = p; 
//    return OK;
//}
//void PopL(LinkStack S) {
//    printf("ջ��Ԫ��Ϊ: ");
//    while (S) {
//        printf("%d ", S->data);
//        S = S->next;
//    }
//    printf("\n");
//}
//
//void PrintLstack(LinkStack S) {
//    printf("ջ��Ԫ��Ϊ: ");
//    while (S) {
//        printf("%d ", S->data);
//        S = S->next;
//    }
//    printf("\n");
//}
//
//int GetLTop(LinkStack S) {
//    if (S != NULL)
//        return S->data;
//}
//int main() {
//    int n, element,add,TOP;
//    Sqstack stack;
//    printf("������˳��ջ�Ĳ���\n");
//    printf("������ջ��Ԫ�ظ���: ");
//    scanf("%d", &n);
//
//    if (InitStack(stack) == ERROR) {
//        printf("ջ��ʼ��ʧ��\n");
//        return 1;
//    }
//
//    printf("������ջ�и�Ԫ��ֵ: ");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &element);
//        if (Push(stack, element) == ERROR) {
//            printf("ջ�������޷������Ԫ��\n");
//            return 1;
//        }
//    }
//    PrintStack(stack);
//    printf("��������Ҫ��ӵ�����");
//    scanf("%d", &add);
//    if (Push(stack, add) == ERROR) {
//        printf("ջ�������޷������Ԫ��\n");
//        return 1;
//    }
//    else{
//        printf("��Ԫ����ջ�ɹ�\n");
//    }
//    PrintStack(stack);
//
//    printf("ջ��Ԫ��Ϊ��");
//    TOP = GetTop(stack);
//    printf("%d\n",TOP);
//    Pop(stack);
//
//
//    //��ջ
//    printf("��������ջ�Ĳ���\n");
//    int n2, element2,add2,TOP2;
//    LinkStack stack2;
//    printf("������ջ��Ԫ�ظ���: ");
//    scanf("%d", &n2);
//    if (InitLstack(stack2) == ERROR) {
//        printf("ջ��ʼ��ʧ��\n");
//        return 1;
//    }
//
//    printf("������ջ�и�Ԫ��ֵ: ");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &element2);
//        if (PushL(stack2, element2) == ERROR) {
//            printf("ջ�������޷������Ԫ��\n");
//            return 1;
//        }
//    }
//    PrintLstack(stack2);
//
//    printf("��������Ҫ��ӵ�����");
//    scanf("%d", &add2);
//    if (PushL(stack2, add2) == ERROR) {
//        printf("ջ�������޷������Ԫ��\n");
//        return 1;
//    }
//    else {
//        printf("��Ԫ����ջ�ɹ�\n");
//    }
//    PrintLstack(stack2);
//
//    printf("ջ��Ԫ��Ϊ��");
//    TOP2 = GetLTop(stack2);
//    printf("%d\n", TOP2);
//    PopL(stack2);
//    return 0;
//}
//















//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct LNode {
//    int data;
//    struct LNode* next;
//} LNode, * LinkList;
//
//void creatlist_r(LinkList& L) {
//    LNode* p, * r;
//    L = (LinkList)malloc(sizeof(LNode)); // ����ͷ���
//    L->next = NULL;
//    r = L;
//    int num;
//    scanf("%d", &num);
//    while (num != 0) {
//        p = (LNode*)malloc(sizeof(LNode)); // �����½ڵ�
//        p->data = num; // ����ڵ�����
//        p->next = NULL;
//        r->next = p; // β�巨����ڵ�
//        r = p;
//        scanf("%d", &num);
//    }
//    p = (LNode*)malloc(sizeof(LNode));
//    p->data = 0;
//    p->next = NULL;
//    r->next = p;
//}
//
//void printList(LinkList L) {
//    LNode* p = L->next;
//    while (p != NULL) {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//int findElem(LinkList L, int e) {
//    LNode* p = L->next;
//    int count = 1;
//    while (p && p->data != e) {
//        p=p->next;
//        count++;
//    }
//    return count;
//}
//
//void insertElement(LinkList &L, int i, int x) {
//    LNode* p = L;
//    int count = 0;
//    while (p && count < i - 1) {
//        p = p->next;
//        count++;
//    }
//    LNode* newNode = (LNode*)malloc(sizeof(LNode));
//    newNode->data = x;
//    newNode->next = NULL;
//    if (i <= 0 || count == 0) { // ��� i С�ڵ��� 0 ��������Ϊ��
//        newNode->next = L->next;
//        L->next = newNode;
//    }
//    else if (count == i - 1) { // ��� i ���������ȣ������������м����
//        newNode->next = p->next;
//        p->next = newNode;
//    }
//    else { // ��� i ���������ȣ�����������ĩβ����
//        p->next = newNode;
//    }
//}
//
//int countNodes(LinkList L, int x) {
//    int count = 0;
//    LNode* p = L->next;
//    while (p != NULL) {
//        if (p->data == x) {
//            count++;
//        }
//        p = p->next;
//    }
//    return count;
//}
//
//int main() {
//    LinkList L;
//    creatlist_r(L);
//    printList(L);
//
//    int target;
//    printf("������Ҫ���ҵ�Ԫ�أ�");
//    scanf("%d", &target);
//    int location = findElem(L, target);
//    printf("Ԫ�� %d �������е�λ��Ϊ��%d\n", target, location);
//
//    int add, pos;
//    printf("������Ҫ�����ֵ��λ�ã��Կո�ָ�����");
//    scanf("%d %d", &add, &pos);
//    insertElement(L, pos, add);
//    printf("����������\n");
//    printList(L);
//    printf("������һ������");
//    int number;
//    scanf("%d", &number);
//    int counts = countNodes(L, number);
//    printf("�����й���%d�������", counts);
//    return 0;
//}






//#include<stdio.h>
//#include<stdlib.h>
//#define MAXSIZE 100
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//typedef struct  {
//	int* elem;
//	int length;
//}SqList;
//int initList(SqList& L) {
//	L.elem = (int*)malloc(MAXSIZE * sizeof(int));//Ϊ˳������һ���ռ�
//	if (!L.elem)
//		exit(OVERFLOW);
//	L.length = 0;
//	return OK;
//}
//int createList(SqList& L, int n) {
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &(L.elem[i])); // ���ζ�ȡԪ��ֵ
//		L.length++; // ����˳�����
//	}
//	return OK;
//}
//void listInsert(SqList& L, int x) {
//	int i, j;
//	for ( i = 0; i < L.length; i++) {
//		if (x <= L.elem[i]) {
//			break;
//		}
//	}
//	for ( j = L.length-1; j >= i; j--) {
//		L.elem[j+1 ] = L.elem[j];
//	}
//	L.elem[i] = x;
//	L.length++;
//}
//void deleteList(SqList& L) {
//	int m = 0; // ��¼�ظ�Ԫ�ظ���
//	for (int i = 0; i < L.length - 1; i++) { // ע��ѭ����Χ
//		if (L.elem[i] == L.elem[i + 1]) { // �����ǰԪ������һ��Ԫ����ͬ
//			m++; // �����ظ�Ԫ�ظ���
//		}
//		else { // �����ǰԪ������һ��Ԫ�ز�ͬ
//			L.elem[i - m] = L.elem[i]; // ����ǰԪ����ǰ�ƶ� m ��λ��
//		}
//	}
//	L.elem[L.length - m - 1] = L.elem[L.length - 1]; // �������һ��Ԫ��
//	L.length -= m; // ����˳�����
//}
//
//void printfList(SqList& L) {
//	for (int i = 0; i < L.length; i++) {
//		printf("%d ", L.elem[i]);
//	}
//}
//int main() {
//	int n;
//	SqList L;
//	scanf("%d", &n);
//	initList(L); // ��ʼ��˳���
//	createList(L, n); // ����˳���
//	printfList(L);
//	int x;
//	scanf("%d", &x);
//	listInsert(L, x);
//	printfList(L); // ���˳����е�Ԫ��ֵ
//	printf("\n");
//	deleteList(L);
////	printfList(L);
////	free(L.elem); // �ͷ�˳����ڴ�
////	return 0;
////}
//
//
//
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_SIZE 100
//
//// �����Ԫ��ϵ�����ݽṹ
//typedef struct {
//    char first;
//    char second;
//} Relation;
//
//// �Է��հ��㷨
//void reflexiveClosure(Relation R[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("<%c, %c>, ", R[i].first, R[i].second);
//    }
//    for (int i = 0; i < n; i++) {
//        printf("<%c, %c>, ", R[i].first, R[i].first);
//    }
//}
//
//// �ԳƱհ��㷨
//void symmetricClosure(Relation R[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("<%c, %c>, ", R[i].first, R[i].second);
//        printf("<%c, %c>, ", R[i].second, R[i].first);
//    }
//}
//
//// ���ݱհ��㷨
//void transitiveClosure(Relation R[], int n) {
//    int matrix[MAX_SIZE][MAX_SIZE] = { 0 }; // �ڽӾ����ʾ��ϵ
//
//    // �����ڽӾ���
//    for (int i = 0; i < n; i++) {
//        matrix[R[i].first - 'a'][R[i].second - 'a'] = 1;
//    }
//
//    // ʹ�� Warshall �㷨���㴫�ݱհ�
//    for (int k = 0; k < MAX_SIZE; k++) {
//        for (int i = 0; i < MAX_SIZE; i++) {
//            for (int j = 0; j < MAX_SIZE; j++) {
//                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
//            }
//        }
//    }
//
//    // ������ݱհ�
//    for (int i = 0; i < MAX_SIZE; i++) {
//        for (int j = 0; j < MAX_SIZE; j++) {
//            if (matrix[i][j]) {
//                printf("<%c, %c>, ", 'a' + i, 'a' + j);
//            }
//        }
//    }
//}
//
//int main() {
//    Relation R[] = { {'a', 'b'}, {'b', 'c'}, {'c', 'c'}, {'c', 'd'}, {'e', 'a'}, {'e', 'd'} };
//    int n = sizeof(R) / sizeof(Relation);
//
//    printf("ԭ��Ԫ��ϵR: ");
//    for (int i = 0; i < n; i++) {
//        printf("<%c, %c>, ", R[i].first, R[i].second);
//    }
//    printf("\n");
//
//    printf("�Է��հ�r(R): ");
//    reflexiveClosure(R, n);
//    printf("\n");
//
//    printf("�ԳƱհ�s(R): ");
//    symmetricClosure(R, n);
//    printf("\n");
//
//    printf("���ݱհ�t(R): ");
//    transitiveClosure(R, n);
//    printf("\n");
//
//    return 0;
//}