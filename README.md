# Collections

Collections is a C library that implements common data structures for developers.
At the moment, only a singly linked list has been implemented.
In the future however, I'll be adding other structures such as stacks,
queues, trees, and more. More thorough documentation is also on the way. 

Stay tuned!

## linkedlist

A linked list is a list of nodes, where each node contains a data element
and a pointer to the next node. A linkedlist can be instantiated
via <code>alloc_ll()</code>, which returns a pointer to a newly
allocated linked list.

### alloc_ll()