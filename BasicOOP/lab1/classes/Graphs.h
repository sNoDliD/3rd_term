#ifndef LAB1_GRAPHS_H
#define LAB1_GRAPHS_H

#include <iostream>
#include <limits>
#include <vector>
#include <set>

/*
 * (****) Графи, дерева. Додавання та видалення елементів/вершин/ребер. Побудова кістякового дерева для заданого графу.
+* за побудову мінімального кістякового дерева;
*/
template<typename T>
class Graph {
private:
    std::vector<std::vector<bool>> matrix;
    std::vector<std::vector<T>> weights;
    int n = 0;

public:
    explicit Graph(int n) : n{n} {
        matrix.resize(n);
        weights.resize(n);
        for (std::size_t i = 0; i < n; i++) {
            matrix[i].resize(n);
            weights[i].resize(n);
        }
    }

    Graph(const Graph &cop) {
        *this = cop;
    }

    void PushEdge(int i, int j, T value) {
        if (!matrix[i][j]) {
            matrix[i][j] = true;
            weights[i][j] = value;
        }
    }

    void Print(std::ostream &out = std::cout) const {
        out << "n = " << n;

        out << "E={\n";
        for (std::size_t i = 0; i < n; i++)
            for (std::size_t j = i; j < n; j++) {
                if (matrix[i][j]) {
                    out << "(" << i << "," << j << ") -> " << weights[i][j] << '\n';
                }
            }
        out << " }" << std::endl;
    }

    bool Connectivity() const {
        int res = 0;
        std::vector<bool> is_passed(n);
        DSGraph(*this, 0, is_passed, res);
        return res == n;
    }

    friend void ToTree_(const Graph &inp, Graph &outp, int cur, std::vector<bool> isin, int &count) {
        isin[cur] = true;
        count++;
        for (size_t j = 0; j < inp.n; j++) {
            if (!isin[j] && inp.matrix[cur][j] > 0) {
                outp.PushEdge(cur, j);
                outp.weights[cur][j] = inp.weights[cur][j];
                ToTree_(inp, outp, j, isin, count);
            }
        }

    }

    Graph ToTree() const {
        Graph res(n);
        std::vector<bool> isin(n, false);
        int count = 0;
        ToTree_(*this, res, 0, isin, count);
        return res;
    }

    Graph MinTree() const {
        Graph res(n);
        std::set<int> V;
        std::set<int> U = {0};
        for (size_t i = 1; i < n; i++)
            V.insert(i);

        while (!V.empty()) {
            int min_i{0}, min_j{0};
            double min_w = std::numeric_limits<double>::max();
            for (int i : U)
                for (int j : V) {
                    if (matrix[i][j] && min_w > weights[i][j]) {
                        min_w = weights[i][j];
                        min_i = i;
                        min_j = j;
                    }
                }
            res.PushEdge(min_i, min_j);
            res.SetWeight(min_i, min_j, weights[min_i][min_j]);
            U.insert(min_j);
            V.erase(min_j);
        }
        return res;
    }


    friend void DSGraph(const Graph &arg, int i, bool *is_passed, int &res) {
        is_passed[i] = true;
        res++;
        for (size_t j = 0; j < arg.n; j++) {
            if (!is_passed[j] && arg.matrix[i][j] > 0)
                DSGraph(arg, j, is_passed, res);
        }
    }
};

#endif //LAB1_GRAPHS_H
