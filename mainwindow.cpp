#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "mymodel.h"
#include "QGridLayout"
#include "breeddelegate.h"
#include "linedelegate.h"
#include "editdogdialog.h"
#include "dialogdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

    DialogDelegate* ddel = new DialogDelegate(nullptr,this);


    BreedDelegate* fdel = new BreedDelegate();
    lineDelegate* ldel = new lineDelegate();

    tableView->setItemDelegateForColumn(0,ddel);
    tableView->setItemDelegateForColumn(1,ldel);
    tableView->setItemDelegateForColumn(2,fdel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);


    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Add");
    QPushButton* pb2 = new QPushButton("Delete");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::AddRow() {
    EditDogDialog* addDialog = new EditDogDialog(this);

    if (addDialog->exec() == QDialog::Accepted) {
        Dog* dog = new Dog(addDialog->id(),addDialog->name(),addDialog->age(), addDialog->breed(), addDialog->owner(), this);
        myModel->AddDog(dog);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow() {
    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteDog(selList.row());
}
