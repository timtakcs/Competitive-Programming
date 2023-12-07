#  File: LeftSum.py

#  Description: Get the left sum of the BST

#  Student Name:

#  Student UT EID:

#  Course Name: CS 313E

#  Unique Number: 86610


import sys

class Queue(object):
    def __init__(self):
        self.queue = []

    # add an item to the end of the queue
    def enqueue(self, item):
        self.queue.append(item)

    # remove an item from the beginning of the queue
    def dequeue(self):
        return (self.queue.pop(0))

    # check if the queue is empty
    def is_empty(self):
        return (len(self.queue) == 0)

    # return the size of the queue
    def size(self):
        return (len(self.queue))

class Node (object):
  def __init__ (self, data):
    self.data = data
    self.lchild = None
    self.rchild = None

class Tree (object):
  def __init__ (self):
    self.root = None

  # insert data into the tree
  def insert (self, data):
    new_node = Node (data)

    if (self.root == None):
      self.root = new_node
      return
    else:
      current = self.root
      parent = self.root
      while (current != None):
        parent = current
        if (data < current.data):
          current = current.lchild
        else:
          current = current.rchild

      # found location now insert node
      if (data < parent.data):
        parent.lchild = new_node
      else:
        parent.rchild = new_node

    # ***There is no reason to change anything above this line***
  def get_height(self, node):
    if node is None:
      return 0
    else:
      # Compute the height of each subtree
      l_height = self.get_height(node.lchild)
      r_height = self.get_height(node.rchild)

        # Use the larger one
      return max(l_height, r_height) + 1

  def get_level(self, node, level, nodes):
    if node is None:
      return
    if level == 1:
      nodes.append(node.data)
    elif level > 1:
      self.get_level(node.lchild, level-1, nodes)
      self.get_level(node.rchild, level-1, nodes)

  def get_left_sum(self):
    total_sum = 0
    height = self.get_height(self.root)
    for i in range(1, height + 1):
      nodes = []
      self.get_level(self.root, i, nodes)
      if nodes:
        total_sum += nodes[0]  # Add the first (left-most) node of each level
    return total_sum


# ***There is no reason to change anything below this line***

def main():
    # Create tree
    line = sys.stdin.readline()
    line = line.strip()
    line = line.split()
    tree_input = list (map (int, line))    # converts elements into ints

    tree = Tree()
    for i in tree_input:
      tree.insert(i)

    print(tree.get_left_sum())

if __name__ == "__main__":
  main()
