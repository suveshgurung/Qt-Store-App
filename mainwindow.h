#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_viewCartButton_clicked();

    void on_backToSelectionButton_clicked();

    void on_payButton_clicked();

    void on_confirmPaymentButton_clicked();

    void on_newListing_clicked();

    void on_addCoke_clicked();

    void on_addPepsi_clicked();

    void on_addSprite_clicked();

    void on_addFanta_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
