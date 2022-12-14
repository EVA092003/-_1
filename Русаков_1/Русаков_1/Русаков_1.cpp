#include <iostream>
#include <stack>
#include <queue>
#include "QueuePtr1head.h"
#include "Adapter4queuePtr1head.h"
#include <windows.h>
using namespace std;

void mergeSort4queuePtr1head(Adapter4queuePtr1head* a, int l, int r)
{
    //cout << endl; a->Display();
    if (l == r) return; // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    mergeSort4queuePtr1head(a, l, mid);
    mergeSort4queuePtr1head(a, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    //int* tmp = (int*)malloc(r * sizeof(int)); // дополнительный массив
    Adapter4queuePtr1head* tmp = new Adapter4queuePtr1head();
    for (int i = 0; i < r + 1; i++)
        tmp->push(-1);

    for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        //if ((j > r) || ((i <= mid) && (a[i] < a[j])))
        if ((j > r) || ((i <= mid) && (a->getElement(i) < a->getElement(j))))
        {
            //tmp[step] = a[i];
            tmp->setElement(step, a->getElement(i));
            i++;
        }
        else
        {
            //tmp[step] = a[j];
            tmp->setElement(step, a->getElement(j));
            j++;
        }
    }
    // переписываем сформированную последовательность в исходный массив
    //tmp->Display();
    for (int step = 0; step < r - l + 1; step++)
        //a[l + step] = tmp[step];
        a->setElement(l + step, tmp->getElement(step));
}

void  example_mergeSort4queuePtr1head() {
    Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
    q1->push(6);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    q1->push(6);
    int size = q1->size();
    cout << "Размер очереди:: " << size << endl;
    cout << endl; q1->Display();
    mergeSort4queuePtr1head(q1, 0, size - 1);
    cout << endl << "Отсортированный: " << endl;
    q1->Display();

}

void insertionSort_adapter4queuePtr(Adapter4queuePtr1head* arrayPtr, int length) // сортировка вставками
{
    int temp, // временная переменная для хранения значения элемента сортируемого массива
        item; // индекс предыдущего элемента
    for (int counter = 1; counter < length; counter++)
    {
        //temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
        temp = arrayPtr->getElement(counter);
        item = counter - 1; // запоминаем индекс предыдущего элемента массива
        while (item >= 0 && arrayPtr->getElement(item) > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
        //while (item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
        {
            //arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
            arrayPtr->setElement(item + 1, arrayPtr->getElement(item));
            //arrayPtr[item] = temp;
            arrayPtr->setElement(item, temp);
            item--;
        }
    }
}


void example_insertionSort_adapter4queuePtr() {
    Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
    q1->push(6);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    q1->push(6);
    int size = q1->size();
    cout << "Размер очереди: " << size << endl;
    cout << endl; q1->Display();
    insertionSort_adapter4queuePtr(q1, size);
    cout << endl << "Отсортированный: " << endl;
    q1->Display();

}
void example_work_QueuePtr1head() {
    QueuePtr1head* q1 = new QueuePtr1head();
    q1->push(1000);
    q1->push(2000);
    q1->push(3000);
    q1->push(4000);
    q1->push(5000);
    q1->push(6000);
    q1->push(7000);
    int size = q1->size();
    cout << "Размер очереди: " << size << endl;
    cout << "front: " << q1->front() << endl;
    q1->pop();
    cout << endl; q1->Display();
    q1->pop();
    cout << endl; q1->Display();
    q1->pop();
    q1->push(999);
    cout << "front: " << q1->front() << endl;
    cout << endl; q1->Display();
    cout << endl; q1->Display();
    cout << endl; q1->Display();
    size = q1->size();
    cout << endl << "Размер очереди: " << size << endl;
}
void example_work_adapter4queuePtr1head() {
    Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    int size = q1->size();
    cout << "Размер очереди: " << size << endl;
    cout << endl; q1->Display();
    q1->setElement(2, 5000);
    int element = q1->getElement(2);
    cout << endl << element;
    cout << endl; q1->Display();
    element = q1->getElement(2);
    cout << endl << element;
    element = q1->getElement(2);
    cout << endl << element;
    cout << endl; q1->Display();

}
void example_work_quickSort() {
    Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
    for (int n = 10; n <= 100; n += 5)
    {
        //int n = 300;
        for (int i = 0; i < n; i++)
            q1->push(rand());
        int size = q1->size();
        //cout << "Size of queue: " << size << endl;
        //cout << endl; q1->display();
        const clock_t begin_time = clock();
        // do something
        mergeSort4queuePtr1head(q1, 0, size - 1);
        //cout << endl; q1->display();
        //cout << endl << " n = " << n << " time (ms): ";
        cout << endl;
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
            q1->pop();
    }
};
void example_work_queueMas(int* _nop) {
    QueueMas* q1 = new QueueMas();
    q1->setNOP(_nop);
    q1->push(10);
    q1->push(20);
    q1->push(30);
    q1->push(40);
    q1->push(50);

    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->display();
    cout << endl; q1->display();
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << q1->front() << " ";
        q1->pop();
    }
    cout << endl; q1->display();
    //q1->push(100);
    cout << endl; q1->display();
    q1->pop();
    size = q1->size();

    //cout << endl << "Size of queue: " << size << endl;
    cout << endl << *q1->getNOP() << endl;
}

void example_work_adapter4queueMas(int* _nop) {
    adapter4queueMas* q1 = new adapter4queueMas();
    q1->setNOP(_nop);
    q1->push(1000);
    q1->push(2000);
    q1->push(3000);
    q1->push(4000);
    q1->push(5000);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->display();
    q1->setElement(3, 9999);
    int element = q1->getElement(3);
    cout << endl << element;
    cout << endl; q1->display();
    cout << endl; q1->display();
    cout << endl << *q1->getNOP() << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    // var 43
    //Указатели	Очередь с 1 головой	Естественное двухпутевое слияние
    //example_work_QueuePtr1head();
    //example_work_adapter4queuePtr1head();
    //example_work_quickSort();
    int* nop = new int;
    *nop = 0;
    example_work_quickSortQueueMas(nop);
}