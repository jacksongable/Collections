# Collections

Collections is a C library that implements useful data structures for developers.
At this time, a singly linked list and a stack have been implemented. Trees, maps, and more
are also on the way. 

Stay tuned!


## Usage

### Linked List
A linked list is a list of nodes, where each node contains a data element
and a pointer to the next node.

#### Creating a new list
A linkedlist can be instantiated via <code>alloc_ll()</code>, which returns
a pointer to a newly allocated linked list. 

#### Adding an element
To add an element, call <code>ll_add(linkedlist *list, void *element)</code>,
where <code>list</code> is a pointer to the linked list to add the element to,
and <code>element</code> is a pointer to the element you wish to add. This function
returns the macro <code>LINKEDLIST_OK</code> on success.

#### Getting an element
To get an element, call <code>ll_get(linkedlist *list, unsigned int position)</code>, 
where <code>list</code> is a pointer to the linked list to get the 
element from, and <code>position</code> is the position of the element you
wish to fetch from the list. 

This function returns a void pointer to the element on success,
and <code>LINKEDLIST_OUT_OF_BOUNDS_EX</code> if <code>position</code>
is outside the bounds of the list.

Remember to cast the result of this function into a pointer to of the
element's type before dereferencing! 

#### Deleting an element
To delete an element, call <code>ll_delete(linkedlist *list, unsigned int position)</code>,
where <code>list</code> is a pointer to the linked list to delete the element from, and
<code>position</code> is the position of the element to delete from the list.

This function returns <code>LINKEDLIST_OK</code> on success and <code>LINKEDLIST_OUT_OF_BOUNDS_EX</code>
if <code>position</code> is outside of the bounds of the list.

#### Getting the list's size
To get the size of a list, call <code>ll_size(linkedlist *list)</code>, where
<code>list</code> is a pointer to the list to get the size of. This function returns
the list's size as an <code>unsigned int</code>.