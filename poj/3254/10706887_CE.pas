uses math;
var
  n,m,i,j,k,tmps,t:longint;
  f,w,a:array[0..12]of longint;
  ss:array[1..4096]of longint;
  s:array[0..12,0..4095]of longint;
procedure dfs(l:longint);
var
  j:longint;
begin
  if l=m+1 then
    begin
      inc(t);
      for j:=1 to m do
        ss[t]:=ss[t]+w[j]*2**(m-j);
      exit;
    end;
  if w[l-1]=0 then
    for j:=0 to 1 do
      begin
        w[l]:=j;
        dfs(l+1);
      end;
  if w[l-1]=1 then
    begin
      w[l]:=0;
      dfs(l+1);
    end;
end;
begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(k);
        f[i]:=f[i]+(1-k)*2**(m-j);
      end;
  w[0]:=0;
  t:=0;
  dfs(1);
  a[0]:=1;
  s[0][1]:=1;
  for i:=1 to n do
    begin
      for j:=1 to t do
        begin
          if (f[i] and ss[j])<>0 then continue;
          for k:=1 to a[i-1] do
            begin
              if (ss[s[i-1][k]] and ss[j])=0 then
                begin
                  inc(a[i]);
                  s[i,a[i]]:=j;
                end;
            end;
        end;
    end;
  writeln(a[n]);
end.
