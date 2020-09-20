#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include "addition.h"
#include "subtraction.h"
#include <memory>
#include <QInputDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  auto pix=std::make_shared<QPixmap>();



  pix->load("x.jpg");
  ui->label->setPixmap(*pix);


  ui->textBrowser->setFontPointSize(11);
  ui->textBrowser->setText("Programming By Hojati");

  connect(ui->exitButton,SIGNAL(clicked()),SLOT(close()));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addition_clicked(){

    addition *addition_window=new addition;
    addition_window->show();



}

void MainWindow::on_subtraction_clicked(){

    subtraction *subtraction_window=new subtraction;
    subtraction_window->show();

}
void MainWindow::on_pushButtonmusic_clicked(){

    QMediaPlayer *player=new QMediaPlayer;
    QMediaPlaylist *playlist=new QMediaPlaylist;

    playlist->addMedia(QUrl::fromLocalFile("sounds/01 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/02 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/03 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/04 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/05 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/06 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/07 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/08 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/09 .mp3"));
    playlist->addMedia(QUrl::fromLocalFile("sounds/10 .mp3"));


    player->setPlaylist(playlist);
    player->setVolume(30);

    player->play();

    connect(ui->pushButtonmusic2,SIGNAL(clicked()),player,SLOT(pause()));


}























