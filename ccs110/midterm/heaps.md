
11 - Graded Participation
13 13 unread replies. 13 13 replies.

Your participation score for this module is based on posting an answer all of the practice questions below to this discussion board.  Review the information on the Graded Participation Information for more details and the Discussion Board Tips for details on using Canvas discussion boards.  Make sure to read the posting code to Canvas guide to make your answer look nice on the discussion board!

For questions 1 and 2, consider the two heaps in this image.  Heap (a) on the left is a maxheap and heap (b) on the right is a minheap.

Heaps

 

    What items[ ] array represents the maxheap in (a)?
    What items[ ] array represents the minheap in (b)?
    Draw the complete binary tree that the following items[ ] array represents.  Is it a maxheap?  A minheap?
        [5, 1, 2, 8, 6, 10, 3, 9, 4, 7]
    How can you determine if a node in items[i] is a leaf?

1.) The items array for the maxheap is [10, 9, 8, 7, 6, 5, 4, 3, 2, 1] and the items array for the minheap is [1, 2, 3, 4, 5, 6, 7, 8, 9, 1


     10
     /\
     9 5
    /\ /\
   8 7 2 3
  /\ /
 1 4 6

4. You can tell if an item is a leaf if it has no children - the equations for the children of a node are 2i+1 and 2i+2, so given node [i], if no other nodes exist at the indices 2i+1 or 2i+2, then the node is a leaf.