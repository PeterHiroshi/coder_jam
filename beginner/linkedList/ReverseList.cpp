//
// Created by 清水ヒロシ on 2019/07/22.
//

#include <iostream>
#include <ctime>

using namespace std;

class Node;
Node *reverseList(Node *);
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
    head.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    clock_t start = clock();
    Node *newHead = reverseList(&head);
    printf("costs:%.3fms\n", ((clock()-start)*1000)/(double)CLOCKS_PER_SEC);
    printList(newHead);
    return 0;
}

Node *reverseList(Node *head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *curNode = head;
    Node *prevNode = nullptr;
    Node *nextNode = nullptr;
    while (curNode != nullptr) {
        nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }
    return prevNode;
}

void printList(Node *head)
{
    Node *curNode = head;
    while (curNode != nullptr) {
        printf("%d\n", curNode->val);
        curNode = curNode->next;
    }
}