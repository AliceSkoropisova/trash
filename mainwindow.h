#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//Добавляется заголовок со всеми виджетами
#include <QtWidgets>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT
public:



public:    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //Указатели на элементы окна
    QPixmap *img_1[4];
    QPixmap *musName;
    QPixmap *album;
    QPixmap *music[7];
    QPixmap* stran;

    QLabel *artist ;
    QLabel *group;
    QLabel *numb;
    QLabel *genre;
    QLabel *time;

    QLabel *first;
    QLabel *speed;
    QLabel *pixelSound;
    QLabel *disk;
    QLabel *songs[7];
    QLabel *MusName;
    QLabel *srange;
    QLabel *nepon;

    QPushButton *sixBtn[6];
    QPushButton *twoBtn[2];
    QPushButton *sixOrangeBtn[6];
    QPushButton *threeBtn[3];
    QPushButton *sixDownBtn[6];
    QPushButton *offBtn;

    QScrollArea *scrollArea;

    QLineEdit *search;

    QProgressBar *volume;
    QProgressBar *balance;
    QProgressBar *songTime;

    QLCDNumber *number;

    QHBoxLayout* layout_1;
    QGridLayout* layoutGrid_1;
    QVBoxLayout* layoutV_1;
    QHBoxLayout* layoutH_1 ;
    QVBoxLayout* musN;
    QHBoxLayout* secondBlock;
    QHBoxLayout* thirdBlock;
    QVBoxLayout* albomInfo;
    QVBoxLayout* mus;
    QHBoxLayout* fourthBlock;
    QHBoxLayout* BtnBlock;
    QVBoxLayout* wig;
    QWidget *window;
};
#endif // MAINWINDOW_H
