#此题线段树WA1
import sys
def initr(l):
    tr={}
    for i in range(1,l+1):
        tr[i]={}
    return tr

def refreshtr(a,b,l,tr):
    for i in range(a,0,-1):
        for j in range(b,l):
            if i>a or j<b:
                continue
            if i==a and b==j:
                tr[i][j]=tr[i][j]
                continue
            if i==a and j in tr[b+1]:
                tr[i][j]=(tr[a][b]+tr[b+1][j]) % 2
                continue
            if j==b and a-1 in tr[i]:
                tr[i][j]=(tr[a][b]+tr[i][a-1]) % 2
                continue
            if a-1 in tr[i] and j in tr[b+1]:
                tr[i][j]=(tr[i][a-1]+tr[a][b]+tr[b+1][j]) % 2
    return tr


def main():
    seqlen=int(input().split()[0])
    que=int(input().split()[0])
    tr=initr(seqlen)
    cnt=0
    s=sys.stdin.read().split()
    while cnt<que:
        a=int(s[cnt*3])
        if a==-1:
            print(cnt)
            return
        b=int(s[cnt*3+1])
        _p=s[cnt*3+2]
        if b not in tr[a]:
            if _p=="even":
                tr[a][b]=0
            else:
                tr[a][b]=1
            tr=refreshtr(a,b,seqlen,tr)
            continue
        p=tr[a][b]
        if (p==1 and _p=="even") or (p==0 and _p=="odd"):
            print(cnt)
            print(tr)
            return
        cnt+=1

main()

