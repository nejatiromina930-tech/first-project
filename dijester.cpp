#include <stdio.h>
#include <limits.h>

#define MAX 100

int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int V, int parent[], int start) {
    printf("\nKootah-tarin masir az ras %d:\n", start);
    for (int i = 0; i < V; i++) {
        if (i != start) {
            printf("Be ras %d ba hazineh %d masir: ", i, dist[i]);
            int path[MAX], j = 0, temp = i;
            while (temp != -1) {
                path[j++] = temp;
                temp = parent[temp];
            }
            for (int k = j - 1; k >= 0; k--) {
                printf("%d ", path[k]);
            }
            printf("\n");
        }
    }
}

void dijkstra(int graph[MAX][MAX], int V, int start) {
    int dist[MAX];
    int sptSet[MAX];
    int parent[MAX];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        if (u == -1) break;
        sptSet[u] = 1;

        printf("\nMarhaleh %d: gereh %d entekhab shod\n", count + 1, u);

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
            else if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] == dist[v]) {
                char choice;
                do {
                    printf("Do masir ba hazineh yeksan be ras %d vojood darad, yeki az tariqe %d va digari az tariqe %d. Entekhab kon (y/n): ", v, parent[v], u);
                    scanf_s(" %c", &choice);
                } while (choice != 'y' && choice != 'n');

                if (choice == 'y') {
                    parent[v] = u;
                }
            }
        }
    }

    printSolution(dist, V, parent, start);
}

int main() {
    int V, start;
    int graph[MAX][MAX];

    printf("Tedad roos-e graph ra vared kon: ");
    scanf_s("%d", &V);

    if (V > MAX) {
        printf("Tedad roos az hade aksar (%d) bishtar ast.\n", MAX);
        return 1;
    }

    printf("Matrix-e mojaavrat ra vared kon (0 be manaye nabood-e yal):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf_s("%d", &graph[i][j]);

    printf("Ras-e shoroo ra vared kon (shomareh bein 0 ta %d): ", V - 1);
    scanf_s("%d", &start);

    dijkstra(graph, V, start);

    return 0;
}























































