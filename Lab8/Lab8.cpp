#include <iostream>
#include <string>

using namespace std;

class Resistor {
private:
    string type;
    double denomination;
    double power;
    double accuracy;

public:
    string getType() { return type; }
    double getDenomination() { return denomination; }
    double getPower() { return power; }
    double getAccuracy() { return accuracy; }

    Resistor operator= (Resistor op) {
        this->type = op.type;
        this->denomination = op.denomination;
        this->power = op.power;
        this->accuracy = op.accuracy;
        return op;
    }

    Resistor() { denomination = 0; power = 0; accuracy = 0; };
    Resistor(string new_type, double new_denomination, double new_power, double new_accuracy) {
        this->type = new_type;
        this->denomination = new_denomination;
        this->power = new_power;
        this->accuracy = new_accuracy;
    }
};

struct node {
    Resistor info;
    struct node* p;
    struct node* n;
};

class CircularDoublyList {
private:
    node* start;
    node* end;
public:
    void addResitor(Resistor value) {
        node* temp = new node;
        temp->info = value;
        if (this->start == NULL) {
            this->start = temp;
            this->end = temp;
            temp->n = temp;
            temp->p = temp;
        }
        else {
            this->end->n = temp;
            temp->n = this->start;
            this->start->p = temp;
            this->end = temp;
        }
    }

    void deleteResistor() {
        int count = 0;
        int pos, i;
        node* ptr;
        node* s;
        if (start == end && start == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        cout << endl << "Enter the position of element to be deleted: ";
        cin >> pos;
        if (count < pos) {
            cout << "Position out of range" << endl;
            return;
        }
        s = start;
        if (pos == 1) {
            count--;
            end->n = s->n;
            s->n->p = end;
            start = s->n;
            free(s);
            cout << "Element Deleted" << endl;
            return;
        }
        for (i = 0; i < pos - 1; i++) {
            s = s->n;
            ptr = s->p;
        }
        ptr->n = s->n;
        s->n->p = ptr;
        if (pos == count) {
            end = ptr;
        }
        count--;
        free(s);
        cout << "Element Deleted" << endl;
    }

    void swapCells(node* cell1, node* cell2) {
        node* temp = new node;
        temp->info = cell1->info;
        cell1->info = cell2->info;
        cell2->info = temp->info;
    }

    void sortResistors() {
        bool isSorted = false;
        node* temp = this->start;
        while (!isSorted) {
            isSorted = true;
            temp = start;
            while (temp != this->end) {
                if (temp->n->info.getDenomination() < temp->info.getDenomination()) {
                    isSorted = false;
                    swapCells(temp->n, temp);
                }
                temp = temp->n;
            }
        }
    }

    void outputResistors(double minAccuracy) {
        cout << "Resistors with accuracy " << minAccuracy << "% or higher:";
        for (node* temp = start; temp = temp->n;) {
            if (temp->info.getAccuracy() >= minAccuracy) {
                cout << "\nResistor:\nType: " << temp->info.getType() 
                     << "\nDenomination: " << temp->info.getDenomination() 
                     << "\nPower: " << temp->info.getPower() 
                     << "\nAccuracy: " << temp->info.getAccuracy() << "%\n";
            }
            if (temp == this->end) {
                break;
            }
        }
    }

    CircularDoublyList() {  start = NULL; end = NULL;  }
    ~CircularDoublyList() {};
};

int main()
{
    Resistor r1("OMLT", 25, 220, 100);
    Resistor r2("PGJH", 64, 153, 20);
    Resistor r3("AHGS", 33, 125, 35);
    Resistor r4("YSGD", 65, 256, 75);
    Resistor r5("IHDY", 85, 210, 80);
    Resistor r6("UGKS", 100, 115, 10);
    Resistor r7("SMBS", 55, 105, 50);
    Resistor r8("SSGB", 153, 22, 5);

    CircularDoublyList list;
    list.addResitor(r1);
    list.addResitor(r2);
    list.addResitor(r3);
    list.addResitor(r4);
    list.addResitor(r5);
    list.addResitor(r6);
    list.addResitor(r7);
    list.addResitor(r8);
    list.deleteResistor();

    list.outputResistors(25);
}
