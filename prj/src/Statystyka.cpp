/*!
 * \file
 * \brief
 * Zawiera definicję metod klasy Statystyka.
 *
 * Plik zawiera definicję metod klasy Statystyka.
 */

#include "../inc/Statystyka.hh"


Statystyka::Statystyka(const unsigned int iloscProb, unsigned int *proby, const unsigned int ilePowtorzen) {
  IleProb = iloscProb;
  Proba = new unsigned int[IleProb];
  Czas = new double[IleProb];
  IloscPowtorzen = ilePowtorzen;
  MojStoper = new Stoper();
  LicznikPowtorzen = 0;
  SumaCzasuProby = 0;
  LicznikProb = 0;
  for(unsigned int i=0; i<IleProb; i++)
     Proba[i] = proby[i];
}

void Statystyka::ZapiszStaty(std::string nazwaPliku) const {

  std::fstream plik;

  plik.open(nazwaPliku.c_str(), std::ios::out|std::ios::trunc);
  if (plik.good()) {

    for(unsigned int i=0; i<IleProb; i++){
      plik << Proba[i] << "," << Czas[i];
      plik << std::endl;
    }
    plik.close();
  }
  else {
    std::cerr << "Blad utworzenia pliku!" << std::endl;
    exit (-4);
  }
}

void Statystyka::Aktualizuj() {
    if(MojStoper -> CzyOdmierza()) {
        MojStoper -> Stop();
        SumaCzasuProby += MojStoper -> DajPomiar();
        MojStoper -> Reset();
        ++LicznikPowtorzen;

        if(LicznikPowtorzen == IloscPowtorzen) {
        Czas[LicznikProb] = SumaCzasuProby/IloscPowtorzen;
        ++LicznikProb;
        SumaCzasuProby = 0;
        LicznikPowtorzen = 0;
        }
    }
    else {
        MojStoper -> Start();
    }

}
