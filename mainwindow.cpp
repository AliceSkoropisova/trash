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
    group= new QLabel("Thin Lizzy",this);
    numb= new QLabel("45",this);
    genre= new QLabel("Rock",this);
    time= new QLabel("02:23",this);

    //спидометр
    speed=new QLabel(this);
    speed->resize(img_1[0]->size());
    speed->setPixmap(*img_1[0]);

    //nepon
    nepon=new QLabel();
    nepon->resize(img_1[3]->size());
    nepon->setPixmap(*img_1[3]);

    //пиксельная музыка
    pixelSound=new QLabel(this);
    pixelSound->resize(img_1[1]->size());
    pixelSound->setPixmap(*img_1[1]);

    //обложка альбома
    disk=new QLabel(this);
    disk->resize(album->size());
    disk->setPixmap(*album);

    //песни
    for( int i=0;i<7;i++)
    {
        songs[i] = new QLabel(this);
        songs[i]->resize(music[i]->size());
        songs[i]->setPixmap(*music[i]);
    }

    //полоска с названием песни
    MusName=new QLabel(this);
    MusName->resize(musName->size());
    MusName->setPixmap(*musName);

    //странная полоска
    srange=new QLabel(this);
    srange->resize(stran->size());
    srange->setPixmap(*stran);



    ///////кнопки///////

    //шесть кнопок в первой части экрана перед спидометром
    sixBtn[0] = new QPushButton(QIcon(":new/prefix1/trash/1.jpg"),"",this);
    sixBtn[1] = new QPushButton(QIcon(":new/prefix1/trash/2.jpg"),"",this);
    sixBtn[2] = new QPushButton(QIcon(":new/prefix1/trash/3.jpg"),"",this);
    sixBtn[3] = new QPushButton(QIcon(":new/prefix1/trash/4.jpg"),"",this);
    sixBtn[4] = new QPushButton(QIcon(":new/prefix1/trash/5.jpg"),"",this);
    sixBtn[5] = new QPushButton(QIcon(":new/prefix1/trash/str.jpg"),"",this);

    //две кнопки м-ду прогрессбарами
    twoBtn[0] = new QPushButton(QIcon(":new/prefix1/trash/knopa.jpg"),"",this);
    twoBtn[1] = new QPushButton(QIcon(":new/prefix1/trash/off.jpg"),"",this);

    //оранжевые круглые кнопы
    for( int i=0;i<6;i++) sixOrangeBtn[i] = new QPushButton(QIcon(":new/prefix1/trash/krug.jpg"),"",this);

    //три кнопки большие
    threeBtn[0] = new QPushButton("Default",this);
    threeBtn[1] = new QPushButton("Pls at 14-39-59",this);
    threeBtn[2] = new QPushButton("Thin Lizzy",this);

    //шесть нижних кноп
    sixDownBtn[0] = new QPushButton(QIcon(":new/prefix1/trash/p.jpg"),"",this);
    sixDownBtn[1] = new QPushButton(QIcon(":new/prefix1/trash/m.jpg"),"",this);
    sixDownBtn[2] = new QPushButton(QIcon(":new/prefix1/trash/t.jpg"),"",this);
    sixDownBtn[3] = new QPushButton(QIcon(":new/prefix1/trash/s.jpg"),"",this);
    sixDownBtn[4] = new QPushButton(QIcon(":new/prefix1/trash/po.jpg"),"",this);
    sixDownBtn[5] = new QPushButton(QIcon(":new/prefix1/trash/fil.jpg"),"",this);

    //выкл в первой части
    offBtn = new QPushButton(QIcon(":new/prefix1/trash/vkl.jpg"),"",this);


    /////скролл ареа/////////
    scrollArea = new QScrollArea(this);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    /////строчка "поиска"///////
    search = new QLineEdit(this);


    /////прогрессбары///////
    volume = new QProgressBar(this);
    balance= new QProgressBar(this);
    songTime= new QProgressBar(this);


    //////цифры////////
    number= new QLCDNumber(this);


    layout_1 = new QHBoxLayout();
    layoutGrid_1 = new QGridLayout();
    layoutV_1 = new QVBoxLayout();
    layoutH_1  = new QHBoxLayout();
    musN = new QVBoxLayout();
    secondBlock = new QHBoxLayout();
    thirdBlock = new QHBoxLayout();
    albomInfo = new QVBoxLayout();
    mus = new QVBoxLayout();
    fourthBlock = new QHBoxLayout();
    BtnBlock = new QHBoxLayout();
    wig = new QVBoxLayout();
    window = new QWidget();

    //первая строчка
    musN->addWidget(MusName);
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
    scrollArea->setLayout(mus);
    thirdBlock->addLayout(albomInfo);
    thirdBlock->addWidget(scrollArea);

    //fourth block
    for( int i=0;i<5;i++) fourthBlock->addWidget(sixDownBtn[i]);
    fourthBlock->addWidget(search);
    fourthBlock->addWidget(sixDownBtn[5]);

    //btn block
    for( int i=0;i<3;i++) BtnBlock->addWidget(threeBtn[i]);

    //all widget

    wig->addLayout(musN);
    wig->addLayout(layout_1);
    wig->addLayout(secondBlock);
    wig->addWidget(songTime);
    wig->addLayout(BtnBlock);
    wig->addWidget(srange);
    wig->addLayout(thirdBlock);
    wig->addLayout(fourthBlock);

    window->setLayout(wig);
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
