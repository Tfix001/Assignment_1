/*Names: Jacob Liu, Taylor Fix, Yuta Nakamara

Assignment 2: 

Exercise 1
If the elements of a list are sorted, is an array-based or a linked-list-based implementation of the list 
  more efficient for binary search? Explain. 
    Taylor's Thought: Array-based, since you have the actual size to look at. A linked-list will not be continuous block to look at efficiently
    Jacob's Thought: Array-based, because you access data by using indexes, but you have traverse the entire list for linked list. Linked list -> O(n) Array -> O(1).
    Yuta: An array would be more efficient.
          This is because with an array, you would be able to access elements through indexes, whereas with linked lists, you would have to traverse the entire list from the head in order to find the element you are looking for.
          A doubly linked list would be slightly more efficient than a singly linked list, since you can search the element from both the head and the tail, however, it would still pale in comparison to using an array.

Write C++ code to implement an integer queue class using linked-list, where the nodes are
  stored sorted by ascending value of the integer they store. We call this a priority queue.
  Specifically, implement enqueue and dequeue methods.

  What is the average asymptotic cost per call to enqueue and to dequeue?
    Taylor's Thought: O(1) (This was discussed in class)
    Jacob's Thought: The enqueue operation is O(N) because it scans the array trying to find the correct position 
    (based on its priority; highest priority is at the rear) for the added value. Dequeue is O(1) because it removes the last value.

  What if for each node, in addition to a pointer to the next node, you add a pointer to the 10th
    next node. Modify your code to take advantage of this.

  Can the modification in (c) improve the cost (not asymptotic but just execution time) of
    enqueue? Does it improve the asymptotic cost?
    Jacob's thoughts: Does it mean every time you add a node you also have add a pointer counting 10 nodes away from the node added?
    It would make the execution time worst then.
  Is there any disadvantage that modification (c) incurs?

Write a C++ class that implement two stacks using a single C++ array. That is, it should have functions
  popFirst(…), popSecond(…), pushFirst(…), pushSecond(…),… When out of space, double the size of the
  array (similarly to what vector is doing).

*/
