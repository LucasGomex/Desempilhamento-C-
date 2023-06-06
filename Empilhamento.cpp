#include <iostream>
using namespace std;
/* *
* Lucas Gomes dos Santos
*/
struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "A pilha está vazia." << endl;
            return -1;
        } else {
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }

    bool isEmpty() {
        return (top == NULL);
    }
};

int main() {
    const int size = 30;
    LinkedListStack oddStack;
    LinkedListStack evenStack;

    int previousNumber = -30
	;

    cout << "Digite 30 numeros inteiros em ordem crescente:" << endl;
    for (int i = 0; i < size; i++) {
        int number;
        cin >> number;

        if (number <= previousNumber) {
            cout << "O número digitado não é maior do que o anterior. Digite novamente." << endl;
            i--;
            continue;
        }

        if (number % 2 == 0) {
            evenStack.push(number);
        } else {
            oddStack.push(number);
        }

        previousNumber = number;
    }

    cout << "numeros desempilhados em ordem decrescente:" << endl;

    cout << "Impares: ";
    while (!oddStack.isEmpty()) {
        int number = oddStack.pop();
        cout << number << " ";
    }
    cout << endl;

    cout << "Pares: ";
    while (!evenStack.isEmpty()) {
        int number = evenStack.pop();
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
