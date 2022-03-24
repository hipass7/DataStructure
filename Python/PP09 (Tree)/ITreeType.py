
class NodeType:
    def __init__(self, data):
        self.info = data
        self.left = None
        self.right = None

class IterBST():
    def __init__(self):
        self.root = None
        self.order_list = []

    def insert(self, data):
        '''[10]'''
        new_node = NodeType(data)
        parent = self.find_node(self.root, data)

        if parent == None:
            self.root = new_node
        elif data < parent.info:
            parent.left = new_node
        else:
            parent.right = new_node


    def find(self, key):
        '''[11]'''
        # cpp 파일에서 명시된 부분이 없어 요소가 있는지 없는지 판단하는 함수로 만들었습니다.
        node = self.root
        found = False
        while not found:
            if node.info > key:
                node = node.left
            elif node.info < key:
                node = node.right
            elif node.info == key:
                found = True
            else:
                break

        return found

    def find_node(self, root, key):
        '''[12]'''
        node = root
        parent = None
        found = False
        while node != None and not found:
            if key < node.info:
                parent = node
                node = node.left
            elif key > node.info:
                parent = node
                node = node.right
            else:
                found = True
        return parent

    def delete(self, key):
        '''[13]'''
        self.root = self.delete_node(self.root, key)

    def delete_node(self, node, key):
        '''[14]'''
        # 이하 cpp대로 구현하라고 하셔서 recursion 사용하였음
        if node is None:
            return node

        if key == node.info:
            if node.left and node.right:
                parent, child = node, node.right
                while child.left != None:
                    parent, child = child, child.left
                child.left = node.left
                if parent != node:
                    parent.left = child.right
                    child.right = node.right
                node = child
            elif node.left or node.right:
                node = node.left or node.right
            else:
                node = None
        elif key < node.info:
            node.left = self.delete_node(node.left, key)
        else:
            node.right = self.delete_node(node.right, key)
        return node
        
    def inorder(self, node):
        # 이하 cpp대로 구현하라고 하셔서 recursion 사용하였음
        '''[15]'''
        if node != None:
            self.inorder(node.left)
            self.order_list.append(node.info)
            self.inorder(node.right)
    
    def preorder(self, node):
        '''[16]'''
        if node != None:
            self.order_list.append(node.info)
            self.preorder(node.left)
            self.preorder(node.right)
    
    def postorder(self, node):
        '''[17]'''
        if node != None:
            self.postorder(node.left)
            self.postorder(node.right)
            self.order_list.append(node.info)

    @staticmethod
    def get_predecessor(tree, data):
        # 멤버 함수로 변경해도 무방하다고 하셔서 변경하였음.
        '''[18]'''
        while tree.right != None:
            tree = tree.right
        data = tree.info
        return data
