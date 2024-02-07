#include "mainwindow.h"
#include "ui_mainwindow.h"

/**********************************************************
* Constructor Mainwindow(QWidget *parent): Class MainWindow
*_________________________________________________________
* Cosntructor to construct the main window.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*     Sets index to 0 and combo box to first integer list
*     Program will start with 1 list from each type.
***********************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    index = 0;
    ui->comboBox->addItem("Integer List 1");
}

/**********************************************************
* Constructor ~Mainwindow(): Class MainWindow
*_________________________________________________________
* Destructor to free the main window.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*     deletes ui
***********************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/**********************************************************
* void display(const int& num1, const int& num2)
*               : Class MainWindow
*_________________________________________________________
* outputs to the text browser the current list
*_________________________________________________________
* PRE-CONDITIONS
*   num1 - index to start displaying at
*   num2 - index to end displaying at
*
* POST-CONDITIONS
*     Outputs the list from num1 to num2
***********************************************************/
void MainWindow::display(const int& num1, //IN - index to start displaying at
                         const int& num2) //IN - index to end displaying at
{
    QString output;
    int count;
    output = "[";
    count = 0;
    if(ui->intRadio->isChecked())
    {
        LinkedList<int>::Iterator it;
        for(it = intLists[index].begin(); it != intLists[index].end(); ++it, count++)
        {
            if(count>= num1 && count <=num2)
            {
                if(count != num1)
                    output += ", ";
                output = output + QString::number(*it);
            }
        }
    }
    else if(ui->doubleRadio->isChecked())
    {
        LinkedList<double>::Iterator it;
        for(it = doubleLists[index].begin(); it != doubleLists[index].end(); ++it, count++)
        {
            if(count>= num1 && count <=num2)
            {
                if(count != num1)
                    output += ", ";
                output = output + QString::number(*it);
            }
        }
    }
    else if(ui->charRadio->isChecked())
    {
        LinkedList<char>::Iterator it;
        for(it = charLists[index].begin(); it != charLists[index].end(); ++it, count++)
        {
            if(count>= num1 && count <=num2)
            {
                if(count != num1)
                    output += ", ";
                output = output + QString(QChar(*it));
            }
        }
    }
    else if(ui->stringRadio->isChecked())
    {
        LinkedList<string>::Iterator it;
        for(it = stringLists[index].begin(); it != stringLists[index].end(); ++it, count++)
        {
            if(count>= num1 && count <=num2)
            {
                if(count > num1)
                    output += ", ";
                output = output + QString::fromStdString(*it);
            }
        }
    }
    else if(ui->rationalRadio->isChecked())
    {
        LinkedList<Rational>::Iterator it;
        for(it = rationalLists[index].begin(); it != rationalLists[index].end(); ++it, count++)
        {
            if(count>= num1 && count <=num2)
            {
                if(count != num1)
                    output += ", ";
                output = output + QString::fromStdString((*it).display());
            }
        }
    }
    else if(ui->dateRadio->isChecked())
    {
        LinkedList<Date>::Iterator it;
        for(it = dateLists[index].begin(); it != dateLists[index].end(); ++it, count++)
        {
            if(count>= num1 && count <=num2)
            {
                if(count != num1)
                    output += ", ";
                output = output + QString::fromStdString((*it).display());
            }
        }
    }
    else if(ui->complexRadio->isChecked())
    {
        LinkedList<Complex>::Iterator it;
        for(it = complexLists[index].begin(); it != complexLists[index].end(); ++it, count++)
        {
            if(count>= num1 && count <=num2)
            {
                if(count != num1)
                    output += ", ";
                output = output + QString::fromStdString((*it).display());
            }
        }
    }
    if(output.size() == 1)
        output += "Empty";
    output += "]";
    ui->textBrowser->setText(output + "\n");
}

/**********************************************************
* void on_pushBackButton_clicked() : Class MainWindow
*_________________________________________________________
* pushes back the line Edit value to the current list
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Adds element to list. If lineEdit is empty, no element
*   is pushed back. Default values may be added if input is
*   invalid
***********************************************************/
void MainWindow::on_pushBackButton_clicked()
{
    QString input;
    input = ui->lineEdit->text();

    if(input == "")
        return;
    if(ui->intRadio->isChecked())
        intLists[index].push_back(input.toInt());
    else if(ui->doubleRadio->isChecked())
        doubleLists[index].push_back(input.toDouble());
    else if(ui->charRadio->isChecked())
        charLists[index].push_back((input.toStdString())[index]);
    else if(ui->stringRadio->isChecked())
        stringLists[index].push_back(input.toStdString());
    else if(ui->rationalRadio->isChecked())
    {
        QStringList list1 = input.split(QLatin1Char('/'));
        if(list1.size()==2)
            rationalLists[index].push_back(Rational(list1[index].toInt(),list1[1].toInt()));
        else
            rationalLists[index].push_back(Rational());
    }
    else if(ui->dateRadio->isChecked())
    {
        QStringList list1 = input.split(QLatin1Char('/'));
        if(list1.size()==3)
            dateLists[index].push_back(Date(list1[index].toInt(),list1[1].toInt(),list1[2].toInt()));
       else
            dateLists[index].push_back(Date());
    }
    else if(ui->complexRadio->isChecked())
    {
        std::string str = input.toStdString();
        complexLists[index].LinkedList::push_back(Complex(str));
    }
    setSpinBox();
}

/**********************************************************
* void on_pushFrontButton_clicked() : Class MainWindow
*_________________________________________________________
* pushes front the line Edit value to the current list
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Adds element to list. If lineEdit is empty, no element
*   is pushed back. Default values may be added if input is
*   invalid
***********************************************************/
void MainWindow::on_pushFrontButton_clicked()
{
    QString input;
    input = ui->lineEdit->text();

    if(input == "")
        return;
    if(ui->intRadio->isChecked())
        intLists[index].push_front(input.toInt());
    else if(ui->doubleRadio->isChecked())
        doubleLists[index].push_front(input.toDouble());
    else if(ui->charRadio->isChecked())
        charLists[index].push_front((input.toStdString())[index]);
    else if(ui->stringRadio->isChecked())
        stringLists[index].push_front(input.toStdString());
    else if(ui->rationalRadio->isChecked())
    {
        QStringList list1 = input.split(QLatin1Char('/'));
        if(list1.size()==2)
            rationalLists[index].push_front(Rational(list1[index].toInt(),list1[1].toInt()));
        else
            rationalLists[index].push_front(Rational());
    }
    else if(ui->dateRadio->isChecked())
    {
        QStringList list1 = input.split(QLatin1Char('/'));
        if(list1.size()==3)
            dateLists[index].push_front(Date(list1[index].toInt(),list1[1].toInt(),list1[2].toInt()));
        else
            dateLists[index].push_front(Date());
    }
    else if(ui->complexRadio->isChecked())
    {
        std::string str = input.toStdString();
        complexLists[index].LinkedList::push_front(Complex(str));
    }
    setSpinBox();
}

/**********************************************************
* void on_displayButton_clicked() : Class MainWindow
*_________________________________________________________
* displays the whole list, starting at 0, ending at last node
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Outputs the list to the screen using display(num1,num2)
***********************************************************/
void MainWindow::on_displayButton_clicked()
{
    if(ui->intRadio->isChecked())
        display(0, intLists[index].length()-1);
    else if(ui->doubleRadio->isChecked())
        display(0, doubleLists[index].length()-1);
    else if(ui->charRadio->isChecked())
        display(0, charLists[index].length()-1);
    else if(ui->stringRadio->isChecked())
        display(0, stringLists[index].length()-1);
    else if(ui->rationalRadio->isChecked())
        display(0, rationalLists[index].length()-1);
    else if(ui->dateRadio->isChecked())
        display(0, dateLists[index].length()-1);
    else if(ui->complexRadio->isChecked())
        display(0, complexLists[index].length()-1);
}

/**********************************************************
* void on_popFrontButton_clicked() : Class MainWindow
*_________________________________________________________
* removes first node in current list
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Removes first element in list. If no elements, nothing
*   is changed.
***********************************************************/
void MainWindow::on_popFrontButton_clicked()
{
    if(ui->intRadio->isChecked())
    {
        try{
            intLists[index].pop_front();
        }catch(...){
            return;
        }
    }
    else if(ui->doubleRadio->isChecked())
    {
        try{
            doubleLists[index].pop_front();
        }catch(...){
            return;
        }
    }
    else if(ui->charRadio->isChecked())
    {
        try{
            charLists[index].pop_front();
        }catch(...) {
            return;
        }
    }
    else if(ui->stringRadio->isChecked())
    {
        try{
            stringLists[index].pop_front();
        }catch(...){
            return;
        }
    }
    else if(ui->rationalRadio->isChecked())
    {
        try{
            rationalLists[index].pop_front();
        }catch(...){
            return;
        }
    }
    else if(ui->dateRadio->isChecked())
    {
        try{
            dateLists[index].pop_front();
        }catch(...){
            return;
        }
    }
    else if(ui->complexRadio->isChecked())
    {
        try{
            complexLists[index].pop_front();
        }catch(...){
            return;
        }
    }
    setSpinBox();
}

/**********************************************************
* void on_insertSortedButton_clicked() : Class MainWindow
*_________________________________________________________
* inserts the lineEdit value into the list in a sorted position
*_________________________________________________________
* PRE-CONDITIONS
*   List is expected to be sorted
*
* POST-CONDITIONS
*   Adds element to list sorted. If lineEdit is empty, no element
*   is pushed back. Default values may be added if input is
*   invalid
***********************************************************/
void MainWindow::on_insertSortedButton_clicked()
{
    QString input;
    input = ui->lineEdit->text();

    if(input == "")
        return;
    if(ui->intRadio->isChecked())
        intLists[index].insert_sorted(input.toInt());
    else if(ui->doubleRadio->isChecked())
        doubleLists[index].insert_sorted(input.toDouble());
    else if(ui->charRadio->isChecked())
        charLists[index].insert_sorted((input.toStdString())[index]);
    else if(ui->stringRadio->isChecked())
        stringLists[index].insert_sorted(input.toStdString());
    else if(ui->rationalRadio->isChecked())
    {
        QStringList list1 = input.split(QLatin1Char('/'));
        if(list1.size()==2)
            rationalLists[index].insert_sorted(Rational(list1[index].toInt(),list1[1].toInt()));
        else
            rationalLists[index].insert_sorted(Rational());

    }
    else if(ui->dateRadio->isChecked())
    {
        QStringList list1 = input.split(QLatin1Char('/'));
        if(list1.size()==3)
            dateLists[index].insert_sorted(Date(list1[index].toInt(),list1[1].toInt(),list1[2].toInt()));
       else
            dateLists[index].insert_sorted(Date());

    }
    else if(ui->complexRadio->isChecked())
    {
        std::string str = input.toStdString();
        complexLists[index].insert_sorted(Complex(str));
    }
    setSpinBox();
}

/**********************************************************
* void on_removeDuplicates_clicked() : Class MainWindow
*_________________________________________________________
* removes all instances of values that appear after the
* initial instance of the value
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   removes none or more nodes depending on if there are
*   duplicates
***********************************************************/
void MainWindow::on_removeDuplicates_clicked()
{
    if(ui->intRadio->isChecked())
        intLists[index].remove_duplicates();
    else if(ui->doubleRadio->isChecked())
        doubleLists[index].remove_duplicates();
    else if(ui->charRadio->isChecked())
        charLists[index].remove_duplicates();
    else if(ui->stringRadio->isChecked())
        stringLists[index].remove_duplicates();
    else if(ui->rationalRadio->isChecked())
        rationalLists[index].remove_duplicates();
    else if(ui->dateRadio->isChecked())
        dateLists[index].remove_duplicates();
    else if(ui->complexRadio->isChecked())
        complexLists[index].remove_duplicates();
    setSpinBox();
}

/**********************************************************
* void on_selectSortButton_clicked() : Class MainWindow
*_________________________________________________________
* Uses selection sort to mutate the current list.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   List is sorted
***********************************************************/
void MainWindow::on_selectSortButton_clicked()
{
    if(ui->intRadio->isChecked())
        intLists[index].select_sort();
    else if(ui->doubleRadio->isChecked())
        doubleLists[index].select_sort();
    else if(ui->charRadio->isChecked())
        charLists[index].select_sort();
    else if(ui->stringRadio->isChecked())
        stringLists[index].select_sort();
    else if(ui->rationalRadio->isChecked())
        rationalLists[index].select_sort();
    else if(ui->dateRadio->isChecked())
        dateLists[index].select_sort();
    else if(ui->complexRadio->isChecked())
        complexLists[index].select_sort();
}

/**********************************************************
* void on_insertAtButton_clicked() : Class MainWindow
*_________________________________________________________
*   Inserts the Line Edit value into the list at a given
*   index. Uses spin box to determine. Error checking built
*   in to the spin Box
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Adds element to list at spin box's value. If lineEdit is empty,
*   no element is pushed back. Default values may be added if input is
*   invalid
***********************************************************/
void MainWindow::on_insertAtButton_clicked()
{
    QString input;
    input = ui->lineEdit->text();

    if(input == "")
        return;
    if(ui->intRadio->isChecked())
        intLists[index].insert_at(input.toInt(), ui->spinBox->value());
    else if(ui->doubleRadio->isChecked())
        doubleLists[index].insert_at(input.toDouble(), ui->spinBox->value());
    else if(ui->charRadio->isChecked())
        charLists[index].insert_at((input.toStdString())[index], ui->spinBox->value());
    else if(ui->stringRadio->isChecked())
        stringLists[index].insert_at(input.toStdString(), ui->spinBox->value());
    else if(ui->rationalRadio->isChecked())
    {
        QStringList list1 = input.split(QLatin1Char('/'));
        if(list1.size()==2)
            rationalLists[index].insert_at(Rational(list1[index].toInt(),list1[1].toInt()), ui->spinBox->value());
        else
            rationalLists[index].insert_at(Rational(), ui->spinBox->value());

    }
    else if(ui->dateRadio->isChecked())
    {
        QStringList list1 = input.split(QLatin1Char('/'));
        if(list1.size()==3)
            dateLists[index].insert_at(Date(list1[index].toInt(),list1[1].toInt(),list1[2].toInt()), ui->spinBox->value());
        else
            dateLists[index].insert_at(Date(), ui->spinBox->value());

    }
    else if(ui->complexRadio->isChecked())
    {
        std::string str = input.toStdString();
        complexLists[index].insert_at(Complex(str), ui->spinBox->value());
    }
    setSpinBox();
}

/**********************************************************
* void setSpinBox() : Class MainWindow
*_________________________________________________________
*   sets all the spinBoxes for the UI. This includes the
*   Insert At Spin Box as well as the To and From Spin Boxes
*   for Display Portion.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Initializes or Reinitializes spin boxes appropriately
***********************************************************/
void MainWindow::setSpinBox()
{
    if(ui->intRadio->isChecked()){
        ui->spinBox->setMaximum(intLists[index].length());
        if(intLists[index].length() != 0){
            ui->spinBox_2->setMaximum(intLists[index].length()-1);
            ui->spinBox_3->setMaximum(intLists[index].length()-1);
            ui->spinBox_3->setValue(intLists[index].length()-1);
        }
        else{
            ui->spinBox_2->setMaximum(0);
            ui->spinBox_3->setMaximum(0);
        }
    }
    else if(ui->doubleRadio->isChecked()){
        ui->spinBox->setMaximum(doubleLists[index].length());
        if(doubleLists[index].length() != 0){
            ui->spinBox_2->setMaximum(doubleLists[index].length()-1);
            ui->spinBox_3->setMaximum(doubleLists[index].length()-1);
            ui->spinBox_3->setValue(doubleLists[index].length()-1);
        }
        else{
            ui->spinBox_2->setMaximum(0);
            ui->spinBox_3->setMaximum(0);
        }
    }
    else if(ui->charRadio->isChecked()){
        ui->spinBox->setMaximum(charLists[index].length());
        if(charLists[index].length() != 0){
            ui->spinBox_2->setMaximum(charLists[index].length()-1);
            ui->spinBox_3->setMaximum(charLists[index].length()-1);
            ui->spinBox_3->setValue(charLists[index].length()-1);
        }
        else{
            ui->spinBox_2->setMaximum(0);
            ui->spinBox_3->setMaximum(0);
        }
    }
    else if(ui->stringRadio->isChecked()){
        ui->spinBox->setMaximum(stringLists[index].length());
        if(stringLists[index].length() != 0){
            ui->spinBox_2->setMaximum(stringLists[index].length()-1);
            ui->spinBox_3->setMaximum(stringLists[index].length()-1);
            ui->spinBox_3->setValue(stringLists[index].length()-1);
        }
        else{
            ui->spinBox_2->setMaximum(0);
            ui->spinBox_3->setMaximum(0);
        }
    }
    else if(ui->rationalRadio->isChecked()){
        ui->spinBox->setMaximum(rationalLists[index].length());
        if(rationalLists[index].length() != 0){
            ui->spinBox_2->setMaximum(rationalLists[index].length()-1);
            ui->spinBox_3->setMaximum(rationalLists[index].length()-1);
            ui->spinBox_3->setValue(rationalLists[index].length()-1);
        }
        else{
            ui->spinBox_2->setMaximum(0);
            ui->spinBox_3->setMaximum(0);
        }
    }
    else if(ui->dateRadio->isChecked()){
        ui->spinBox->setMaximum(dateLists[index].length());
        if(dateLists[index].length() != 0){
            ui->spinBox_2->setMaximum(dateLists[index].length()-1);
            ui->spinBox_3->setMaximum(dateLists[index].length()-1);
            ui->spinBox_3->setValue(dateLists[index].length()-1);
        }
        else{
            ui->spinBox_2->setMaximum(0);
            ui->spinBox_3->setMaximum(0);
        }
    }
    else if(ui->complexRadio->isChecked()){
        ui->spinBox->setMaximum(complexLists[index].length());
        if(complexLists[index].length() != 0){
            ui->spinBox_2->setMaximum(complexLists[index].length()-1);
            ui->spinBox_3->setMaximum(complexLists[index].length()-1);
            ui->spinBox_3->setValue(complexLists[index].length()-1);
        }
        else{
            ui->spinBox_2->setMaximum(0);
            ui->spinBox_3->setMaximum(0);
        }
    }
}

/**********************************************************
* void setComboBox() : Class MainWindow
*_________________________________________________________
*   sets all the comboBox for the UI. Allows user to pick
*   a different list.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Initializes or Reinitializes Combo Box appropriately
***********************************************************/
void MainWindow::setComboBox()
{
    if(ui->intRadio->isChecked()){
       while(ui->comboBox->count() > 0)
           ui->comboBox->removeItem(0);
       for(int i = 0; i < intLists.size(); i++)
           ui->comboBox->addItem("Integer List " + QString::number(i+1));
    }
    else if(ui->doubleRadio->isChecked()){
        while(ui->comboBox->count() > 0)
            ui->comboBox->removeItem(0);
        for(int i = 0; i < doubleLists.size(); i++)
            ui->comboBox->addItem("Double List " + QString::number(i+1));
    }
    else if(ui->charRadio->isChecked()){
        while(ui->comboBox->count() > 0)
            ui->comboBox->removeItem(0);
        for(int i = 0; i < charLists.size(); i++)
            ui->comboBox->addItem("Char List " + QString::number(i+1));
    }
    else if(ui->stringRadio->isChecked()){
        while(ui->comboBox->count() > 0)
            ui->comboBox->removeItem(0);
        for(int i = 0; i < stringLists.size(); i++)
            ui->comboBox->addItem("String List " + QString::number(i+1));
    }
    else if(ui->rationalRadio->isChecked()){
        while(ui->comboBox->count() > 0)
            ui->comboBox->removeItem(0);
        for(int i = 0; i < rationalLists.size(); i++)
            ui->comboBox->addItem("Rational List " + QString::number(i+1));
    }
    else if(ui->dateRadio->isChecked()){
        while(ui->comboBox->count() > 0)
            ui->comboBox->removeItem(0);
        for(int i = 0; i < dateLists.size(); i++)
            ui->comboBox->addItem("Date List " + QString::number(i+1));
    }
    else if(ui->complexRadio->isChecked()){
        while(ui->comboBox->count() > 0)
            ui->comboBox->removeItem(0);
        for(int i = 0; i < complexLists.size(); i++)
            ui->comboBox->addItem("Complex List " + QString::number(i+1));
    }
    index = 0;
}

/**********************************************************
* void on_intRadio_clicked() : Class MainWindow
*_________________________________________________________
*   resets index to 0, spinBoxes, and comboBox
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   resets index to 0, spinBoxes, and comboBox
***********************************************************/
void MainWindow::on_intRadio_clicked()
{
    index = 0;
    setSpinBox();
    setComboBox();

}

/**********************************************************
* void on_doubleRadio_clicked() : Class MainWindow
*_________________________________________________________
*   resets index to 0, spinBoxes, and comboBox
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   resets index to 0, spinBoxes, and comboBox
***********************************************************/
void MainWindow::on_doubleRadio_clicked()
{
    index = 0;
    setSpinBox();
    setComboBox();
}


/**********************************************************
* void on_charRadio_clicked() : Class MainWindow
*_________________________________________________________
*   resets index to 0, spinBoxes, and comboBox
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   resets index to 0, spinBoxes, and comboBox
***********************************************************/
void MainWindow::on_charRadio_clicked()
{
    index = 0;
    setSpinBox();
    setComboBox();
}


/**********************************************************
* void on_stringRadio_clicked() : Class MainWindow
*_________________________________________________________
*   resets index to 0, spinBoxes, and comboBox
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   resets index to 0, spinBoxes, and comboBox
***********************************************************/
void MainWindow::on_stringRadio_clicked()
{
    index = 0;
    setSpinBox();
    setComboBox();
}

/**********************************************************
* void on_rationalRadio_clicked() : Class MainWindow
*_________________________________________________________
*   resets index to 0, spinBoxes, and comboBox
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   resets index to 0, spinBoxes, and comboBox
***********************************************************/
void MainWindow::on_rationalRadio_clicked()
{
    index = 0;
    setSpinBox();
    setComboBox();
}

/**********************************************************
* void on_complexRadio_clicked() : Class MainWindow
*_________________________________________________________
*   resets index to 0, spinBoxes, and comboBox
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   resets index to 0, spinBoxes, and comboBox
***********************************************************/
void MainWindow::on_complexRadio_clicked()
{
    index = 0;
    setSpinBox();
    setComboBox();
}

/**********************************************************
* void on_dateRadio_clicked() : Class MainWindow
*_________________________________________________________
*   resets index to 0, spinBoxes, and comboBox
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   resets index to 0, spinBoxes, and comboBox
***********************************************************/
void MainWindow::on_dateRadio_clicked()
{
    index = 0;
    setSpinBox();
    setComboBox();
}


/**********************************************************
* void on_spinBox_2_valueChanged(int arg1) : Class MainWindow
*_________________________________________________________
*   detects change of value in "From:" spinBox in order to make
*   sure display portion is not displaying from a number higher
*   than it is displaying to.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Initializes spinBox3's minimum value
***********************************************************/
void MainWindow::on_spinBox_2_valueChanged(int arg1)    //IN - value of spinBox2
{
    ui->spinBox_3->setMinimum(arg1);
}

/**********************************************************
* void on_spinBox_3_valueChanged(int arg1) : Class MainWindow
*_________________________________________________________
*   detects change of value in "To:" spinBox in order to make
*   sure display portion is not displaying from a number lower
*   than it is displaying to.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Initializes spinBox2's maximum value
***********************************************************/
void MainWindow::on_spinBox_3_valueChanged(int arg1)    //IN - value of spinBox3
{
    ui->spinBox_2->setMaximum(arg1);
}


/**********************************************************
* void on_displayPortionButton_clicked() : Class MainWindow
*_________________________________________________________
*   displays the portion of the list from SpinBox2's value
*   to SpinBox3's value
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   outputs the list to the screen.
***********************************************************/
void MainWindow::on_displayPortionButton_clicked()
{
    display(ui->spinBox_2->value(),  ui->spinBox_3->value());
}

/**********************************************************
* void on_newList_clicked() : Class MainWindow
*_________________________________________________________
*   creates a new empty list in the vector that is being
*   currently selected
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   A new Linked List of the current type is constructed
***********************************************************/
void MainWindow::on_newListButton_clicked()
{
    if(ui->intRadio->isChecked())
        intLists.push_back(LinkedList<int>());
    else if(ui->doubleRadio->isChecked())
        doubleLists.push_back(LinkedList<double>());
    else if(ui->charRadio->isChecked())
        charLists.push_back(LinkedList<char>());
    else if(ui->stringRadio->isChecked())
        stringLists.push_back(LinkedList<string>());
    else if(ui->rationalRadio->isChecked())
        rationalLists.push_back(LinkedList<Rational>());
    else if(ui->dateRadio->isChecked())
        dateLists.push_back(LinkedList<Date>());
    else if(ui->complexRadio->isChecked())
        complexLists.push_back(LinkedList<Complex>());
    setSpinBox();
    setComboBox();
}

/**********************************************************
* void on_comboBox_currentIndexChanged(int index) : Class MainWindow
*_________________________________________________________
*   Sets the Member variable index to the index of the combo
*   Box making sure the proper list is being referenced.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   A new Linked List is now thee current Linked List.
***********************************************************/
void MainWindow::on_comboBox_currentIndexChanged(int index) //IN - index of combo box
{
    this->index = index;
}

/**********************************************************
* void on_copyList_clicked() : Class MainWindow
*_________________________________________________________
*   creates a new copied list in the vector that is being
*   currently selected
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   A new Linked List with copied data is created.
***********************************************************/
void MainWindow::on_copyListButton_clicked()
{
    if(ui->intRadio->isChecked())
        intLists.push_back(LinkedList<int>(intLists[index]));
    else if(ui->doubleRadio->isChecked())
        doubleLists.push_back(LinkedList<double>(doubleLists[index]));
    else if(ui->charRadio->isChecked())
        charLists.push_back(LinkedList<char>(charLists[index]));
    else if(ui->stringRadio->isChecked())
        stringLists.push_back(LinkedList<string>(stringLists[index]));
    else if(ui->rationalRadio->isChecked())
        rationalLists.push_back(LinkedList<Rational>(rationalLists[index]));
    else if(ui->dateRadio->isChecked())
        dateLists.push_back(LinkedList<Date>(dateLists[index]));
    else if(ui->complexRadio->isChecked())
        complexLists.push_back(LinkedList<Complex>(complexLists[index]));
    setSpinBox();
    setComboBox();
}

/**********************************************************
* void on_deleteList_clicked() : Class MainWindow
*_________________________________________________________
*   deletes the currently selected list.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   The selected list is deleted and freed from memory
***********************************************************/
void MainWindow::on_deleteListButton_clicked()
{
    if(ui->intRadio->isChecked())
    {
        intLists.remove(index);
        if(intLists.size() == 0)
            intLists.push_back(LinkedList<int>());
    }
    else if(ui->doubleRadio->isChecked())
    {
        doubleLists.remove(index);
        if(doubleLists.size() == 0)
            doubleLists.push_back(LinkedList<double>());
    }
    else if(ui->charRadio->isChecked())
    {
        charLists.remove(index);
        if(charLists.size() == 0)
            charLists.push_back(LinkedList<char>());
    }
    else if(ui->stringRadio->isChecked())
    {
        stringLists.remove(index);
        if(stringLists.size() == 0)
            stringLists.push_back(LinkedList<string>());
    }
    else if(ui->rationalRadio->isChecked())
    {
        rationalLists.remove(index);
        if(rationalLists.size() == 0)
            rationalLists.push_back(LinkedList<Rational>());
    }
    else if(ui->dateRadio->isChecked())
    {
        dateLists.remove(index);
        if(dateLists.size() == 0)
            dateLists.push_back(LinkedList<Date>());
    }
    else if(ui->complexRadio->isChecked())
    {
        complexLists.remove(index);
        if(complexLists.size() == 0)
            complexLists.push_back(LinkedList<Complex>());
    }
    index = 0;
    setSpinBox();
    setComboBox();
}

