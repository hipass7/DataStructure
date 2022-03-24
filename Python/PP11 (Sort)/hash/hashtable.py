
class HashTable:

    def __init__(self, max):
        self.info = [None] * max
        self.length = 0
        self.max = max

    def InsertItem(self, item):
        location = item % self.max
        while self.info[location] != None:
            location = (location + 1) % self.max
        self.info[location] = item
        self.length += 1

    def RetrieveItem(self, item):
        startLoc = item % self.max
        location = startLoc
        moreToSearch = True
        while True:
            if self.info[location] == item or self.info[location] == None:
                moreToSearch = False
            else:
                location += 1
                if location == self.max: # 꽉차있을때 고려 안했음
                    location %= self.max

            if not moreToSearch:
                break
        
        found = (self.info[location] == item)
        if found:
            item = self.info[location]
        
        return found

    