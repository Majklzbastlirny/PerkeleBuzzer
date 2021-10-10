//The glorious PERKELE BLASTER 420, product of Finland. Haista vittu 05/2021


const int piezo = 4; // přiřadí vývody ke svým jménům
const int fotodioda = 1;
int lightlevel = 0; // osvětlení učebny
int ticho = 10;  // určuje délku ticha mezi skupinami 
int kmitocet = 1000; // určuje kmitočet písknutí
int n = 1;  // určuje počet písknutí v jedné skupině
int perioda = 100;  // určuje délku samotných písknutí
int mezera = 100;  // určuje krátké mezery uvnitř skupiny
int persing = 1000;  // počítá skupiny písknutí
int persing_treshold = 50; // Mez při které se rozjede odměna

void setup() {
  

 
pinMode(piezo, OUTPUT);  // nastaví použité vývody
pinMode(fotodioda, INPUT);
}

void loop() {
lightlevel = analogRead(fotodioda); //navzorkuje hodnotu osvětlení
if (lightlevel > 3){ //Tady Perkele rozhoduje, zda se v učebně svítí
  

if (persing > persing_treshold){ // tady Perkele odměňuje dobrovolně zůčastněné 😉 rozjezdem 163.
  tone(piezo, 33, 1000);
  delay(1000);
  tone(piezo, 100, 750);
  delay(750);
  tone(piezo, 300, 750);
  delay(750);
  persing = 0;
  persing_treshold = random(100, 120);
  delay(100);
  
};
for(n; n > 0;n--){  // Když se do mně strčí bombon, vydám krásný zvučný tón !                
  kmitocet = random(800, 2000); 
  perioda = random(300, 1200);
  mezera = random(400, 1000);
  tone(piezo,kmitocet , perioda); 
  delay(mezera+perioda); 
  
}
persing++;  //Perkele inkrementuje počítadlo odměny
n = random(1, 7); // Perkele vybere počet pípnutí v nadcházející provokaci

ticho = random(15, 40); // po dobu v tomto intervalu Perkele nepíská 
for(ticho; ticho > 0; ticho--){// Perkele čeká po dobu ticha
delay(1000); 
}
}
else {
delay(1000); //Po tuto periodu Perkele čeká mezi vzorky čidla (když se nesvítí)
}
}
