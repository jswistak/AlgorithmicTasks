#include <iostream>
#include <map>
#include <string>
using namespace std;
int testow,wynik;
string mic,slowo;
map<string,int> s;
int w[100000];
int main(){
s["Winicjusz"]=2;s["Petroniusz"]=2;s["Ligia"]=2;s["Winicjusza"]=2;s["cezara"]=2;s["Ligii"]=2;s["cezar"]=2;s["albowiem"]=2;s["Nero"]=2;s["Ligie"]=2;s["Chilo"]=2;s["Ursus"]=2;s["Akte"]=2;s["Petroniusza"]=2;s["Piotr"]=2;s["Tadeusz"]=1;s["Wojski"]=1;s["Apostol"]=2;s["Eunice"]=2;s["Ancjum"]=2;s["chrzescijanie"]=2;s["Nerona"]=2;s["Pomponia"]=2;s["Pomponii"]=2;s["atrium"]=2;s["Chilona"]=2;s["Ostrianum"]=2;s["Tygellinus"]=2;s["Aulusow"]=2;s["Winicjuszowi"]=2;s["Gerwazy"]=1;s["Poppea"]=2;s["Telimena"]=1;s["Cezar"]=2;s["Aulus"]=2;s["Ligio"]=2;s["Apostola"]=2;s["niemal"]=2;s["niewolnicy"]=2;s["Chilon"]=2;s["Klucznik"]=1;s["Glauka"]=2;s["Robak"]=1;s["Podkomorzy"]=1;s["Tadeusza"]=1;s["bogowie"]=2;s["Tygellina"]=2;s["Ursusa"]=2;s["uczynic"]=2;s["Rykow"]=1;s["Tygellin"]=2;s["pretorianow"]=2;s["uczynil"]=2;s["naokol"]=2;s["Go"]=2;s["Tarsu"]=2;s["cyrku"]=2;s["Litwie"]=1;s["Glaukus"]=2;s["chrzescijaninem"]=2;s["Asesor"]=1;s["Sedziego"]=1;s["Aulusa"]=2;s["Grek"]=2;s["Zali"]=2;s["arenie"]=2;s["Rejent"]=1;s["Zosia"]=1;s["Krotona"]=2;s["cezarem"]=2;s["Chryzotemis"]=2;s["boski"]=2;s["Marku"]=2;s["Winicjuszu"]=2;s["cezarowi"]=2;s["wtenczas"]=1;s["Poppei"]=2;s["triclinium"]=2;s["arene"]=2;s["augustianow"]=2;s["Zosi"]=1;s["Kryspus"]=2;s["lektyki"]=2;s["Horeszkow"]=1;s["Achai"]=2;s["Greka"]=2;s["Petroniuszu"]=2;s["odrzekla"]=2;s["srod"]=1;s["Kroto"]=2;s["Linus"]=2;s["Linusa"]=2;s["Nazariusz"]=2;s["Winicjuszem"]=2;s["czynil"]=2;s["niewolnik"]=2;s["Hrabiego"]=1;s["Jacek"]=1;s["Ligow"]=2;s["Miriam"]=2;s["Palatynie"]=2;s["Seneka"]=2;s["amfiteatrze"]=2;s["wiezieniu"]=2;s["Soplica"]=1;s["Petroniuszowi"]=2;s["Westynus"]=2;s["cezarze"]=2;s["Maciej"]=1;s["Rzekl"]=1;s["Zatybrze"]=2;s["cubiculum"]=2;s["Lig"]=2;s["areny"]=2;s["willi"]=2;s["Soplicow"]=1;s["Grecji"]=2;s["Via"]=2;s["augustianie"]=2;s["dziewice"]=2;s["odnalezc"]=2;s["poczucie"]=2;s["Moskali"]=1;s["Protazy"]=1;s["Chrzescijanie"]=2;s["Grecyna"]=2;s["Neapolis"]=2;s["Plaucjusz"]=2;s["chrzescijanami"]=2;s["Dabrowski"]=1;s["Kryspa"]=2;s["Pomponie"]=2;s["amfiteatr"]=2;s["centurion"]=2;s["legii"]=2;s["lektyke"]=2;s["przerazenia"]=2;s["swiatynie"]=2;s["Dobrzynscy"]=1;s["Baranka"]=2;s["Chilonie"]=2;s["Herkulesa"]=2;s["Miedzianobrody"]=2;s["czynic"]=2;s["igrzysk"]=2;s["meke"]=2;s["ogrodow"]=2;s["rzymski"]=2;s["trybun"]=2;s["Chrzciciel"]=1;s["Maciek"]=1;s["Soplicowie"]=1;s["Stolnik"]=1;s["Wojskiego"]=1;s["Augusty"]=2;s["Jowisza"]=2;s["Palatynu"]=2;s["Watyniusz"]=2;s["chrzescijanom"]=2;s["gladiatorow"]=2;s["igrzyska"]=2;s["pretorianie"]=2;s["przeto"]=2;s["sestercji"]=2;s["tunike"]=2;s["uczynila"]=2;s["Sedziemu"]=1;s["Sedzio"]=1;s["Bogowie"]=2;s["Chilonowi"]=2;s["Palatyn"]=2;s["miluje"]=2;s["podium"]=2;s["wiedz"]=2;s["Plut"]=1;s["Zosie"]=1;s["Aulusowi"]=2;s["Lukan"]=2;s["Mu"]=2;s["Porta"]=2;s["Scewinus"]=2;s["Senecjo"]=2;s["Ursusem"]=2;s["Zatybrzu"]=2;s["augustianami"]=2;s["lekarz"]=2;s["lwow"]=2;s["niechybnie"]=2;s["nieprzyjaciolmi"]=2;s["pozarem"]=2;s["toge"]=2;s["zakladniczka"]=2;s["zgube"]=2;s["Dobrzynski"]=1;s["charty"]=1;s["Aulusowie"]=2;s["Azji"]=2;s["Grecyny"]=2;s["Niego"]=2;s["Polluksa"]=2;s["Tuliusz"]=2;s["Vicus"]=2;s["Witeliusz"]=2;s["barbarzyncy"]=2;s["cnote"]=2;s["jeno"]=2;s["patrycjusz"]=2;s["poszukiwania"]=2;s["wigilow"]=2;s["wyznawcow"]=2;s["wyzwolency"]=2;s["Kropiciel"]=1;s["bernardyna"]=1;s["rzecze"]=1;s["strzelcy"]=1;s["Aulusom"]=2;s["Niewolnicy"]=2;s["Seneki"]=2;s["Tygellinowi"]=2;s["Zbawiciel"]=2;s["nakazuje"]=2;s["niewolnic"]=2;s["niewolnikom"]=2;s["odnajdzie"]=2;s["pochodni"]=2;s["rozpoznac"]=2;s["wiezienie"]=2;s["zadzy"]=2;s["Buchman"]=1;s["Jankiel"]=1;s["Stolnika"]=1;s["Telimenie"]=1;s["Telimeny"]=1;s["krzykneli"]=1;s["kwestarz"]=1;s["rapier"]=1;s["Chilonem"]=2;s["Eurycjusza"]=2;s["Liga"]=2;s["Niger"]=2;s["Ostii"]=2;s["Petroniuszem"]=2;s["Plaucjusza"]=2;s["Tygellinem"]=2;s["Westy"]=2;s["Wierze"]=2;s["Zatybrza"]=2;s["chrzescijanach"]=2;s["chrzescijanina"]=2;s["cytry"]=2;s["opieka"]=2;s["peplum"]=2;s["pochodnie"]=2;s["potu"]=2;s["szmaragd"]=2;s["togi"]=2;s["Hrabie"]=1;s["Klucznika"]=1;s["Konewka"]=1;s["Macka"]=1;s["Majorze"]=1;s["Moskal"]=1;s["Moskala"]=1;s["Robaka"]=1;s["biezy"]=1;s["karabele"]=1;s["kedy"]=1;s["polowanie"]=1;s["powiecie"]=1;s["Ahenobarba"]=2;s["Gor"]=2;s["Grecy"]=2;s["Kastora"]=2;s["Kryspinilla"]=2;s["Kwartus"]=2;s["Pomyslal"]=2;s["Poppee"]=2;s["Rubria"]=2;s["Rzymem"]=2;s["Tlumy"]=2;s["Tullianum"]=2;s["boga"]=2;s["carissime"]=2;s["czuwac"]=2;s["czynila"]=2;s["dobrem"]=2;s["dochodzily"]=2;s["filozof"]=2;s["kaplani"]=2;s["kaplanow"]=2;s["lutnie"]=2;s["milowac"]=2;s["niesc"]=2;s["oraz"]=2;s["orszak"]=2;s["owce"]=2;s["plaszcza"]=2;s["prefekt"]=2;s["rzymskiego"]=2;s["rzymskim"]=2;s["skrecili"]=2;s["uczynie"]=2;s["zmartwychwstal"]=2;s["Bernardyn"]=1;s["Dobrzynskich"]=1;s["Iz"]=1;s["Litwa"]=1;s["Polski"]=1;s["Rejentem"]=1;s["Scyzoryk"]=1;s["Soplice"]=1;s["chartow"]=1;s["jegry"]=1;s["rury"]=1;s["stola"]=1;s["tem"]=1;s["Atacynus"]=2;s["Augustianie"]=2;s["Dolow"]=2;s["Italii"]=2;s["Kwirytow"]=2;s["Plaucjuszow"]=2;s["Rufiusa"]=2;s["Subury"]=2;s["Tybru"]=2;s["Ursusowi"]=2;s["Wydalo"]=2;s["barbarzyncow"]=2;s["bogiem"]=2;s["cyprysow"]=2;s["dymy"]=2;s["lektyka"]=2;s["muly"]=2;s["nocami"]=2;s["oddychac"]=2;s["oddzialy"]=2;s["plonace"]=2;s["pozarze"]=2;s["przybrany"]=2;s["spiewem"]=2;s["tegoz"]=2;s["trybunie"]=2;s["uczt"]=2;s["westalka"]=2;s["wystapic"]=2;s["wyznawcy"]=2;s["zaulki"]=2;s["By"]=1;s["Hrabi"]=1;s["Prusak"]=1;s["Rebajlo"]=1;s["Rejenta"]=1;s["Rykowa"]=1;s["Soplicy"]=1;s["Srod"]=1;s["Wtenczas"]=1;s["bernardyn"]=1;s["jegrow"]=1;s["kropic"]=1;s["litewskich"]=1;s["mopanku"]=1;s["pono"]=1;s["ramiony"]=1;s["zascianku"]=1;s["Ahenobarbus"]=2;s["Albanskich"]=2;s["Baiae"]=2;s["Benewentu"]=2;s["Christo"]=2;s["Chrystusie"]=2;s["Cuchnacych"]=2;s["Domicjusz"]=2;s["Emporium"]=2;s["Eurycjusz"]=2;s["Kampanii"]=2;s["Kapitol"]=2;s["Krotonem"]=2;s["Merkurego"]=2;s["Nazariusza"]=2;s["Neronowi"]=2;s["Terpnos"]=2;s["Tyber"]=2;s["Widocznym"]=2;s["Widziano"]=2;s["biodrach"]=2;s["czyniono"]=2;s["kaganek"]=2;s["lektyce"]=2;s["marmuru"]=2;s["odnalazl"]=2;s["oliwy"]=2;s["pacholeta"]=2;s["plonacego"]=2;s["podniosly"]=2;s["porywac"]=2;s["prefektem"]=2;s["pretorianom"]=2;s["robotnika"]=2;s["rozpocznie"]=2;s["senatorowie"]=2;s["tabliczki"]=2;s["tchnieniem"]=2;s["tejze"]=2;s["troski"]=2;s["trybuna"]=2;s["tryumf"]=2;s["uczynilo"]=2;s["uniesienie"]=2;s["wszechmocny"]=2;s["wyzwolenca"]=2;s["zlotowlosa"]=2;s["Asesora"]=1;s["Bracie"]=1;s["Chrzciciela"]=1;s["Dobrzynie"]=1;s["Ktorych"]=1;s["Litwy"]=1;s["Moskalow"]=1;s["Pluta"]=1;s["Podkomorzego"]=1;s["Pyta"]=1;s["Sak"]=1;s["Scyzorykiem"]=1;s["Skoluba"]=1;s["Soplicowa"]=1;s["Stoja"]=1;s["konopie"]=1;s["lowach"]=1;s["mysliwcow"]=1;s["ochmistrzyni"]=1;s["polskie"]=1;s["strzelby"]=1;s["traw"]=1;s["wloscian"]=1;s["wszerz"]=1;s["zareczyny"]=1;s["Afer"]=2;s["Agryppy"]=2;s["Arycji"]=2;s["Augusto"]=2;s["Benewencie"]=2;s["Cezara"]=2;s["Cie"]=2;s["Cumae"]=2;s["Cyrku"]=2;s["Demas"]=2;s["Diodor"]=2;s["Flawiusz"]=2;s["Fortuna"]=2;s["Glaukos"]=2;s["Grecja"]=2;s["Hades"]=2;s["Karynach"]=2;s["Ligowie"]=2;s["Markus"]=2;s["Mniejszej"]=2;s["Salaria"]=2;s["Tyberiusza"]=2;s["Tygellinie"]=2;s["Uczyn"]=2;s["Watyniusza"]=2;s["Witeliusza"]=2;s["Zrozumial"]=2;s["augustianina"]=2;s["centuriona"]=2;s["cesarskiego"]=2;s["chrzest"]=2;s["czynili"]=2;s["dech"]=2;s["doszli"]=2;s["fontannie"]=2;s["kleknal"]=2;s["ligijski"]=2;s["mirtow"]=2;s["morduja"]=2;s["naloznica"]=2;s["nieprzebrane"]=2;s["obozu"]=2;s["oczekiwania"]=2;s["odleglych"]=2;s["ogarniac"]=2;s["okazywal"]=2;s["patrycjusza"]=2;s["plomienia"]=2;s["podpalic"]=2;s["podziemia"]=2;s["pomste"]=2;s["posilku"]=2;s["pozogi"]=2;s["prawdzie"]=2;s["przebraniu"]=2;s["przybrane"]=2;s["przypuszczenia"]=2;s["rozpoznal"]=2;s["rzez"]=2;s["rzut"]=2;s["senatu"]=2;s["velarium"]=2;s["widzom"]=2;s["wladca"]=2;s["wokol"]=2;s["wskaze"]=2;s["zaslubic"]=2;s["znad"]=2;s["Biezy"]=1;s["Brzytewka"]=1;s["Brzytwa"]=1;s["Dawal"]=1;s["Dobyl"]=1;s["Hejze"]=1;s["Hrabiemu"]=1;s["Jacku"]=1;s["Kedy"]=1;s["Kniaziewicz"]=1;s["Kropidlo"]=1;s["Kusego"]=1;s["Kusy"]=1;s["Mopanku"]=1;s["Moskale"]=1;s["Polszcze"]=1;s["Radziwill"]=1;s["Rozga"]=1;s["Rymsza"]=1;s["Sokola"]=1;s["Strzelcy"]=1;s["Telimene"]=1;s["Zgoda"]=1;s["ascka"]=1;s["chwaly"]=1;s["drazki"]=1;s["dumania"]=1;s["dziedzica"]=1;s["kontusza"]=1;s["kryjomu"]=1;s["kurki"]=1;s["lice"]=1;s["liku"]=1;s["mysliwi"]=1;s["mysliwych"]=1;s["nazbyt"]=1;s["oblawa"]=1;s["ogary"]=1;s["owad"]=1;s["pleban"]=1;s["plebana"]=1;s["polowania"]=1;s["pospieszal"]=1;s["ptastwo"]=1;s["rzadka"]=1;s["sasiedzie"]=1;s["szabli"]=1;s["tabaki"]=1;s["wasc"]=1;s["wiwat"]=1;s["zawzdy"]=1;s["Apostolow"]=2;s["Apostolowi"]=2;s["Appijskiej"]=2;s["Aula"]=2;s["Chilonides"]=2;s["Corioli"]=2;s["Egiptu"]=2;s["Galow"]=2;s["Grekow"]=2;s["Juniusz"]=2;s["Kalwia"]=2;s["Klaudiusza"]=2;s["Neronem"]=2;s["Nerwa"]=2;s["Nomentana"]=2;s["Portuensis"]=2;s["Rzymian"]=2;s["Stroze"]=2;s["Suburze"]=2;s["Urbanie"]=2;s["Ustrinum"]=2;s["Wschodzie"]=2;s["Zeusie"]=2;s["bluszczow"]=2;s["bramami"]=2;s["cudnych"]=2;s["cyrk"]=2;
    cin>>testow;
    cin.ignore(1);
    for(int j=0;j<testow;j++){
        getline(cin,mic);
        slowo="";
        wynik = 0;
        //int i=0;
        //while(mic[i] != roz)
        for(int i = 0; i <mic.size(); i++){
            if(mic[i]>='0' && mic[i]<='9'){
                slowo+=mic[i];
            }
            else if(mic[i]>='A' && mic[i]<='Z'){
                slowo+=mic[i];
            }
            else if(mic[i]>='a' && mic[i]<='z'){
                  slowo+=mic[i];
            }
            else{
                if(s.find(slowo)!=s.end()){
                    w[j]=s.find(slowo)->second;
                    
                }
                slowo="";

            }
        }
        
    }
    
    
    for(int i=0;i<testow;i++){
        
        if(w[i]==0){
            cout<<"Prus\n";
        }
        else if(w[i]==1){
            cout<<"Mickiewicz\n";
        }
        else{
            cout<<"Sienkiewicz\n";
        }
    }
    return 0;
}
