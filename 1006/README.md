# Notes

## E - Military Problem
In order to meet the runtime limit, you need to traverse the tree only once.

### the general idea
* Use ordered sets to keep track of subordinates of each node.
* Perform DFS once, keeping track of:
  * the nodes in DFS order (useful to retrieval the node corresponding to a given index `i`)
  * the number of nodes visited by DFS at the start and end of the node's visit (so that you can calculate the number of nodes in the subtree)
 * For each query `(u,k)`, check that each subtree contains at least `k` nodes, if not just return `-1`. Otherwise, you can get the from the DFS order index the `k-1`th node after node `u`.

