#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QPixmap>
#include <QMainWindow>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_select_file_button_clicked();

    void on_invert_button_clicked();

private:
    Ui::MainWindow *ui;
    QString filename;
    QPixmap selected_image;
    QPixmap transformed_image;
    QImage image;
};

#endif // MAINWINDOW_H
