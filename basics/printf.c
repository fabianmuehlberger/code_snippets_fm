#include <stdio.h>

/*
    FORMAT SPECIFIER
    Zeichen	Umwandlung
%d  oder %i	int
%c	einzelnes Zeichen
%e  oder %E	double im Format [-]d.ddd e±dd bzw. [-]d.ddd E±dd
%f	double im Format [-]ddd.ddd
%o	int als Oktalzahl ausgeben
%p	die Adresse eines Zeigers
%s	Zeichenkette ausgeben
%u	unsigned int
%x oder %X	int als Hexadezimalzahl ausgeben
%%	Prozentzeichen
*/

/*
    FLAGS
- (Minus):      Der Text wird links ausgerichtet.
+ (Plus):       Es wird auch bei einem positiven Wert ein Vorzeichen ausgegeben.
Leerzeichen:    Ein Leerzeichen wird ausgegeben, wenn der Wert positiv ist.
0 :             Die Auffüllung erfolgt mit Nullen anstelle von Leerzeichen, wenn die Feldbreite verändert wird.
*/

/*
    FELDBREITE
Hinter dem Flag kann die Feldbreite (engl. field width) festgelegt werden. Das bedeutet,
dass die Ausgabe mit der entsprechenden Anzahl von Zeichen aufgefüllt wird. Beispiel.
*/

/*
    NACHKOMMASTELLEN
Nach der Feldbreite folgt, durch einen Punkt getrennt, die Genauigkeit.
Bei %f werden ansonsten standardmäßig 6 Nachkommastellen ausgegeben.
*/

int main(void)
{

    //FORMAT SPECIFIERS
    printf("FORMAT SPECIFIERS\n");
    printf("Integer: %d\n", 42);
    printf("Double: %.6f\n", 3.141);
    printf("Zeichen: %c\n", 'z');
    printf("Zeichenkette: %s\n", "abc");
    printf("43 Dezimal ist in Oktal: %o\n", 43);
    printf("43 Dezimal ist in Hexadezimal: %x\n", 43);
    printf("Und zum Schluss geben wir noch das Prozentzeichen aus: %%\n");

    //FLAGS
    printf("FLAGS\n");
    printf("Zahl 67:%+i\n", 67);
    printf("Zahl 67:% i\n", 67);
    printf("Zahl 67:%#x\n", 67);
    printf("Zahl 0:%0x\n", 0);

    //FELDBREITE
    printf("FELDBREITE\n");
    printf("Zahlen rechtsbündig ausgeben: %5d, %5d, %5d\n",34, 343, 3343);
    printf("Zahlen rechtsbündig ausgeben, links mit 0 aufgefüllt: %05d, %05d, %05d\n",34, 343, 3343);
    printf("Zahlen linksbündig ausgeben: %-5d, %-5d, %-5d\n",34, 343, 3343);

    //NACHKOMMASTELLEN
    printf("NACHKOMMASTELLEN\n");
    double betrag1 = 0.5634323;
    double betrag2 = 0.2432422;
    printf("Summe: %.3f\n", betrag1 + betrag2);

}

