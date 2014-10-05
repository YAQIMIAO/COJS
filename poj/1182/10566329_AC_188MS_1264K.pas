type
  node=record
    p,r:longint;
    end;
var
  n,k,i,t,d,x,y,fx,fy:longint;
  s:array[1..50000]of node;
procedure mix_fset(i,j:longint);
begin
  if s[i].p>s[j].p then
    begin
      s[j].p:=s[i].p+s[j].p;
      s[i].p:=j;
      s[i].r:=(s[y].r+3-(d-1)+(3-s[x].r)) mod 3;
    end
  else
    begin
      s[i].p:=s[j].p+s[i].p;
      s[j].p:=i;
      s[j].r:=(s[x].r+d-1+3-s[y].r) mod 3;
    end;
end;
function search(i:longint):longint;
var
  j,k,t,sum,q:longint;
begin
  j:=i;
  k:=i;
  sum:=0;
  while (s[j].p>0) do
    begin
      sum:=sum+s[j].r;
      j:=s[j].p;
    end;
  while (k<>j) and (s[k].p<>j) do
    begin
      t:=s[k].p;
      q:=s[k].r;
      s[k].p:=j;
      s[k].r:=sum mod 3;
      sum:=sum-q;
      k:=t;
    end;
  exit(j);
end;
begin
  readln(n,k);
  t:=0;
  for i:=1 to n do
    begin
      s[i].p:=-1;
      s[i].r:=0;
    end;
  for i:=1 to k do
    begin
      read(d,x,y);
      if ((x>n) or (y>n)) or
        ((d=2) and (x=y)) then
          begin
            continue;
          end;
      fx:=search(x);
      fy:=search(y);
      if fx=fy then
        if (3-s[x].r+s[y].r)mod 3<>d-1 then
          begin
            continue;
          end
        else
          begin
            inc(t);
            continue;
          end;
      if fx<>fy then
        begin
          inc(t);
          mix_fset(fx,fy);
        end;
    end;
  writeln(k-t);
end.
