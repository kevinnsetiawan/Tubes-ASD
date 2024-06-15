//MultiList Variasi 2
#include <iostream>
#include <string>
#include "Tubes.h"
#include "Tubes.cpp"
using namespace std;
int main()
{
    ListDosen T;
    ListMatkul I;
    createListDosen(T);
    createListMatkul(I);
    int pilihan;
    string namaDosen, namaMatkul,id;
    do
    {

        system("cls");
        cout << "====================Program Pendataan Dosen=======================" << endl;
        viewMatkul(I);
        viewDosen(T);
        cout << "Menu" << endl;
        cout << "1.Masukkan data Dosen " << endl;
        cout << "2.Masukkan data Matkul  " << endl;
        cout << "3.Tambahkan Relasi Dosen dan Matkul  " << endl;
        cout << "4.Hapus Data Dosen  " << endl;
        cout << "5.Hapus Data Matkul beserta Relasinya " << endl;
        cout << "6.Lihat Data " << endl;
        cout << "7.Lihat Data Matkul Paling Banyak dan Sedikit Peminat" << endl;
        cout << "8.Lihat Data Dosen Berdasarkan Matkul" << endl;
        cout << "9.Lihat Data Matkul Berdasarkan Dosen " << endl;
        cout << "10.Keluar" << endl;
        cout << "Pilih Menu :";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Nama Dosen :";
            cin >> namaDosen;
            cout << "Masukkan ID Dosen : ";
            cin >> id;
            insertDosen(T, createElmDosen(namaDosen,id));
            cout << "Nama Dosen telah di tambahkan" << endl;
            system("pause");
            break;
        case 2:
            cout << "Masukkan Nama Matkul :";
            cin >> namaMatkul;
            cout << "Masukkan ID Matkul :";
            cin >> id;
            insertMatkul(I, createElmMatkul(namaMatkul,id));
            cout << "Nama Matkul telah di tambahkan" << endl;
            system("pause");
            break;
        case 3:
            cout << "Masukkan Nama Dosen :";
            cin >> namaDosen;
            cout << "Masukkan Nama Matkul : ";
            cin >> namaMatkul;
            Add(T, I, namaDosen, namaMatkul);
            cout << "Dosen dan Matkul telah terhubung" << endl;
            system("pause");
            break;
        case 4:
            cout << "Masukkan Nama Dosen :";
            cin >> namaDosen;
            deleteDosen(T, namaDosen);
            cout << "Nama Dosen Telah di hapus" << endl;
            system("pause");
            break;
        case 5:
            cout << "Masukkan Nama Matkul : ";
            cin >> namaMatkul;
            deleteMatkul(T, I, namaMatkul);

            cout << "Nama Matkul Telah di hapus" << endl;
            system("pause");
            break;
        case 6:
            viewAll(T);
            system("pause");
            break;
        case 7:
            lihatPeminatMatkul(T, I);
            system("pause");
            break;
        case 8:
            cout << "Masukkan Nama Matkul : ";
            cin >> namaMatkul;
            searchDosendariMatkul(T, I, namaMatkul);
            system("pause");
            break;
        case 9:
            cout << "Masukkan Nama Dosen :";
            cin >> namaDosen;
            searchMatkuldariDosen(T, namaDosen);
            system("pause");
            break;
        case 0:
            return 0;
            break;

        default:
            break;
        }
    } while (true);
    return 0;
}
