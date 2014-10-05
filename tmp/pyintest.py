"""from sys import stdin,stdout

def main():
    for st in stdin.read().split():
        print(st)

main()
"""
import sys
print(sum(int(x) for x in sys.stdin.read().split()))