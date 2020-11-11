// Problem Statement :
// Write a C++ program for storing binary numbers using doubly linked lists. Write functions -
// To compute 1s and 2s complement
// To add two binary numbers

#include <iostream>
using namespace std;

class binaryCell{
    public:
    string bin;
    binaryCell* prev;
    binaryCell* next;

    binaryCell(string number){
        bin = number;
        prev = NULL;
        next = NULL;
    }
};

class binaryRepresentation{
private:
    binaryCell* head;
public:
    binaryRepresentation(){
        head = NULL;
    }
    void addCell(string bin);
    void displayCells();
    string complement1(string bin);
    string complement2(string bin);
    string add(string bin1, string bin2);
};

// Function implementations below main()

int main(){
    int val;
    string binNumber, cont;

    //Doubly Linked List
    binaryRepresentation binary;
    cout << "Doubly Link List Representation---\nEnter count:: ";
    cin >> val;
    for (int i = 0; i < val; i++){
        cout << "\nEnter value:: ";
        cin >> binNumber;
        if (verify(binNumber)) {
            binary.addCell(binNumber);
            cout << "Currently in list --\n";
            binary.displayCells();
        }
    }

    cout << "\n1s complement and 2s complement---\n";
    cout << "Enter \'none\' if you are done\nWaiting for response... ";
    cin >> cont;

    //1s and 2s Complement functions
    if (cont != "none") {
        while(true){
            cout << "\nEnter binary:: ";
            cin >> binNumber;
            if (binNumber == "none")
                break;
            else {
                if(verify(binNumber)) {
                    cout << "1s Complement -- " << binary.complement1(binNumber);
                    cout << "\n2s Complement -- " << binary.complement2(binNumber);
                }
            }
        }
    }

    cout << "\nBinary Addition:---\n";
    cout << "Enter \'none\' if you are done\nWaiting for response... ";
    cin >> cont;

    //Addition
    if (cont != "none"){
        string a, b;
        while (true) {
            cout << "\nEnter two binary numbers: ";
            cin >> a;
            if (a == "none")
                break;
            cin >> b;
            if (b == "none")
                break;
            if (!verify(a) || !verify(b))
                continue;
            cout << "Addition: " << binary.add(a, b) << '\n';
        }
    }
    return 0;
}

void binaryRepresentation::addCell(string bin){
    if (head == NULL){
        head = new binaryCell(bin);
        head -> prev = head;
        head -> next = head;
        return;
    }
    binaryCell* newCell = new binaryCell(bin);
    newCell -> next = head;
    binaryCell* curr = head;
    while(curr -> next != head){
        curr = curr -> next;
    }
    curr -> next = newCell;
    newCell -> prev = curr;
}

void binaryRepresentation::displayCells(){
    if (head == NULL){
        cout<<"Empty List\n";
        return;
    }
    binaryCell* curr = head;
    do{
        cout << curr -> bin <<'\n';
        curr = curr -> next;
    } while (curr != head);
}

string binaryRepresentation::complement1(string bin){
    for (int i=0;i<bin.size();i++){
        if (bin[i] == '0')
            bin[i] = '1';
        else if (bin[i] == '1')
            bin[i] = '0';
    }
    return bin;
}

string binaryRepresentation::complement2(string bin){
    bin = complement1(bin);
    bin = add(bin, "1");
    return bin;
}

string binaryRepresentation::add(string bin1, string bin2){
    string addition = "";
    int sum = 0;
    int i = bin1.size() - 1, j = bin2.size() - 1;
    while (i >= 0 || j >= 0 || sum == 1)
    {
        sum += ((i >= 0)? bin1[i] - '0': 0);
        sum += ((j >= 0)? bin2[j] - '0': 0);
        addition = char(sum % 2 + '0') + addition;

        sum /= 2;
        i--;
        j--;
    }
    return addition;
}

bool verify(string str){
    for (int i = 0; i < str.size(); i++){
        if (str[i] != '1' && str[i] != '0'){
            cout << "Invalid Entry...\n";
            return false;
        }
    }
    return true;
}
