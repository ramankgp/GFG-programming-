"""

https://www.geeksforgeeks.org/shortest-path-unweighted-graph/
https://www.geeksforgeeks.org/find-paths-given-source-destination/
https://www.geeksforgeeks.org/print-all-shortest-paths-between-given-source-and-destination-in-an-undirected-graph/

"""

from collections import deque

def findPaths(parents,paths, curr_path, u,s):
  #print(u)
  if u == s:
    paths.append(curr_path[::-1])
    return
  
  for p in parents[u]:
    curr_path.append(p)
    findPaths(parents,paths, curr_path, p,s)
    curr_path.pop()
    

def getShortestPaths(graph, s,d,n):
  # BFS
  paths = []
  parents = {}
  dist = [float('inf')]*n
  dist[s] = 0
  
  q = deque([])
  q.append(s)
  parents[s] =[-1]
  
  #print(parents)
  while q:
    curr = q.pop()
    
    if curr in graph:
      for ni in graph[curr]:
        #print(ni)
        if dist[ni] > dist[curr] +1:
          #print('here')
          dist[ni] = dist[curr] +1
          if ni in parents:
            parents[ni] = [curr]
          else:
            parents[ni] = [curr]
          q.append(ni)
          
        elif dist[ni] == dist[curr] +1:
          parents[ni].append(curr)
   
  #print(parents)
  # DFS on parent
  curr_path = [d]
  findPaths(parents,paths, curr_path, d, s)
  
  print(paths)


graph ={0:[1,2], 1:[0,3,4], 2:[0,3], 3:[1,2,5], 4:[1,5], 5:[3,4]}
getShortestPaths(graph, 0,5,6)
