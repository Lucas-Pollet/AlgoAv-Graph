#include <iostream>
#include <cassert>
#include "graph.hpp" // C'est a vous de l'ecrire

int main() {
  Graph g; // C'est votre classe
  
  // Grille 4x3
  for(int x = 1; x <= 4; x++) {
    for(int y = 1; y <= 3; y++) {
      if(x <= 3)
        g.addEdge(10*x+y, 10*(x+1)+y); // Horizontal edge
      if(y <= 2)
        g.addEdge(10*x+y, 10*x+y+1); // Vertical edge
    }
  }
  
  std::vector<int> bfs_list = g.bfs(11);
  std::cout << "bfs : ";
  for(int v : bfs_list)
    std::cout << v << " ";
  std::cout << std::endl;
  
  assert(bfs_list.size() == 12);
  assert(bfs_list.at(0) == 11);
  assert(bfs_list.at(1) == 12 || bfs_list.at(1) == 21);
  assert(bfs_list.at(2) == 12 || bfs_list.at(2) == 21);
  assert(bfs_list.back() == 43);
  
  std::vector<int> dfs_list = g.dfs(11);
  std::cout << "dfs : ";
  for(int v : dfs_list)
    std::cout << v << " ";
  std::cout << std::endl;
  assert(dfs_list.size() == 12);
  assert(dfs_list.at(1) == 12 || dfs_list.at(1) == 21);
  assert(dfs_list.at(2) == 13 || dfs_list.at(2) == 31 || dfs_list.at(2) == 22);
  
  std::cout << "Vous avez reussi !" << std::endl;
  
  return 0;
}
