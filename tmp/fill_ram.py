#!/usr/bin/python3

l = []
for i in range(1000000000):
    l.append([j for  j in range(i)]) # c is almost 400 times faster than python in while allocating storage
    x = [j for  j in range(i)] #garbage collection existes 
    print(i)
    
