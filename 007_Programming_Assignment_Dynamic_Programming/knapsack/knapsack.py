# Uses python3
import sys
# from copy import deepcopy

def optimal_weight(W, w):
    # write your code here
    result = 0
    # for this specific problem weight and value are same
    # but values is added for more general case
    # values = deepcopy(w)
    matrix = [[0 for i in range(W+1)] for j in range(len(w)+1)]

    n = len(w)+1 # number of items

    for i in range(1, n):
        for j in range(1, W+1):
            matrix[i][j] = matrix[i-1][j]
            if w[i-1] <= j:
                val = matrix[i-1][j-w[i-1]] + w[i-1]
                if (matrix[i][j]) < val:
                    matrix[i][j] = val

    # print (matrix)
    # set result to last element in matrix (n-1, W)
    result = matrix[-1][-1] 
    return result

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
