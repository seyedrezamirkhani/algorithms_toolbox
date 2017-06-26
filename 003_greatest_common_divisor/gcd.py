import sys


'''
euclidGCD takes two integers where a > b
returns Greatest Common Divisor
'''
def euclidGCD(a, b):
    if b == 0:
        return a
    rem = a % b # a'    
    return euclidGCD(b, rem)

''' 
main function expects data from std input in the format:
line 1 an int representing the number of lines to read
line 2 and onwards to have two space separated int values largest value first

prints the value returned by GDC function to std output
'''
if __name__ == "__main__":
    n = int(raw_input())
    for i in range(n):
        a, b = map(int, raw_input().strip().split())
        gcd = euclidGCD(a, b)
        print str(gcd)
