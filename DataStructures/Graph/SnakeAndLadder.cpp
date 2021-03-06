/**
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell.
Basically, the player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

If the player reaches a cell which is base of a ladder,
the player has to climb up that ladder and if reaches a cell is mouth of the snake,
has to go down to the tail of snake without a dice throw.

The idea is to consider the given snake and ladder board as a directed graph with number of vertices equal to the number of cells in the board.
The problem reduces to finding the shortest path in a graph.
Every vertex of the graph has an edge to next six vertices if next 6 vertices do not have a snake or ladder.
If any of the next six vertices has a snake or ladder, then the edge from current vertex goes to the top of the ladder or tail of the snake.
Since all edges are of equal weight, we can efficiently find shortest path using Breadth First Search of the graph.

Following is the implementation of the above idea. 
The input is represented by two things, first is ‘N’ which is number of cells in the given board, second is an array ‘move[0…N-1]’ of size N.
An entry move[i] is -1 if there is no snake and no ladder from i, otherwise move[i] contains index of destination cell for the snake or the ladder at i.
**/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> iPair; //vertex, distance

int minThrow(int N, int arr[]){
  map<int, int> m;
  for(int i=0; i<N; i++)
    m[arr[i*2]] = arr[i*2+1];

  vector<bool> visited(30, false);
  queue<iPair> q;
  q.push({1,0});
  visited[1] = true;
  iPair u;
  while(!q.empty()) {
    u = q.front();
    q.pop();

    if(u.first == 30)
      break;

    bool found = false;
    for(int v = u.first+1; v<=u.first+6 && v <= 30; v++) {
      if(!visited[v]) {
        if(m.find(v) != m.end()) {
          q.push({m[v], u.second + 1});
          visited[m[v]] = true;
        }
        else {
          q.push({v, u.second + 1});
          visited[v] = true;
        }
      }
    }
  }
  return u.second;
}
