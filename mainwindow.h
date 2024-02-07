#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LinkedList.h"
#include "myVector.h"
#include "date.h"
#include "complex.h"
#include "rational.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*************************
    ******  CONSTRUCTOR ******
    *************************/
    MainWindow(QWidget *parent = nullptr);
    /*************************
    ******  DESTRUCTOR  ******
    *************************/
    ~MainWindow();

private slots:
    ////Button Clicked Methods
    void on_pushBackButton_clicked();
    void on_pushFrontButton_clicked();
    void on_popFrontButton_clicked();
    void on_insertSortedButton_clicked();
    void on_removeDuplicates_clicked();
    void on_selectSortButton_clicked();
    void on_insertAtButton_clicked();
    void on_displayButton_clicked();
    void on_displayPortionButton_clicked();
    void on_newListButton_clicked();
    void on_copyListButton_clicked();
    void on_deleteListButton_clicked();

    ////Radio Clicked Methods
    void on_intRadio_clicked();
    void on_doubleRadio_clicked();
    void on_charRadio_clicked();
    void on_stringRadio_clicked();
    void on_rationalRadio_clicked();
    void on_complexRadio_clicked();
    void on_dateRadio_clicked();

    ////Spin Box Methods
    void on_spinBox_2_valueChanged(int arg1);
    void on_spinBox_3_valueChanged(int arg1);

    ////Combo Box Method
    void on_comboBox_currentIndexChanged(int index);

private:
    /*************************
    *** PRIVATE MEMBERS ******
    *************************/
    Ui::MainWindow *ui;                             //UI pointer
    Vector<LinkedList<int>> intLists;               //Vector of Linked Lists that store ints
    Vector<LinkedList<double>> doubleLists;         //Vector of Linked Lists that store doubles
    Vector<LinkedList<char>> charLists;             //Vector of Linked Lists that store chars
    Vector<LinkedList<string>> stringLists;         //Vector of Linked Lists that store strings
    Vector<LinkedList<Date>> dateLists;             //Vector of Linked Lists that store Dates
    Vector<LinkedList<Rational>> rationalLists;     //Vector of Linked Lists that store Rational numbers
    Vector<LinkedList<Complex>> complexLists;       //Vector of Linked Lists that store Complex numbers
    int index;                                      //The index of the current Vector being operated on

    /*************************
    *** PRIVATE METHODS ******
    *************************/
    void setSpinBox();                              //Initializes or reinitializes all the Spin Boxes
    void setComboBox();                             //Initializes or reinitializes the Combo Box
    void setIndex();                                //Initializes or reinitializes the Index
    void display(const int& num1, const int& num2); //Displays a Linked List from index num1 to index num2
};
#endif // MAINWINDOW_H
