def main():
    try:
        while 1:
            for x in input().split(' '):
                num=int(x)
                if num!=42:
                    print(num)
                else:
                    return
    except EOFError as e:
        return

main()
