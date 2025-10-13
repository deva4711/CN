#include <stdio.h>

#define MAX 20

int parent[MAX];

// Find operation for union-find

int find(int i) {

   while (parent[i] != i)

       i = parent[i];

   return i;

}

// Union operation

void union_sets(int i, int j) {

   int a = find(i);

   int b = find(j);

   parent[a] = b;

}

int main() {

   int n, i, j, u, v, a, b;

   int cost[MAX][MAX];

   int min, mincost = 0, edges = 1;

   printf("Enter the number of hosts (nodes): ");

   scanf("%d", &n);

   printf("Enter the cost adjacency matrix (use 999 for no link):\n");

   for (i = 1; i <= n; i++) {

       for (j = 1; j <= n; j++) {

           scanf("%d", &cost[i][j]);

           if (cost[i][j] == 0) {

               cost[i][j] = 999;  // avoid self-loop

           }

       }

   }

   // Initialize parent array

   for (i = 1; i <= n; i++) {

       parent[i] = i;

   }

   printf("\nEdges in the Broadcast Tree (MST):\n");

   while (edges < n) {

       min = 999;

       // Find minimum edge

       for (i = 1; i <= n; i++) {

           for (j = 1; j <= n; j++) {

               if (cost[i][j] < min) {

                   min = cost[i][j];

                   a = u = i;

                   b = v = j;

               }

           }

       }

 

       u = find(u);

       v = find(v);

       // If including this edge doesn't form a cycle

       if (u != v) {

           printf("Edge %d: (%d -- %d) cost: %d\n", edges++, a, b, min);

           mincost += min;

           union_sets(u, v);

       }

       cost[a][b] = cost[b][a] = 999;  // remove edge

   }

   printf("\nMinimum Cost of Broadcast Tree = %d\n", mincost);

 

   return 0;

}

