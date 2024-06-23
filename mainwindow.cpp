#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>
#include <string>
#include <QString>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// global variables

struct itemPrice {
    std::string itemName;
    int itemPrice;
};

struct receiptInfo {
    int receiptNum;
    QString customerName, cardNum;
};

std::vector<itemPrice> v;
int totalPrice = 0, vectorIndex = 0;

MainWindow::~MainWindow()
{
    delete ui;
}


// navigation buttons

void MainWindow::on_viewCartButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    std::string str;
    int i;

    for (i = vectorIndex; i < v.size(); i++) {
        str = v[i].itemName + "\t\t\t" + std::to_string(v[i].itemPrice);
        ui->itemsInCartList->addItem(str.c_str());
        totalPrice += v[i].itemPrice;
    }
    vectorIndex = i;

    ui->totalPriceInCart->setText(std::to_string(totalPrice).c_str());
}


void MainWindow::on_backToSelectionButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_payButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    ui->totalPriceToPay->setText(std::to_string(totalPrice).c_str());
}


void MainWindow::on_confirmPaymentButton_clicked()
{
    std::ofstream outputFile;
    receiptInfo ri;

    ri.receiptNum = rand();
    ri.customerName = ui->userName->toPlainText();
    ri.cardNum = ui->userCardNumber->toPlainText();

    outputFile.open("Receipt.txt", std::ios::app);

    if (outputFile) {
        outputFile << "Receipt Number : " << ri.receiptNum << "\n";
        outputFile << "Customer Name : " << ri.customerName.toStdString() << "\n";
        outputFile << "Card Information : " << ri.cardNum.toStdString() << "\n";

        outputFile << "-------------------------------------------------------------\n";

        outputFile << "Items \t\t Price\n";
        for (int i = 0; i < v.size(); i++) {
            outputFile << v[i].itemName << "\t\t" << v[i].itemPrice << "\n";
        }

        outputFile << "Total : \t" << totalPrice << "\n\n\n";
    }

    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_newListing_clicked()
{
    v.clear();
    ui->itemsInCartList->clear();
    totalPrice = 0;
    ui->stackedWidget->setCurrentIndex(0);
}


// adding items to the cart

void MainWindow::on_addCoke_clicked()
{
    itemPrice item;

    item.itemName = "Coke";
    item.itemPrice = 100;

    v.push_back(item);
}


void MainWindow::on_addPepsi_clicked()
{
    itemPrice item;

    item.itemName = "Pepsi";
    item.itemPrice = 80;

    v.push_back(item);
}


void MainWindow::on_addSprite_clicked()
{
    itemPrice item;

    item.itemName = "Sprite";
    item.itemPrice = 75;

    v.push_back(item);
}


void MainWindow::on_addFanta_clicked()
{
    itemPrice item;

    item.itemName = "Fanta";
    item.itemPrice = 70;

    v.push_back(item);
}

