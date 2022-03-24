class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None
        self.back = None

class DoublyLL:
    def __init__(self):
        self.head = NodeType('head')
    
    def find_item(self, item):
        '''[1]'''
        location = self.head
        more_to_search = True
        found = False
        while more_to_search and not found:
            if item == location.info:
                found = True
            else:
                if location.next == None:
                    more_to_search = False
                else:
                    location = location.next
        return location
    
    def insert_item(self, item, new):
        '''[2]'''
        newNode = NodeType(new)
        location = self.find_item(item) # item의 위치를 찾아 다음에 new를 삽입
        if location.next == None:
            newNode.next = None
        else:
            newNode.next = location.next
            location.next.back = newNode
        newNode.back = location
        location.next = newNode

    def delete_item(self, item):
        '''[3]'''
        location = self.find_item(item)
        if location.next == None:
            location.back.next = None
        else:
            location.back.next = location.next
            location.next.back = location.back
            
    def __str__(self):
        cur_node = self.head
        items = []
        while cur_node is not None:
            items.append("(" + str(cur_node.info) + ")\n")
            cur_node = cur_node.next
        return "".join(items)

