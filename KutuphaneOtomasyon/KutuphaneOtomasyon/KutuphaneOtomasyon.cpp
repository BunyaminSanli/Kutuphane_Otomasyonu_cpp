/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			 BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**			    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				 PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI….....: 2 proje
**				ÖĞRENCİ ADI........: Bünyamin Şanlı
**				ÖĞRENCİ NUMARASI...: b181210040
**				DERS GRUBU.........: 1A
****************************************************************************/

#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <ctime>



using namespace std;


int main()
{
    setlocale(LC_ALL, "Turkish");
    int secim;

    int kitapSayisi;
    string uyeNo, tcNo, sorguTcNo, adi, soyadi, gorevi, telefon, tarih,
        isbn, yazarAdi, yazarSoyad, kitapAdi, sayfaSayisi, konu, tur, alisTarih, verisTarih, sorguIsbn, sorguVerisTarih;

    string satir = "";
    bool kosul = 0;

    do {

        //dosyalar tek tek acilir
        ofstream dosyaYazTmp("okuyucuTmp.txt", ios::app);
        ofstream dosyaYaz("okuyucu.txt", ios::app);
        ifstream dosyaOku("okuyucu.txt");

        ofstream kitapYaz("Kitaplar.txt", ios::app);
        ofstream kitapYazTmp("KitaplarTmp.txt", ios::app);
        ifstream kitapOku("Kitaplar.txt");

        ofstream oduncYaz("Odunc.txt", ios::app);
        ofstream oduncYazTmp("OduncTmp.txt", ios::app);
        ifstream oduncOku("Odunc.txt");

        //menu yazdırma islemi
        cout << "------ LUTFEN TURKCE KARAKTER VE BOSLUK KULLANMAYINIZ ------" << endl;
        cout << "1 - Okuyucu kaydi \n";
        cout << "2 - Okuyucu kaydi güncelleme\n";
        cout << "3 - Okuyucu silme(Okuyucu silindiğinde okuyucunun oduncleri geri dönmelidir.)\n";
        cout << "4 - Okuyucu üzerindeki kitaplar listesi\n";
        cout << "5 - Okuyucu kitap odunc alma\n";
        cout << "6 - Okuyucu kitap geri dondurme\n";
        cout << "7 - Kitap ekleme\n";
        cout << "8 - Kitap silme\n";
        cout << "9 - Kitap duzeltme\n";
        cout << "0 - Çıkış\n";

        //kullanicidan menu secimi aliriz ve ekranı temizleriz
        cin >> secim;
        system("cls");

        //secime gore gerekli switche gideriz
        switch (secim)
        {
            //case 1 okuyucu kadı yapar bilgileri alır ve dosyaya yazar
        case 1:
            cout << "********* Okuyucu Kaydı *********" << endl;

            cout << "TCNO" << endl;
            cin >> tcNo;

            cout << "ADI" << endl;
            cin >> adi;

            cout << "SOYADI" << endl;
            cin >> soyadi;

            cout << "UYE NO" << endl;
            cin >> uyeNo;

            cout << "TELEFON" << endl;
            cin >> telefon;

            cout << "DOGUM TARİHİ" << endl;
            cin >> tarih;

            cout << "GÖREVİ" << endl;
            cin >> gorevi;

            cout << "ALABİLECEĞİ KİTAP SAYİSİ" << endl;
            cin >> kitapSayisi;

            dosyaYaz << tcNo << " ";
            dosyaYaz << adi << " ";
            dosyaYaz << soyadi << " ";
            dosyaYaz << uyeNo << " ";
            dosyaYaz << telefon << " ";
            dosyaYaz << tarih << " ";
            dosyaYaz << gorevi << " ";
            dosyaYaz << kitapSayisi << "\n";


            dosyaYaz.close();

            break;


        case 2:
            //case 2 guncelleme yapar dosyayı bastan sona okur ve gecici dosyaya yazar daha sonra degistirilen de girilir ve dosyaya yazılıp eskisi silinir gecici yeniden adlandırılır
            dosyaYazTmp.clear();
            cout << "**** Okuyucu Kaydı Güncelleme ****" << endl;
            cout << "Güncellemek istediğiniz üyenin TC no'sunu giriniz.." << endl;
            cin >> tcNo;

            while (getline(dosyaOku, satir))
            {

                if (satir.find(tcNo) != string::npos)
                {
                    kosul = 1;
                }
                else
                {
                    dosyaYazTmp << satir << endl;
                }
            }

            if (kosul == 1)
            {
                cout << "TCNO" << endl;
                cin >> tcNo;

                cout << "ADI" << endl;
                cin >> adi;

                cout << "SOYADI" << endl;
                cin >> soyadi;

                cout << "UYE NO" << endl;
                cin >> uyeNo;

                cout << "TELEFON" << endl;
                cin >> telefon;

                cout << "DOGUM TARİHİ" << endl;
                cin >> tarih;

                cout << "GÖREVİ" << endl;
                cin >> gorevi;

                cout << "ALABİLECEĞİ KİTAP SAYİSİ" << endl;
                cin >> kitapSayisi;

                dosyaYazTmp << tcNo << " ";
                dosyaYazTmp << adi << " ";
                dosyaYazTmp << soyadi << " ";
                dosyaYazTmp << uyeNo << " ";
                dosyaYazTmp << telefon << " ";
                dosyaYazTmp << tarih << " ";
                dosyaYazTmp << gorevi << " ";
                dosyaYazTmp << kitapSayisi << "\n";


                dosyaOku.close();
                dosyaYaz.close();
                dosyaYazTmp.close();
                remove("okuyucu.txt");
                if (rename("okuyucuTmp.txt", "okuyucu.txt"))
                {
                    cout << "islem basarılı";
                }
            }
            else
            {
                cout << "\n güncellenecek kullanici bulunamadi" << endl;
            }
            dosyaOku.close();
            break;



        case 3:
            //kayıt silme islemi 
            dosyaYazTmp.clear();
            kosul = 0;
            cout << "****** Okuyucu Kaydı Silme ******" << endl;
            cout << "Silmek istediğiniz üyenin TC no'sunu giriniz.." << endl;
            cin >> tcNo;
            //tc alinir ve silme istenen kisi atlanarak baska dosyaya yazılır 
            while (getline(dosyaOku, satir))
            {

                if (satir.find(tcNo) != string::npos)
                {
                    kosul = 1;
                }
                else
                {
                    dosyaYazTmp << satir << endl;
                }
            }

            dosyaOku.close();
            dosyaYaz.close();
            dosyaYazTmp.close();
            //eski dosya sşlşnşr yeni dosyanın adı eski dosya yapılır
            if (kosul == 1)
            {
                remove("okuyucu.txt");
                if (rename("okuyucuTmp.txt", "okuyucu.txt"))
                {
                    cout << "islem basarılı";
                }
            }
            else
            {
                cout << "\n silmek istediğini kullanici bulunamadi" << endl;
            }


            dosyaOku.close();
            break;


        case 4:
            //odunc.txt dosyasından veri cekilip gosterilir
            cout << "** Okuyucu Üzerindeki Kitaplar  **" << endl;
            cout << "okuyucu tc no girin" << endl;
            cin >> sorguTcNo;

            while (oduncOku >> isbn >> tcNo >> alisTarih >> verisTarih)
            {

                if (sorguTcNo == tcNo)
                {
                    cout << "isbn:" << isbn << " tc no:" << tcNo << " alis tarih:" << alisTarih << " veris tarih:" << verisTarih << endl;
                }

            }
            break;


        case 5:
            //okuyucu tc ve isbn girilir kosullar sağlanıyorsa odunc txt ye yazılır ve kullanıcının kitap sayısı bir düşürülerek guncellenir
            kosul = 0;
            dosyaYazTmp.clear();
            cout << "**** Okuyucu Kitap Ödünç Alma ****" << endl;
            cout << "Ödünç alacak üye Tc no giriniz" << endl;
            cin >> sorguTcNo;

            cout << "Ödünç ainacak kitabın isbn no girin" << endl;
            cin >> sorguIsbn;

            cout << "Ödünç alınacak kitap tarihi giriniz" << endl;
            cin >> alisTarih;
            verisTarih = "0";

            while (dosyaOku >> tcNo >> adi >> soyadi >> uyeNo >> telefon >> tarih >> gorevi >> kitapSayisi)
            {

                if ((kitapSayisi > 0) && (sorguTcNo == tcNo))
                {
                    while (kitapOku >> isbn >> kitapAdi >> yazarAdi >> yazarSoyad >> konu >> tur >> sayfaSayisi)
                    {
                        if (sorguIsbn == isbn)
                        {
                            oduncYaz << isbn << " " << tcNo << " " << alisTarih << " " << verisTarih << endl;
                        }
                    }
                    dosyaYazTmp << tcNo << " ";
                    dosyaYazTmp << adi << " ";
                    dosyaYazTmp << soyadi << " ";
                    dosyaYazTmp << uyeNo << " ";
                    dosyaYazTmp << telefon << " ";
                    dosyaYazTmp << tarih << " ";
                    dosyaYazTmp << gorevi << " ";
                    dosyaYazTmp << kitapSayisi - 1 << "\n";
                }

                dosyaYazTmp << tcNo << " ";
                dosyaYazTmp << adi << " ";
                dosyaYazTmp << soyadi << " ";
                dosyaYazTmp << uyeNo << " ";
                dosyaYazTmp << telefon << " ";
                dosyaYazTmp << tarih << " ";
                dosyaYazTmp << gorevi << " ";
                dosyaYazTmp << kitapSayisi << "\n";

            }


            dosyaOku.close();
            dosyaYaz.close();
            dosyaYazTmp.close();
            remove("okuyucu.txt");
            if (rename("okuyucuTmp.txt", "okuyucu.txt"))
            {
                cout << "islem basarılı";
            }

            dosyaOku.close();

            break;


        case 6:
            //odunc.txt den veri çekilir ve geri donus tarihi girilen tc no lu uyenın veriş tarihi txt ye kaydedileir 
            dosyaYazTmp.clear();
            cout << "*** Okuyucu Kitap Geri Döndürme ***" << endl;
            cout << "kitap geri döndüren üye Tc no giriniz" << endl;
            cin >> sorguTcNo;


            cout << "Geri döndürülen kitap ISBN giriniz" << endl;
            cin >> sorguIsbn;

            cout << "tarih giriniz" << endl;
            cin >> sorguVerisTarih;


            while (oduncOku >> isbn >> tcNo >> alisTarih >> verisTarih)
            {

                if (sorguTcNo == tcNo && sorguIsbn == isbn)
                {
                    oduncYazTmp << isbn << " " << tcNo << " " << alisTarih << " " << sorguVerisTarih << endl;
                }
                else
                {
                    oduncYazTmp << isbn << " " << tcNo << " " << alisTarih << " " << verisTarih << endl;
                }
            }

            oduncOku.close();
            oduncYaz.close();
            oduncYazTmp.close();
            remove("Odunc.txt");
            if (rename("OduncTmp.txt", "Odunc.txt"))
            {
                cout << "islem basarılı";
            }
            oduncOku.close();

            //okuyucu kitap sayısı guncelleme islermi
            while (dosyaOku >> tcNo >> adi >> soyadi >> uyeNo >> telefon >> tarih >> gorevi >> kitapSayisi)
            {
                if (sorguTcNo == tcNo)
                {

                    while (getline(dosyaOku, satir))
                    {

                        if (satir.find(tcNo) != string::npos)
                        {

                        }
                        else
                        {
                            dosyaYazTmp << satir << endl;
                        }
                    }

                    dosyaYazTmp << tcNo << " ";
                    dosyaYazTmp << adi << " ";
                    dosyaYazTmp << soyadi << " ";
                    dosyaYazTmp << uyeNo << " ";
                    dosyaYazTmp << telefon << " ";
                    dosyaYazTmp << tarih << " ";
                    dosyaYazTmp << gorevi << " ";
                    dosyaYazTmp << kitapSayisi + 1 << "\n";


                    dosyaOku.close();
                    dosyaYaz.close();
                    dosyaYazTmp.close();
                    remove("okuyucu.txt");
                    if (rename("okuyucuTmp.txt", "okuyucu.txt"))
                    {
                        cout << "islem basarılı";
                    }


                    dosyaOku.close();
                }
            }
            break;


        case 7:
            //sisteme kitap eklemek icin kullanilir butun degerleri alarak txt ye kaydeder
            cout << "********** Kitap Ekleme **********" << endl;

            cout << "ISBN" << endl;
            cin >> isbn;

            cout << "KİTAP ADI" << endl;
            cin >> kitapAdi;

            cout << "YAZAR ADI" << endl;
            cin >> yazarAdi;

            cout << "YAZAR SOYADI" << endl;
            cin >> yazarSoyad;

            cout << "KONU" << endl;
            cin >> konu;

            cout << "TÜR" << endl;
            cin >> tur;

            cout << "SAYFA SAYISI" << endl;
            cin >> sayfaSayisi;



            kitapYaz << isbn << " ";
            kitapYaz << kitapAdi << " ";
            kitapYaz << yazarAdi << " ";
            kitapYaz << yazarSoyad << " ";
            kitapYaz << konu << " ";
            kitapYaz << tur << " ";
            kitapYaz << sayfaSayisi << "\n";



            kitapYaz.close();

            break;


        case 8:
            //kitap silme islemi satırlar dolasılırken girilmis isbn bulununca atlanarak baska dosyaya yazdırılır ve eski dosya silinir yeni dosyanın ismi eski dosya yapılır
            dosyaYazTmp.clear();
            cout << "********** Kitap Silme **********" << endl;
            cout << "Silmek istediğiniz kitabın ISBN giriniz.." << endl;
            cin >> sorguIsbn;

            dosyaYazTmp.clear();
            kosul = 0;



            while (getline(kitapOku, satir))
            {

                if (satir.find(sorguIsbn) != string::npos)
                {
                    kosul = 1;
                }
                else
                {
                    kitapYazTmp << satir << endl;
                }
            }

            kitapOku.close();
            kitapYaz.close();
            kitapYazTmp.close();
            if (kosul == 1)
            {
                remove("Kitaplar.txt");
                if (rename("KitaplarTmp.txt", "Kitaplar.txt"))
                {
                    cout << "islem basarılı";
                }
            }
            else
            {
                cout << "\n silmek istediğiniz kitap bulunamadi" << endl;
            }


            kitapOku.close();
            break;


        case 9:
            //kitap guncelleme islemi okuyucu guncellem eile aynıdır
            cout << "********* Kitap Düzeltme *********" << endl;

            kitapYazTmp.clear();

            cout << "Güncellemek istediğiniz kitabın ISBN giriniz.." << endl;
            cin >> sorguIsbn;

            while (getline(kitapOku, satir))
            {

                if (satir.find(sorguIsbn) != string::npos)
                {

                }
                else
                {
                    kitapYazTmp << satir << endl;
                }
            }

            cout << "ISBN" << endl;
            cin >> isbn;

            cout << "KİTAP ADI" << endl;
            cin >> kitapAdi;

            cout << "YAZAR ADI" << endl;
            cin >> yazarAdi;

            cout << "YAZAR SOYADI" << endl;
            cin >> yazarSoyad;

            cout << "KONU" << endl;
            cin >> konu;

            cout << "TÜR" << endl;
            cin >> tur;

            cout << "SAYFA SAYISI" << endl;
            cin >> sayfaSayisi;



            kitapYazTmp << isbn << " ";
            kitapYazTmp << kitapAdi << " ";
            kitapYazTmp << yazarAdi << " ";
            kitapYazTmp << yazarSoyad << " ";
            kitapYazTmp << konu << " ";
            kitapYazTmp << tur << " ";
            kitapYazTmp << sayfaSayisi << " \n";


            kitapOku.close();
            kitapYaz.close();
            kitapYazTmp.close();
            remove("Kitaplar.txt");
            if (rename("KitaplarTmp.txt", "Kitaplar.txt"))
            {
                cout << "islem basarılı";
            }

            kitapYazTmp.close();
            kitapOku.close();
            break;




        default:
            break;

        }//0 a basıldıgı zaman uyg durur 
    } while (secim != 0);



}






