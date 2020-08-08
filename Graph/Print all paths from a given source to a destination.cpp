"""

https://www.geeksforgeeks.org/find-paths-given-source-destination/

"""

https://www.geeksforgeeks.org/find-paths-given-source-destination/

The idea is to do Depth First Traversal of given directed graph.
Start the DFS traversal from source.
Keep storing the visited vertices in an array or HashMap say ‘path[]’.
If the destination vertex is reached, print contents of path[].
The important thing is to mark current vertices in the path[] as visited also so that the traversal doesn’t go in a cycle.

def DFSPathUtil(graph,paths, curr_path, visited,curr,d):
  visited[curr] = True
  curr_path.append(curr)
  
  if curr == d:
    paths.append(curr_path[:])
    curr_path.pop()
    visited[curr]= False
    return
  
  if curr in graph:
    for ni in graph[curr]:
      if not visited[ni]:
        DFSPathUtil(graph,paths, curr_path, visited,ni,d)
      
  curr_path.pop()
  visited[curr]= False      
  

def getDFSPaths(graph, s, d, n):
  paths = []
  
  visited = [False]*n
  curr_path = []
  DFSPathUtil(graph,paths, curr_path, visited,s,d)
  
  print(paths)

graph ={0:[1,2,3], 1:[3], 2:[0,1]}
getDFSPaths(graph, 2,3,4)
