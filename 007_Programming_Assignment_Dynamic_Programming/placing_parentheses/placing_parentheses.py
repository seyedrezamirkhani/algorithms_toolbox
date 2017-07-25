# Uses python3
import math

def evalt(a, op, b):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def get_maximum_value(dataset):
    #write your code here
    n = int((len(dataset) / 2)) + 1
    # generate new string d containing numbers without operators
    nums = list(map(int,''.join(c for c in dataset if c not in '+-*')))
    # generate new list with of all operators
    ops = list(''.join(c for c in dataset if c not in '0123456789'))

    min_matrix = [[0 for x in range(n)] for y in range(n)]
    max_matrix = [[0 for x in range(n)] for y in range(n)]

    for i in range(n):
        min_matrix[i][i] = nums[i]
        max_matrix[i][i] = nums[i]

    for s in range(1,n): # start range at 1 to shift to 1st calculation col
        for i in range(n-s):
            j = i + s
            ########### MinAndMax
            max_num = -math.inf
            min_num = math.inf
            for k in range(i, j):
                fa = evalt(max_matrix[i][k], ops[k], max_matrix[k+1][j])
                fb = evalt(max_matrix[i][k], ops[k], min_matrix[k+1][j])
                fc = evalt(min_matrix[i][k], ops[k], max_matrix[k+1][j])
                fd = evalt(min_matrix[i][k], ops[k], min_matrix[k+1][j])
                min_num = min(min_num, fa, fb, fc, fd)
                max_num = max(max_num, fa, fb, fc, fd)
            ###########
            min_matrix[i][j] = min_num
            max_matrix[i][j] = max_num
    return max_matrix[0][n-1]

if __name__ == "__main__":
    print(get_maximum_value(input()))
