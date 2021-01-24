
#include <iostream> 
using namespace std;
#include <iomanip> 
#include <cmath>

void inputAndPrintInteger(){
    int x;
    cout << "Skriv inn et heltall";
    cin >> x;
    cout << "Du skrev: " << x << endl;
}
int inputInteger(){
    int y;
    cout << "skriv inn et heltall";
    cin >> y;
    return y;
}

void inputIntegersAndPrintSum(){
    int x = inputInteger();
    int y = inputInteger();
    cout << (x+y) << endl;
    // brukte inputInteger fordi den gir en returverdi som jeg kan tilordne til en variabel.
}
bool isOdd(int n){
    if (n%2==0){
        return false;
    }
    return true;
}

void printHumanReadableTime(int sec){
    int t = sec/3600;
    int min = (sec%3600)/60;
    sec = sec - (t*3600) - (min*60);
    cout << "timer: " << t << " , minutter: " << min << " , Sekunder: " << sec << endl;
}

// OPPGAVE 2 ----------------------------------------------------------------

void inputIntegersUsingLoopAndPrintSum(){
    int x;
    int summ=0;
    cout << "skriv inn et heltall (0, for å avslutte)" << endl;
    cin >> x;
    while (x!=0){
        summ += x;
        cout << "skriv inn et heltall (0, for å avslutte)" << endl;
        cin >> x;
    }
    cout << summ << endl;
}
// når man skal fortsette å lese inn tall til brukeren taster inn 0, børr man bruke en while-løkke,
// fordi da kan man enkel skrive at så lenge man ikke skriver inn 0 så skal den fortsette.
// når man skal skrive inn antall tall på forhånd er det bedre å bruke for-løkke fordi det er like enkelt, men gjør koden kortere og man slipper en tellevariabel utenfor løkken.
double inputdouble(){
    double x;
    cout << "skriv inn et desimaltall" << endl;
    cin >> x;
    return x;
}

void konverterNokTilEuro(){
    
    //mangler å avrunde(finn hjelp)
    
    double NOK = inputdouble();
    while (NOK<0){
        NOK = inputdouble();
    }
    double EUR = NOK/9.64;
    cout << fixed;
    cout << NOK << " NOK er " << setprecision(2) << EUR << " Euro" << endl;
}
// Det er dumt å bruke en inttype til å ta in tall her, fordi man ofte vil konvertere mellom desimaltall. derfor må man bruke inputdouble.
// har valgt returtype void, fordi jeg printer ut resultatet i stedenfo å returnere den. Hadde jeg returnert den ville jeg brukt double.

void gangetabell(){
    int lengde;
    int bredde;
    
    cout << "Skriv inn lengeden og bredden til gangetabellen" << endl;
    cin >> lengde;
    cin >> bredde;
    for(int i=1; i<=lengde; i++){
        for(int j=1; j<=bredde; j++){
            int tall = i*j;
            cout << tall << "\t";
        }
        cout << endl;
    }
}

double rot(int a, int b, int c){
    return (pow(b,2)-4*a*c);
}

double printRealRoots(double a, double b, double c){
    if (rot(a,b,c)<0){
        cout << "Ingen reelle røtter" << endl;
    }
    else if (rot(a,b,c)==0){
        double x1 = (-b + sqrt(rot(a,b,c)))/(2*a);
        cout << x1 << endl;
    }
    else{
        double x1 = (-b + sqrt(rot(a,b,c)))/(2*a);
        double x2 = (-b - sqrt(rot(a,b,c)))/(2*a);
        cout << x1  << " og " << x2 << endl;
    }
    return 0;
}

double solveQuadraticEquation(){
    double a;
    double b;
    double c;
    cout << "Skriv inn 3 desimaltall for a, b, c" << endl;
    cin >> a >> b >> c;
    printRealRoots(a,b,c);
    return 0;
}

void calculateLoanPayments(){
    double lån;
    double rente;
    cout << "Skriv inn hvor stort lån du vil ha, og rente på lånet" << endl;
    cin >> lån >> rente;
    cout << "År" << "\t\t" << "Innbetaling" << "\t\t" << "Gjenstående Lån" << endl;
    for (int i=0; i<10; i++){
        double rest = lån-(lån/10)*i;
        double innbetaling=(lån/10)+(rente/100)*(rest);
        cout << (i+1) << "\t\t" << innbetaling << "\t\t\t" << rest << endl;
    }
}

int main(){
    
    int velger;
    cout << "Skriv inn et tall mellom 1-3 for å velge mellom: \n 1) summere to tall \n 2)summere flere tall \n 3) konvertere NOK til Euro \n 4) skrive ut gangetabell \n 5) løse 2.grads likning \n 6) se innbetaling for lån \n 0) for å avslutte" << endl;
    cin >> velger;
    
    while (velger!=0){
        switch (velger){
        case 1:
            inputIntegersAndPrintSum();
            break;
        case 2:
            inputIntegersUsingLoopAndPrintSum();
            break;
        case 3:
            konverterNokTilEuro();
            break;
        case 4:
            gangetabell();
            break;
        case 5:
            solveQuadraticEquation();
            break;
        case 6:
            calculateLoanPayments();
            break;
                
    }
        cout << "Skriv inn ett nytt tall" << endl;
        cin >> velger;
    }
    
    
    
    //inputAndPrintInteger();
    //cout << "Du skrev " << inputInteger() << endl;
    //inputIntegersAndPrintSum();
    //for (int i = 10; i < 15; i++) {
    //    if (isOdd(i)) {
    //        std::cout << i << " er et oddetall." << std::endl;
    //    } else {
    //        std::cout << i << " er et partall." << std::endl;
    //    }
    //}
    //printHumanReadableTime(4000);
    //cout << "oppg 2" << endl;
    //inputIntegersUsingLoopAndPrintSum();
    //cout << inputdouble() << endl;
    //cout << "2 d)" << endl;
    //konverterNokTilEuro();
    //cout << "Oppg 3" << "\n" << "----------------------------" << endl;
    return 0;
}


