#!/usr/bin/env python

# The optimizations make a difference when digits go beyond 100
def findRoot(n, digits):
    root = []
    X = int(n)
    mult = (len(str(X)) - 1) / 2
    prev = 0
    while (X or mult >= 0) and len(root) < digits:
        if mult >= 0: 
            factor = 10**(mult*2)
        else:
            X *= 100
            factor = 1
        # Binary searching for current digit shaves off about 20% runtime!
        # It only costs -200% code readability!
        l = 0
        r = 9
        while 1:
            m = (l+r+1)/2
            # Rearranging operation order further shaves off 30% runtime!
            # It only costs -3000% code readability!
            f1 = m*factor
            f2 = 20*f1
            c1 = m*f1
            value = f2*prev + c1
            if l == r:
                root.append(m)
                X -= value
                prev = prev*10 + m
                break
            if value > X:
                r = m-1
            else:
                l = m
        mult -= 1
    return root

def main():
    total = 0
    digits = 10000
    for i in xrange(1, 101):
        digitList = findRoot(i, digits)
        if len(digitList) == digits:
            total += sum(digitList)
    print total

if __name__ == "__main__":
    main()
