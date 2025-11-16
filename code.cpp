#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int start;
    int end;
};

int main() {
    // Изначальный набор задач (интервалы)
    vector<Task> tasks = {
        {1, 3}, {2, 5}, {4, 6},
        {5, 8}, {7, 9}, {8, 10}
    };

    // Сортировка по времени окончания.
    // Это нужно, чтобы первым брать тот интервал, который заканчивается раньше,
    // так вероятность вместить больше задач выше.
    sort(tasks.begin(), tasks.end(),
         [](const Task &a, const Task &b) {
             return a.end < b.end;
         });

    vector<Task> selected;

    // Здесь будет храниться окончание последней выбранной задачи.
    // Начальное значение ставлю -1, чтобы первая задача точно подошла.
    int lastEnd = -1;

    // Проходим по отсортированным задачам и проверяем пересечения.
    for (const auto &t : tasks) {
        // Если начало текущей задачи не раньше, чем конец предыдущей,
        // значит, пересечения нет, и можно взять её.
        if (t.start >= lastEnd) {
            selected.push_back(t);
            lastEnd = t.end;  // обновляем конец последней выбранной
        }
    }

    // Вывод результата
    cout << "Выбранные задачи:\n";
    for (const auto &t : selected) {
        cout << "(" << t.start << ", " << t.end << ")\n";
    }

    cout << "Количество: " << selected.size() << endl;

    return 0;
}
