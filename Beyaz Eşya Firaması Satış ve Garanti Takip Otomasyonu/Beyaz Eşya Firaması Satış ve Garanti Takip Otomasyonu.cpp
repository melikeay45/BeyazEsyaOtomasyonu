#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
class urun
{
public:
	string urunID;
	string gun;
	string ay;
	string yil;
	int sayac = 0;
	string urunAd;
	string urunSahibi;
	string urunSahibiadresi;
	void veriekleme();
	void verilisteleme();
	void veriguncelleme();
	void veriarama(string);
	void verisilme(string);
	void kayitsayisi();

	urun(string urunId, string Gun, string Ay, string Yil, string urunad, string urunsahibi, string urunsahibiadresi) {
		urunID = urunId;
		gun = Gun;
		ay = Ay;
		yil = Yil;
		urunAd = urunad;
		urunSahibi = urunsahibi;
		urunSahibiadresi = urunsahibiadresi;
	}
	urun() {}

};

void urun::kayitsayisi() {
	sayac++;
}
void urun::veriekleme() {
	ofstream veriyaz;
	veriyaz.open("beyazesya.txt", ios::app);
	veriyaz << sayac << "    " << urunID << "    ";
	veriyaz << urunAd << "    ";
	veriyaz << urunSahibi << "    ";
	veriyaz << urunSahibiadresi << "         ";
	veriyaz << "Ürünün Satış Tarihi : " << gun << " / ";
	veriyaz << ay << " / ";
	veriyaz << yil << endl;
	cout << "Eğer bu urunun garanti bilgilerini eklemek isterseniz işlemler kısmından 2 yi seciniz." << endl;
	cout << "Eğer bu urunun servis bilgilerini eklemek isterseniz işlemler kısmından 3 ü seciniz." << endl;

}

void urun::verilisteleme() {
	ifstream verilisteleme;
	verilisteleme.open("beyazesya.txt");
	string satir;
	while (getline(verilisteleme, satir)) {
		cout << satir << endl;
	}
}

void urun::veriarama(string _aranan) {
	string okunan, aranan;
	int uzunluk1, uzunluk2, kat = 0;
	ifstream verioku;
	verioku.open("beyazesya.txt", ios::in);
	aranan = _aranan;
	while (!verioku.eof()) {
		getline(verioku, okunan);
		uzunluk1 = okunan.length();
		uzunluk2 = aranan.length();
		for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
			if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
				cout << "Aranan kayit:" << endl;
				cout << okunan << endl;
				kat++;
			}
		}
	}
	if (kat == 0)
		cout << "Aranan kayıt bulunamadi." << endl;
	verioku.close();
	aranan = urunID;
}

void urun::verisilme(string _aranan) {
	string okunan, aranan, yazma;
	int uzunluk1, uzunluk2, kat = 0;
	ifstream verioku;
	ofstream veriyaz;
	verioku.open("beyazesya.txt");
	veriyaz.open("gecici.tmp");
	aranan = _aranan;
	while (!verioku.eof()) {
		getline(verioku, okunan);
		uzunluk1 = okunan.length();
		uzunluk2 = aranan.length();
		for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
			if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
				cout << okunan << endl;
				yazma = okunan;
				kat++;
			}
		}

		if (yazma == okunan) {
		}
		else
			veriyaz << okunan << endl;;
	}
	if (kat >= 1) {

		verioku.close();
		veriyaz.close();

		remove("beyazesya.txt");
		rename("gecici.tmp", "beyazesya.txt");
	}
	else
		cout << "Yanlis id girdiniz." << endl;
}



void urun::veriguncelleme() {
	string okunan, aranan, yazma;
	int uzunluk1, uzunluk2, kat = 0;
	ifstream verioku;
	ofstream veriyaz;
	string urun_adi;
	string urun_sahibi;
	string urun_sahibi_adresi;
	string urun_id;
	string urun_gun;
	string urun_ay;
	string urun_yil;
	verioku.open("beyazesya.txt");
	veriyaz.open("gecici.tmp");
	cout << "Guncellemek istediginiz urunun id numarasini giriniz: ";
	cin >> aranan;
	while (!verioku.eof()) {

		getline(verioku, okunan);
		uzunluk1 = okunan.length();
		uzunluk2 = aranan.length();
		for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
			if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
				cout << okunan << endl;
				yazma = okunan;
				kat++;
			}
			if (yazma != okunan) {
				yazma = "yenile";
			}
		}

		if (yazma == okunan) {
			cin.ignore();
			cout << "Urunun guncel id numarasını giriniz : ";
			getline(cin, urun_id);
			cout << "Urunun guncel ismini giriniz : ";
			getline(cin, urun_adi);
			cout << "Urunun guncel sahibini giriniz : ";
			getline(cin, urun_sahibi);
			cout << "Urunun sahibinin guncel adresini giriniz : ";
			getline(cin, urun_sahibi_adresi);
			cout << "Urunun satis tarihini güncelleyiniz gün ay yil olarak giriniz..." << endl;
			cout << "Urunun satis gununu giriniz : ";
			cin >> urun_gun;
			cout << "Urunun satis ayini giriniz : ";
			cin >> urun_ay;
			cout << "Urunun satis yilini giriniz : ";
			cin >> urun_yil;
			veriyaz << sayac + 1 << "     " << urun_id << "    " << urun_adi << "    " << urun_sahibi << "    " << urun_sahibi_adresi << "   " << urun_gun << " / " << urun_ay << " / " << urun_yil << endl;
			cout << "Urun bilgileri güllendi." << endl;
		}
		else
		{
			veriyaz << okunan << endl;
		}

	}
	if (kat == 1) {

		verioku.close();
		veriyaz.close();

		remove("beyazesya.txt");//dosyayi sildim.
		rename("gecici.tmp", "beyazesya.txt");//Gecici dosyalar kayıt silindikten tmp dosyasi txt dosyasina aktarılır.
	}
	else
		cout << "Yanlis id girdiniz" << endl;
}
class garanti :public urun {
public:
	string id;
	char secim;
	int gar_suresi;
	string garantibaslangic_gun;
	string garantibaslangic_ay;
	string garantibaslangic_yil;

	~garanti() {
		cout << "İşleminiz / işlemleriniz gerçekleşmiştir." << endl;
	}

	void garantibilgisiekle() {
		ofstream veriyaz;
		veriyaz.open("garanti.txt", ios::app);
		cout << "Ürünün İD numararını giriniz.";
		cin >> id;
		veriyaz << id << "     ";
		cout << "urunun garanti süresini giriniz : ";
		cin >> gar_suresi;
		veriyaz << "Garanti Suresi = " << gar_suresi << "     ";
		cout << "Ürünün garanti başlangıç tarihini gün / ay / yıl şeklinde giriniz." << endl;
		cout << "Ürünün Garanti Baslangıç Gununu Giriniz : ";
		cin >> garantibaslangic_gun;
		cout << "Ürünün Garanti Baslangıç Ayını Giriniz : ";
		cin >> garantibaslangic_ay;
		cout << "Ürünün Garanti Baslangıç Yılını Giriniz : ";
		cin >> garantibaslangic_yil;
		veriyaz << "Garanti Başlangıç tarihi = " << garantibaslangic_gun << " / " << garantibaslangic_ay << " / " << garantibaslangic_yil << endl;

	}
	void garantibilgisilisteleme() {
		ifstream verilisteleme;
		verilisteleme.open("garanti.txt");
		string satir;
		while (getline(verilisteleme, satir)) {
			cout << satir << endl;
		}
	}

	void garantibilgisiarama() {


		string okunan, aranan;
		cout << "Garanti bilgilerini aramak istediğiniz ürünün ID numarasını giriniz : ";
		cin >> aranan;
		urun::veriarama(aranan);
		int uzunluk1, uzunluk2, kat = 0;
		ifstream verioku;
		verioku.open("garanti.txt", ios::in);
		while (!verioku.eof()) {
			getline(verioku, okunan);
			uzunluk1 = okunan.length();
			uzunluk2 = aranan.length();
			for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
				if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
					cout << "Garanti Bilgileri :" << endl;
					cout << okunan << endl;
					kat++;
				}
			}
		}

		verioku.close();
	}

	void garantibilgisisilme(string _aranan) {
		string okunan, aranan, yazma;
		int uzunluk1, uzunluk2, kat = 0;
		ifstream verioku;
		ofstream veriyaz;
		verioku.open("garanti.txt");
		veriyaz.open("gecici.tmp");
		aranan = _aranan;
		while (!verioku.eof()) {
			getline(verioku, okunan);
			uzunluk1 = okunan.length();
			uzunluk2 = aranan.length();
			for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
				if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
					cout << okunan << endl;
					yazma = okunan;
					kat++;
				}
			}

			if (yazma == okunan) {
			}
			else
				veriyaz << okunan << endl;;
		}
		if (kat >= 1) {

			verioku.close();
			veriyaz.close();

			remove("garanti.txt");
			rename("gecici.tmp", "garanti.txt");
		}
		else
			cout << "Yanlis id girdiniz." << endl;
	}

	void garantibilgisiguncelleme() {
		string okunan, aranan, yazma;
		int uzunluk1, uzunluk2, kat = 0;
		ifstream verioku;
		ofstream veriyaz;
		string urun_garantisuresi;
		string urun_garantibaslangic_gun;
		string urun_garantibaslangic_ay;
		string urun_garantibaslangic_yil;
		string urun_sahibi_adresi;
		string urun_id;
		verioku.open("garanti.txt");
		veriyaz.open("gecici.tmp");
		cout << "Guncellemek istediginiz urunun id numarasini giriniz: ";
		cin >> aranan;
		while (!verioku.eof()) {

			getline(verioku, okunan);
			uzunluk1 = okunan.length();
			uzunluk2 = aranan.length();
			for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
				if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
					cout << okunan << endl;
					yazma = okunan;
					kat++;
				}
				if (yazma != okunan) {
					yazma = "yenile";
				}
			}

			if (yazma == okunan) {
				cin.ignore();
				cout << "Urunun guncel id numarasını giriniz : ";
				cin >> urun_id;
				cout << "Ürünün Güncel Garanti Süresini Giriniz : ";
				cin >> urun_garantisuresi;
				cout << "Ürünün güncel garanti başlangıç tarihini gün ay yıl şeklinde giriniz. " << endl;
				cout << "Gününü Giriniz : ";
				cin >> urun_garantibaslangic_gun;
				cout << "Ayını Giriniz : ";
				cin >> urun_garantibaslangic_ay;
				cout << "Yılını Giriniz : ";
				cin >> urun_garantibaslangic_yil;
				veriyaz << urun_id << "     Garanti Süresi = " << urun_garantisuresi << "     Garanti Başlangıç Tarihi = " << urun_garantibaslangic_gun << " / " << urun_garantibaslangic_ay << " / " << urun_garantibaslangic_yil << endl;
				cout << "Garanti Bilgileri Güncellendi." << endl;
			}
			else
			{
				veriyaz << okunan << endl;
			}

		}
		if (kat >= 1) {

			verioku.close();
			veriyaz.close();

			remove("garanti.txt");//dosyayi sildim.
			rename("gecici.tmp", "garanti.txt");//Gecici dosyalar kayıt silindikten tmp dosyasi txt dosyasina aktarılır.
		}
		else
			cout << "Yanlis id girdiniz" << endl;
	}

	friend void garantihesapla(string);
};
void garantihesapla(string k) {
	int satistarihi_gun;
	int satistarihi_ay;
	int satistarihi_yil;
	int garantibitis_gun;
	int garantibitis_ay;
	int garantibitis_yil;
	int garanti_suresi;
	string okunan, aranan;
	aranan = k;
	int uzunluk1, uzunluk2, kat = 0;
	ifstream verioku;
	verioku.open("beyazesya.txt", ios::in);
	while (!verioku.eof()) {
		getline(verioku, okunan);
		uzunluk1 = okunan.length();
		uzunluk2 = aranan.length();
		for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
			if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
				cout << "urun:" << endl;
				cout << okunan << endl;
				kat++;
			}
		}
	}
	if (kat == 0) {
		cout << "Aranan kayıt bulunamadi." << endl;
		verioku.close();
	}
	else {
		int uzunluk3, uzunluk4, kat = 0;
		ifstream verioku;
		verioku.open("garanti.txt", ios::in);
		aranan = k;
		while (!verioku.eof()) {
			getline(verioku, okunan);
			uzunluk1 = okunan.length();
			uzunluk2 = aranan.length();
			for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
				if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
					cout << okunan << endl;
				}
			}
		}


		cout << "Ekranda yazan garanti süresini giriniz : ";
		cin >> garanti_suresi;
		cout << "Ekranda yazan ürünün garanti başlangıç tarihini gün ay yil şeklinde giriniz. " << endl;
		cout << "Gününü Giriniz : ";
		cin >> satistarihi_gun;
		cout << "Ayını Giriniz : ";
		cin >> satistarihi_ay;
		cout << "Yılını Giriniz : ";
		cin >> satistarihi_yil;

		garantibitis_gun = satistarihi_gun + garanti_suresi;
		if (garantibitis_gun >= 30) {
			garantibitis_ay = satistarihi_ay + (garantibitis_gun / 30);
			garantibitis_gun = garantibitis_gun % 30;
			if (garantibitis_ay >= 12) {
				garantibitis_yil = satistarihi_yil + (garantibitis_ay / 12);
				garantibitis_ay = garantibitis_ay % 12;
			}
			else
				garantibitis_yil = satistarihi_yil;
		}
		else {
			garantibitis_ay = satistarihi_ay;
			garantibitis_yil = satistarihi_yil;
		}
		cout << "Urunun garanti bitis tarihi : " << garantibitis_gun << " / " << garantibitis_ay << " / " << garantibitis_yil << endl;;
		verioku.close();

	}
}
class servis :public urun {
public:
	string urun_ID;
	string urunkurulum_gunu;
	string urunkurulum_ayi;
	string urunkurulum_yili;
	string urunkuran_calisan;


	void servisbilgisiekle() {
		ofstream veriyaz;
		veriyaz.open("servis.txt", ios::app);
		cout << "Urun Id giriniz : ";
		cin >> urunID;
		cin.ignore();
		veriyaz << urunID << "    ";
		cout << "Urunu Kuran Calısanın Adini Giriniz :";
		getline(cin, urunkuran_calisan);
		veriyaz << "Ürünü Kuran Çalışanın Adı = " << urunkuran_calisan << "    ";
		cout << "Ürünün kuruluş tarihini gün ay yıl şeklinde giriniz. " << endl;
		cout << "Ürünün Kuruluş Gününü giriniz : ";
		cin >> urunkurulum_gunu;
		veriyaz << "Ürünün Kuruluş Tarihi = " << urunkurulum_gunu << " / ";
		cout << "Ürünün Kuruluş Ayını Giriniz : ";
		cin >> urunkurulum_ayi;
		veriyaz << urunkurulum_ayi << " / ";
		cout << "Ürünün Kuruluş Yılını Giriniz : ";
		cin >> urunkurulum_yili;
		veriyaz << urunkurulum_yili << endl;
	}

	void servisbilgisiara() {
		string aranan, okunan;
		cout << "Servis bilgilerini aramak istediğiniz ürünün ID numarasını giriniz : ";
		cin >> aranan;
		urun::veriarama(aranan);
		int uzunluk1, uzunluk2, kat = 0;
		ifstream verioku;
		verioku.open("servis.txt", ios::in);
		while (!verioku.eof()) {
			getline(verioku, okunan);
			uzunluk1 = okunan.length();
			uzunluk2 = aranan.length();
			for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
				if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
					cout << "Servis Bilgileri : " << endl << okunan << endl;
					kat++;
				}
			}
		}

		verioku.close();

	}

	void servibilgilerinilistele() {
		ifstream verilisteleme;
		verilisteleme.open("servis.txt");
		string satir;
		while (getline(verilisteleme, satir)) {
			cout << satir << endl;
		}
	}

	void servisbilgilerinisil(string _aranan) {
		string okunan, aranan, yazma;
		int uzunluk1, uzunluk2, kat = 0;
		ifstream verioku;
		ofstream veriyaz;
		verioku.open("servis.txt");
		veriyaz.open("gecici.tmp");
		aranan = _aranan;
		while (!verioku.eof()) {
			getline(verioku, okunan);
			uzunluk1 = okunan.length();
			uzunluk2 = aranan.length();
			for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
				if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
					cout << okunan << endl;
					yazma = okunan;
					kat++;
				}
			}

			if (yazma == okunan) {
			}
			else
				veriyaz << okunan << endl;;
		}
		if (kat >= 1) {

			verioku.close();
			veriyaz.close();

			remove("servis.txt");
			rename("gecici.tmp", "servis.txt");
		}
		else
			cout << "Yanlis id girdiniz." << endl;
	}

	void servisbilgileriniguncelle() {
		string okunan, aranan, yazma;
		int uzunluk1, uzunluk2, kat = 0;
		ifstream verioku;
		ofstream veriyaz;
		string urun_iD;
		string urun_kurancalisan;
		string urun_kurulumgun;
		string urun_kurulumay;
		string urun_kurulumyil;
		verioku.open("servis.txt");
		veriyaz.open("gecici.tmp");
		cout << "Guncellemek istediginiz urunun id numarasini giriniz: ";
		cin >> aranan;
		while (!verioku.eof()) {

			getline(verioku, okunan);
			uzunluk1 = okunan.length();
			uzunluk2 = aranan.length();
			for (int i = 0; i < (uzunluk1 - uzunluk2); i++) {
				if (aranan.compare(okunan.substr(i, uzunluk2)) == 0) {
					cout << okunan << endl;
					yazma = okunan;
					kat++;
				}
				if (yazma != okunan) {
					yazma = "yenile";
				}
			}

			if (yazma == okunan) {
				cin.ignore();
				cout << "Ürünün Güncel İD Numarasını Giriniz = ";
				getline(cin, urun_iD);
				cout << "Ürünü kuran güncel çalışanın ismini giriniz : ";
				getline(cin, urun_kurancalisan);
				cout << "Urunun kurulum tarihini güncelleyiniz gün ay yil olarak giriniz..." << endl;
				cout << "Urunun kurulum gununu giriniz : ";
				getline(cin, urun_kurulumgun);
				cout << "Urunun kurulum ayini giriniz : ";
				getline(cin, urun_kurulumay);
				cout << "Urunun kurulum yilini giriniz : ";
				getline(cin, urun_kurulumyil);
				veriyaz << urun_iD << "    Ürünü Kuran Çalışanın Adı = " << urun_kurancalisan << "    Ürünün Kuruluş Tarihi = " << urun_kurulumgun << " / " << urun_kurulumay << " / " << urun_kurulumyil << endl;
				cout << "Servis Bilgileri Güllendi." << endl;
			}
			else
			{
				veriyaz << okunan << endl;
			}

		}
		if (kat == 1) {

			verioku.close();
			veriyaz.close();

			remove("servis.txt");//dosyayi sildim.
			rename("gecici.tmp", "servis.txt");//Gecici dosyalar kayıt silindikten tmp dosyasi txt dosyasina aktarılır.
		}
		else
			cout << "Yanlis id girdiniz" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Turkish");
	char devam;
	int islem;
	urun beyazesya;
	garanti garanti1;
	servis servis1;
	string urun_id;
	string satisgunu;
	string satisayi;
	string satisyili;
	string adi_urun;
	string sahibi_urun;
	string sahibiadresi_urun;
	string aranan_;

	do {
		cout << "1 - Ürün Ekle" << endl;
		cout << "2 - Garanti Bilgisi Ekle" << endl;
		cout << "3 - Servis Bilgisi Ekle" << endl;
		cout << "4 - Ürünleri Listele " << endl;
		cout << "5 - Ürünlerin Garanti Bilgilerini Listele " << endl;
		cout << "6 - Ürünlerin Servis Bilgilerini Listele " << endl;
		cout << "7 - Ürün Ara" << endl;
		cout << "8 - Ürünün Garanti Bilgisini Ara" << endl;
		cout << "9 - Ürünün servis Bilgisini Ara" << endl;
		cout << "10 - Ürünün Garanti Bitiş Tarihini Öğrenme" << endl;
		cout << "11 - Ürünün Bilgilerini Güncelle" << endl;
		cout << "12 - Ürünün Garanti Bilgilerini Güncelle" << endl;
		cout << "13 - Ürünün Servis Bilgilerini Güncelle" << endl;
		cout << "14 - Kayıtlı Ürünü Silme" << endl;
		cout << "15 - Kayıtlı Ürünün Garanti Bilgilerini Silme" << endl;
		cout << "16 - Kayıtlı Ürünün Servis Bilgilerini Silme" << endl;
		cin >> islem;
		switch (islem) {
		case 1: {
			cout << "Kayit Ekleme İslemi..." << endl;
			cout << "Ürünün ID Numarasını giriniz : ";
			cin >> urun_id;
			cin.ignore();
			cout << "Ürünün Adını Giriniz :";
			getline(cin, adi_urun);
			cout << "Ürünü Satın Alan Kişinin İsmini Giriniz : ";
			getline(cin, sahibi_urun);
			cout << "Ürünü Satın Alan Kişinin Adresini Giriniz : ";
			getline(cin, sahibiadresi_urun);
			cout << "Ürünün satış tarihini gün ay yıl şeklinde giriniz. " << endl;
			cout << "Ürünün Satış Gününü Giriniz : ";
			cin >> satisgunu;
			cout << "Ürünün Satıldığı Ayı Giriniz : ";
			cin >> satisayi;
			cout << "Ürünün Satıldığı Yılı Giriniz : ";
			cin >> satisyili;
			urun beyazesya1(urun_id, satisgunu, satisayi, satisyili, adi_urun, sahibi_urun, sahibiadresi_urun);
			beyazesya1.kayitsayisi();
			beyazesya1.veriekleme(); }
			  break;
		case 2:
			cout << "Garanti Bilgisi Ekleme İşlemi..." << endl;
			garanti1.garantibilgisiekle();
			break;
		case 3:
			cout << "Garanti Bilgisi Ekleme İşlemi..." << endl;
			servis1.servisbilgisiekle();
			break;
		case 4:
			cout << "Ürünleri Listeleme İşlemi..." << endl;
			beyazesya.verilisteleme();
			break;
		case 5:
			cout << "Ürünlerin Garanti Bilgilerini Lİsteleme İşlemi..." << endl;
			garanti1.garantibilgisilisteleme();
			break;
		case 6:
			cout << "Ürünlerin Servis Bilgilerini Lİsteleme İşlemi..." << endl;
			servis1.servibilgilerinilistele();
			break;
		case 7:
			cout << "Ürün Sorgulama İşlemi..." << endl;
			cout << "Aramak istediğiniz ürünün id numarasını giriniz : " << endl;
			cin >> aranan_;
			beyazesya.veriarama(aranan_);
			break;

		case 8:
			cout << "Ürünün Garanti Bilgisini Sorgulama İşlemi..." << endl;
			garanti1.garantibilgisiarama();
			break;
		case 9:
			cout << "Ürünün Servis Bilgisini Sorgulama İşlemi..." << endl;
			servis1.servisbilgisiara();
			break;
		case 10:
			cout << "Ürünün Garanti Bitiş Günü..." << endl;
			cout << "Garanti bitiş gününü öğrenmek istediginiz urunun id no giriniz : ";
			cin >> aranan_;
			garantihesapla(aranan_);
			break;
		case 11:
			cout << "Ürün Bilgisi Güncelleme İşlemi..." << endl;
			beyazesya.veriguncelleme();
			break;
		case 12:
			cout << "Ürünün Garanti Bilgilerini Güncelleme İşlemi..." << endl;
			garanti1.garantibilgisiguncelleme();
			break;
		case 13:
			cout << "Ürünün Servis Bilgilerini Güncelleme İşlemi..." << endl;
			servis1.servisbilgileriniguncelle();
			break;
		case 14:
			cout << "Kayıtlı Ürünü Silme İşlemi..." << endl;
			cout << "Silmek istediginiz urunun id numarasini giriniz: ";
			cin >> aranan_;
			beyazesya.verisilme(aranan_);
			break;
		case 15:
			cout << "Kayıtlı Ürünün Garanti Bilgilerini Silme İşlemi..." << endl;
			cout << "Silmek istediginiz urunun id numarasini giriniz: ";
			cin >> aranan_;
			garanti1.garantibilgisisilme(aranan_);
			break;
		case 16:
			cout << "Kayıtlı Ürünün Servis Bilgilerini Silme İşlemi..." << endl;
			cout << "Servis bilgisini silmek istediginiz urunun id numarasini giriniz: ";
			cin >> aranan_;
			servis1.servisbilgilerinisil(aranan_);
			break;
		default:
			cout << "Yanlis Secim yaptiniz." << endl;
			break;
		}
		cout << "Devam etmek ister misiniz? (E/H)" << endl;
		cin >> devam;
	} while (devam == 'E' || devam == 'e');
	return 0;

}
