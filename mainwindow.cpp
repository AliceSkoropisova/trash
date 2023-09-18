#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{

    //Чтобы отличать установим заголовок у окна
    setWindowTitle("Music");

    ///////////картинки//////////
    //первая картинка
    musName=new QPixmap();
    musName->load(":new/prefix1/trash/b.jpg");

    //картинки первого блока
    for( int i=0;i<4;i++) img_1[i] = new QPixmap();
    img_1[0]->load(":new/prefix1/trash/a.jpg");
    img_1[1]->load(":new/prefix1/trash/d.jpg");
    img_1[2]->load(":new/prefix1/trash/vkl.jpg");
    img_1[3]->load(":new/prefix1/trash/nepon.jpg");

    //картинка альбома
    album = new QPixmap(":new/prefix1/trash/album.jpg");

    //картинки треков
    for( int i=0;i<7;i++) music[i] = new QPixmap();
    music[0]->load(":new/prefix1/trash/11.jpg");
    music[1]->load(":new/prefix1/trash/22.jpg");
    music[2]->load(":new/prefix1/trash/33.jpg");
    music[3]->load(":new/prefix1/trash/44.jpg");
    music[4]->load(":new/prefix1/trash/55.jpg");
    music[5]->load(":new/prefix1/trash/66.jpg");
    music[6]->load(":new/prefix1/trash/77.jpg");

    //картинка странной штуки
    stran = new QPixmap;
    stran->load(":new/prefix1/trash/c.jpg");



    ///////лейблы///////
    //имя исполнителя
    artist = new QLabel("Cowboy song",this);
    artist->setStyleSheet("color : rgb(245, 130, 49)");
    group= new QLabel("Thin Lizzy",this);
    numb= new QLabel("45",this);
    genre= new QLabel("Rock",this);
    time= new QLabel("02:23",this);
    time->setStyleSheet("color : rgb(245, 130, 49)");

    //спидометр
    speed=new QLabel(this);
   // speed->resize(img_1[0]->size());
    speed->setPixmap(*img_1[0]);
    speed->setScaledContents(img_1[0]);

    //nepon
    nepon=new QLabel();
    //nepon->resize(img_1[3]->size());
    nepon->setPixmap(*img_1[3]);
    nepon->setScaledContents(img_1[3]);


    //пиксельная музыка
    pixelSound=new QLabel(this);
    //pixelSound->resize(img_1[1]->size());
    pixelSound->setPixmap(*img_1[1]);
    pixelSound->setScaledContents(img_1[1]);

    //обложка альбома
    disk=new QLabel(this);
    //disk->resize(album->size());
    disk->setPixmap(*album);
    disk->setScaledContents(album);

    //песни
    for( int i=0;i<7;i++)
    {
        songs[i] = new QLabel(this);
        //songs[i]->resize(music[i]->size());
        songs[i]->setPixmap(*music[i]);
        songs[i]->setScaledContents(music[i]);

    }

    //полоска с названием песни
    MusName=new QLabel(this);

    //MusName->resize(musName->size());
    MusName->setPixmap(*musName);
    MusName->setScaledContents(musName);

    //странная полоска
    srange=new QLabel(this);
    srange->setPixmap(*stran);
    srange->setScaledContents(stran);



    ///////кнопки///////

    //шесть кнопок в первой части экрана перед спидометром
    sixBtn[0] = new QPushButton(QIcon(":new/prefix1/trash/1.jpg"),"",this);
    sixBtn[1] = new QPushButton(QIcon(":new/prefix1/trash/2.jpg"),"",this);
    sixBtn[2] = new QPushButton(QIcon(":new/prefix1/trash/3.jpg"),"",this);
    sixBtn[3] = new QPushButton(QIcon(":new/prefix1/trash/4.jpg"),"",this);
    sixBtn[4] = new QPushButton(QIcon(":new/prefix1/trash/5.jpg"),"",this);
    sixBtn[5] = new QPushButton(QIcon(":new/prefix1/trash/str.jpg"),"",this);
    for( int i=0;i<6;i++)
    {
        sixBtn[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        sixBtn[i]->setMaximumSize(25,25);
        sixBtn[i]->setMinimumSize(25,25);
        sixBtn[i]->setCursor(Qt::PointingHandCursor);
        sixBtn[i]->setIconSize(QSize(25 ,25));
        sixBtn[i]->setFlat(true);
    }

    //две кнопки м-ду прогрессбарами
    twoBtn[0] = new QPushButton(QIcon(":new/prefix1/trash/knopa.jpg"),"",this);
    twoBtn[1] = new QPushButton(QIcon(":new/prefix1/trash/off.jpg"),"",this);
    for( int i=0;i<2;i++)
    {
        twoBtn[i]->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Fixed);
        twoBtn[i]->setMinimumSize(15,6);
        twoBtn[i]->setMaximumSize(20,11);
        twoBtn[i]->setCursor(Qt::PointingHandCursor);
        twoBtn[i]->setIconSize(QSize(27 ,21));
        twoBtn[i]->setFlat(true);
    }

    //оранжевые круглые кнопы
    for( int i=0;i<6;i++) sixOrangeBtn[i] = new QPushButton(QIcon(":new/prefix1/trash/krug.jpg"),"",this);
    for( int i=0;i<5;i++)
    {
        sixOrangeBtn[i]->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Fixed);
        sixOrangeBtn[i]->setMinimumSize(17,30);
        sixOrangeBtn[i]->setMaximumSize(17,30);
        sixOrangeBtn[i]->setCursor(Qt::PointingHandCursor);
        sixOrangeBtn[i]->setIconSize(QSize(31 ,26));
        sixOrangeBtn[i]->setFlat(true);
    }
    sixOrangeBtn[5]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    sixOrangeBtn[5]->setMinimumSize(13,13);
    sixOrangeBtn[5]->setMaximumSize(13,13);
    sixOrangeBtn[5]->setCursor(Qt::PointingHandCursor);
    sixOrangeBtn[5]->setIconSize(QSize(13 ,13));
    sixOrangeBtn[5]->setFlat(true);

    //три кнопки большие
    threeBtn[0] = new QPushButton("Default",this);
    threeBtn[1] = new QPushButton("Pls at 14-39-59",this);
    threeBtn[2] = new QPushButton("Thin Lizzy",this);
    for( int i=0;i<3;i++)
    {
        threeBtn[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        threeBtn[i]->setMinimumSize(150,30);
        threeBtn[i]->setMaximumSize(170,50);
        threeBtn[i]->setCursor(Qt::PointingHandCursor);
        threeBtn[i]->setStyleSheet("color : rgb(192, 191, 188); background-color: rgb(94, 92, 100)");
    }
    threeBtn[2]->setStyleSheet("color : rgb(255, 255, 255); background-color: rgb(255, 120, 0)");

    //шесть нижних кноп
    sixDownBtn[0] = new QPushButton(QIcon(":new/prefix1/trash/p.jpg"),"",this);
    sixDownBtn[1] = new QPushButton(QIcon(":new/prefix1/trash/m.jpg"),"",this);
    sixDownBtn[2] = new QPushButton(QIcon(":new/prefix1/trash/t.jpg"),"",this);
    sixDownBtn[3] = new QPushButton(QIcon(":new/prefix1/trash/s.jpg"),"",this);
    sixDownBtn[4] = new QPushButton(QIcon(":new/prefix1/trash/po.jpg"),"",this);
    sixDownBtn[5] = new QPushButton(QIcon(":new/prefix1/trash/fil.jpg"),"",this);
    for( int i=0;i<6;i++)
    {
        sixDownBtn[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
        sixDownBtn[i]->setMinimumSize(25,25);
        sixDownBtn[i]->setMaximumSize(25,25);
        sixDownBtn[i]->setCursor(Qt::PointingHandCursor);
        sixDownBtn[i]->setIconSize(QSize(25 ,19));
        sixDownBtn[i]->setFlat(true);
    }


    //выкл в первой части
    offBtn = new QPushButton(QIcon(":new/prefix1/trash/vkl.jpg"),"",this);
    offBtn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Ignored);
    offBtn->setMaximumSize(25,25);
    offBtn->setMinimumSize(25,25);
    offBtn->setCursor(Qt::PointingHandCursor);
    offBtn->setIconSize(QSize(30 ,30));
    offBtn->setFlat(true);


    /////скролл ареа/////////
    scrollArea = new QScrollArea(this);
    scrollArea->setStyleSheet("QScrollBar::handle:vertical {\n    color: rgb(255, 120, 0);\n    background-color: rgb(255, 120, 0);\nborder-radius: 7px;\n}");
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    /////строчка "поиска"///////
    search = new QLineEdit(this);
    search->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    search->setMinimumSize(300,25);
    search->setStyleSheet("color : rgb(119, 118, 123); background-color: rgb(94, 92, 100)");


    /////прогрессбары///////
    volume = new QProgressBar(this);
    volume->setStyleSheet("QProgressBar {\n border-radius: 7px;\n background-color: rgb(89, 89, 89);\n}\n\nQProgressBar::chunk {\n background-color: #ff8722;\n border-radius: 7px;\n}");
    volume->setValue(66);
    volume->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    volume->setMinimumWidth(143);
    volume->setFormat("");
    volume->setMinimumHeight(15);
    volume->setMaximumHeight(15);

    balance= new QProgressBar(this);
    balance->setStyleSheet("QProgressBar {\n border-radius: 7px;\n background-color: rgb(89, 89, 89);\n}\n\nQProgressBar::chunk {\n background-color: #ff8722;\n border-radius: 7px;\n}");
    balance->setValue(24);
    balance->setMinimumWidth(340);
    balance->setMinimumHeight(15);
    balance->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    balance->setFormat("");
    balance->setMaximumHeight(15);

    songTime= new QProgressBar(this);
    songTime->setStyleSheet("QProgressBar {\n    border-radius: 7px;\n	background-color: rgb(89, 89, 89);\n}\n\nQProgressBar::chunk {\n    background-color: #ff8722;\n    border-radius: 7px;\n}");
    songTime->setValue(33);
    songTime->setMinimumHeight(15);
    songTime->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    songTime->setFormat("");
    songTime->setMaximumHeight(15);



    //////цифры////////
    number= new QLCDNumber(this);
    number->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    number->setMaximumSize(60,60);
    number->setMinimumSize(40,40);
    number->display(2.33);



    layout_1 = new QHBoxLayout();
    layoutGrid_1 = new QGridLayout();
    layoutV_1 = new QVBoxLayout();
    layoutH_1  = new QHBoxLayout();
    musN = new QVBoxLayout();
    secondBlock = new QHBoxLayout();
    thirdBlock = new QHBoxLayout();
    albomInfo = new QVBoxLayout();
    QWidget *scrollWidget = new QWidget(this);
    scrollWidget->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    mus = new QVBoxLayout();
    fourthBlock = new QHBoxLayout();
    BtnBlock = new QHBoxLayout();
    wig = new QVBoxLayout();
    window = new QWidget();



    //first block
    layoutGrid_1->addWidget(sixBtn[0],0,0);
    layoutGrid_1->addWidget(sixBtn[1],0,1);
    layoutGrid_1->addWidget(sixBtn[2],1,0);
    layoutGrid_1->addWidget(sixBtn[3],1,1);
    layoutGrid_1->addWidget(sixBtn[4],2,0);
    layoutGrid_1->addWidget(sixBtn[5],2,1);
    layout_1->addLayout(layoutGrid_1);
    layout_1->addWidget(speed);
    layoutH_1->addWidget(offBtn);
    layoutH_1->addWidget(number);
    layoutV_1->addLayout(layoutH_1);
    layoutV_1->addWidget(pixelSound);
    layout_1->addLayout(layoutV_1);
    layout_1->addWidget(nepon);

    //second block
    for(int i=0;i<6;i++) secondBlock->addWidget(sixOrangeBtn[i]);
    secondBlock->addWidget(volume);
    for( int i=0;i<2;i++) secondBlock->addWidget(twoBtn[i]);
    secondBlock->addWidget(balance);


    //third block
    albomInfo->addWidget(disk);
    albomInfo->addWidget(artist);
    albomInfo->addWidget(group);
    albomInfo->addWidget(numb);
    albomInfo->addWidget(genre);
    albomInfo->addWidget(time);

    for( int i=0;i<7;i++) mus->addWidget(songs[i]);

    scrollWidget->setLayout(mus);
    scrollWidget->setMinimumWidth(250);

    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    //scrollWidget->setLayout(mus);
    //scrollArea->setWidget(scrollWidget);

    thirdBlock->addLayout(albomInfo);

    thirdBlock->addWidget(scrollArea);

    //fourth block
    for( int i=0;i<5;i++) fourthBlock->addWidget(sixDownBtn[i]);
    fourthBlock->addWidget(search);
    fourthBlock->addWidget(sixDownBtn[5]);

    //btn block
    BtnBlock->setContentsMargins(0,0,350,0);
    for( int i=0;i<3;i++) BtnBlock->addWidget(threeBtn[i]);

    //all widget

    wig->addWidget(MusName);
    wig->addLayout(layout_1);
    wig->addLayout(secondBlock);
    wig->addWidget(songTime);
    wig->addLayout(BtnBlock);
    wig->addWidget(srange);
    wig->addLayout(thirdBlock);
    wig->addLayout(fourthBlock);

    window->setLayout(wig);
    window->setStyleSheet("background-color: rgb(52, 52, 52);");
    window->show();


}

MainWindow::~MainWindow()
{

    for( int i=0;i<4;i++) delete img_1[i];

    delete artist ;
    delete group;
    delete numb;
    delete genre;
    delete time;

    delete speed;

    delete pixelSound;

    delete disk;

    for( int i=0;i<7;i++) delete songs[i];

    delete MusName;
    delete srange;

    for( int i=0;i<6;i++) delete sixBtn[i];

    for( int i=0;i<2;i++) delete twoBtn[i];

    for( int i=0;i<6;i++) delete sixOrangeBtn[i];

    for( int i=0;i<3;i++) delete threeBtn[i];

    for( int i=0;i<6;i++) delete sixDownBtn[i];

    delete offBtn;

    delete scrollArea;

    delete search;

    delete volume;
    delete balance;
    delete songTime;

    delete number;


    delete wig;
    delete window;

}
