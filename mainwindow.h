#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QLabel>
#include <QMainWindow>



namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    QLabel    *l1;
    QLabel    *l2;
    QLabel    *l3;
};
#endif // MAINWINDOW_H
