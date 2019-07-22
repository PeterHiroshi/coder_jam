//
// Created by 清水ヒロシ on 2019/07/22.
//

#include <iostream>
#include <ctime>

using namespace std;

class Node;
Node *reverseBetween(Node *, int, int);
void printList(Node *);

class Node
{
public:
    Node(int val, Node *next) :
            val(val), next(next)
    {}
    int val;
    Node *next;
};

int main()
{
    Node head = Node(1, nullptr);
    Node node1 = Node(2, nullptr);
    Node node2 = Node(3, nullptr);
    Node node3 = Node(4, nullptr);
    Node node4 = Node(5, nullptr);
    head.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    clock_t start = clock();
    Node *newHead = reverseBetween(&head, 2, 7);
    printf("costs:%.3fms\n", ((clock()-start)*1000)/(double)CLOCKS_PER_SEC);
    printList(newHead);
    return 0;
}

Node *reverseBetween(Node *head, int m, int n)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *startNode = head;
    Node *prevStartNode = nullptr;
    int tmpM = m;
    while ((tmpM-1) > 0 && startNode != nullptr) {
        prevStartNode = startNode;
        startNode = startNode->next;
        tmpM --;
    }
    if (startNode == nullptr) {
        return head;
    }
    Node *curNode = startNode;
    Node *prevNode = nullptr;
    Node *nextNode = nullptr;
    while ((n-m) >= 0 && curNode != nullptr) {
        nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
        n --;
    }
    startNode->next = curNode;
    if (prevStartNode != nullptr) {
        prevStartNode->next = prevNode;
    }
    return (prevStartNode == nullptr) ? prevNode : head;
}

void printList(Node *head)
{
    Node *curNode = head;
    while (curNode != nullptr) {
        printf("%d\n", curNode->val);
        curNode = curNode->next;
    }
}
