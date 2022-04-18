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
    kullanılabılınsın dıye txt ye yazdırmak ıcın fopen komutu ıle txt dosyası acılır
    gereklı degerler karsılastırılmanın yapılabılınmesı ıcın 0 atanır.dızı sonun akada ',','=',
    '[',']' degerlerı hesaplanır.[ sayı degerı ] sayı degerıne esıtse dizi ya da matrıs vardır denılır
    ve bu esıtlık kullanılarak int[]veya int [][] olup olmadıgı bulunur ve buna gore yer
    karmasıklıgında hesaplanırken kullanılıcak forma getırılır.eger vırgul degerı sifirsa -1 e esıtlenır
    islem yaparken olusan karısıklıgın onlenmesı ıcın . tum bu hesaplamalardan sonra genel int sayısı
    bulunur eger bulunan ınt sayısı sıfırdan farklıysa basılması gereken degerler ekrana bastırırlır
    ve bu degerler yer karmasıklıgı hesabında da kullanılsın dıye txt ye yazdırılır.acılan dosya
    fclose komutuyla kapatılır*/
    int sayacInt=0;
    dosya3=fopen("yerkarm.txt","a+");
    int a=0,isayisi=0,byte;//sayi degerleri byte ile carpılıp  kapladıgı byte degeri bulundu
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
    /* int degerlerın byte toplamı bulunurken yapılan ıslemler float ıcın de yapılır
    fark olarak float byte degerı farklı atanır ve ona gore hesap yapılır  */
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
    /* int degerlerın byte toplamı bulunurken yapılan ıslemler double degerler ıcın de yapılır
    fark olarak double byte(8 byte)degerı farklı atanır ve ona gore hesap yapılır  */
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
    /* int degerlerın byte toplamı bulunurken yapılan ıslemler long degerler ıcın de yapılır
    fark olarak long byte(4 byte)degerı farklı atanır ve ona gore hesap yapılır  */
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
    /* int degerlerın byte toplamı bulunurken yapılan ıslemler char degerler ıcın de yapılır
    fark olarak char byte(1 byte)degerı farklı atanır ve ona gore hesap yapılır  */
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
    /* intSayac,floatSayac,doubleSayac,longSayac,charSayac fonksıyonlarında bulunup
    yerkarm.txt ye yazdırılan degerler okutulur ve kodun yer karmasıklıgı degerı
    ekrana yazdırılır  */
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
    int findis[100];  // dizide bulunan for dongülerinin indislerini tutar.
    int p = 0;
    int yildizSayac =0; //bütün for parantezleri icerisindeki yildizlari sayar.
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


/*ic ice for dongülerini dizi icerisinden tespit edebilmek icin daha önce buldugumuz for dongulerinin indislerini kullanarak aralarindaki süslü parantez
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
    /* kodun tn degerı hesaplansın dıye yazılan fonksıyon */
    int ilkd=0,a,sayy,sayi=0;
    dosya=fopen("tn.txt","a+");
    /* ac parantez degeri bulunur tutulur  doger degerler bulunmaya o ındısten baslanır
    tn degı satır deegrelerı ; sayımı yapılarak bulunur gerı kalan degerler kodun bıgo
     karmasıklık degerlerınden alınır sonuc olarak genel tn degerı elde edılmıs olur */
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
/* okunan metındekı '(',')','{','}'sayıları sayılıp karsılastırırlır esitlik varsa syntax
dogru olur ve kodun bıg-o yer karmasıklıgı ve tn degerelerının hesaplanması ıcın
gereklı fonksıyonlara gırıs yapılır eger else duserse yanı sayılan degerelerın gereklı esıtlıgı saglanmazsa
syntax hatalı denır ve degerler hesaplanmaz */
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
        /*  syntax dogrudur ve fonksıyonlara gırılıp degerler hesaplanır  */
        bigO(i);
        intSayac(i);
        whileSay(i);
        floatSayac(i);
        doubleSayac(i);
        longSayac(i);
        charSayac(i);
        karm();// yer karmasıklıgını ekrana yazdıran fonksıyon
        tn(i);
        tnokuma(i);

    }
    else
    {
        /*hesaplanan degerler esıt olmadıgı ıcın ekrana syntax hatalı uyarısı basılır */
        printf("Syntax hatali.");

    }
}

void dosyadanOkuma()
{
    int i = 0, b = 0;
    dosya = fopen("kod.txt", "r+");
    /* Dosyadan okuma islemi yapılır acılamazsa nulla duser.*/
    if (dosya == NULL)
    {
        printf("dosya acilamadi");
    }
    /* okunna degerler harfler dizisine atanır.atama islemi yaparken \t \n space
    bolumlerı silinir ve yenı adli farkli diziye atanır böylece dizi elemanları arasında arama
    daha kolay sekilde yapılmıs olur */
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
    /* okunan metın ekrana yazdırılır */
    printf("KOD TARANIYOR...\n");
    printf("%s",harfler);
    printf("\n---------------------------\n");
    //okunanKod(yeni);

    /*  if (NULL != strstr(yeni, "for"))
     {printf("buldu");
      sayac++;} */
    /* kod kontrol fonksıyonu cagırılır */
    kodKontrol(b);
}
/* void okunanKod(char yeni[] )
{

   dosya2=fopen("ana.c","w+");
    if (fwrite(harfler, strlen(harfler)-1, 1, dosya2) != 1) {
       printf("Dosyaya yazma hatası!\n");
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
