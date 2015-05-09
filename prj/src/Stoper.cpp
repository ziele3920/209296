#include "../inc/Stoper.hh"

Stoper::Stoper() {
  CzasPoczatkowy = 0; 
  CzasKoncowy = 0;
  CzyLiczy = false;
}

void Stoper::Start() {
  CzasPoczatkowy = std::clock();
  CzyLiczy = true;
}

void Stoper::Stop() {
  CzasKoncowy = std::clock();
  CzyLiczy = false;
}

void Stoper::Reset() {
    CzasPoczatkowy = 0;
    CzasKoncowy = 0;
    CzyLiczy = false;
}

double Stoper::DajPomiar() const {
  return (CzasKoncowy - CzasPoczatkowy)/(double)(CLOCKS_PER_SEC/1000);
}

bool Stoper::CzyOdmierza() const {
    return CzyLiczy;
}
