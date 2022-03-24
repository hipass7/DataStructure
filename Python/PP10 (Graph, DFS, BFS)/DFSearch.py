from GraphType import *

def depth_first_search(graph, startVertex, endVertex):
    stack = StackType()
    vertexQ = QueType()
    found = False

    '''[9]'''
    graph.clear_marks()
    stack.push(startVertex)
    
    while True:
        vertex = stack.top()
        stack.pop()
        if vertex == endVertex:
            print(vertex)
            found = True
        else:
            if not graph.is_marked(vertex):
                graph.mark_vertex(vertex)
                print(vertex)
                graph.get_to_vertices(vertex, vertexQ)

                while not vertexQ.is_empty():
                    item = vertexQ.dequeue()
                    if not graph.is_marked(item):
                        stack.push(item)
        if not stack.is_empty() and not found:
            continue
        break
    if not found:
        print("Path not found")

def depth_first_search_r(graph, startVertex, endVertex):
    vertexQ = QueType()
    found = False
    graph.clear_marks()

    '''[9]'''
    if startVertex == endVertex:
        print(endVertex)
        return True
    
    graph.get_to_vertices(startVertex, vertexQ)
    while not vertexQ.is_empty():
        vertex = vertexQ.dequeue()
        if graph.is_marked(vertex) == True:
            continue
        if vertex != startVertex:
            graph.mark_vertex(vertex)
            if depth_first_search_r(graph, vertex, endVertex):
                print("<-", startVertex)
                return True
        else: continue

    return False