#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
FILE *dosya;
FILE *dosya2;
FILE *dosya3;
char harfler[600];
char yeni[600];
char veri;
int tns=0;
int intSayac(int i)
{
    /* int degerleri saymak icin sayac 0 tutulur.Sonda bulunan degerler sonradan
    kullan�lab�l�ns�n d�ye txt ye yazd�rmak �c�n fopen komutu �le txt dosyas� ac�l�r
    gerekl� degerler kars�last�r�lman�n yap�lab�l�nmes� �c�n 0 atan�r.d�z� sonun akada ',','=',
    '[',']' degerler� hesaplan�r.[ say� deger� ] say� deger�ne es�tse dizi ya da matr�s vard�r den�l�r
    ve bu es�tl�k kullan�larak int[]veya int [][] olup olmad�g� bulunur ve buna gore yer
    karmas�kl�g�nda hesaplan�rken kullan�l�cak forma get�r�l�r.eger v�rgul deger� sifirsa -1 e es�tlen�r
    islem yaparken olusan kar�s�kl�g�n onlenmes� �c�n . tum bu hesaplamalardan sonra genel int say�s�
    bulunur eger bulunan �nt say�s� s�f�rdan farkl�ysa bas�lmas� gereken degerler ekrana bast�r�rl�r
    ve bu degerler yer karmas�kl�g� hesab�nda da kullan�ls�n d�ye txt ye yazd�r�l�r.ac�lan dosya
    fclose komutuyla kapat�l�r*/
    int sayacInt=0;
    dosya3=fopen("yerkarm.txt","a+");
    int a=0,isayisi=0,byte;//sayi degerleri byte ile carp�l�p  kaplad�g� byte degeri bulundu
    int virgul=0,esittir=0,akoseli=0,kkoseli=0,dizi=0;
    //printf("\n");
    for(int k = 0; k < i; k++)
    {
        if((yeni[k]=='i')&&(yeni[k+1]=='n')&&(yeni[k+2]=='t')&&(yeni[k+3]!='f')&&(yeni[k-1]!='r')&&(yeni[k+1]!='m')&&(yeni[k+2]!='a')&&(yeni[k+3]!='i')&&(yeni[k+4]!='n'))
        {
            a=k;
            while(yeni[a]!=';')
            {
                //printf("%c",yeni[a]);
                if(yeni[a]==',')
                {
                    virgul++;
                }
                if(yeni[a]=='=')
                {
                    esittir++;
                }
                if(yeni[a]=='[')
                {
                    akoseli++;
                }
                if(yeni[a]==']')
                {
                    kkoseli++;
                }
                a++;
            }
            sayacInt++;
            //printf("\n");
        }
    }
    if(akoseli==kkoseli)
    {
        dizi=((akoseli)/2);
    }
    if(virgul==0)
    {
        virgul=-1;
    }
    isayisi=((virgul+1)+esittir)*4;
    if (isayisi!=0)
    {
        if(akoseli==0)
        {
            //printf("\nDongudeki int byte toplam=%d\n",isayisi);
           // printf("-----------------------------");
            fprintf(dosya3,"+%d ",isayisi);
        }
        else
        {
            byte=4;// integer 4 byte
            //printf("\nDongudeki int byte toplam=%d+%d*n^%d\n",isayisi,byte,dizi*2);
            //printf("-----------------------------");
            fprintf(dosya3,"+%d+%d*n^%d ",isayisi,byte,dizi*2);
        }
    }

    fclose(dosya3);
}
int floatSayac(int i)
{
    /* int degerler�n byte toplam� bulunurken yap�lan �slemler float �c�n de yap�l�r
    fark olarak float byte deger� farkl� atan�r ve ona gore hesap yap�l�r  */
    dosya3=fopen("yerkarm.txt","a+");
    int sayacFloat=0;
    int a=0,fsayisi=0,byte;
    int virgul=0,esittir=0,akoseli=0,kkoseli=0,dizi=0;
    //printf("\n");
    for(int k = 0; k < i; k++)
    {
        if((yeni[k]=='f')&&(yeni[k+1]=='l')&&(yeni[k+2]=='o')&&(yeni[k+3]=='a')&&(yeni[k+4]=='t'))
        {
            a=k;
            while(yeni[a]!=';')
            {
                //printf("%c",yeni[a]);
                if(yeni[a]==',')
                {
                    virgul++;
                }
                if(yeni[a]=='=')
                {
                    esittir++;
                }
                if(yeni[a]=='[')
                {
                    akoseli++;
                }
                if(yeni[a]==']')
                {
                    kkoseli++;
                }
                a++;
            }
            sayacFloat++;
            //printf("\n");
        }
    }
    if(akoseli==kkoseli)
    {
        dizi=(akoseli)/2;
    }
    if(virgul==0)
    {
        virgul=-1;
    }
    fsayisi= ((virgul+1)+esittir)*4;//4 byte
    if (fsayisi!=0)
    {
        if(akoseli==0)
        {
            //printf("\nDongudeki float byte toplam=%d\n",fsayisi);
           // printf("-----------------------------");
            fprintf(dosya3,"+%d ",fsayisi);
        }
        else
        {
            byte=4;//float 4 byte
            printf("\nDongudeki float byte toplam=%d+%d*n^%d\n",fsayisi,byte,dizi*2);
            printf("-----------------------------");
            fprintf(dosya3,"+%d+%d*n^%d ",fsayisi,byte,dizi*2);
        }
    }

    fclose(dosya3);

}
int doubleSayac(int i)
{
    /* int degerler�n byte toplam� bulunurken yap�lan �slemler double degerler �c�n de yap�l�r
    fark olarak double byte(8 byte)deger� farkl� atan�r ve ona gore hesap yap�l�r  */
    int sayacDouble=0;
    dosya3=fopen("yerkarm.txt","a+");
    int a=0,dsayisi=0,byte;
    int virgul=0,esittir=0,akoseli=0,kkoseli=0,dizi=0;
   // printf("\n");
    for(int k = 0; k < i; k++)
    {
        if((yeni[k]=='d')&&(yeni[k+1]=='o')&&(yeni[k+2]=='u')&&(yeni[k+3]=='b')&&(yeni[k+4]=='l')&&(yeni[k+5]=='e'))
        {
            a=k;
            while(yeni[a]!=';')
            {
                //printf("%c",yeni[a]);
                if(yeni[a]==',')
                {
                    virgul++;
                }
                if(yeni[a]=='=')
                {
                    esittir++;
                }
                if(yeni[a]=='[')
                {
                    akoseli++;
                }
                if(yeni[a]==']')
                {
                    kkoseli++;
                }
                a++;
            }
            sayacDouble++;
            //printf("\n");
        }
    }
    if(akoseli==kkoseli)
    {
        dizi=(akoseli)/2;
    }
    if(virgul==0)
    {
        virgul=-1;
    }
    dsayisi=((virgul+1)+esittir)*8;//8 byte
    if (dsayisi!=0)
    {
        if(akoseli==0)
        {
            //printf("\nDongudeki double byte toplam=%d\n",dsayisi);
            //printf("-----------------------------");
            fprintf(dosya3,"+%d ",dsayisi,byte,dizi*2);
        }
        else
        {
            byte=8;//double 8 byte
           // printf("\nDongudeki double byte toplam=%d+%d*n^%d\n",dsayisi,byte,dizi*2);
           // printf("-----------------------------");
            fprintf(dosya3,"+%d+%d*n^%d ",dsayisi,byte,dizi*2);
        }
    }

    fclose(dosya3);
}
int longSayac(int i)
{
    /* int degerler�n byte toplam� bulunurken yap�lan �slemler long degerler �c�n de yap�l�r
    fark olarak long byte(4 byte)deger� farkl� atan�r ve ona gore hesap yap�l�r  */
    int sayacLong=0;
    dosya3=fopen("yerkarm.txt","a+");
    //printf("\n");
    int a=0,lsayisi=0,byte;
    int virgul=0,esittir=0,akoseli=0,kkoseli=0,dizi=0;
    for(int k = 0; k < i; k++)
    {
        if((yeni[k]=='l')&&(yeni[k+1]=='o')&&(yeni[k+2]=='n')&&(yeni[k+3]=='g'))
        {
            a=k;
            while(yeni[a]!=';')
            {
                //printf("%c",yeni[a]);
                if(yeni[a]==',')
                {
                    virgul++;
                }
                if(yeni[a]=='=')
                {
                    esittir++;
                }
                if(yeni[a]=='[')
                {
                    akoseli++;
                }
                if(yeni[a]==']')
                {
                    kkoseli++;
                }
                a++;
            }
            sayacLong++;
            //printf("\n");
        }
    }
    if(akoseli==kkoseli)
    {
        dizi=(akoseli)/2;
    }
    if(virgul==0)
    {
        virgul=-1;
    }
    lsayisi=((virgul+1)+esittir)*4;//4 byte
    if (lsayisi!=0)
    {
        if(akoseli==0)
        {
            //printf("\nDongudeki long byte toplam=%d\n",lsayisi);
            //printf("-----------------------------");
            fprintf(dosya3,"+%d ",lsayisi);
        }
        else
        {
            byte=4;//4 byte
            //printf("\nDongudeki long byte toplam=%d+%d*n^%d\n",lsayisi,byte,dizi*2);
            //printf("-----------------------------");
            fprintf(dosya3,"+%d+%d*n^%d ",lsayisi,byte,dizi*2);
        }
        fclose(dosya3);
    }

}
int charSayac(int i)
{
    /* int degerler�n byte toplam� bulunurken yap�lan �slemler char degerler �c�n de yap�l�r
    fark olarak char byte(1 byte)deger� farkl� atan�r ve ona gore hesap yap�l�r  */
    int sayacChar=0;
    dosya3=fopen("yerkarm.txt","a+");
    int a=0,csayisi=0,byte;
    int virgul=0,esittir=0,akoseli=0,kkoseli=0,dizi=0;
    //printf("\n");
    for(int k = 0; k < i; k++)
    {
        if((yeni[k]=='c')&&(yeni[k+1]=='h')&&(yeni[k+2]=='a')&&(yeni[k+3]=='r'))
        {
            a=k;
            while(yeni[a]!=';')
            {
                //printf("%c",yeni[a]);
                if(yeni[a]==',')
                {
                    virgul++;
                }
                if(yeni[a]=='=')
                {
                    esittir++;
                }
                if(yeni[a]=='[')
                {
                    akoseli++;
                }
                if(yeni[a]==']')
                {
                    kkoseli++;
                }
                a++;
            }
            sayacChar++;
            //printf("\n");
        }
    }
    if(akoseli==kkoseli)
    {
        dizi=(akoseli)/2;
    }
    if(virgul==0)
    {
        virgul=-1;
    }
    csayisi=(virgul+1)+esittir;//1 byte
    if (csayisi!=0)
    {
        if(akoseli==0)
        {
           // printf("\nDongudeki char byte toplam=%d\n",csayisi);
           //printf("-----------------------------");
            fprintf(dosya3,"+%d ",csayisi);
        }
        else
        {
            byte=1;//1 byte
          //printf("\nDongudeki char byte toplam=%d+%d*n^%d\n",csayisi,byte,dizi*2);
          //printf("-----------------------------");
            fprintf(dosya3,"+%d+%d*n^%d ",csayisi,byte,dizi*2);
        }
    }

    fclose(dosya3);
}
void karm()
{
    /* intSayac,floatSayac,doubleSayac,longSayac,charSayac fonks�yonlar�nda bulunup
    yerkarm.txt ye yazd�r�lan degerler okutulur ve kodun yer karmas�kl�g� deger�
    ekrana yazd�r�l�r  */
    char karmas[50];
    char e;
    int j=0;
    printf("\nYER KARMASIKLIGI=");
    dosya3=fopen("yerkarm.txt","r+");
    while (!feof(dosya3))
    {
        karmas[j] = fgetc(dosya3);
        j++;
    }
    printf("%s",karmas);
    fclose(dosya3);
}

int bigO(int i)
{

    int sayac=0;
    int wsayac=0;
    int findis[100];  // dizide bulunan for dong�lerinin indislerini tutar.
    int p = 0;
    int yildizSayac =0; //b�t�n for parantezleri icerisindeki yildizlari sayar.
    int bolmeSayac = 0;
    int ikiliforYildizSayac=0;
    int ikiliforBolmeSayac=0;

 //big(o) hesabi icin gerekli olucak bazi degerleri dizi icerisinden bulur ve istenen karakterin tekrar sayisini tutar.
    for (int k = 0; k < i; k++)
    {
        if((yeni[k]=='f')&&(yeni[k+1]=='o')&&(yeni[k+2]=='r')&&(yeni[k+3]=='('))
        {
            sayac++;
            findis[p]=k;
            p++;
        }

        if( (yeni[k]=='w')&&(yeni[k+1]=='h')&&(yeni[k+2]=='i')&&(yeni[k+3]=='l')&&(yeni[k+4]=='e')&&(yeni[k+5]=='('))
        {
            wsayac++;
        }

        if((yeni[k] == '*') && ( (yeni[k+1] == ')') || (yeni[k+2] == ')') || (yeni[k+3] == ')')  || (yeni[k+4] == ')')   )   )
        {
            yildizSayac++;
        }
        if((yeni[k] == '/') && ( (yeni[k+1] == ')') || (yeni[k+2] == ')') || (yeni[k+3] == ')')  || (yeni[k+4] == ')')   )   )
        {
            bolmeSayac++;
        }

        if((yeni[k] == '*') && ( ((yeni[k+1] == ')') && (yeni[k+2] == '{')  &&  (yeni[k+3] == 'f') ) ||
                                 (  (yeni[k+2] == ')') &&   (yeni[k+3] == '{')  &&  (yeni[k+4] == 'f') ) || (  (yeni[k+3] == ')') &&  (yeni[k+4] == '{')  &&  (yeni[k+5] == 'f') ) ||
                                 ( (yeni[k+4] == ')')&&  (yeni[k+5] == '{')  &&  (yeni[k+6] == 'f') ) )   )
        {

            ikiliforYildizSayac++;
        }

        if((yeni[k] == '/') && ( ((yeni[k+1] == ')') && (yeni[k+2] == '{')  &&  (yeni[k+3] == 'f') ) ||
                                 (  (yeni[k+2] == ')') &&   (yeni[k+3] == '{')  &&  (yeni[k+4] == 'f') ) || (  (yeni[k+3] == ')') &&  (yeni[k+4] == '{')  &&  (yeni[k+5] == 'f') ) ||
                                 ( (yeni[k+4] == ')')&&  (yeni[k+5] == '{')  &&  (yeni[k+6] == 'f') ) )   )
        {

            ikiliforBolmeSayac++;
        }
    }

//printf("\n---------%d----------",ikiliforYildizSayac);


/*ic ice for dong�lerini dizi icerisinden tespit edebilmek icin daha �nce buldugumuz for dongulerinin indislerini kullanarak aralarindaki s�sl� parantez
sayilarini bulur ve bir dizi icerisine atar.*/
    int acparantez[100];
    int kapaparantez[100];
    int acparantezSayisi[100];
    int kapaparantezSayisi[100];

    int suslup1=0,suslup2=0;
    for(int cd =0; cd<sayac-1; cd++ )
    {
        for (int k = findis[cd]; k <findis[cd+1]; k++ )
        {
            if(yeni[k]=='}')
            {
                suslup1++;
            }

            if(yeni[k]=='{')
            {
                suslup2++;
            }
        }
        acparantez[cd] =suslup2;
        kapaparantez[cd]=suslup1;


 // printf("\nAcparantez toplm: %d Kapaparantez toplam: %d\n",acparantez[cd],kapaparantez[cd]);

        if(cd==0)
        {
            acparantezSayisi[0] = acparantez[0];
            kapaparantezSayisi[0]=kapaparantez[0];
        }
        else
        {
            acparantezSayisi[cd] = acparantez[cd]-acparantez[cd-1];
            kapaparantezSayisi[cd] = kapaparantez[cd]-kapaparantez[cd-1];
        }


// printf("\nAcparantez sayisi: %d Kapaparantez sayisi: %d\n",acparantezSayisi[cd],kapaparantezSayisi[cd]);



    }


    printf("----------------------------");

//ic ice iki forlu ve uc forlu dongu sayisini bulur.
    int iciceucluforSayisi=0;
    int iciceikiforludonguSayisi=0;
    for (int ab=0; ab<sayac-1; ab++)
    {
        if(acparantezSayisi[ab]== 1 && kapaparantezSayisi[ab]== 0 )
        {
            iciceikiforludonguSayisi++;

        }
        if (acparantezSayisi[ab]== 1 && acparantezSayisi[ab+1] == 1 && kapaparantezSayisi[ab]==0 && kapaparantezSayisi[ab+1] ==0)
        {

            iciceucluforSayisi++;
        }
    }
     //printf("------------%d-----------\n",iciceikiforludonguSayisi);
     //printf("------------%d-----------\n",iciceucluforSayisi);


   // printf("------------%d-----------",iciceikiliforSayisi);
     int iciceikiliforSayisi =iciceikiforludonguSayisi-(iciceucluforSayisi*2) ;


/*   for(int w=0;w<sayac;w++){
  printf("\nForun bulundugu indisler= %d ", findis[w]); } */


 //ic ice olmayan forlarin sayisini bulur.
    int tekliforSayisi = sayac-((iciceikiliforSayisi*2)+(iciceucluforSayisi*3));

//---------------------------------------------------------------
//ic ice ikili forlarin indislerini bulur.
    int ikiliforIndis1[100];
    int ikiliforIndis2[100];
    int op=0;
    int pr =0;
    for(int de =0; de<sayac-1; de++ )
    {
        for (int k = findis[de]; k <findis[de+1]; k++ )
        {
            if(  (yeni[k]=='{'&& yeni[k+1]=='f' ) && yeni[k]!='}')
            {
                ikiliforIndis1[op] = findis[de];
                ikiliforIndis2[pr] = findis[de+1];
                pr++;

                op++;
            }
        }

    }
  /*  for(int km =0; km<iciceikiliforSayisi; km++)
    {
        printf("\nikili forlarin indisleri: %d - %d\n",ikiliforIndis1[km],ikiliforIndis2[km]);

    }*/

//------------------------------------------------------
//BIGO NOTASYONU
    int sayac1=0;
    int sayac2 = 0;
    int sayac3=0;
    int sayac4 =0;
    int sayac5=0;


    //N^3
    if(iciceucluforSayisi!=0)
    {
        sayac1++;
        printf("\n\nZAMAN KARMASIKLIGI = BIG-O(N^3)\n");
    }

    //N^2
    if(iciceucluforSayisi==0 && iciceikiliforSayisi!=0 && iciceikiliforSayisi !=(ikiliforBolmeSayac+ikiliforYildizSayac) )
    {

        if(sayac1==0)
        {
            sayac2++;
            printf("\n\nZAMAN KARMASIKLIGI = BIG-O(N^2)\n");
        }
    }

    //Nlog(N)
    if (iciceikiliforSayisi != 0  && iciceucluforSayisi==0 &&  iciceikiliforSayisi == (ikiliforBolmeSayac+ikiliforYildizSayac) )
    {
        if(sayac1==0 && sayac2==0 )
        {
            sayac3++;
            printf("\n\nZAMAN KARMASIKLIGI = BIG-O(Nlog(N))\n");
        }

    }


    //N
    if(iciceucluforSayisi == 0 && iciceikiliforSayisi ==0 && (wsayac+sayac)!=( yildizSayac +bolmeSayac ) && (wsayac != 0 || sayac!=0))
    {
        if(sayac1==0 && sayac2==0 && sayac3 == 0)
        {
            sayac4++;
            printf("\n\nZAMAN KARMASIKLIGI = BIG-O(N)\n");
        }

    }
    //log(n)
    if(tekliforSayisi!= 0 && iciceikiliforSayisi==0 && iciceucluforSayisi==0 && (sayac+wsayac) == (yildizSayac+bolmeSayac) )
    {
        if( sayac1==0 && sayac2==0 && sayac3 == 0 && sayac4==0  )
        {
            sayac5++;
            printf("\n\nZAMAN KARMASIKLIGI = BIG-O(log(N))\n");

        }

    }

    //1
    if(iciceikiliforSayisi == 0 && iciceucluforSayisi == 0 && sayac==0 && wsayac==0)
    {
        if(sayac1==0 && sayac2==0 && sayac3 == 0 && sayac4==0 && sayac5==0 )
        {
            printf("\n\nZAMAN KARMASIKLIGI = BIG-O(1)\n");
        }

    }

//printf("\n%d\n%d\n%d\n%d\n %d\n",sayac1,sayac2,sayac3,sayac4,yildizSayac);
//-------------------------------------------------------------------------------------------


       //printf("\n%d n2 ", ( (iciceikiliforSayisi-ikiliforYildizSayac)-ikiliforBolmeSayac ) );
      // printf("\n%d N",  (tekliforSayisi-  ( (yildizSayac-ikiliforYildizSayac)+(bolmeSayac-ikiliforBolmeSayac)) )+wsayac  );
      // printf("\nDongudeki iciceler dahil toplam for sayisi=%d", sayac);
      // printf("\nDongudeki while sayisi=%d", wsayac);
      //printf("\nDongudeki LOG(N) sayisi=%d",(yildizSayac+bolmeSayac)-(ikiliforBolmeSayac+ikiliforYildizSayac));
      //printf("\nDongudeki NLOG(N) sayisi=%d\n\n",ikiliforYildizSayac+ikiliforBolmeSayac);
      // printf("%d-------%d\n\n",ikiliforYildizSayac,ikiliforBolmeSayac);
      //printf("%d-------%d\n\n",yildizSayac,bolmeSayac);


    dosya=fopen("tn.txt","a");
    //printf("\n\nYurutme Zamani T(N) = ");

    if(iciceucluforSayisi!=0)
    {
       // printf("+ %dN^3",iciceucluforSayisi);
        fprintf(dosya,"+ %dN^3 ",iciceucluforSayisi);
    }
    if( ( (iciceikiliforSayisi-ikiliforYildizSayac)-ikiliforBolmeSayac ) !=0)
    {
       // printf("+ %dN^2 ",( (iciceikiliforSayisi-ikiliforYildizSayac)-ikiliforBolmeSayac ));
        fprintf(dosya,"+ %dN^2 ",(( (iciceikiliforSayisi-ikiliforYildizSayac)-ikiliforBolmeSayac )));

    }
    if( (ikiliforYildizSayac+ikiliforBolmeSayac)!=0)
    {
       // printf("+ %dNLOG(N) ",( ikiliforBolmeSayac+ikiliforYildizSayac) );
        fprintf(dosya,"+ %dNLOG(N)",( ikiliforYildizSayac+ikiliforBolmeSayac )  );

    }

    if(tekliforSayisi-( (yildizSayac+bolmeSayac)-(ikiliforYildizSayac+ikiliforBolmeSayac))+wsayac!=0)
    {
       // printf("+ %dN ",(tekliforSayisi-  ( (yildizSayac-ikiliforYildizSayac)+(bolmeSayac-ikiliforBolmeSayac)) )+wsayac  );
        fprintf(dosya,"+ %dN ",(tekliforSayisi - ((yildizSayac-ikiliforYildizSayac)+(bolmeSayac-ikiliforBolmeSayac) ) ) +wsayac );

    }
    if( ( (yildizSayac+bolmeSayac)-(ikiliforBolmeSayac+ikiliforYildizSayac) )!=0 )
    {
      //  printf("+ %dLOGN ",(yildizSayac+bolmeSayac)-(ikiliforBolmeSayac+ikiliforYildizSayac));
        fprintf(dosya,"+ %dLOGN ",(yildizSayac+bolmeSayac)-(ikiliforBolmeSayac+ikiliforYildizSayac));

    }
    fclose(dosya);

}
int whileSay(int i)
{
    if (NULL != strstr(yeni, "do{"))
    {
    }
    /* for (int k = 0; k < i; k++)
     {  int indis;
         if((yeni[k]=='w')&&(yeni[k+1]=='h')&&(yeni[k+2]=='i')&&(yeni[k+3]!='l')&&(yeni[k+4]!='e'))
        {  k=k+5;
            while(yeni[k]!=')')
            {
                printf("**        %c",yeni[k]);
                k++;
            }
            break;
        }
    } */
}
int tn(int i)
{
    /* kodun tn deger� hesaplans�n d�ye yaz�lan fonks�yon */
    int ilkd=0,a,sayy,sayi=0;
    dosya=fopen("tn.txt","a+");
    /* ac parantez degeri bulunur tutulur  doger degerler bulunmaya o �nd�sten baslan�r
    tn deg� sat�r deegreler� ; say�m� yap�larak bulunur ger� kalan degerler kodun b�go
     karmas�kl�k degerler�nden al�n�r sonuc olarak genel tn deger� elde ed�lm�s olur */
    for (int a = 0; a < i; a++)
    {
        if(yeni[a]=='{')
        {
            ilkd=a;
            break;
        }
    }
    printf("\n");
    /* for (int a =ilkd; a <i;)
    {
        if(yeni[a]!=';')
        {
            printf("%c",yeni[a]);

        }
       a++;
    } */
    for (int a =ilkd; a <i;)
    {
        if(yeni[a]==';')
        {
            sayy++;
        }
        a++;

    }
    //printf("%d",sayy);

    for (int a = 0; a <i; a++)
    {
        if(yeni[a]=='f'&&yeni[a+1]=='o'&&yeni[a+2]=='r'&&yeni[a+3]=='(')
        {
            sayi++;
        }
    }
    tns=sayy-(sayi*2);
    //printf("tn = +%d",tns);
    fprintf(dosya,"+ %d ",tns);
    fclose(dosya);


}
int tnokuma()
{
    char tnoku[50],j=0;
    dosya=fopen("tn.txt","r");
    while (!feof(dosya))
    {
        tnoku[j] = fgetc(dosya);
        j++;
    }
    printf("\nYURUTME ZAMANI T(N) =");
    printf(" %s",tnoku);
    printf("\n");
    fclose(dosya);


}

int kodKontrol(int i)
/* okunan met�ndek� '(',')','{','}'say�lar� say�l�p kars�last�r�rl�r esitlik varsa syntax
dogru olur ve kodun b�g-o yer karmas�kl�g� ve tn degereler�n�n hesaplanmas� �c�n
gerekl� fonks�yonlara g�r�s yap�l�r eger else duserse yan� say�lan degereler�n gerekl� es�tl�g� saglanmazsa
syntax hatal� den�r ve degerler hesaplanmaz */
{
    int suslu1=0,suslu2=0,parantez1 = 0, parantez2=0;

    for (int k = 0; k < i; k++)
    {
        if(yeni[k]=='}')
        {
            suslu1++;
        }

        if(yeni[k]=='{')
        {
            suslu2++;
        }
        if(yeni[k]==')')
        {
            parantez1++;
        }

        if(yeni[k]=='(')
        {
            parantez2++;
        }
    }
    if(suslu1 == suslu2 && parantez1==parantez2 && suslu1!=0 && parantez1!=0)
    {
        printf("\nSyntax dogru, kodun karmasiklik degeri hesaplaniyor...\n\n");
        /*  syntax dogrudur ve fonks�yonlara g�r�l�p degerler hesaplan�r  */
        bigO(i);
        intSayac(i);
        whileSay(i);
        floatSayac(i);
        doubleSayac(i);
        longSayac(i);
        charSayac(i);
        karm();// yer karmas�kl�g�n� ekrana yazd�ran fonks�yon
        tn(i);
        tnokuma(i);

    }
    else
    {
        /*hesaplanan degerler es�t olmad�g� �c�n ekrana syntax hatal� uyar�s� bas�l�r */
        printf("Syntax hatali.");

    }
}

void dosyadanOkuma()
{
    int i = 0, b = 0;
    dosya = fopen("kod.txt", "r+");
    /* Dosyadan okuma islemi yap�l�r ac�lamazsa nulla duser.*/
    if (dosya == NULL)
    {
        printf("dosya acilamadi");
    }
    /* okunna degerler harfler dizisine atan�r.atama islemi yaparken \t \n space
    bolumler� silinir ve yen� adli farkli diziye atan�r b�ylece dizi elemanlar� aras�nda arama
    daha kolay sekilde yap�lm�s olur */
    else
    {
        while (!feof(dosya))
        {
            harfler[i] = fgetc(dosya);
            // strcpy(harfler[i],veri);
            i++;
        }
        for (int a = 0; a < i; a++)
        {
            if ((harfler[a] == '\n') || (harfler[a] == ' ') || (harfler[a] == '\t'))
            {
                //yeni[a] = ' ';
                continue;
            }
            else
            {
                yeni[b] = harfler[a];
                b++;
            }
        }
    }
    //printf("%s", yeni);
    //printf("\n--------------------\n");
    /* okunan met�n ekrana yazd�r�l�r */
    printf("KOD TARANIYOR...\n");
    printf("%s",harfler);
    printf("\n---------------------------\n");
    //okunanKod(yeni);

    /*  if (NULL != strstr(yeni, "for"))
     {printf("buldu");
      sayac++;} */
    /* kod kontrol fonks�yonu cag�r�l�r */
    kodKontrol(b);
}
/* void okunanKod(char yeni[] )
{

   dosya2=fopen("ana.c","w+");
    if (fwrite(harfler, strlen(harfler)-1, 1, dosya2) != 1) {
       printf("Dosyaya yazma hatas�!\n");
       exit(1);
   }
   // int i;
   // dosya2=fopen("ana.c","w+");

   //     while(harfler[i]!=NULL)
   //     {
   //         fwrite(harfler,1,"%c",dosya2);
   //     }

}  */
int main()
{
    dosyadanOkuma();
    remove("yerkarm.txt");
    remove("tn.txt");

    // okunanKod();
}
