def split(values, first, last): # 무조건 first를 pivot으로 잡음
    split_val = values[first]
    save_first = first
    first += 1
    
    while first <= last:
        on_correct = True
        while on_correct:
            if values[first] > split_val:
                on_correct = False
            else:
                first += 1
                on_correct = first <= last
        
        on_correct = first <= last

        while on_correct:
            if values[last] <= split_val:
                on_correct = False
            else:
                last -= 1
                on_correct = first <= last
        
        if first < last:
            temp = values[first]
            values[first] = values[last]
            values[last] = temp
            first += 1
            last -= 1

    split_point = last
    temp = values[save_first]
    values[save_first] = values[split_point]
    values[split_point] = temp

    return split_point

def quick_sort(values, first, last):
    '''[5]'''
    if first < last:
        split_point = split(values, first, last)
        quick_sort(values, first, split_point - 1)
        quick_sort(values, split_point + 1, last)
    return values
