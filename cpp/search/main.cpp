#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define string string
using namespace std;

struct SimpleGraph {
    unordered_map<char, vector<char>> edges;
    vector<char> neigbours(char id) { return edges[id]; }
};
struct Coords {
    int x;
    int y;

    bool operator==(const Coords& other) const { return (x == other.x) && (y == other.y); }
};

namespace std {
template <>
struct hash<Coords> {
    size_t operator()(const Coords& id) const noexcept { return hash<int>()(id.x ^ (id.y << 16)); }
};

}  // namespace std

struct Grid {
    static vector<Coords> DIRS;
    int width, height;
    unordered_set<Coords> walls;
    Grid(int width, int height)
    {
        this->height = height;
        this->width = width;
    }
    inline bool Inbounds(Coords id) const { return ((0 <= id.x && 0 <= id.y) && (id.x < width && id.y < height)); }
    inline bool Passable(Coords id) const { return walls.find(id) == walls.end(); }
    vector<Coords> isNeighbor(Coords id)
    {
        vector<Coords> results;
        for (Coords dir : DIRS) {
            Coords next = { id.x + dir.x, id.y + dir.y };
            if (Inbounds(id) && Passable(id)) {
                results.push_back(next);
            }
        }

        if ((id.x + id.y) % 2 == 0) {
            reverse(results.begin(), results.end());
        }

        return results;
    }
};
vector<Coords> Grid::DIRS = { Coords{ 0, 1 }, Coords{ -1, 1 }, Coords{ 1, 0 }, Coords{ 1, -1 } };

template <class Graph>
void draw_grid(const Graph& graph,
               unordered_map<Coords, double>* distances = nullptr,
               unordered_map<Coords, Coords>* point_to = nullptr,
               vector<Coords>* path = nullptr,
               Coords* start = nullptr,
               Coords* goal = nullptr)
{
    const int field_width = 3;
    cout << string(field_width * graph.width, '_') << '\n';
    for (int y = 0; y != graph.height; ++y) {
        for (int x = 0; x != graph.width; ++x) {
            Coords id{ x, y };
            if (graph.walls.find(id) != graph.walls.end()) {
                cout << string(field_width, '#');
            } else if (start && id == *start) {
                cout << " A ";
            } else if (goal && id == *goal) {
                cout << " Z ";
            } else if (path != nullptr && find(path->begin(), path->end(), id) != path->end()) {
                cout << " @ ";
            } else if (point_to != nullptr && point_to->count(id)) {
                Coords next = (*point_to)[id];
                if (next.x == x + 1) {
                    cout << " > ";
                } else if (next.x == x - 1) {
                    cout << " < ";
                } else if (next.y == y + 1) {
                    cout << " v ";
                } else if (next.y == y - 1) {
                    cout << " ^ ";
                } else {
                    cout << " * ";
                }
            } else if (distances != nullptr && distances->count(id)) {
                cout << ' ' << left << setw(field_width - 1) << (*distances)[id];
            } else {
                cout << " . ";
            }
        }
        cout << '\n';
    }
    cout << string(field_width * graph.width, '~') << '\n';
}

void add_rect(Grid& grid, int x1, int y1, int x2, int y2)
{
    for (int x = x1; x < x2; ++x) {
        for (int y = y1; y < y2; ++y) {
            grid.walls.insert(Coords{ x, y });
        }
    }
}

Grid make_diagram1()
{
    Grid grid(30, 15);
    add_rect(grid, 3, 3, 5, 12);
    add_rect(grid, 13, 4, 15, 15);
    add_rect(grid, 21, 0, 23, 7);
    add_rect(grid, 23, 5, 26, 7);
    return grid;
}

void bfs(SimpleGraph, char);
void dfs(SimpleGraph, char);
void aStar(SimpleGraph, char);

int main()
{
    // SimpleGraph example = { {
    //     { 'A', { 'B' } },
    //     { 'B', { 'C' } },
    //     { 'C', { 'B', 'D', 'F' } },
    //     { 'D', { 'C', 'E' } },
    //     { 'E', { 'F' } },
    //     { 'F', {} },
    // } };

    Grid grid = make_diagram1();
    Coords start{ 10, 10 };
    auto parents = bfs(grid, start);
    // bfs(example, 'A');
    // dfs(example, 'A');
    // printf("█"); // █ █ █ █
    // printf(make_diagram1());
    draw_grid(grid, nullptr, &parents, nullptr, &start);
    return 1028543692;
}

bfs(SimpleGraph graph, char v)
{
    queue<char> Q;
    Q.push(v);
    unordered_set<char> visited;
    visited.insert(v);
    while (!Q.empty()) {
        char current = Q.front();
        Q.pop();
        cout << "\n " << current;

        for (char next : graph.neigbours(current)) {
            if (visited.find(next) == visited.end()) {
                cout << " - " << next;
                Q.push(next);
                visited.insert(next);
            }
        }
    }
    return result;
}

void dfs()
{
    cout << "";
}

void aStar() {}
