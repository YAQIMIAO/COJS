const
  maxn=10000;
type
node=record
     y,next:longint;
     end;
var
  i,j,k,x,y,t,n,m,w:longint;
  ch:char;
  f,h,inn,outt:array[1..maxn]of longint;
  v:array[1..maxn]of boolean;
  g:array[1..maxn]of node;
procedure dfs(x:longint);
var
  tmp:longint; 
  begin
    inc(t);
    inn[x]:=t;
    tmp:=g[f[x]].y;
    while tmp<>0 do
      begin
        if inn[g[tmp].y]=0 then dfs(g[tmp].y);
        tmp:=g[tmp].next;
      end;
    outt[x]:=t;
  end;
function lowbit(x:longint):longint;
  begin
    lowbit:=x and(-x);
  end;
procedure change(k,delta:longint);
  begin
    while k<=n do
      begin
        h[k]:=h[k]+delta;
        k:=k+lowbit(k);
      end;
  end;
function getsum(k:longint):longint;
var
  t:longint;
  begin
    t:=0;
    while k>0 do
      begin
        t:=t+h[k];
        k:=k-lowbit(k);
      end;
    getsum:=t;
  end;
begin

  readln(n);
  m:=0;
  fillchar(h,sizeof(h),0);
  fillchar(f,sizeof(f),0);
  fillchar(g,sizeof(g),0);

  for i:=1 to n-1 do
    begin
      readln(x,y);
      inc(m);
      g[m].y:=y;
      g[m].next:=f[x];
      f[x]:=m;
      inc(m);
      g[m].y:=x;
      g[m].next:=f[y];
      f[y]:=m;
    end;
  for i:=1 to n do
    change(i,1);
  fillchar(v,sizeof(v),true);
  dfs(1);
  readln(w);
  for i:=1 to w do
    begin
      read(ch);
      if ch='Q' then
        begin
          readln(k);
          writeln(getsum(outt[k])-getsum(inn[k]-1));
        end;
      if ch='C' then
        begin
          readln(k);
          if (v[k]=true) then
            change(inn[k],-1)
          else
            change(inn[k],1);
          v[k]:=not v[k];
        end;
    end;

end.
