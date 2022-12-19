# Circular Doubly Linked-List C

This is a simple implementation of Circular Doubly Linked-List in C. Circular Doubly Linked-List is a data structure that is a combination of a doubly linked list and a circular linked list. It is a linked list where all nodes are connected to each other. It is a circular linked list because all nodes are connected to each other. It is a doubly linked list because each node has a pointer to the next node and a pointer to the previous node. The last node points to the first node and the first node points to the last node. This makes it easy to traverse the list in both directions. It is also easy to insert and delete nodes from the list. The only disadvantage of a circular doubly linked list is that it takes up more memory than a regular doubly linked list because each node has two pointers instead of one. This is because each node has a pointer to the next node and a pointer to the previous node.

## Usage

```c
// Create a new list
CircularDoublyLinkedList *list = createNewCircularDoublyLinkedList();

// Add some data
insertAtBeginning(list, 1);
insertAtBeginning(list, 2);
insertAtBeginning(list, 3);
insertAtBeginning(list, 4);

// Print the list
printList(list);

// Print the list in reverse order
printListReverse(list);

// Reverse the list
reverseList(list);

// Print the list
printList(list);

// Print the list
printList(list);

// Get the size of the list
printf("Size: %d\n", getSize(list));

// Get the data at the given index
printf("Data at index 2: %d\n", getDataAtIndex(list, 2));

// Get the index of the given data
printf("Index of data 3: %d\n", getIndex(list, 3));

// Get the first node
Node *firstNode = getFirstNode(list);

// Get the last node
Node *lastNode = getLastNode(list);

// Get the node at the given index
Node *nodeAtIndex = getNodeAtIndex(list, 2);
printf("Data of node at index 2: %d\n", getData(nodeAtIndex));

// Get the next node
Node *nextNode = getNextNode(firstNode);
printf("Data of next node: %d\n", getData(nextNode));

// Get the previous node
Node *prevNode = getPrevNode(lastNode);
printf("Data of previous node: %d\n", getData(prevNode));

// Get the data of the given node
printf("Data of first node: %d\n", getData(firstNode));

// Set the data of the given node
setData(firstNode, 5);

// Print the list
printList(list);

// Delete the list
deleteList(list);
```

## License

This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.

Copyright (c) 2022, Max Base
