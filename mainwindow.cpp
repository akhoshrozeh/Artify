#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_select_file_button_clicked()
{
    filename = QFileDialog::getOpenFileName(this, "Open Document",
                                                    "/Users/akhoshrozeh/Pictures",
                                                    "Images (*.png *.xpm *.jpg)");
    if(filename.isNull())
        return;

    selected_image.load(filename);
    int w = ui->before_pic->width();
    int h = ui->before_pic->height();
    ui->before_pic->setPixmap(selected_image.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_invert_button_clicked()
{
    image = selected_image.toImage();

    image.invertPixels(QImage::InvertRgb);
    transformed_image = QPixmap::fromImage(image);
    int w = ui->before_pic->width();
    int h = ui->before_pic->height();
    ui->after_pic->setPixmap(transformed_image.scaled(w,h,Qt::KeepAspectRatio));
}
