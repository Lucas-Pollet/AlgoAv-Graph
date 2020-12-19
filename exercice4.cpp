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
  
  assert(g.neighbors(11) == std::vector<int>({12,21}));
  assert(g.neighbors(22) == std::vector<int>({12,21,23,32}));
  assert(g.commonNeighbors(11,22) == std::vector<int>({12,21}));
  assert(g.commonNeighbors(33,22) == std::vector<int>({23,32}));
  assert(g.commonNeighbors(11,33) == std::vector<int>({}));
  
  std::cout << "Vous avez reussi !" << std::endl;
  
  return 0;
}
