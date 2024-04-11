#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int max_kapacitaD1, max_kapacitaD2, obsahD1 = 0, obsahD2 = 0, vyber;
    string odklik;
    string cars[2][4] = {
        {"volvo", "bmw", "jaguar", "ford"},
        {"Lotus",  "brambor", "Volstok", "skoda"}};











    cout << "Prosím vyberte program" << endl;
    cout << "1) Džbány" << endl;
    cout << "2) Pole" << endl;
    cin >> vyber;
    system("CLS");


    switch(vyber){
case 1:
    vstup:
    //Komunikace s uzivatelem
    cout << "Zadejte Maximalni kapacitu dzbanu 1" << endl;
    cin >> max_kapacitaD1;
    cout << endl << "Zadejte Maximalni kapacitu dzbanu 2" << endl;
    cin >> max_kapacitaD2;

    //Podmínka pro vstup
    if(((max_kapacitaD1 % 2) == 1) && ((max_kapacitaD2 % 2) == 1) && (max_kapacitaD1 < max_kapacitaD2) && ((max_kapacitaD2 % max_kapacitaD1) > 0))
    {
        system("CLS");
        cout  << "Dzban 1 ma: " << obsahD1 << " || Dzban 2 ma: " << obsahD2 << endl; //výpis stavu džbánù
        while(obsahD1!= 1){

            if(obsahD1 == 0){
                obsahD1 = obsahD1 + max_kapacitaD1;//Naplneni dzbanu 1
                cout << "Dzban 1 ma: " << obsahD1 << " || Dzban 2 ma: " << obsahD2 << endl;
            }
            obsahD2 = obsahD2 + obsahD1;//Prelevani z d1 do d2
            obsahD1 = 0; //Vynulování dzbanu 1
            if(obsahD2>max_kapacitaD2){
                obsahD1 = obsahD2-max_kapacitaD2;
                obsahD2 = max_kapacitaD2;
                cout << "Dzban 1 ma: " << obsahD1 << " || Dzban 2 ma: " << obsahD2 << endl;
                obsahD2=0;
            }
            cout << "Dzban 1 ma: " << obsahD1 << " || Dzban 2 ma: " << obsahD2 << endl;
        }//Konec while
    cout << "Program dokoncen \n ";
    }else{ //Else pro pripad spatne zadanych hodnot
    cout << "Spatne zadane hodnoty, prosim zadejte znovu" << endl << "Pro pokracovani zadejte libovolny znak" << endl;
    cin >> odklik;
    system("CLS");
    goto vstup;
    }
    break;





case 2:
 // Pomocí jedničky značíme že se někde nachází loď
  bool lode[4][4] = {
    { 0, 1, 1, 1 },
    { 0, 0, 0, 0 },
    { 0, 0, 1, 0 },
    { 0, 0, 1, 0 }
  };
  string mapa[4][4] = {
  { " 0 "," 0 "," 0 "," 0"},
  { " 0 "," 0 "," 0 "," 0"},
  { " 0 "," 0 "," 0 "," 0"},
  { " 0 "," 0 "," 0 "," 0"}
  };

  // Do těchto promenných zapisujeme počet tahů a zásahu
  int zasahy = 0;
  int tahy = 0;
  int radkymapy = 4;
  int sloupcemapy = 4;
  // Dokud nebude počet zasahů odpovidat poctu zasahu 1 v poli program poběží
  while (zasahy < 5) {
        system("cls");
    int radek, sloupec;

    cout << "Zvolte misto strely\n";
    cout << " 0  1  2  3  Sloupec" <<"\n";
    cout << "--------------------" << "\n";
for (int a = 0; a < radkymapy; ++a)
    {
        for (int j = 0; j < sloupcemapy; ++j)
        {
        cout << mapa[a][j];
        }
        cout << "\n";
    }

    // Volba radku
    cout << "Vyberte radek mezi 0 az 3: ";
    cin >> radek;

    // Volba sloupce
    cout << "Vyberte sloupec 0 az 3: ";
    cin >> sloupec;

    // Kontrola zda na souřadnici je loď
    if (lode[radek][sloupec]) {
      // Pokud dojde k zasahu zmenime 1 na 0
      lode[radek][sloupec] = 0;
      mapa[radek][sloupec] = " X ";

      // Přičtu zásah
      zasahy++;

      // Oznámíme zásah a kolik 1 zbývá tahů.
      cout << "Zasah! "  << " zbyva " << (5-zasahy) << "\n\n";
      Sleep(1000);
    } else {
      // Oznameni ze nebylo nic zasazeno
      cout << "Voda\n\n";
      mapa [radek][sloupec] = " V ";
      Sleep(1000);
    }

    // Pricteme tah
    tahy++;
  }

  cout << "Vitezstvi!\n";
  cout << "Vyhrali jste za " << tahy << " tahu";

  return 0;
      break;
}//Konec switch
    }//Konec main












