from sys import stdin

def main():
    num=[]
    for x in stdin.read().split():
        num.append(float(x))
    num.reverse()
    for x in num:
        print(x**0.5)
    return

main()