#include "subtraction.h"
#include "ui_subtraction.h"
#include <QInputDialog>
#include <stdlib.h>
#include <time.h>
#include <QMediaPlayer>
#include <QLocale>

QString student_name1;

subtraction::subtraction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::subtraction)
{
    ui->setupUi(this);

   student_name1= QInputDialog::getText(this,tr("نام دانش آموز"),tr("لطفا نام دانش آموز را وارد کنید."));

   connect(ui->pushbutton2,SIGNAL(clicked()),SLOT(close()));


}

subtraction::~subtraction()
{
    delete ui;
}


void subtraction::on_pushbutton1_clicked(){

    srand(time(NULL));

    QInputDialog get_numb;

    int num;
    int first_num_rang;
    int second_num_rang;
    int score=0;

    num= get_numb.getInt(this,tr("تعداد"),tr("تعداد تساوی ها را وارد کنید. "));

    first_num_rang= get_numb.getInt(this,tr("حدود"),tr("حدود عدد اول را وارد کنید.(از صفر)"));
    second_num_rang= get_numb.getInt(this,tr("حدود"),tr("حدود عدد دوم را وارد کنید.(از صفر)"));

    ui->textBrowser2->setFontPointSize(20);
    ui->textBrowser2->setText("شروع!");

    for(int i=0;i<num;i++){

       int first_num;
       int second_num;

       do{

       first_num=rand()%(first_num_rang);
       second_num=rand()%(second_num_rang);

       }
       while (second_num>first_num);


       QLocale conv_num(QLocale::Persian);

       QString first_per_num=conv_num.toString(first_num);

       QString second_per_num=conv_num.toString(second_num);

       QString all=first_per_num+"-"+second_per_num+"= ";

       ui->textBrowser2->append(all);

       int user_answer;

       bool ok=false;

       user_answer=QInputDialog::getInt(this,tr("دریافت پاسخ"),tr("پاسخ را وارد کنید. "),0,0,1000,1,&ok);

       if(ok!=true) break;

       if(user_answer==first_num-second_num){

         QMediaPlayer *player=new QMediaPlayer;

         player->setMedia(QUrl::fromLocalFile("Tone.mp3"));
         player->setVolume(25);
         player->play();


         if(rand()%(2)==1){
         QString con="آفرین "+student_name1+" جان!";
         ui->textBrowser2->append(con);
         ui->textBrowser2->append("-------------------------------------");
         }

         else{
             QString con="ادامه بده "+student_name1+" جان!";
             ui->textBrowser2->append(con);
             ui->textBrowser2->append("-------------------------------------");
         }

         score+=10;
       }
       else{

           int i=1;

           while(user_answer!=first_num-second_num){

                  i++;

                  ui->textBrowser2->append("دوباره سعی کن !");

                 user_answer= QInputDialog::getInt(this,tr("دریافت پاسخ"),tr("حاصل صحیح را وارد کنید."));


               if(i==3) break;

           }

           if(user_answer!=first_num-second_num){
           ui->textBrowser2->append("حاصل برابر است با :");
           QString correct_ans=first_per_num+"+"+second_per_num+"="+conv_num.toString(first_num+second_num);
           ui->textBrowser2->append(correct_ans);

           score-=10;

           ui->textBrowser2->append("-------------------------------------");
           }
           else {

               QMediaPlayer *player=new QMediaPlayer;

               player->setMedia(QUrl::fromLocalFile("Tone.mp3"));
               player->setVolume(25);
               player->play();

               QString con="آفرین "+student_name1+" جواب صحیح بود.";
               ui->textBrowser2->append(con);

               ui->textBrowser2->append("-------------------------------------");


           }

       }

    }

    QString cong="تبریک " +student_name1+" جان ! امتیاز شما برابر "+QString::number(score)+" می باشد .";

    ui->textBrowser2->append(cong);


}






