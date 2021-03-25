#include<iostream>
using namespace std;

int* dizi;
int boyut = 15;
int cnt = 0;
int sil = -1;
int bos = -2;

int hash_hesapla(int x)
{
	return x % boyut;
}

void ekle(int x)
{
	int hash_indis = hash_hesapla(x);
	if (cnt == boyut)
		cout << "Hash Table Dolu" << endl;

	else
	{
		while (dizi[hash_indis] != bos && dizi[hash_indis] != sil)
		{
			hash_indis++;
			if (hash_indis == boyut)
				hash_indis = 0;
		}
		dizi[hash_indis] = x;
		cnt++;
	}
}

int bul(int x)
{
	int hash_indis = hash_hesapla(x);
	int baslangic = hash_indis;

	while (dizi[hash_indis] != x || dizi[hash_indis] == sil)
	{
		if (dizi[hash_indis] == bos)
		{
			cout << "Aranan Eleman -->" << x << " | Eleman Yok" << endl;
			return NULL;
		}
		hash_indis++;
		if (hash_indis == boyut)
			hash_indis = 0;
		if (baslangic == boyut)
		{
			cout << "Tablo Bos" << endl;
			return NULL;
		}
	}
	if (dizi[hash_indis] == x)
		return hash_indis;
}

void silme(int x)
{
	cout << "Silinecek Eleman -->" << x << " | ";
	int y = bul(x);
	if (y != NULL)
		dizi[y] = sil;
}

void yaz()
{
	for (int i = 0; i < boyut; i++)
	{
		if (dizi[i] != bos)
			cout << i << ".indis=\t" << dizi[i] << endl;
		else
			cout << i << ".indis=\t" << "-" << endl;
	}
	system("pause");
}

int main()
{
	dizi = new int[boyut];
	for (int i = 0; i < boyut; i++)
		dizi[i] = bos;
	ekle(7);
	ekle(12);
	ekle(14);
	ekle(29);
	yaz();
	int a = bul(14);
	if (a != NULL)
		cout << a << ".indiste eleman var" << endl;
	system("pause");
	silme(15);

	system("pause");

	return 0;
}

