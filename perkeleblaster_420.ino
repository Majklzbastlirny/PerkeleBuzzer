//The glorious PERKELE BLASTER 420, product of Finland. Haista vittu 05/2021


const int piezo = 4; // přiřadí vývody ke svým jménům
const int fotodioda = 1;
int lightlevel = 0; // osvětlení učebny
int ticho = 10;  // určuje délku ticha mezi skupinami 
int kmitocet = 1000; // určuje kmitočet písknutí
int n = 1;  // určuje počet písknutí v jedné skupině
int perioda = 100;  // určuje délku samotných písknutí
int mezera = 100;  // určuje krátké mezery uvnitř skupiny
int persing = 100;  // počítá skupiny písknutí
int persing_treshold = 50; // Mez při které se rozjede odměna

void setup() {
  

 
pinMode(piezo, OUTPUT);  // nastaví použité vývody
pinMode(fotodioda, INPUT);
}

void loop() {
lightlevel = analogRead(fotodioda); //navzorkuje hodnotu osvětlení
if (lightlevel > 30){ //Tady Perkele rozhoduje, zda se v učebně svítí
  

if (persing > persing_treshold){ // tady Perkele odměňuje dobrovolně zůčastněné ;) rozjezdem 163.
  tone(piezo, 33, 750);
  delay(750);
  tone(piezo, 100, 750);
  delay(750);
  tone(piezo, 300, 750);
  delay(750);
  persing = 0;
  persing_treshold = random(50, 75);
  delay(100);
  
};
for(n; n > 0;n--){  // Když se do mně strčí bombon, vydám krásný zvučný tón !                
  kmitocet = random(500, 2500); 
  perioda = random(50, 500);
  mezera = random(750, 2000);
  tone(piezo, kmitocet, perioda); 
  delay(mezera); 
  
}
persing++;  //Perkele inkrementuje počítadlo odměny
n = random(1, 5); // Perkele vybere počet pípnutí v nadcházející provokaci
ticho = random(20000, 60000); // po dobu v tomto intervalu Perkele nepíská 

delay(ticho); // Perkele čeká po dobu ticha
}
else {
delay(60000); //Po tuto periodu Perkele čeká mezi vzorky čidla (když se nesvítí)
  
}

}
