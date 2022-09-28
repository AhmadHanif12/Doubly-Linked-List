#include <iostream>

using namespace std;

class Student
{
public:
    string Student_ID;
    string Student_Name;
    int age;
    double CGPA;

    Student(string id = " ", string Name = " ", int Age = 0, double CGPA = 0)
    {
        Student_ID = id;
        Student_Name = Name;
        age = Age;
        this->CGPA = CGPA;
    }

    Student(Student &temp)
    {
        Student_ID = temp.Student_ID;
        Student_Name = temp.Student_Name;
        age = temp.age;
        CGPA = temp.CGPA;
    }

    void display()
    {
        cout << "ID of the Student:              " << Student_ID << endl;
        cout << "Name of the Student:            " << Student_Name << endl;
        cout << "Age of the Student:             " << age << endl;
        cout << "CGPA of the student:            " << CGPA << endl;
    }
};

class node
{
public:
    Student value;
    node *next;
    node *previous;

    node()
    {
        next = NULL;
        previous = NULL;
    }
    node(const Student &temp)
    {
        value = temp;
    }
};

class Queue
{
private:
    node *front;
    node *rear;

public:
    Queue()
    {
        rear = NULL;
        front = NULL;
    }

    bool isEmpty()
    {
        if (!rear && !front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Enqueue(const Student &std)
    {
        if (isEmpty())
        {
            front = new node;
            front->value = std;
            rear = front;
            return true;
        }
        else
        {
            node *temp = new node(std);
            node *temp2 = rear;
            rear->next = temp;
            temp->previous = rear;
            rear = temp;
            rear->next = NULL;
            rear->previous = temp2;
            return true;
        }
    }

    int Dequeue(string id)
    {
        if (isEmpty())
        {
            cout << "No Record Found !" << endl;
            return 0;
        }

        node *current;
        current = front;

        node *temp = new node;
        while (current)
        {
            if (current->value.Student_ID == id)
            {
                if (current->previous == NULL)
                {
                    temp = front->next;
                    front->next->previous=temp;
                    front = temp;
                    front->previous = NULL;

                    delete current;
                    return 1;
                }
                else if (current->next == NULL)
                {
                    rear = current->previous;
                    rear->next = NULL;
                    return 1;
                }
                else
                {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    delete current;
                    return 1;
                }
            }

            current = current->next;
        }
        cout << "\nRecord not found!\n";
        return 0;
    }

    void display()
    {

        node *current = front;

        while (current)
        {
            current->value.display();
            cout << "---------------------------------------------------\n";
            current = current->next;
        }
    }

    void UpdateSalary(const int &Age, string id)
    {
        node *current = front;

        while (current)
        {
            if (current->value.Student_ID == id)
            {
                current->value.age = Age;
            }
            current = current->next;
        }
    }
    void UpdateGPA(const double &cGPA, string id)
    {
        node *current = front;

        while (current)
        {
            if (current->value.Student_ID == id)
            {
                current->value.CGPA = cGPA;
            }
            current = current->next;
        }
    }

    void clear()
    {
        Student decoy;
        node *current = new node;
        current = front;

        while (current)
        {
            current->value = decoy;
            current = current->next;
        }
    }

    void sort()
    {
        node *current = front;

        bool flag = false;
        while (current->next)
        {

            if (current->value.CGPA > current->next->value.CGPA)
            {
                flag = true;
                Enqueue(current->value);
                Dequeue(current->value.Student_ID);
                
            }
            else
            {
                flag = false;
            }

            if (flag)
            {
                current = front;
            }
            else
            current = current->next;
        }
    }

    void displayage()
    {
        cout << endl
             << rear->value.CGPA << endl;
    }
};

int main()
{
    Student emp1("21i-1551", "Khagga", 20, 3.9);
    Student emp2("21i-1552", "Arain", 24, 3.1);
    Student emp3("21i-1553", "Jutt", 18, 3.4);
    Student emp4("21i-1554", "Pathaan", 29, 2.3);
    Student emp5("21i-1555", "Pathaan", 29, 1.3);
    Student emp6("21i-1556", "Pathaan", 29, 4.3);
    Student emp7("21i-1557", "Pathaan", 29, 0.3);
    Student emp8("21i-1558", "Pathaan", 29, 0.1);
    Queue l1;
    l1.Enqueue(emp1);
    l1.Enqueue(emp2);
    l1.Enqueue(emp3);
    l1.Enqueue(emp4);
    l1.Enqueue(emp5);
    l1.Enqueue(emp6);
    l1.Enqueue(emp7);
    l1.Enqueue(emp8);
    l1.display();

    l1.displayage();
    cout << endl
         << endl;
    cout << "\nAfter Deleting id 21i-1551 node: \n\n";

    l1.Dequeue("21i-1551");

    l1.display();

    cout<<"After Sorting!\n\n";
  l1.sort();
    l1.display();
}
