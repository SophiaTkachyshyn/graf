#include <iostream>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Функція для звільнення пам'яті, використованої для графа
void deleteGraph(int** graph, int vertices) {
    for (int i = 0; i < vertices; ++i)
        delete[] graph[i];
    delete[] graph;
}

// Функція для знаходження найкоротших шляхів від вершини source
void Dijkstra(int** graph, int vertices, int source, int destination) {
    int* distance = new int[vertices]; // Масив для зберігання найкоротших відстаней
    int* parent = new int[vertices]; // Масив для зберігання батьківських вершин у найкоротших шляхах

    // Ініціалізуємо відстані до всіх вершин як нескінченні, крім джерела
    for (int i = 0; i < vertices; ++i) {
        distance[i] = (i == source ? 0 : INF);
        parent[i] = -1;
    }

    // Міні пріоритетна черга для зберігання вершин та їхніх відстаней
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, source }); // Додаємо початкову вершину в чергу

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Переглядаємо всі сусідні вершини поточної вершини
        for (int v = 0; v < vertices; ++v) {
            // Оновлюємо відстань до вершини v, якщо існує ребро з u до v
            if (graph[u][v] != INF && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u; // Встановлюємо батьківську вершину для v
                pq.push({ distance[v], v });
            }
        }
    }

    // Виводимо найкоротші відстані від вершини source
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < vertices; ++i) {
        if (distance[i] == INF)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << distance[i] << "\n";
    }

    // Виводимо найкоротший шлях та його довжину до певної вершини (destination)
    cout << "\nShortest path length from " << source << " to " << destination << ": " << distance[destination] << "\n";
    cout << "Shortest path: ";
    int current = destination;
    while (current != source) {
        cout << current;
        current = parent[current];
        cout << " -> ";
    }
    cout << source << "\n";

    // Звільняємо пам'ять, виділену для масивів distance та parent
    delete[] distance;
    delete[] parent;
}

int main() {
    int vertices = 6;
    int** graph = new int* [vertices];

    // Ініціалізуємо граф
    for (int i = 0; i < vertices; ++i) {
        graph[i] = new int[vertices];
        fill(graph[i], graph[i] + vertices, INF); // Ініціалізуємо всі ваги ребер як INF
    }

    // Додаємо ребра в граф
    graph[0][1] = 5;
    graph[0][2] = 3;
    graph[0][4] = 2;
    graph[1][3] = 6;
    graph[1][4] = 8;
    graph[1][5] = 7;
    graph[2][4] = 4;
    graph[3][5] = 9;
    graph[4][5] = 10;

    int source = 0;
    int destination = 5;
    Dijkstra(graph, vertices, source, destination);

    // Звільняємо пам'ять, використовану для графа
    deleteGraph(graph, vertices);

    return 0;
}
