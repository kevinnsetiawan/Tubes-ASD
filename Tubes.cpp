#include <iostream>
#include <string>
#include "Tubes.h"
using namespace std;

typedef struct ElmMatkul *adr_Matkul;          // pointer to elmStudent
typedef struct ElmDosen *adr_Dosen;          // pointer to elmClass
typedef struct ElmRelation *adr_relations; // pointer to relations
void createListDosen(ListDosen &LT)
{
    LT.first_Dosen = NULL;
}
void createListMatkul(ListMatkul &LI)
{
    LI.first_Matkul = NULL;
    LI.last_Matkul = NULL;
}
adr_Dosen createElmDosen(string namaDosen,string iddosen)
{
    adr_Dosen p = new ElmDosen;
    p->info_Dosen.NamaDosen = namaDosen;
    p->info_Dosen.ID_Dosen = iddosen;
    p->next_Dosen = NULL;
    p->Matkul.firs_relations = NULL;
    return p;
}
adr_Matkul createElmMatkul(string namaMatkul,string idmatkul)
{
    adr_Matkul q = new ElmMatkul;
    q->info_Matkul.NamaMatkul = namaMatkul;
    q->info_Matkul.ID_Matkul = idmatkul;
    q->next_Matkul = NULL;
    q->prev_Matkul = NULL;
    return q;
}
adr_relations createElmRelations()
{
    adr_relations r = new ElmRelation;
    r->next_Matkul = NULL;
    r->next_relation = NULL;
    return r;
}
void insertDosen(ListDosen &LT, adr_Dosen p)
{
    if (LT.first_Dosen == NULL)
    {
        LT.first_Dosen = p;
    }
    else
    {
        p->next_Dosen = LT.first_Dosen;
        LT.first_Dosen = p;
    }
}
void insertMatkul(ListMatkul &LI, adr_Matkul c)
{
    if (LI.first_Matkul == NULL)
    {
        LI.first_Matkul = c;
        LI.last_Matkul = c;
    }
    else
    {
        c->prev_Matkul = LI.last_Matkul;
        LI.last_Matkul->next_Matkul = c;
        LI.last_Matkul = c;
    }
}
adr_Dosen searchDosen(ListDosen LT, string NamaDosen)
{
    if (LT.first_Dosen == NULL)
    {
        return NULL;
    }
    else
    {
        adr_Dosen p = LT.first_Dosen;
        while ((p->next_Dosen != NULL) && (p->info_Dosen.NamaDosen != NamaDosen))
        {
            p = p->next_Dosen;
        }
        if (p->info_Dosen.NamaDosen == NamaDosen)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
}
adr_Matkul searchMatkul(ListMatkul LI, string NamaMatkul)
{
    if (LI.first_Matkul == NULL)
    {
        return NULL;
    }
    else
    {
        adr_Matkul q = LI.first_Matkul;
        while ((q->next_Matkul != NULL) && (q->info_Matkul.NamaMatkul != NamaMatkul))
        {
            q = q->next_Matkul;
        }
        if (q->info_Matkul.NamaMatkul == NamaMatkul)
        {
            return q;
        }

        {
            return NULL;
        }
    }
}
adr_relations searchrelation(Listrelation r, adr_Matkul LI)
{
    adr_relations q = r.firs_relations;
    while ((q != NULL) && (q->next_Matkul != LI))
    {
        q = q->next_relation;
    }
    if (q->next_Matkul == LI)
    {
        return q;
    }
    else
    {
        return NULL;
    }
}
void searchMatkuldariDosen(ListDosen LT, string NamaDosen)
{
    adr_Dosen p = searchDosen(LT, NamaDosen);
    if (p != NULL)
    {
        if (p->Matkul.firs_relations != NULL)
        {
            adr_relations r = p->Matkul.firs_relations;
            while (p->Matkul.firs_relations != NULL)
            {
                cout << "Nama Matkul \t: " << r->next_Matkul->info_Matkul.NamaMatkul << endl;
                cout << "" << endl;
                r = r->next_relation;
            }
        }
    }
}
void searchDosendariMatkul(ListDosen LT, ListMatkul LI, string NamaMatkul)
{
    adr_Matkul p = searchMatkul(LI, NamaMatkul);
    if (p != NULL)
    {
        adr_Dosen q = LT.first_Dosen;
        while (q->next_Dosen != NULL)
        {
            if (q->Matkul.firs_relations != NULL)
            {
                adr_relations r = searchrelation(q->Matkul, p);
                if (r != NULL)
                {
                    cout << "Nama Dosen \t: " << q->info_Dosen.NamaDosen << endl;
                    cout << "" << endl;
                }
            }
            q = q->next_Dosen;
        }
        if (q->Matkul.firs_relations != NULL)
        {
            adr_relations r = searchrelation(q->Matkul, p);
            if (r != NULL)
            {
                cout << "Nama Dosen \t: " << q->info_Dosen.NamaDosen << endl;
                cout << "" << endl;
            }
        }
    }
}
void Add(ListDosen &LT, ListMatkul &LI, string NamaDosen, string NamaMatkul)
{
    adr_Dosen p = searchDosen(LT, NamaDosen);
    adr_Matkul q = searchMatkul(LI, NamaMatkul);
    if ((p != NULL) && (q != NULL))
    {
        adr_relations r = createElmRelations();
        r->next_Matkul = q;
        if (p->Matkul.firs_relations == NULL)
        {
            p->Matkul.firs_relations = r;
        }
        else
        {
            r->next_relation = p->Matkul.firs_relations;
            p->Matkul.firs_relations = r;
        }
    }
    else
    {
        cout << "Dosen atau Matkul Tidak Ditemukan" << endl;
    }
}
void deleteRelation(ListDosen &g, string namadosen, string namamatkul)
{                                         // menghapus Relasi tertentu pada student yang sesuai
    adr_Dosen p = searchDosen(g, namadosen); // searching id student yang ingin dihapus
    if (p != NULL)
    { // jika menemukan
        if (p->Matkul.firs_relations != NULL)
        {                                             // cek apakah list relasi ada
            adr_relations q = p->Matkul.firs_relations; // buat dua pointer, 1 untuk menunjuk id yang sesuai dengan id_couse dan 1 menunjuk sebelum di_Relasi
            adr_relations r = p->Matkul.firs_relations;
            while ((q->next_Matkul->info_Matkul.NamaMatkul != namamatkul) && (q->next_relation != NULL))
            {
                r = q;                // pointer r menunjuk sebelum idNetizen
                q = q->next_relation; // pointer q menunjuk idNetizen
            }
            if (q->next_Matkul->info_Matkul.NamaMatkul == namamatkul)
            { // jika terdapat idNetizen yang sesuai
                if (q == p->Matkul.firs_relations)
                { // jika elemen yand dihapus di first
                    p->Matkul.firs_relations = r->next_relation;
                    q->next_relation = NULL;
                }
                else if (q->next_relation == NULL)
                { // elemen yang dihapus di elemen terakhir
                    r->next_relation = NULL;
                }
                else
                { // element di tengah-tengah
                    r->next_relation = q->next_relation;
                    q->next_relation = NULL;
                }
                q->next_Matkul = NULL;
            }
        }
    }
}
void deleteDosen(ListDosen &LT, string NamaDosen)
{
    adr_Dosen p = searchDosen(LT, NamaDosen);
    if (p != NULL)
    {
        p->Matkul.firs_relations = NULL;
        if (p == LT.first_Dosen)
        {
            LT.first_Dosen = p->next_Dosen;
            p->next_Dosen = NULL;
        }
        else if (p->next_Dosen == NULL)
        {
            adr_Dosen q = LT.first_Dosen;
            while (q->next_Dosen != p)
            {
                q = q->next_Dosen;
            }
            q->next_Dosen = NULL;
        }
        else
        {
            adr_Dosen q = LT.first_Dosen;
            while (q->next_Dosen != p)
            {
                q = q->next_Dosen;
            }
            q->next_Dosen = p->next_Dosen;
            p->next_Dosen = NULL;
        }
    }
    else
    {
        cout << "Nama Dosen tidak ada" << endl;
        system("pause");
    }
}
void deleteMatkul(ListDosen &LT, ListMatkul &LI, string NamaMatkul)
{
    adr_Matkul p = searchMatkul(LI, NamaMatkul);
    if (p != NULL)
    {
        adr_Dosen q = LT.first_Dosen;
        while (q != NULL)
        {
            deleteRelation(LT, q->info_Dosen.NamaDosen, NamaMatkul);
            q = q->next_Dosen;
        }

        if (p == LI.first_Matkul)
        {
            LI.first_Matkul = p->next_Matkul;
            p->next_Matkul = NULL;
        }
        else if (p->next_Matkul == NULL)
        {
            LI.last_Matkul = LI.last_Matkul->prev_Matkul;
            p->prev_Matkul = NULL;
            LI.last_Matkul->next_Matkul = NULL;
        }
        else
        {
            adr_Matkul r = LI.first_Matkul;
            while (r->next_Matkul != p)
            {
                r = r->next_Matkul;
            }
            r->next_Matkul = p->next_Matkul;
            p->next_Matkul = NULL;
        }
    }
}

void viewAll(ListDosen LT)
{
    adr_Dosen p = LT.first_Dosen;
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << "===========================" << endl;
            cout << "ID Dosen \t: " << p->info_Dosen.ID_Dosen << endl;
            cout << "Nama Dosen \t: " << p->info_Dosen.NamaDosen << endl;
            cout << "" << endl;
            if (p->Matkul.firs_relations != NULL)
            {
                
                adr_relations q = p->Matkul.firs_relations;

                while (q != NULL)
                {
                    cout << "Nama Matkul \t: " << q->next_Matkul->info_Matkul.NamaMatkul << endl;
                     cout << "ID Matkul \t: " << q->next_Matkul->info_Matkul.ID_Matkul<< endl;
                    cout << "" << endl;
                    q = q->next_relation;
                }
                cout << "" << endl;
            }
            p = p->next_Dosen;
        }
    }
}
void viewDosen(ListDosen LT)
{
    cout << "Daftar Dosen :";
    adr_Dosen p = LT.first_Dosen;
    while (p != NULL)
    {
        cout << p->info_Dosen.NamaDosen << ",";
        cout << p->info_Dosen.ID_Dosen << ",";
        p = p->next_Dosen;
    }
    cout << "" << endl;
}
void viewMatkul(ListMatkul LI)
{
    cout << "Daftar Matkul :";
    adr_Matkul q = LI.first_Matkul;
    while (q != NULL)
    {
        cout << q->info_Matkul.NamaMatkul << ",";
        q = q->next_Matkul;
    }
    cout << "" << endl;
}
void lihatPeminatMatkul(ListDosen LT, ListMatkul LI)
{
    adr_Matkul MatkulMax = NULL, MatkulMin = NULL;
    int maxjumlah = 0, minjumlah = 0;

    adr_Matkul p = LI.first_Matkul;
    while (p != NULL)
    {
        int jumlah = 0;
        adr_Dosen q = LT.first_Dosen;
        while (q != NULL)
        {
            if (searchrelation(q->Matkul, p) != NULL)
            {
                jumlah++;
            }
            q = q->next_Dosen;
        }

        if (jumlah > maxjumlah)
        {
            maxjumlah = jumlah;
            MatkulMax = p;
        }

        if (minjumlah == 0 || jumlah < minjumlah)
        {
            minjumlah = jumlah;
            MatkulMin = p;
        }

        p = p->next_Matkul;
    }

    if (MatkulMax != NULL)
    {
        cout << "Matkul dengan peminat terbanyak adalah: " << MatkulMax->info_Matkul.NamaMatkul << " dengan " << maxjumlah << " Dosen." << endl;

    }
    
        if (MatkulMin != NULL)
        {
            cout << "Matkul dengan peminat tersedikit adalah: " << MatkulMin->info_Matkul.NamaMatkul << " dengan " << minjumlah << " Dosen." << endl;
        }
        else
        {
            cout << "Tidak ada Matkul dengan peminat." << endl;
        }
}