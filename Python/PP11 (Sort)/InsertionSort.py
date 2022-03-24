def insertion_sort(values):
    '''[4]'''
    for count in range(len(values)):
        finished = False
        current = count
        moreToSearch = (current != 0)
        
        while moreToSearch and not finished:
            if values[current] < values[current - 1]:
                values[current], values[current - 1] = values[current - 1], values[current]
                current -= 1
                moreToSearch = (current != 0)
            else:
                finished = True
    
