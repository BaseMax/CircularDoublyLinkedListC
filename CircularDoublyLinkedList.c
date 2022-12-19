/**
 * 
 * @file CircularDoublyLinkedList.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Circular Doubly Linked List (CDLL) is a variation of Doubly Linked List (DLL). In CDLL, the last node points to the first node and the first node points to the last node. It is a circular list and hence the name. It is also called a Ring List. It can be a singly circular linked list or doubly circular linked list.
 * @version 0.1
 * @date 2022-12-19
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h> // for printf, scanf, NULL
#include <stdlib.h> // for malloc, free
#include <stdbool.h> // for bool type

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} CircularDoublyLinkedList;

/**
 * @brief Create a new Circular Doubly Linked List object
 * 
 * @return CircularDoublyLinkedList* 
 */
CircularDoublyLinkedList* createNewCircularDoublyLinkedList() {
    CircularDoublyLinkedList *list = (CircularDoublyLinkedList*) malloc(sizeof(CircularDoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/**
 * @brief Create a new Node object
 * 
 * @param data 
 * @return Node* 
 */
Node* createNewNode(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/**
 * @brief Insert a new node at the end of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtEnd(CircularDoublyLinkedList *list, int data) {
    Node *node = createNewNode(data);
    if(list->head == NULL) {
        list->head = node;
        list->tail = node;
        node->next = node;
        node->prev = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
        list->tail->next = list->head;
        list->head->prev = list->tail;
    }
    list->size++;
}

/**
 * @brief Insert a new node at the beginning of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtBeginning(CircularDoublyLinkedList *list, int data) {
    Node *node = createNewNode(data);
    if(list->head == NULL) {
        list->head = node;
        list->tail = node;
        node->next = node;
        node->prev = node;
    } else {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
        list->tail->next = list->head;
        list->head->prev = list->tail;
    }
    list->size++;
}

/**
 * @brief Insert a new node at the given index
 * 
 * @param list 
 * @param data 
 * @param index 
 */
void insertAtIndex(CircularDoublyLinkedList *list, int data, int index) {
    if(index < 0 || index > list->size) {
        printf("Index out of range!\n");
        return;
    }
    if(index == 0) {
        insertAtBeginning(list, data);
    } else if(index == list->size) {
        insertAtEnd(list, data);
    } else {
        Node *node = createNewNode(data);
        Node *temp = list->head;
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next->prev = node;
        temp->next = node;
        node->prev = temp;
        list->size++;
    }
}

/**
 * @brief Delete the first node of the list
 * 
 * @param list 
 */
void deleteFirstNode(CircularDoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if(list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        Node *temp = list->head;
        list->head = list->head->next;
        list->head->prev = list->tail;
        list->tail->next = list->head;
        free(temp);
    }
    list->size--;
}

/**
 * @brief Delete the last node of the list
 * 
 * @param list 
 */
void deleteLastNode(CircularDoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if(list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        Node *temp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = list->head;
        list->head->prev = list->tail;
        free(temp);
    }
    list->size--;
}

/**
 * @brief Delete the node at the given index
 * 
 * @param list 
 * @param index 
 */
void deleteNodeAtIndex(CircularDoublyLinkedList *list, int index) {
    if(index < 0 || index >= list->size) {
        printf("Index out of range!\n");
        return;
    }
    if(index == 0) {
        deleteFirstNode(list);
    } else if(index == list->size - 1) {
        deleteLastNode(list);
    } else {
        Node *temp = list->head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        list->size--;
    }
}

/**
 * @brief Search for a node in the list
 * 
 * @param list 
 * @param data 
 * @return true 
 * @return false 
 */
bool search(CircularDoublyLinkedList *list, int data) {
    Node *temp = list->head;
    for(int i = 0; i < list->size; i++) {
        if(temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

/**
 * @brief Print the list
 * 
 * @param list 
 */
void printList(CircularDoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    for(int i = 0; i < list->size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Print the list in reverse order
 * 
 * @param list 
 */
void printListReverse(CircularDoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->tail;
    for(int i = 0; i < list->size; i++) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/**
 * @brief Print the list in reverse order using recursion
 * 
 * @param list 
 */
void printListReverseRecursive(CircularDoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printListReverseRecursiveHelper(list->head);
    printf("\n");
}

/**
 * @brief Helper function for printListReverseRecursive
 * 
 * @param node 
 */
void printListReverseRecursiveHelper(Node *node) {
    if(node->next == NULL) {
        printf("%d ", node->data);
        return;
    }
    printListReverseRecursiveHelper(node->next);
    printf("%d ", node->data);
}

/**
 * @brief Reverse the list
 * 
 * @param list 
 */
void reverseList(CircularDoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    Node *temp2 = list->tail;
    for(int i = 0; i < list->size / 2; i++) {
        int tempData = temp->data;
        temp->data = temp2->data;
        temp2->data = tempData;
        temp = temp->next;
        temp2 = temp2->prev;
    }
}

/**
 * @brief Reverse the list using recursion
 * 
 * @param list 
 */
void reverseListRecursive(CircularDoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    reverseListRecursiveHelper(list->head);
}

/**
 * @brief Helper function for reverseListRecursive
 * 
 * @param node 
 */
void reverseListRecursiveHelper(Node *node) {
    if(node->next == NULL) {
        return;
    }
    reverseListRecursiveHelper(node->next);
    int tempData = node->data;
    node->data = node->next->data;
    node->next->data = tempData;
}

/**
 * @brief Get the size of the list
 * 
 * @param list 
 * @return int 
 */
int getSize(CircularDoublyLinkedList *list) {
    return list->size;
}

/**
 * @brief Get the data at the given index
 * 
 * @param list 
 * @param index 
 * @return int 
 */
int getDataAtIndex(CircularDoublyLinkedList *list, int index) {
    if(index < 0 || index >= list->size) {
        printf("Index out of range!\n");
        return -1;
    }
    Node *temp = list->head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

/**
 * @brief Get the index of the given data
 * 
 * @param list 
 * @param data 
 * @return int 
 */
int getIndex(CircularDoublyLinkedList *list, int data) {
    Node *temp = list->head;
    for(int i = 0; i < list->size; i++) {
        if(temp->data == data) {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

/**
 * @brief Get the first node
 * 
 * @param list 
 * @return Node* 
 */
Node *getFirstNode(CircularDoublyLinkedList *list) {
    return list->head;
}

/**
 * @brief Get the last node
 * 
 * @param list 
 * @return Node* 
 */
Node *getLastNode(CircularDoublyLinkedList *list) {
    return list->tail;
}

/**
 * @brief Get the node at the given index
 * 
 * @param list 
 * @param index 
 * @return Node* 
 */
Node *getNodeAtIndex(CircularDoublyLinkedList *list, int index) {
    if(index < 0 || index >= list->size) {
        printf("Index out of range!\n");
        return NULL;
    }
    Node *temp = list->head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

/**
 * @brief Get the next node
 * 
 * @param node 
 * @return Node* 
 */
Node *getNextNode(Node *node) {
    return node->next;
}

/**
 * @brief Get the previous node
 * 
 * @param node 
 * @return Node* 
 */
Node *getPrevNode(Node *node) {
    return node->prev;
}

/**
 * @brief Get the data of the given node
 * 
 * @param node 
 * @return int 
 */
int getData(Node *node) {
    if (node == NULL) return -1;
    return node->data;
}

/**
 * @brief Set the data of the given node
 * 
 * @param node 
 * @param data 
 */
void setData(Node *node, int data) {
    node->data = data;
}