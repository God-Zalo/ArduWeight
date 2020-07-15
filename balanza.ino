#include "HX711.h"

const int DOUT=A1;
const int CLK=A0;

HX711 balanza;

void setup() {
  Serial.begin(9600);
  balanza.begin(DOUT, CLK);
  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(balanza.read());
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  balanza.set_scale(429.3); // Establecemos la escala
  balanza.tare(50);  //El peso actual es considerado Tara.
  
  Serial.println("Listo para pesar");  
}

void loop() {
  Serial.println(balanza.get_units(20),2);
}
