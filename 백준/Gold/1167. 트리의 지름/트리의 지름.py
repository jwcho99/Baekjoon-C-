import sys
import copy
from collections import deque
import heapq
from collections import Counter
from itertools import combinations
#from itertools import permutations
#sys.setrecursionlimit(10**5)
input = sys.stdin.readline

v=int(input())
graph = [[] for _ in range(v+1)]
for _ in range(v):
  nums = list(map(int,input().split()))
  l = len(nums)
  for i in range(1,l-1,2):
    x,y = nums[i],nums[i+1]
    graph[nums[0]].append([x,y])

def bfs(start):
  q=deque()
  q.append(start)
  while q:
    k=q.popleft()
    for a,b in graph[k]:
      if distance[a] == -1:
        distance[a] = distance[k]+b
        q.append(a)



ans = -1
distance = [-1 for _ in range(v+1)]
distance[1] = 0
bfs(1)
start_node = distance.index(max(distance))
distance = [-1 for _ in range(v+1)]
distance[start_node] = 0
bfs(start_node)
print(max(distance))
