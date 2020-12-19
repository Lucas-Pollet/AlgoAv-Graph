#include "graph.hpp"

        void Graph::addVertex(int v){
            if(!containsVertex(v)){
                dict[v].insert({});   
            }
         }

        void Graph::addEdge(int u, int v){
            if(!containsEdge(u, v)){
               dict[v].insert(u);
               dict[u].insert(v);
            }
        }

        bool Graph::containsVertex(int v) const {
            if (dict.find(v) != dict.end()){
                return true;        
            }
            return false;
        }

        bool Graph::containsEdge(int u, int v) const {
            if (containsVertex(v)){
                auto it = dict.at(v).find(u);

                if (it != dict.at(v).end()){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }

        int Graph::degree(int v) const {
            if(containsVertex(v)){
                int i = dict.at(v).size();
                return i;
            }else{
                return -1;
            }
        }

    int Graph::maxDegree() const{
        if(!dict.empty()){
            int max = 0;
            for(auto it = dict.begin(); it != dict.end(); ++it) {    
               if(degree(it->first) > max){      
                    max = degree(it->first);
                }
            }
            return max;
        }else{
            return -1;
        }
    }

    int Graph::countVertices() const{
        return dict.size();
    }

    int Graph::countEdges() const{
        int nb = 0;
        for(auto it = dict.begin(); it != dict.end(); ++it) {
            nb = nb + it->second.size();
        }

        return nb / 2;
    }

    void Graph::removeEdge(int u, int v){
        if(containsEdge(u, v)){
            dict[u].erase(v);
            dict[v].erase(u);
        }
    }

    void Graph::removeVertex(int v){
        if(containsVertex(v)){
            for (auto set_v = dict[v].begin(); set_v != dict[v].end(); set_v++){
                if(containsEdge(*set_v, v)){
                    dict[*set_v].erase(v);
                }
            }
            
            dict[v].clear();
            dict.erase(v);
        }
    }

    void Graph::contract(int u, int v){
        if(containsVertex(v)){
            for (auto set_v = dict[v].begin(); set_v != dict[v].end(); set_v++){
                if(containsEdge(*set_v, v)){
                    dict[u].insert(*set_v);
                    dict[*set_v].erase(v);
                }
            }
            
            dict[v].clear();
            dict.erase(v);
        }
    }

    vector<int> Graph::neighbors(int v) const{
        if(containsVertex(v)){
            vector<int> vec(dict.at(v).size());
            std::copy(dict.at(v).begin(), dict.at(v).end(), vec.begin());
            std::sort(vec.begin(), vec.end());

            return vec;
        }

        // renvoie un vecteur vide si v n'est pas dans le graph
        return vector<int>();
    }

    vector<int> Graph::commonNeighbors(int u, int v) const{
        if(containsVertex(v) && containsVertex(u)){
            vector<int> list;
            for (auto set_v = dict.at(v).begin(); set_v != dict.at(v).end(); set_v++){
                for (auto set_u = dict.at(u).begin(); set_u != dict.at(v).end(); set_u++){
                    // compairaison des 2 points, si ils sont commun on ajoute le point au vecteur
                    if(*set_v == *set_u)
                        list.push_back(*set_v);                               
                }
            }

            std::sort(list.begin(), list.end());
            return list;
        }
         
         // renvoie un vecteur vide si v et u ne sont pas dans le graph 
        return vector<int>();
    }

    // Parcours en profondeur du graph
    vector<int> Graph::dfs(int v) const {
        if(containsVertex(v)){
            vector<int> chem;
            vector<int> marked_point;

            chem.push_back(v);
            marked_point.push_back(v);

            vector<int> list_neighboor = neighbors(v);
            std::reverse(list_neighboor.begin(), list_neighboor.end());

            while (list_neighboor.size() > 0){
                int current = list_neighboor.back();
                list_neighboor.pop_back();

                if(find(marked_point.begin(), marked_point.end(), current) == marked_point.end()){
                    marked_point.push_back(current);
                    chem.push_back(current);

                    vector<int> cur_neigh = neighbors(current);
                    std::reverse(cur_neigh.begin(), cur_neigh.end());

                    for(int value_cur : cur_neigh){
                        if(find(marked_point.begin(), marked_point.end(), value_cur) == marked_point.end()){
                            list_neighboor.push_back(value_cur);
                        }
                    }
                }
            }
            return chem;
        }
        
         return vector<int>();
    }

    // Parcours en largeur du graph
    vector<int> Graph::bfs(int v) const {
        if(containsVertex(v)){
            vector<int> chem;
            vector<int> marked_point;

            chem.push_back(v);
            marked_point.push_back(v);

            queue<int> list_point;
            list_point.push(v);

            while (list_point.size() > 0){
                int current = list_point.front();
                list_point.pop();

                for (auto set_v = dict.at(current).begin(); set_v != dict.at(current).end(); set_v++){
                        int point = *set_v;

                        if(find(marked_point.begin(), marked_point.end(), point) == marked_point.end()){
                            chem.push_back(point); 
                            marked_point.push_back(point);

                            list_point.push(point);
                        }   
                    }
                }
            return chem;           
        }
        
        return vector<int>();
    }