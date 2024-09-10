#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

// 函数声明
double binaryToDecimal(const char* s);
double octalToDecimal(const char* s);
double hexToDecimal(const char* s);
void decimalToBase(int x, int r);

int main() {
    char s[100];  // 定义一个字符数组来存储输入的字符串
    int x, r;

    // 二进制转十进制部分
    printf("请输入一个二进制数：");
    scanf("%s", s);  // 使用 scanf 输入二进制字符串
    double result = binaryToDecimal(s);  // 调用函数进行二进制转十进制
    printf("二进制 %s 对应的十进制数是：%lf\n", s, result);  // 输出结果

    // 八进制转十进制部分
    printf("请输入一个八进制数：");
    scanf("%s", s);  // 输入八进制字符串
    result = octalToDecimal(s);  // 调用函数进行八进制转十进制
    printf("八进制 %s 对应的十进制数是：%lf\n", s, result);  // 输出结果

    // 十六进制转十进制部分
    printf("请输入一个十六进制数：");
    scanf("%s", s);  // 输入十六进制字符串
    result = hexToDecimal(s);  // 调用函数进行十六进制转十进制
    printf("十六进制 %s 对应的十进制数是：%lf\n", s, result);  // 输出结果

    // 十进制转任意进制部分
    printf("请输入一个十进制数：");
    scanf("%d", &x);
    printf("请输入目标进制：");
    scanf("%d", &r);
    printf("十进制 %d 对应的 %d 进制数是：", x, r);
    decimalToBase(x, r);  // 调用函数进行十进制转 r 进制

    return 0;
}

// 将二进制字符串转换为十进制的函数
double binaryToDecimal(const char* s) {
    int len = strlen(s);  // 获取字符串长度  
    int n = 0;  // 存储转换后的十进制数
    for (int i = 0; i < len ; ++i) {
        if (s[i] == '1') {
            n += pow(2, len - i - 1);
        }
    }
    return n;
}

// 将八进制字符串转换为十进制的函数
double octalToDecimal(const char* s) {
    int len = strlen(s);
    double n = 0.0;

    // 求整数部分
    for (int i = 0; i < len; ++i) {
        if (s[i] >= '0' && s[i] <= '7') {
            n = n * 8 + (s[i] - '0');
        }
    }

    return n;
}

// 将十六进制字符串转换为十进制的函数
double hexToDecimal(const char* s) {
    int len = strlen(s);
    double n = 0.0;

    // 求整数部分
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

// 将十进制数转换为 r 进制的函数
void decimalToBase(int x, int r) {
    int h[1000];  // 用于存储转换后的各位数值
    int j = 0;  // 数组索引初始化为 0

    // 将十进制数转换为 r 进制
    while (x) {
        h[j++] = x % r;  // 将余数存入数组
        x /= r;  // 更新商
    }

    // 反向输出数组，得到正确的 r 进制表示
    for (int i = j - 1; i >= 0; --i) {
        // 如果 r 大于 10，需转换为对应字符输出
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
//    printf("请输入学生数量：");
//    scanf("%d", &n);
//
//    // 创建学生数组
//    sqlist students;
//    students.length = n;
//
//    // 输入学生信息
//    for (int i = 1; i <= n; i++) {
//        printf("请输入第 %d 个学生的分数：", i);
//        scanf("%d", &students.r[i].key);
//    }
//
//    // 调用直接插入排序函数
//    insertsort(students);
//
//    // 输出排序后的学生信息
//    printf("\n按分数升序排列后的学生信息（直接插入排序）：\n");
//    for (int i = 1; i <= n; i++) {
//        printf("分数：%d\n", students.r[i].key);
//    }
//
//    // 调用冒泡排序函数
//    bubblesort(students);
//    printf("\n按分数升序排列后的学生信息（冒泡排序）：\n");
//    for (int i = 1; i <= n; i++) {
//        printf("分数：%d\n", students.r[i].key);
//    }
//
//    // 调用选择排序函数
//    selectsort(students);
//    printf("\n按分数升序排列后的学生信息（选择排序）：\n");
//    for (int i = 1; i <= n; i++) {
//        printf("分数：%d\n", students.r[i].key);
//    }
//
//    // 调用快速排序函数
//    quicksort(students, 1, n);
//    printf("\n按分数升序排列后的学生信息（快速排序）：\n");
//    for (int i = 1; i <= n; i++) {
//        printf("分数：%d\n", students.r[i].key);
//    }
//
//    return 0;
//}




//
//#include <stdio.h>
//
//#define MAX_SIZE 100
//
//// 顺序查找
//int sequential_search(int table[], int n, int key) {
//    for (int i = 0; i < n; i++) {
//        if (table[i] == key) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//// 二分查找
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
//    printf("请选择查找操作：\n");
//    printf("1. 顺序查找\n");
//    printf("2. 二分查找\n");
//    printf("3. 退出\n");
//
//    while (1) {
//        printf("请输入选项编号：");
//        scanf("%d", &choice);
//
//        if (choice == 1) {
//            printf("请输入查找表的表长n（不超过100）：");
//            scanf("%d", &n);
//            if (n > MAX_SIZE) {
//                printf("表长超过最大限制，重新输入：");
//                continue;
//            }
//            int table[MAX_SIZE];
//            printf("请输入%d个关键字值：\n", n);
//            for (int i = 0; i < n; i++) {
//                scanf("%d", &table[i]);
//            }
//            printf("请输入要查找的关键值：");
//            scanf("%d", &key);
//            result = sequential_search(table, n, key);
//            if (result != -1) {
//                printf("找到关键值 %d，位于表中索引位置 %d。\n", key, result);
//            }
//            else {
//                printf("未找到关键值 %d。\n", key);
//            }
//        }
//        else if (choice == 2) {
//            printf("请输入查找表的表长n（不超过100）：");
//            scanf("%d", &n);
//            if (n > MAX_SIZE) {
//                printf("表长超过最大限制，重新输入：");
//                continue;
//            }
//            int table[MAX_SIZE];
//            printf("请输入%d个按升序排列的关键字值：\n", n);
//            for (int i = 0; i < n; i++) {
//                scanf("%d", &table[i]);
//            }
//            printf("请输入要查找的关键值：");
//            scanf("%d", &key);
//            result = binary_search(table, n, key);
//            if (result != -1) {
//                printf("找到关键值 %d，位于表中索引位置 %d。\n", key, result);
//            }
//            else {
//                printf("未找到关键值 %d。\n", key);
//            }
//        }
//        else if (choice == 3) {
//            printf("感谢使用，再见！\n");
//            break;
//        }
//        else {
//            printf("无效选项，请重新选择。\n");
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
//// 定位顶点在顶点数组中的位置
//int locateVex(ALGraph G, int v) {
//    for (int i = 0; i < G.vexnum; i++) {
//        if (G.vertices[i].data == v) {
//            return i;
//        }
//    }
//    return -1; // 未找到
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
//        // 分配内存并添加边 v1->v2
//        p1 = (ArcNode*)malloc(sizeof(ArcNode));
//        p1->adjvex = j;
//        p1->nextarc = G.vertices[i].firstarc;
//        G.vertices[i].firstarc = p1;
//
//        // 分配内存并添加边 v2->v1
//        p2 = (ArcNode*)malloc(sizeof(ArcNode));
//        p2->adjvex = i;
//        p2->nextarc = G.vertices[j].firstarc;
//        G.vertices[j].firstarc = p2;
//    }
//    return ok;
//}
//int visited[MVNum];
//
//// 初始化访问标记数组
//void initVisited() {
//    for (int i = 0; i < MVNum; i++) {
//        visited[i] = 0;
//    }
//}
//
//// 深度优先搜索遍历
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
//// 广度优先搜索遍历
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
//    // 测试打印邻接表
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
//	scanf("%c", &ch);//通过输入的ch是否是‘#’来判断该节点是否有孩子节点
//
//	if (ch == '#') //'#'代表传入的是空结点
//	{
//		//此时为空结点
//		return NULL;
//	}
//	else
//	{
//		//不为空
//		T = (BitNode*)malloc(sizeof(BitNode));
//		T->val = ch;
//		//创建左子树，逻辑一致，进行递归
//		T->left = creatTree();
//		//创建右子树，逻辑一致，进行递归
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
//// 创建一个空栈
//void initStack(Stack* stack) {
//    stack->top = -1;
//}
//
//// 入栈
//void push(Stack* stack, BiTree node) {
//    if (stack->top < MAX_STACK_SIZE - 1) {
//        stack->data[++stack->top] = node;
//    }
//}
//
//// 出栈
//BiTree pop(Stack* stack) {
//    if (stack->top != -1) {
//        return stack->data[stack->top--];
//    }
//    return NULL;
//}
//
//// 非递归先序遍历
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
//// 非递归中序遍历
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
//// 非递归后序遍历
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
//	// 构建二叉树
//	printf("请输入字符以构建二叉树，无左右孩子分别用#表示:");
//	BiTree root = creatTree();
//
//	// 先序遍历
//	printf("Preorder traversal: ");
//	preOrderTraverse(root); 
//    printf("\n");
//    nonRecursivePreOrderTraverse(root);
//	printf("\n");
//
//	// 中序遍历
//	printf("Inorder traversal: ");
//	InOrderTraverse(root);
//    printf("\n");
//    nonRecursiveInOrderTraverse(root);
//	printf("\n");
//
//	// 后序遍历
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
////链队列
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
//	printf("输入队列长度：");
//	scanf("%d", &lengths);
//	printf("输入值：");
//	InitQueue(Q); // Initialize the queue
//	for (int i = 0; i < lengths; i++) {
//		int numbers;
//		scanf("%d", &numbers);
//		EnQueue(Q, numbers);
//	}
//	printf("你输入的是：");
//	printQueue(Q);
//	printf("\n");
//	printf("出队元素是：");
//	printf("%d\n",GetHead(Q));
//	printf("剩下的元素是：");
//	if(DeQueue(Q, a))
//	   printQueue(Q);
//	printf("\n");
//	int lengths1;
//	int a1;
//	LinkQueue Q1;
//	printf("输入队列长度：");
//	scanf("%d", &lengths);
//	printf("输入值：");
//	InitQueue1(Q1); // Initialize the queue
//	for (int i = 0; i < lengths; i++) {
//		int numbers;
//		scanf("%d", &numbers);
//		EnQueue1(Q1, numbers);
//	}
//	printf("你输入的是：");
//	printQueue1(Q1);
//	printf("出队元素是：%d\n", Q1.front->next->data);
//	printf("剩下的元素是：");
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
////顺序栈
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
//    printf("栈中元素为: ");
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
//    printf("栈中元素为: ");
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
////链栈
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
//    printf("栈中元素为: ");
//    while (S) {
//        printf("%d ", S->data);
//        S = S->next;
//    }
//    printf("\n");
//}
//
//void PrintLstack(LinkStack S) {
//    printf("栈中元素为: ");
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
//    printf("以下是顺序栈的操作\n");
//    printf("请输入栈中元素个数: ");
//    scanf("%d", &n);
//
//    if (InitStack(stack) == ERROR) {
//        printf("栈初始化失败\n");
//        return 1;
//    }
//
//    printf("请输入栈中各元素值: ");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &element);
//        if (Push(stack, element) == ERROR) {
//            printf("栈已满，无法添加新元素\n");
//            return 1;
//        }
//    }
//    PrintStack(stack);
//    printf("请输入你要添加的数：");
//    scanf("%d", &add);
//    if (Push(stack, add) == ERROR) {
//        printf("栈已满，无法添加新元素\n");
//        return 1;
//    }
//    else{
//        printf("新元素入栈成功\n");
//    }
//    PrintStack(stack);
//
//    printf("栈顶元素为：");
//    TOP = GetTop(stack);
//    printf("%d\n",TOP);
//    Pop(stack);
//
//
//    //链栈
//    printf("以下是链栈的操作\n");
//    int n2, element2,add2,TOP2;
//    LinkStack stack2;
//    printf("请输入栈中元素个数: ");
//    scanf("%d", &n2);
//    if (InitLstack(stack2) == ERROR) {
//        printf("栈初始化失败\n");
//        return 1;
//    }
//
//    printf("请输入栈中各元素值: ");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &element2);
//        if (PushL(stack2, element2) == ERROR) {
//            printf("栈已满，无法添加新元素\n");
//            return 1;
//        }
//    }
//    PrintLstack(stack2);
//
//    printf("请输入你要添加的数：");
//    scanf("%d", &add2);
//    if (PushL(stack2, add2) == ERROR) {
//        printf("栈已满，无法添加新元素\n");
//        return 1;
//    }
//    else {
//        printf("新元素入栈成功\n");
//    }
//    PrintLstack(stack2);
//
//    printf("栈顶元素为：");
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
//    L = (LinkList)malloc(sizeof(LNode)); // 分配头结点
//    L->next = NULL;
//    r = L;
//    int num;
//    scanf("%d", &num);
//    while (num != 0) {
//        p = (LNode*)malloc(sizeof(LNode)); // 分配新节点
//        p->data = num; // 输入节点数据
//        p->next = NULL;
//        r->next = p; // 尾插法插入节点
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
//    if (i <= 0 || count == 0) { // 如果 i 小于等于 0 或者链表为空
//        newNode->next = L->next;
//        L->next = newNode;
//    }
//    else if (count == i - 1) { // 如果 i 大于链表长度，或者在链表中间插入
//        newNode->next = p->next;
//        p->next = newNode;
//    }
//    else { // 如果 i 大于链表长度，或者在链表末尾插入
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
//    printf("请输入要查找的元素：");
//    scanf("%d", &target);
//    int location = findElem(L, target);
//    printf("元素 %d 在链表中的位置为：%d\n", target, location);
//
//    int add, pos;
//    printf("请输入要插入的值和位置（以空格分隔）：");
//    scanf("%d %d", &add, &pos);
//    insertElement(L, pos, add);
//    printf("插入后的链表：\n");
//    printList(L);
//    printf("请输入一个数：");
//    int number;
//    scanf("%d", &number);
//    int counts = countNodes(L, number);
//    printf("链表中共有%d个这个数", counts);
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
//	L.elem = (int*)malloc(MAXSIZE * sizeof(int));//为顺序表分配一个空间
//	if (!L.elem)
//		exit(OVERFLOW);
//	L.length = 0;
//	return OK;
//}
//int createList(SqList& L, int n) {
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &(L.elem[i])); // 依次读取元素值
//		L.length++; // 更新顺序表长度
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
//	int m = 0; // 记录重复元素个数
//	for (int i = 0; i < L.length - 1; i++) { // 注意循环范围
//		if (L.elem[i] == L.elem[i + 1]) { // 如果当前元素与下一个元素相同
//			m++; // 增加重复元素个数
//		}
//		else { // 如果当前元素与下一个元素不同
//			L.elem[i - m] = L.elem[i]; // 将当前元素向前移动 m 个位置
//		}
//	}
//	L.elem[L.length - m - 1] = L.elem[L.length - 1]; // 处理最后一个元素
//	L.length -= m; // 更新顺序表长度
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
//	initList(L); // 初始化顺序表
//	createList(L, n); // 创建顺序表
//	printfList(L);
//	int x;
//	scanf("%d", &x);
//	listInsert(L, x);
//	printfList(L); // 输出顺序表中的元素值
//	printf("\n");
//	deleteList(L);
////	printfList(L);
////	free(L.elem); // 释放顺序表内存
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
//// 定义二元关系的数据结构
//typedef struct {
//    char first;
//    char second;
//} Relation;
//
//// 自反闭包算法
//void reflexiveClosure(Relation R[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("<%c, %c>, ", R[i].first, R[i].second);
//    }
//    for (int i = 0; i < n; i++) {
//        printf("<%c, %c>, ", R[i].first, R[i].first);
//    }
//}
//
//// 对称闭包算法
//void symmetricClosure(Relation R[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("<%c, %c>, ", R[i].first, R[i].second);
//        printf("<%c, %c>, ", R[i].second, R[i].first);
//    }
//}
//
//// 传递闭包算法
//void transitiveClosure(Relation R[], int n) {
//    int matrix[MAX_SIZE][MAX_SIZE] = { 0 }; // 邻接矩阵表示关系
//
//    // 构建邻接矩阵
//    for (int i = 0; i < n; i++) {
//        matrix[R[i].first - 'a'][R[i].second - 'a'] = 1;
//    }
//
//    // 使用 Warshall 算法计算传递闭包
//    for (int k = 0; k < MAX_SIZE; k++) {
//        for (int i = 0; i < MAX_SIZE; i++) {
//            for (int j = 0; j < MAX_SIZE; j++) {
//                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
//            }
//        }
//    }
//
//    // 输出传递闭包
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
//    printf("原二元关系R: ");
//    for (int i = 0; i < n; i++) {
//        printf("<%c, %c>, ", R[i].first, R[i].second);
//    }
//    printf("\n");
//
//    printf("自反闭包r(R): ");
//    reflexiveClosure(R, n);
//    printf("\n");
//
//    printf("对称闭包s(R): ");
//    symmetricClosure(R, n);
//    printf("\n");
//
//    printf("传递闭包t(R): ");
//    transitiveClosure(R, n);
//    printf("\n");
//
//    return 0;
//}