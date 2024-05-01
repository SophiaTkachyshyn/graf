#include "pch.h"
#include "CppUnitTest.h"
#include "../graf/main.cpp"




using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestShortestPath)
        {
            // Arrange
            const int vertices = 6;
            int** graph = new int* [vertices];
            for (int i = 0; i < vertices; ++i) {
                graph[i] = new int[vertices];
                fill(graph[i], graph[i] + vertices, INF);
            }

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

            deleteGraph(graph, vertices);
        }

        TEST_METHOD(TestShortestPathNoPath)
        {
            // Arrange
            const int vertices = 4;
            int** graph = new int* [vertices];
            for (int i = 0; i < vertices; ++i) {
                graph[i] = new int[vertices];
                fill(graph[i], graph[i] + vertices, INF);
            }

            graph[0][1] = 1;
            graph[1][2] = 2;
            graph[2][3] = 3;

            int source = 0;
            int destination = 3;

            // Act
            Dijkstra(graph, vertices, source, destination);

           
            deleteGraph(graph, vertices);
        }

        TEST_METHOD(TestShortestPathNegativeWeights)
        {
            // Arrange
            const int vertices = 4;
            int** graph = new int* [vertices];
            for (int i = 0; i < vertices; ++i) {
                graph[i] = new int[vertices];
                fill(graph[i], graph[i] + vertices, INF);
            }

            graph[0][1] = 1;
            graph[1][2] = -2;
            graph[2][3] = 3;

            int source = 0;
            int destination = 3;

            // Act
            Dijkstra(graph, vertices, source, destination);

           
            deleteGraph(graph, vertices);
        }

    };
}
