This problem is **solved using dfs.**
Data structures needed to solve the problem:
1. Discovery vector - shows the discovery time of the node i.e, when the node is traverse.
2. Lowest time vector - Shows the lowest time to reach the node.
3. Visited vector - to mark the node visited when reached.
​
Three condition can be occur during dfs.
1. Backedge Condition- this is the condition when it is found that the adjacent of the node is already visited. In this case, make sure to update the lowest time of the node because this means that there is another path to reach the node and maybe that path is small so the node would get smaller lowest time.
2. Avoid the above condition when **(node  ==parent)**  we ignore that condition using **continue**
3. **While returning** from the dfs call , **the lowest time of node must be update **.
4.If the lowertime of node is larger than the discovery time of the adj. that means there is no other way for them to reach each other. we can say that there is a bridge between them.