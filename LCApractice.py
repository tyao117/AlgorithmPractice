#LCA Practice
import collections

class Node:
    def __init__(self, value):
        self.value = value
        self.right = None
        self.left = None
    def insert(self, value):
        if self.right == None:
            self.right = Node(value)
            return self.right
        else:
            self.left = Node(value)
            return self.left

num_of_trees = int(input())
nodeMap = {}

while (True):
    try:
        x = input()
    except EOFError:
        break
    # split the input
    line = [int(x) for x in x.split()]
    # if the node is not there, then node[0] = [node[1]],
    #   same for node [1]
    if line[0] not in nodeMap:
        nodeMap[line[0]] = Node(line[0])
    nodeMap[line[1]] = nodeMap[line[0]].insert(line[1])

def preOrder(x):
    if x == None:
        return
    print(x.value)
    preOrder(x.left)
    preOrder(x.right)

def LCA(node, val1, val2):
    if node == None:
        return None
    
    if node == val1 or node == val2:
        return node

    left = LCA(node.left, val1, val2)
    right = LCA(node.right, val1, val2)

    if left != None and right != None:
        return node

    if left == None:
        return right
    else:
        return left

def lca(tree, node0, node1):
    Status = collections.namedtuple('Status', ('num_target_nodes', 'ancestor'))
    def lca_helper(tree, node0, node1):
        if not tree:
            return Status(0 , None)

        left_result = lca_helper(tree.left, node0, node1)
        if left_result.num_target_nodes == 2:
            return left_result

        right_result = lca_helper(tree.right, node0, node1)
        if right_result.num_target_nodes == 2:
            return right_result

        num_target_nodes = (left_result.num_target_nodes + right_result.num_target_nodes
                            + int (tree is node0) + int (tree is node1))
        return Status(num_target_nodes, tree if num_target_nodes == 2 else None)
    return lca_helper(tree, node0, node1).ancestor

parent = (lca(nodeMap[3], None, nodeMap[11]))

if parent:
    print (parent.value)    
else:
    print ("None ancestor")
