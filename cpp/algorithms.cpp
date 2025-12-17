#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <tuple> // Нужен для std::tie

using namespace std;

// -------------------------------------------------------------
// БАЗОВЫЕ СТРУКТУРЫ
// -------------------------------------------------------------

// Простая реализация графа через списки смежности.
// Используется для демонстрации, в main не активна.
struct SimpleGraph
{
    // Ключ: имя вершины ('A'), Значение: вектор соседей ({'B', 'C'})
    unordered_map<char, vector<char>> edges;

    // Метод-обертка для получения соседей
    vector<char> neighbours(char id)
    {
        return edges[id];
    }
};

// Структура, описывающая координаты клетки на 2D сетке
struct GridLocation
{
    int x, y;
};

// -------------------------------------------------------------
// ПЕРЕГРУЗКА ОПЕРАТОРОВ
// -------------------------------------------------------------

// Оператор равенства (==).
// Нужен для unordered_map/unordered_set, чтобы понимать, 
// что ключи {1,1} и {1,1} - это одна и та же клетка.
bool operator == (GridLocation a, GridLocation b)
{
    return (a.x == b.x) && (a.y == b.y);
}

// Оператор неравенства (!=). Стандартная практика.
bool operator != (GridLocation a, GridLocation b)
{
    return !(a == b);
}

// Оператор "меньше" (<).
// Нужен, если бы мы использовали std::map, std::set или 
// хотели сортировать векторы координат.
// std::tie создает кортеж ссылок и сравнивает их лексикографически:
// сначала x, если равны — то y.
bool operator < (GridLocation a, GridLocation b)
{
    return tie(a.x, a.y) < tie(b.x, b.y);
}

// -------------------------------------------------------------
// СПЕЦИАЛИЗАЦИЯ ХЭШ-ФУНКЦИИ
// -------------------------------------------------------------

// Мы вторгаемся в пространство имен std, чтобы научить C++ вычислять
// хэш для нашей структуры GridLocation. Это ОБЯЗАТЕЛЬНО для использования
// GridLocation в качестве ключа в unordered_map или элемента в unordered_set.
namespace std
{
    template <> struct hash<GridLocation>
    {
        size_t operator() (const GridLocation& id) const noexcept
        {
            // Простейшая хэш-функция для двух int.
            // Сдвигаем биты Y влево на 16 (как бы кладем в старшие биты)
            // и делаем XOR с X. Это упаковывает два числа в одно уникальное (почти).
            // Работает хорошо, пока координаты влезают в short.
            return hash<int>()(id.x ^ (id.y << 16));
        }
    };
}

// -------------------------------------------------------------
// ЛОГИКА СЕТКИ (КАРТЫ)
// -------------------------------------------------------------

struct SquareGrid
{
    // Статический массив направлений (смещений):
    // Вправо, Влево, Вверх, Вниз.
    static vector<GridLocation> DIRS;

    int width, height;

    // Множество стен. Используем set для поиска за O(1).
    unordered_set<GridLocation> walls;

    SquareGrid(int width, int height)
    {
        this->height = height;
        this->width = width;
    }

    // Проверка: не вышли ли координаты за пределы карты
    bool InBounds(GridLocation id) const
    {
        return ((0 <= id.x && 0 <= id.y) &&
            (id.x < width && id.y < height));
    }

    // Проверка: не является ли клетка стеной
    bool Passable(GridLocation id) const
    {
        // Если элемент не найден в списке стен, значит пройти можно
        return walls.find(id) == walls.end();
    }

    // Главный метод для алгоритмов поиска. Возвращает список доступных соседних клеток.
    vector<GridLocation> neighbours(GridLocation id) const
    {
        vector<GridLocation> results;

        for (GridLocation dir : DIRS)
        {
            // Вычисляем координаты потенциального соседа
            GridLocation next{ id.x + dir.x, id.y + dir.y };

            // Если сосед внутри карты и не стена — добавляем
            if (InBounds(next) && Passable(next))
            {
                results.push_back(next);
            }
        }

        // ЭСТЕТИЧЕСКИЙ ТРЮК:
        // Если сумма координат четная, мы меняем порядок соседей.
        // Это заставляет алгоритмы (особенно BFS) исследовать карту не "ёлочкой",
        // а более красивыми прямыми линиями (шахматный порядок перебора).
        // На корректность поиска пути это не влияет, только на визуальную форму пути.
        if ((id.x + id.y) % 2 == 0)
        {
            reverse(results.begin(), results.end());
        }

        return results;
    }
};

// Инициализация статического вектора направлений
vector<GridLocation> SquareGrid::DIRS =
{
    GridLocation{1, 0}, GridLocation{-1, 0}, // Восток, Запад
    GridLocation{0, 1}, GridLocation{0, -1}  // Север, Юг
};

// -------------------------------------------------------------
// СЕТКА С ВЕСАМИ (ДЛЯ ДЕЙКСТРЫ И A*)
// -------------------------------------------------------------

struct GridWithWeights : SquareGrid
{
    // Список "лесов" — клеток, по которым идти дороже
    unordered_set<GridLocation> forests;

    GridWithWeights(int w, int h) : SquareGrid(w, h) {}

    // Функция стоимости перемещения из одной клетки в другую
    double cost(GridLocation from, GridLocation to) const
    {
        // Если целевая клетка в лесу — цена 5, иначе — 1.
        return forests.find(to) != forests.end() ? 5 : 1;
    }
};

// -------------------------------------------------------------
// ОБЕРТКА НАД ПРИОРИТЕТНОЙ ОЧЕРЕДЬЮ
// -------------------------------------------------------------

// T - тип элемента (GridLocation)
// priority_t - тип приоритета (double, int и т.д.)
template<typename T, typename priority_t>
struct PriorityQueue
{
    // Элемент очереди — это пара: (Приоритет, Значение).
    // В C++ пары сравниваются сначала по первому элементу.
    typedef pair<priority_t, T> PQElement;

    // std::priority_queue по умолчанию — Max-Heap (наверху самое большое число).
    // Нам нужен Min-Heap (наверху самая маленькая стоимость пути).
    // Для этого используем компаратор std::greater.
    priority_queue<PQElement, vector<PQElement>, greater<PQElement>> elements;

    inline bool empty() const
    {
        return elements.empty();
    }

    // Кладем элемент: сначала приоритет (для сортировки), потом сам объект
    inline void put(T item, priority_t priority)
    {
        elements.emplace(priority, item);
    }

    // Достаем лучший элемент
    T get()
    {
        T best_item = elements.top().second; // Берем значение (второй элемент пары)
        elements.pop();                      // Удаляем из очереди
        return best_item;
    }
};

// -------------------------------------------------------------
// ВОССТАНОВЛЕНИЕ ПУТИ
// -------------------------------------------------------------

template<typename Location>
vector<Location> reconstruct_path(Location start, Location goal, unordered_map<Location, Location> came_from)
{
    vector<Location> path;
    Location current = goal;

    // Если мы не дошли до цели (ее нет в карте посещенных), возвращаем пустой путь
    if (came_from.find(goal) == came_from.end())
    {
        return path; 
    }

    // Идем от Финиша к Старту по ссылкам "откуда пришел"
    while (current != start)
    {
        path.push_back(current);
        current = came_from[current];
    }

    path.push_back(start); // Не забываем добавить саму точку старта
    reverse(path.begin(), path.end()); // Переворачиваем, чтобы путь шел от Старта к Финишу

    return path;
}

// -------------------------------------------------------------
// ОТРИСОВКА (ВИЗУАЛИЗАЦИЯ)
// -------------------------------------------------------------

// Сложная функция для красивого вывода в консоль.
// Использует указатели, чтобы можно было передавать nullptr для опциональных данных.
template<class Graph>
void draw_grid(const Graph& graph,
    std::unordered_map<GridLocation, double>* distances = nullptr,    // карта стоимостей
    std::unordered_map<GridLocation, GridLocation>* point_to = nullptr, // карта родителей (стрелочки)
    std::vector<GridLocation>* path = nullptr,                        // итоговый путь
    GridLocation* start = nullptr,
    GridLocation* goal = nullptr)
{
    const int field_width = 3;
    cout << string(field_width * graph.width, '_') << '\n';
    
    for (int y = 0; y != graph.height; ++y) {
        for (int x = 0; x != graph.width; ++x) {
            GridLocation id{ x, y };

            // 1. Рисуем стены
            if (graph.walls.find(id) != graph.walls.end()) {
                cout << "\033[43;47m" << string(field_width, '#') << "\033[0m"; // ANSI escape codes для цвета
            }
            // 2. Рисуем Старт
            else if (start && id == *start) {
                cout << "\033[43;34m A \033[0m";
            }
            // 3. Рисуем Финиш
            else if (goal && id == *goal) {
                cout << "\033[43;34m X \033[0m";
            }
            // 4. Рисуем Путь (если передан)
            else if (path != nullptr && find(path->begin(), path->end(), id) != path->end()) {
                cout << " @ ";
            }
            // 5. Рисуем Лес с весами (если включено отображение дистанций)
            else if (graph.forests.find(id) != graph.forests.end() && 
                distances != nullptr && distances->count(id)) {
                cout << "\033[42;37m" << ' ' << left << setw(field_width - 1) << (*distances)[id] << "\033[0m";
            }
            // 6. Рисуем стрелочки (откуда пришли)
            else if (point_to != nullptr && point_to->count(id)) {
                GridLocation next = (*point_to)[id];
                if (next.x == x + 1) { cout << "\033[44;104m > \033[0m"; }
                else if (next.x == x - 1) { cout << "\033[44;104m < \033[0m"; }
                else if (next.y == y + 1) { cout << "\033[44;104m v \033[0m"; }
                else if (next.y == y - 1) { cout << "\033[44;104m ^ \033[0m"; }
                else { cout << " * "; }
            }
            // 7. Рисуем просто веса
            else if (distances != nullptr && distances->count(id)) {
                cout << ' ' << left << setw(field_width - 1) << (*distances)[id];
            }
            // 8. Пустое место
            else {
                cout << " . ";
            }
        }
        cout << '\n';
    }
    std::cout << std::string(field_width * graph.width, '~') << '\n';
}

// Хелпер для создания стен прямоугольниками
void add_rect(SquareGrid& grid, int x1, int y1, int x2, int y2) {
    for (int x = x1; x < x2; ++x) {
        for (int y = y1; y < y2; ++y) {
            grid.walls.insert(GridLocation{ x, y });
        }
    }
}

// Создание карт (с лесами и без)
SquareGrid make_diagram_weightless() {
    SquareGrid grid(30, 15);
    add_rect(grid, 5, 5, 7, 15);
    add_rect(grid, 7, 5, 9, 6);
    add_rect(grid, 9, 5, 11, 15);
    add_rect(grid, 15, 6, 17, 7);
    add_rect(grid, 17, 5, 20, 10);
    return grid;
}

GridWithWeights make_diagram_weights() {
    GridWithWeights grid(30, 20);
    add_rect(grid, 5, 5, 7, 15);
    add_rect(grid, 7, 5, 9, 6);
    add_rect(grid, 9, 5, 11, 15);
    add_rect(grid, 15, 6, 17, 7);
    add_rect(grid, 17, 5, 20, 10);

    typedef GridLocation L;
    // Добавляем труднопроходимые участки
    grid.forests = unordered_set<GridLocation>{ L{ 13, 2 }, L{13, 3}, L{12, 2},
        L{12, 3}, L{12, 4}, L{11, 1}, L{12, 1}, L{11, 0}, L{11, 3} };

    return grid;
}

// -------------------------------------------------------------
// АЛГОРИТМ BFS (ПОИСК В ШИРИНУ)
// -------------------------------------------------------------

template<typename Graph, typename Location>
unordered_map<Location, Location> bfs(Graph graph, Location start, Location goal)
{
    // Обычная очередь FIFO. Гарантирует кратчайший путь в НЕВЗВЕШЕННОМ графе.
    queue<Location> frontier;
    frontier.push(start);

    // came_from играет две роли:
    // 1. Хранит путь (Child -> Parent)
    // 2. Служит списком посещенных (visited), чтобы не ходить кругами
    unordered_map<Location, Location> came_from;
    came_from[start] = start; // Родитель старта - сам старт (маркер конца)

    while (!frontier.empty())
    {
        Location current = frontier.front();
        frontier.pop();

        // Ранний выход: если нашли цель, дальше искать нет смысла
        if (current == goal) { break; }

        for (Location next : graph.neighbours(current))
        {
            // Если мы еще не были в этой клетке (нет ключа в map)
            if (came_from.find(next) == came_from.end())
            {
                frontier.push(next);
                came_from[next] = current; // Запоминаем, что пришли из current
            }
        }
    }
    return came_from;
}

// -------------------------------------------------------------
// АЛГОРИТМ ДЕЙКСТРЫ (DIJKSTRA)
// -------------------------------------------------------------

template <typename Graph, typename Location>
void dijkstra(Graph graph, Location start, Location goal,
    unordered_map<Location, Location>& came_from,
    unordered_map<Location, double>& cost_so_far)
{
    // Очередь с приоритетом (Min-Heap). Сначала извлекает узлы с меньшей стоимостью.
    PriorityQueue<Location, double> frontier;
    frontier.put(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty())
    {
        Location current = frontier.get();

        if (current == goal) { break; }

        for (Location next : graph.neighbours(current))
        {
            // Считаем новую стоимость пути до соседа: 
            // Стоимость до текущей + цена ребра (1 или 5)
            double new_cost = cost_so_far[current] + graph.cost(current, next);

            // Релаксация ребра:
            // Если соседа еще не посещали ИЛИ нашли более дешевый путь к нему
            if (cost_so_far.find(next) == cost_so_far.end() ||
                new_cost < cost_so_far[next])
            {
                cost_so_far[next] = new_cost;   // Обновляем стоимость
                came_from[next] = current;      // Обновляем родителя
                frontier.put(next, new_cost);   // Кладем в очередь с приоритетом (g(x))
            }
        }
    }
}

// -------------------------------------------------------------
// АЛГОРИТМ A* (A-STAR)
// -------------------------------------------------------------

// Эвристика: Манхэттенское расстояние (|dx| + |dy|).
// Показывает минимально возможное расстояние до цели, игнорируя стены.
inline double heuristics(GridLocation a, GridLocation b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

template <typename Graph, typename Location>
void a_star(Graph graph, Location start, Location goal,
    unordered_map<Location, Location>& came_from,
    unordered_map<Location, double>& cost_so_far)
{
    PriorityQueue<Location, double> frontier;
    frontier.put(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty())
    {
        Location current = frontier.get();

        if (current == goal) { break; }

        for (Location next : graph.neighbours(current))
        {
            // g(x) - реальная стоимость пути от старта
            double new_cost = cost_so_far[current] + graph.cost(current, next);

            if (cost_so_far.find(next) == cost_so_far.end() ||
                new_cost < cost_so_far[next])
            {
                cost_so_far[next] = new_cost;
                
                // f(x) = g(x) + h(x)
                // Приоритет = Реальная стоимость + Предполагаемое расстояние до конца.
                // Это заставляет алгоритм "тянуться" к финишу.
                double priority = new_cost + heuristics(next, goal);
                
                frontier.put(next, priority);
                came_from[next] = current;
            }
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");

    // Создаем карту с весами (лесами)
    GridWithWeights grid = make_diagram_weights();
    
    // Старт и цель
    GridLocation start{ 15, 2 };
    GridLocation goal{ 5, 2 };

    // Контейнеры для результатов
    unordered_map<GridLocation, GridLocation> came_from; // Родители
    unordered_map<GridLocation, double> cost_so_far;     // Стоимости

    // Пример запуска BFS (закомментирован, так как он не видит веса лесов)
    // auto parents = bfs(grid, start, goal);
    
    // Пример запуска Дейкстры (находит оптимальный путь, но исследует больше клеток)
    // dijkstra(grid, start, goal, came_from, cost_so_far);

    // Запуск A* (самый быстрый направленный поиск)
    a_star(grid, start, goal, came_from, cost_so_far);

    // 1. Рисуем карту "распространения" алгоритма (стрелочки)
    cout << "Процесс поиска (карта родителей):\n";
    draw_grid(grid, nullptr, &came_from, nullptr, &start, &goal);

    // Восстанавливаем чистый путь
    vector<GridLocation> path = reconstruct_path(start, goal, came_from);

    // 2. Рисуем итоговый путь (@) и стоимости прохода в клетках
    cout << "\nИтоговый путь и стоимости (тепловая карта):\n";
    draw_grid(grid, &cost_so_far, nullptr, &path, &start, &goal);
    
    return 0;
}
