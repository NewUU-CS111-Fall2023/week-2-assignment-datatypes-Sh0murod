/*
 * Author: Shomurod Anvarov
 * Date: 25.10.2023
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

struct Coordinate {
    int x, y;
    bool operator < (const Coordinate& c) const {
        return std::make_pair(x, y) < std::make_pair(c.x, c.y);
    }
};

bool compareDistances(const std::pair<double, Coordinate>& a, const std::pair<double, Coordinate>& b) {
    return a.first < b.first;
}

bool canKillEnemy(const Coordinate& enemy, const Coordinate& current, const Coordinate& next) {
    int ex = enemy.x, ey = enemy.y;
    int cx = current.x, cy = current.y;
    int nx = next.x, ny = next.y;
    return (nx - cx) * (ey - cy) == (ex - cx) * (ny - cy);
}

void findClosestEnemy(std::vector<Coordinate>& enemies, const Coordinate& current, const Coordinate& next) {
    std::vector<std::pair<double, Coordinate>> distances;
    for (const auto& enemy : enemies) {
        double dx = current.x - enemy.x;
        double dy = current.y - enemy.y;
        double dist = std::sqrt(dx * dx + dy * dy);
        distances.push_back(std::make_pair(dist, enemy));
    }
    std::sort(distances.begin(), distances.end(), compareDistances);
    for (const auto& distance : distances) {
        if (canKillEnemy(distance.second, current, next)) {
            std::cout << "character dies at (" << next.x << ", " << next.y << ")\n";
            return;
        }
    }
    std::cout << "character survives at (" << next.x << ", " << next.y << ")\n";
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Coordinate> coordinates(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> coordinates[i].x >> coordinates[i].y;
    }
    std::sort(coordinates.begin(), coordinates.end());
    std::vector<Coordinate> enemies;
    for (int i = 1; i < N; ++i) {
        if (coordinates[i].x == coordinates[i - 1].x && coordinates[i].y == coordinates[i - 1].y) {
            enemies.push_back(coordinates[i]);
        }
    }
    for (int i = 1; i < N; ++i) {
        findClosestEnemy(enemies, coordinates[i - 1], coordinates[i]);
    }
    return 0;
}
