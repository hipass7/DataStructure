class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class CircularLL:
    def __init__(self):
        self.listData = None
        self.length = 0
        self.currentPos = None

    def is_full(self):
        try:
            location = NodeType("test")
            return False
        except:
            return True

    def length_is(self):
        return self.length

    def make_empty(self):
        while self.listData != None:
            tempPtr = self.listData.next
            del self.listData
            self.listData = tempPtr
        self.length = 0

    def find_item(self, listData, item):
        '''[4]'''
        more_to_search = True
        location = listData.next
        predLoc = listData
        found = False

        while more_to_search and not found:
            if item < location.info:
                more_to_search = False
            elif item == location.info:
                found = True
            else:
                predLoc = location
                location = location.next
                more_to_search = (location != listData.next)
        return predLoc
    
    def insert_item(self, item):
        '''[5]'''
        newNode = NodeType(item)
        if self.listData != None:
            predLoc = self.find_item(self.listData, item)
            newNode.next = predLoc.next
            predLoc.next = newNode
            if self.listData.info < item: # 맨 끝에 넣을 때, listData는 맨 끝을 가리킴
                self.listData = newNode
        else: # 맨 처음에 넣을 때
            self.listData = newNode
            newNode.next = newNode
        self.length += 1


    def delete_item(self, item):
        '''[6]'''
        predLoc = self.find_item(self.listData, item)
        location = predLoc.next
        if predLoc == location: # 요소가 하나 밖에 없을 때
            self.listData = None
        else:
            predLoc.next = location.next
            if location == self.listData: # 맨 끝 요소를 삭제할 때
                self.listData = predLoc
        
        del location
        self.length -= 1
   

    def reset_list(self):
        self.currentPos = None

    def get_next_item(self):
        if self.currentPos == None:
            self.currentPos = self.listData
        else:
            self.currentPos = self.currentPos.next
        return self.currentPos.info

    def __str__(self):
        self.reset_list()
        items = []
        for i in range(0, self.length):
            t = self.get_next_item()
            items.append(str(t))
        return "\n".join(items)
