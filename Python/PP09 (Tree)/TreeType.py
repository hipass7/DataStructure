class TreeNode:

    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None
    
class BST():

    def __init__(self):
        self.root = None
        self.order_list = []
    
    def is_empty(self):
        return (self.root == None)
    
    def count_nodes(self, tree):
        '''[1]'''
        if tree == None:
            return 0
        else:
            return self.count_nodes(tree.left) + self.count_nodes(tree.right) + 1

    def length_is(self):
        return self.count_nodes(self.root)

    def insert(self, item):
        '''[2]'''
        if self.root == None:
            new_node = TreeNode(item)
            self.root = new_node
        else:
            self.insert_item(self.root, item)

    def insert_item(self, node, item):
        '''[3]'''
        if node == None:
            node = TreeNode(item)
            return node

        elif item < node.info:
            res = self.insert_item(node.left, item)
            node.left = res
            
        else:
            res = self.insert_item(node.right, item)
            node.right = res
            
        return node
  
    def inorder(self, node):
        '''[4]'''
        if node != None:
            self.inorder(node.left)
            self.order_list.append(node.info)
            self.inorder(node.right)
    
    def preorder(self, node):
        '''[5]'''
        if node != None:
            self.order_list.append(node.info)
            self.preorder(node.left)
            self.preorder(node.right)
    
    def postorder(self, node):
        '''[6]'''
        if node != None:
            self.postorder(node.left)
            self.postorder(node.right)
            self.order_list.append(node.info)

    def delete(self, item):
        '''[7]'''
        self.root = self.delete_node(self.root, item)
        # temp = res
        # data = 0
        # if res.left == None:
        #     res = res.right
        #     del temp
        # elif res.right == None:
        #     res = res.left
        #     del temp
        # else:
        #     g = self.get_predecessor(res.left, data)
        #     res.info = g
        #     self.delete_node(res.left, g)
    
    def delete_node(self, current, item):
        '''[8]'''
        data = 0
        if item < current.info:
            current.left = self.delete_node(current.left, item)
        elif item > current.info:
            current.right = self.delete_node(current.right, item)
        else:
            if current.left == None:
                return current.right
            elif current.right == None:
                return current.left
            else:
                g = self.get_predecessor(current.left, data)
                current.info = g
                self.delete_node(current.left, g)
        return current

            
    @staticmethod
    def get_predecessor(tree, data):
        # 멤버 함수로 변경해도 무방하다고 하셔서 변경하였음.
        '''[9]'''
        while tree.right != None:
            tree = tree.right
        data = tree.info
        return data