#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GPU {
public:
    string company;
    int seria;

    GPU(string company, int seria) {
        this->company = company;
        this->seria = seria;
    }
};

void BubbleSort(vector<GPU>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].seria < arr[j + 1].seria) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int OLD_SERIES = 3000;

    GPU gpu_1("Nvidia", 4070);
    GPU gpu_2("AMD", 7700);
    GPU gpu_3("Nvidia", 3050);
    GPU gpu_4("Nvidia", 1070);
    GPU gpu_5("AMD", 550);
    GPU gpu_6("AMD", 6600);

    vector<GPU> list;

    list.push_back(gpu_1);
    list.push_back(gpu_2);
    list.push_back(gpu_3);
    list.push_back(gpu_4);
    list.push_back(gpu_5);
    list.push_back(gpu_6);

    vector<GPU> oldlist;

    for (auto it = list.begin(); it != list.end();) {
        if (((it->company == "AMD") && it->seria < OLD_SERIES) || ((it->company == "Nvidia") && it->seria < OLD_SERIES)) {
            oldlist.push_back(*it);
            it = list.erase(it);
        } else {
            ++it;
        }
    }

    BubbleSort(list);
    BubbleSort(oldlist);

    cout << "Список старых моделей видеокарт: " << endl;
    for (auto it = oldlist.begin(); it != oldlist.end(); it++) {
        cout << it->company << " " << it->seria << endl;
    }

    cout << "Список новых моделей видеокарт: " << endl;
    for (auto it = list.begin(); it != list.end(); it++) {
        cout << it->company << " " << it->seria << endl;
    }

    return 0;
}
