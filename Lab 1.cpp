#include <iostream>
#include <string>

using namespace std;

struct Menu {
    int id;
    string name;
    double price;
    double weight;
    Menu* next;
};

void display(Menu* head) {
    Menu *tmp = head;
    cout << endl;
    while (tmp != NULL) {
        cout << tmp->id << " | " << tmp->name << ", " << tmp->price << " rub, " << tmp->weight << " gr" << endl;
        tmp = tmp->next;
    }
    cout << endl;
}

void add(Menu *&head) {
    Menu *tmp = new Menu;
    cout << "Enter ID:";
    cin >> tmp->id;
    cin.ignore();
    cout << "Enter name:";
    getline(cin, tmp->name);
    cout << "Enter price:";
    cin >> tmp->price;
    cout << "Enter weight:";
    cin >> tmp->weight;
    tmp->next = head;
    head = tmp;
    display(head);
}

void remove(Menu *&head, int id) {
    Menu *tmp = head;
    if (tmp->id == id) {
        head = head->next;
        delete tmp;
    }
    else {
        while (tmp->next != NULL) {
            if (tmp->next->id == id) {
                Menu *tmp_to_remove = tmp->next;
                tmp->next = tmp->next->next;
                delete tmp_to_remove;
                break;
            }
            tmp = tmp->next;
        }
    }
    display(head);
}

int main() {
    Menu *head = NULL;
    add(head);
    add(head);
    add(head);
    remove(head, 1);
    remove(head, 3);
    return 0;
}