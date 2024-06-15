#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef struct ElmMatkul *adr_Matkul; // pointer to elmDosen
typedef struct ElmDosen *adr_Dosen; // pointer to elmMatkul
typedef struct ElmRelation *adr_relations;

struct InfoDosen
{
    string NamaDosen;
    string ID_Dosen;
};
struct InfoMatkul
{
    string NamaMatkul;
    string ID_Matkul;
};

struct ListDosen
{
    adr_Dosen first_Dosen;
};
struct ListMatkul
{
    adr_Matkul first_Matkul;
    adr_Matkul last_Matkul;
};
struct Listrelation
{
    adr_relations firs_relations;
};

struct ElmDosen
{
    InfoDosen info_Dosen;
    adr_Dosen next_Dosen;
    Listrelation Matkul;
};
struct ElmMatkul
{
    InfoMatkul info_Matkul;
    adr_Matkul next_Matkul;
    adr_Matkul prev_Matkul;
};
struct ElmRelation
{
    adr_Matkul next_Matkul;
    adr_relations next_relation;
};

// Procedure List
void createListDosen(ListDosen &LT);
void createListMatkul(ListMatkul &LI);
adr_Dosen createElmDosen(InfoDosen info_Dosen);
adr_Matkul createElmMatkul(InfoMatkul info_Matkul);
adr_relations createElmRelations();

// Procedur Insert
void insertDosen(ListDosen &LT, adr_Dosen p);
void insertChild(ListMatkul &LI, adr_Matkul c);
void Add(ListDosen &LT, ListMatkul &LI, string NamaDosen, string NamaMatkul);

// Procedure Searching
adr_Dosen searchDosen(ListDosen LT, string NamaDosen);
adr_Matkul searchMatkul(ListMatkul LI, string NamaMatkul);
adr_relations searchrelation(Listrelation r, adr_Matkul LI);
void searchMatkuldariDosen(ListDosen LT, string NamaDosen);
void searchDosendariMatkul(ListDosen LT, ListMatkul LI, string NamaMatkul);
void lihatPeminatMatkul(ListDosen LT, ListMatkul LI);
// Procedure Tampilan
void viewDosen(ListDosen LT);
void viewMatkul(ListMatkul LI);
void viewAll(ListMatkul LT);
// Procedure Delete
void deleteDosen(ListDosen &LT, string NamaDosen);
void deleteMatkul(ListDosen &LT, ListMatkul &LI, string NamaMatkul);
void deleteRelation(ListDosen &LT, string NamaMatkul, string NamaDosen);
#endif // TUBES_H_INCLUDED