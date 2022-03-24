from enum import Enum

MAX_ITEMS = 100

class Compare(Enum):
    LESS = 0
    GREATER = 1
    EQUAL = 2
    
class ItemType:
    """ Item Type """

    def __init__(self, val):
        self.value = val

    def compared_to(self, otherItem):
        if self.value < otherItem.value:
            return Compare.LESS
        elif self.value > otherItem.value:
            return Compare.GREATER
        return Compare.EQUAL
    
    def __str__(self):
        return str(self.value)

class SortedType:
    """ Chapter 3: Sorted List """

    def __init__(self):
        self.length = 0
        self.info = []
        self.current_pos = -1

    def make_empty(self):
        self.length = 0

    def length_is(self):
        return self.length

    def is_full(self):
        if self.length == MAX_ITEMS:
            return True
        return False

    def insert_item(self, item):
        loc = 0
        more_to_search = (loc < self.length)
        while more_to_search:
            if item.compared_to(self.info[loc]) == Compare.LESS:
                more_to_search = False
                break
            elif item.compared_to(self.info[loc]) == Compare.GREATER:
                loc += 1
                more_to_search = loc < self.length
        idx = self.length
        self.info.append(0)
        while idx > loc:
            self.info[idx] = self.info[idx - 1]
            idx -= 1
        self.info[loc] = item
        self.length += 1
        

    def retrieve_item(self, item): # Binary Search
        first = 0
        last = self.length - 1
        more_to_search = first <= last
        found = False
        while more_to_search and not found:
            mid_point = int((first + last) / 2)
            if item.compared_to(self.info[mid_point]) == Compare.LESS:
                last = mid_point - 1
                more_to_search = first <= last
            elif item.compared_to(self.info[mid_point]) == Compare.GREATER:
                first = mid_point + 1
                more_to_search = first <= last
            else:
                found = True
                item = self.info[mid_point]
        return found

    def delete_item(self, item):
        loc = 0
        while item.compared_to(self.info[loc]) != Compare.EQUAL:
            loc += 1
        idx = loc + 1
        while idx < self.length:
            self.info[idx - 1] = self.info[idx]
            idx += 1
        self.length -= 1
        

    def reset_list(self):
        self.current_pos = -1

    def get_next_item(self):
        self.current_pos += 1
        return self.info[self.current_pos]

    def __str__(self):
        self.reset_list()
        
        print_list = []
        for i in range(self.length):
            print_list.append(str(self.get_next_item()))
        
        return str(" ".join(print_list))