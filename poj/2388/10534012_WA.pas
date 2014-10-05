program build_heap;

var
  a:array[1..10000]of longint;
  n,i,j:longint;
procedure build_heap(num,max:longint);
var
  x:longint;
begin
  x:=a[num];
  j:=2*num;
  while j<=max do
    begin
      if (j<max) and (a[j]<a[j+1]) then inc(j);
      if x<a[j] then
        begin
          a[num]:=a[j];
          num:=j;
          j:=2*num;
        end
      else
        break;
    end;
  a[num]:=x;
end;
procedure swap(i,j:longint);
var t:longint;
begin
  t:=a[i];
  a[i]:=a[j];
  a[j]:=t;
end;

begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=n div 2 downto 1 do
    build_heap(n,i);
  for i:=n downto 2 do
    begin
      swap(1,i);
      build_heap(i-1,1);
    end;
  writeln(a[(n+1) div 2]);
end.
