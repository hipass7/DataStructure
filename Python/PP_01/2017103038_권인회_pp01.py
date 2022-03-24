class Matrix:
    def __init__(self, first, second, third, fourth):
        self.first = first
        self.second = second
        self.third = third
        self.fourth = fourth
        self.list = [first, second, third, fourth]
    
    def __add__(self, other):
        result = Matrix(0, 0, 0, 0)
        result.list = [self.first + other.first, self.second + other.second, self.third + other.third, self.fourth + other.fourth]
        return result
        
    def __sub__(self, other):
        result = Matrix(0, 0, 0, 0)
        result.list = [self.first - other.first, self.second - other.second, self.third - other.third, self.fourth - other.fourth]
        return result
    
    def __str__(self):
        return "{} {} \n{} {}".format(self.list[0], self.list[1], self.list[2], self.list[3])

if __name__ == "__main__":
    A = Matrix(1, 2, 3, 4)
    B = Matrix(5, 6, 7, 8)
    
    C = A+B
    D = A-B
    
    print(C)
    print(D)