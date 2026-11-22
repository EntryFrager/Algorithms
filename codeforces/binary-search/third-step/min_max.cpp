#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    long long to;
    long long cost;
};

bool check_way(int n, int d, vector<vector<Edge>>& graph, long long m, vector<int>& way) {
    vector<int> dist(n, 1e9);
    fill(way.begin(), way.end(), -1);
    dist[0] = 0;

    for (int i = 0; i < n; ++i) {
        if (dist[i] >= d)
            continue;
        for (const auto& e : graph[i]) {
            if (e.cost <= m && (dist[i] + 1) < dist[e.to]) {
                dist[e.to] = dist[i] + 1;
                way[e.to] = i;
            }
        }
    }

    return dist[n - 1] <= d;
}

long long find_min_way(int n, int d, vector<vector<Edge>>& graph, long long max_cost, vector<int>& way) {
    if (!check_way(n, d, graph, max_cost, way))
        return -1;

    long long l = -1;
    long long r = max_cost;
    long long m = 0;

    while ((l + 1) < r) {
        m = (r + l) / 2;

        if (check_way(n, d, graph, m, way)) {
            r = m;
        } else {
            l = m;
        }
    }

    check_way(n, d, graph, r, way);
    return r;
}

#ifndef LOCAL_TESTS

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    long long a, b, c;
    long long max_cost = 0;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        max_cost = max(max_cost, c);
    }

    vector<int> way(n, -1);
    long long ans = find_min_way(n, d, graph, max_cost, way);

    if (ans == -1) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    for (int cur = n - 1; cur != -1; cur = way[cur]) {
        path.push_back(cur + 1);
    }
    reverse(path.begin(), path.end());

    cout << path.size() - 1 << "\n";
    for (int v : path) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}

#else

#include <gtest/gtest.h>

TEST(FindMinWayTest, FirstTest) {
    int n = 4, d = 2;
    vector<vector<Edge>> graph(n);
    vector<tuple<int, int, long long>> edges = {
        {1, 2, 5},
        {2, 3, 3},
        {1, 3, 7},
        {2, 4, 6},
        {3, 4, 4}
    };
    long long max_cost = 0;
    for (auto [u, v, c] : edges) {
        graph[u - 1].push_back({v - 1, c});
        max_cost = max(max_cost, c);
    }

    vector<int> way(n, -1);
    long long ans = find_min_way(n, d, graph, max_cost, way);
    ASSERT_NE(ans, -1);

    vector<int> path;
    for (int cur = n - 1; cur != -1; cur = way[cur]) {
        path.push_back(cur + 1);
    }
    reverse(path.begin(), path.end());

    EXPECT_EQ(static_cast<int>(path.size()) - 1, 2);
    EXPECT_EQ(path, (vector<int>{1, 2, 4}));
}

TEST(FindMinWayTest, SecondTest) {
    int n = 3, d = 2;
    vector<vector<Edge>> graph(n);
    vector<tuple<int, int, long long>> edges = {
        {1, 2, 1},
        {2, 3, 2},
        {1, 3, 1}
    };
    long long max_cost = 0;
    for (auto [u, v, c] : edges) {
        graph[u - 1].push_back({v - 1, c});
        max_cost = max(max_cost, c);
    }

    vector<int> way(n, -1);
    long long ans = find_min_way(n, d, graph, max_cost, way);
    ASSERT_NE(ans, -1);

    vector<int> path;
    for (int cur = n - 1; cur != -1; cur = way[cur]) {
        path.push_back(cur + 1);
    }
    reverse(path.begin(), path.end());

    EXPECT_EQ(static_cast<int>(path.size()) - 1, 1);
    EXPECT_EQ(path, (vector<int>{1, 3}));
}

TEST(FindMinWayTest, ThirdTest) {
    int n = 3, d = 1;
    vector<vector<Edge>> graph(n);
    vector<tuple<int, int, long long>> edges = {
        {1, 2, 1},
        {2, 3, 1}
    };
    long long max_cost = 0;
    for (auto [u, v, c] : edges) {
        graph[u - 1].push_back({v - 1, c});
        max_cost = max(max_cost, c);
    }

    vector<int> way(n, -1);
    long long ans = find_min_way(n, d, graph, max_cost, way);
    EXPECT_EQ(ans, -1);
}

#endif