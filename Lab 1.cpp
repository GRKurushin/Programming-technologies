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
    if (head == nullptr) {
        cout << "THE LIST IS EMPTY" << endl;
        return;
    }
    Menu* tmp = head;
    while (tmp->next != nullptr) {
        cout << tmp->id << " | " << tmp->name << ", " << tmp->price << " rub, " << tmp->weight << " gr" << endl;
        tmp = tmp->next;
    }
    cout << tmp->id << " | " << tmp->name << ", " << tmp->price << " rub, " << tmp->weight << " gr" << endl << endl;
}

void addToStart(Menu*& head, int id, const string& name, float price, float weight) {
    Menu* tmp = new Menu;

    tmp->id = id;
    tmp->name = name;
    tmp->price = price;
    tmp->weight = weight;

    tmp->next = head;
    head = tmp;
}

void addToEnd(Menu*& head, int id, const string& name, float price, float weight) {
    if (head == nullptr) {
        addToStart(head, id, name, price, weight);
        return ;
    }
    Menu* tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new Menu;
    tmp->next->id = id;
    tmp->next->name = name;
    tmp->next->price = price;
    tmp->next->weight = weight;
    tmp->next->next = nullptr;
}

void addAfterElement(Menu*& head, int idx, int id, const string& name, float price, float weight) {
    if (head == nullptr) {
        cout << "NO ELEMENTS IN STRUCT " << endl;
        return ;
    }
    Menu* tmp = head;
    while (tmp->next != nullptr) {
        if (tmp->id == idx) {
            Menu* newNode = new Menu;
            newNode->id = id;
            newNode->name = name;
            newNode->price = price;
            newNode->weight = weight;
            newNode->next = tmp->next;
            tmp->next = newNode;
            return;
        }
        tmp = tmp->next;
    }
    cout << "NO ELEMENT WITH ID " << idx << " WERE FOUND" << endl;
}

void remove(Menu*& head, int id) {
    if (head == nullptr) { return; }
    Menu* tmp = head;
    if (tmp->id == id) {
        head = head->next;
        delete tmp;
        return;
    }
    else {
        while (tmp->next != nullptr) {
            if (tmp->next->id == id) {
                Menu* tmp_to_remove = tmp->next;
                tmp->next = tmp->next->next;
                delete tmp_to_remove;
                return;
            }
            tmp = tmp->next;
        }
    }
}

void find(Menu* head, int id) {
    Menu* tmp = head;
    while (tmp != nullptr) {
        if (tmp->id == id) {
            cout << tmp->id << " | " << tmp->name << ", " << tmp->price << " rub, " << tmp->weight << " gr" << endl;
            return ;
        }
        tmp = tmp->next;
    }
    cout << "NO ELEMENT FOUND WITH ID: " << id << endl;
}

int main() {
    // ДЗ Добавление в конец списка и добавление после заданного элемента
    Menu* head = nullptr;
    addToEnd(head, 14, "LOL", 99.99, 100.0);
    addToStart(head, 1, "Burger", 349.99, 250.0);
    addToStart(head, 2, "Chicken nuggets", 149.99, 150.0);
    addToStart(head, 3, "Fries", 99.99, 100.0);
    addToEnd(head, 0, "LOL", 99.99, 100.0);
    addToEnd(head, -1, "LOL", 99.99, 100.0);
    addToStart(head, 16, "Fries", 99.99, 100.0);
    addToStart(head, 21, "Fries", 99.99, 100.0);
    display(head);
    cout << endl;
    addAfterElement(head, 2, 1000, "AOISHJDNOIAHS", 99.99, 100.0);
    display(head);
    remove(head, 3);
    find(head, 4);
    display(head);
    return 0;
}