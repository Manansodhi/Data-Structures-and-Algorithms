// Time Complexity: O(N).
// Reason: We are traversing N nodes and every node is visited exactly once.
// Space Complexity: O(N)
// Reason: In the worst case, (a tree with every node having a single right child and 
//left-subtree the space complexity can be considered as O(N).

vector <int> preOrderTrav(node * curr) {
  vector <int> preOrder;
  if (curr == NULL)
    return preOrder;

  stack <node *> s;
  s.push(curr);

  while (!s.empty()) {
    node * topNode = s.top();
    preOrder.push_back(topNode -> data);
    s.pop();
    if (topNode -> right != NULL)
      s.push(topNode -> right);
    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
  return preOrder;

}

