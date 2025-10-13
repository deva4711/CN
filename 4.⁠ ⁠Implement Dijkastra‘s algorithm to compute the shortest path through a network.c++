 
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
 
const int INF = 1000;   // A large number representing infinity
int n;
vector<vector<int>> dis;  // adjacency matrix
 
void spath(int s, int t);
 
int main() {
   int i, j, c, s, t;
 
   cout << "Enter number of nodes: ";
   cin >> n;
 
   // Initialize adjacency matrix
   dis.assign(n, vector<int>(n, INF));
   for (i = 0; i < n; i++) {
       dis[i][i] = 0;
   }
 
   // Input graph
   for (i = 0; i < n; i++) {
       for (j = i + 1; j < n; j++) {
           cout << "Enter weight between " << i << " -> " << j
                << " (enter -1 if no edge): ";
           cin >> c;
           if (c >= 0) {
               dis[i][j] = c;
               dis[j][i] = c;  // Undirected graph
           }
       }
   }
 
   cout << "Enter source and destination nodes: ";
   cin >> s >> t;
 
   spath(s, t);
 
   return 0;
}
 
void spath(int s, int t) {
   struct State {
       int pre;
       int len;
       enum Label { PERMANENT, TENTATIVE } label;
   };
 
   vector<State> state(n);
 
   // Initialization
   for (int i = 0; i < n; i++) {
       state[i].pre = -1;
       state[i].len = INF;
       state[i].label = State::TENTATIVE;
   }
 
   state[s].len = 0;
   state[s].label = State::PERMANENT;
   int k = s;
 
   // Dijkstra’s algorithm
   do {
       for (int i = 0; i < n; i++) {
           if (dis[k][i] != INF && state[i].label == State::TENTATIVE) {
               if (state[k].len + dis[k][i] < state[i].len) {
                   state[i].pre = k;
                   state[i].len = state[k].len + dis[k][i];
               }
           }
       }
 
       int min = INF;
       for (int i = 0; i < n; i++) {
           if (state[i].label == State::TENTATIVE && state[i].len < min) {
               min = state[i].len;
               k = i;
           }
       }
       state[k].label = State::PERMANENT;
   } while (k != t);
 
   // Backtrack to find path
   vector<int> path;
   int c = 0;
   k = t;
   do {
       path.push_back(k);
       k = state[k].pre;
       c++;
   } while (k >= 0);
 
   cout << "\nMinimum Cost = " << state[t].len << endl;
   cout << "Shortest Path = ";
   for (int i = path.size() - 1; i >= 0; i--) {
       cout << path[i];
       if (i > 0) cout << " -> ";
   }
   cout << endl;
}
 