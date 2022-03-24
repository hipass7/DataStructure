from hashtable import *

if __name__ == '__main__':
    arr = HashTable(10)
    arr.InsertItem(5)
    arr.InsertItem(3)
    arr.InsertItem(8)
    arr.InsertItem(88)
    arr.InsertItem(888)

    print(arr.RetrieveItem(5))
    print(arr.RetrieveItem(6))
    print(arr.RetrieveItem(888))

    print(arr.info)