#include <iostream>
#include <string>

using namespace std;

struct Menu {
    string name;
    int id;
    double price;
    Menu* next;
};

void display(Menu* head) {
    if (head == nullptr) {
        cout << "THE LIST IS EMPTY" << endl;
        return;
    }
    Menu* tmp = head;
    while (tmp->next != nullptr) {
        cout << tmp->id << " | " << tmp->name << ", " << tmp->price << " rub" << endl;
        tmp = tmp->next;
    }
    cout << tmp->id << " | " << tmp->name << ", " << tmp->price << " rub" << endl << endl;
}

void addToStart(Menu*& head, int id, const string& name, double price) {
    Menu* tmp = new Menu;

    tmp->id = id;
    tmp->name = name;
    tmp->price = price;

    tmp->next = head;
    head = tmp;
}

void addToEnd(Menu*& head, int id, const string& name, double price) {
    if (head == nullptr) {
        addToStart(head, id, name, price);
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
    tmp->next->next = nullptr;
}

void addAfter(Menu*& head, int idx, int id, const string& name, double price) {
    if (head == nullptr) {
        cout << "NO ELEMENTS IN STRUCT" << endl;
        return ;
    }
    Menu* tmp = head;
    while (tmp != nullptr) {
        if (tmp->id == idx) {
            Menu* newNode = new Menu;
            newNode->id = id;
            newNode->name = name;
            newNode->price = price;
            newNode->next = tmp->next;
            tmp->next = newNode;
            return;
        }
        tmp = tmp->next;
        if (tmp == nullptr) { break; }
    }
    cout << "NO ELEMENT WITH ID " << idx << " WERE FOUND" << endl;
}

void addBefore(Menu*& head, int idx, int id, const string& name, double price) {
    if (head == nullptr) {
        cout << "NO ELEMENTS IN STRUCT" << endl;
        return;
    }
    if (head->id == idx) {
        Menu* newNode = new Menu;
        newNode->id = id;
        newNode->name = name;
        newNode->price = price;
        newNode->next = head;
        head = newNode;
        return;
    }
    Menu* tmp = head;
    while (tmp->next != nullptr) {
        if (tmp->next->id == idx) {
            Menu* newNode = new Menu;
            newNode->id = id;
            newNode->name = name;
            newNode->price = price;
            newNode->next = tmp->next;
            tmp->next = newNode;
            return;
        }
        tmp = tmp->next;
    }
    cout << "NO ELEMENT WITH ID " << idx << " WERE FOUND" << endl;
}

void remove(Menu*& head, const string& name) {
    if (head == nullptr) { 
        cout << "NO ELEMENTS IN STRUCT" << endl;
        return; 
    }
    Menu* tmp = head;
    if (tmp->name == name) {
        head = head->next;
        delete tmp;
        return;
    }
    while (tmp->next != nullptr) {
        if (tmp->next->name == name) {
            Menu* tmp_to_remove = tmp->next;
            tmp->next = tmp->next->next;
            delete tmp_to_remove;
            return;
        }
        tmp = tmp->next;
    }
    cout << "NO ELEMENT WITH NAME '" << name << "' WERE FOUND" << endl;
}

int main() {
    Menu* head = nullptr;
    addToStart(head, 1, "Burger", 350.00);
    addAfter(head, 1, 3, "Pasta", 250.00);
    addToEnd(head, 2, "Pizza", 500.00);
    addBefore(head, 1, 4, "Fries", 99.00);
    cout << "Menu after additions:" << endl;
    display(head);
    remove(head, "Pasta");
    cout << "Menu after removal:" << endl;
    display(head);
    return 0;
}