# Ant
Dokumentasjon:


ant: – Basisklassen for alle typer maur.


Har ansvar for:


Posisjon (både "ekte" rutenettposisjon og visuell posisjon)


Retning og fart


Animasjon (veksler mellom to sprites)


Endring av retning (change_direction)


Oppdatering hver frame (posisjon + animasjon)


Animated_Ant – Arver fra Ants. Brukes til maur (eller skyer) som går automatisk og teleporterer tilbake når de forlater skjermen. De er for menyen.


Player_Ant – En spesialisert Ants som styres av brukeren.


Leser input (f.eks. "up", "left", ...) og forsøker å snu i den retningen.


Har funksjoner for å sjekke:


Kollisjon med vegger


Treff på mat


Follower_Ant – Maur som følger etter spilleren, lik "halen" i Snake.


Tar imot et mål (set_destination)


Går mot målet, og stopper når den er fremme


Har en id for å holde orden på rekkefølgen i halen


Cloud – En sky basert på Animated_Ant, som bruker en annen sprite og er større i størrelse. For bakgrunnen i menyen.


Når spillet kjøres, lages det én Player_Ant som spilleren kontrollerer.


Etter hvert kan det lages Follower_Ant-objekter som følger etter spilleren.


Maurene beveger seg på et rutenett (13x13), og når de beveger seg én rute (64 piksler), oppdateres den interne posisjonen.


Animasjonssprites veksles etter en intern klokke basert på hastighet.


Hvis spilleren treffer mat vil nye maur legges til “halen”. De følger bare etter hverandre. Hvis spilleren treffer “halen” eller kanten av brettet vil det bety game over. 


food:
Inneholder food klassen


game:
Her er selve game loopen. Den er delt inn i mange ulike deler avhengig av hva game_screen er. 


GUI:
Inneholder en klasse som arver fra Animation Window. Det er selve vinduet og inneholder en del elementer som tegnes på skjermen.
I tillegg til det er masse knapper og andre funskjoner i GUI.h og cpp som tegner på skjermen.


highscore inneholder: highscore_menu, difficulty_menu, control_menu og paused_menu. Disse blir kalt i game.cpp for å lage de forskjelige game_screens. Kjapt fortalt det er bare utsene hovedsakelig. highscore_menu kaller også på text-filen vår scores.txt som printer ut highscore i tabellen som er laget.


main kjører funksjonen play_gmae og spillet begynner


reasources inneholder alle bildene som blir brukt, de blir innisialisert. (+ noen globale variable)


save_and_load lagrer informasjon som blir skrevet i i terminalen etter at game_over funksjonen blir kjørt. Det blir lagret og så skrevet inn i highscore. Det er også et av stedene hvor vi bruker error chatch.


REFLEKSJONS NOTAT:


Sondre:
Det som er lett å se er at koden er veldig komplex og veldig skjør, det er fordi vi lærte mens vi jobbet og når vi lærte og fikk feilmeldinger fikset vi det med hva vi lærte, men gikk ikke lenger tilbake slik at tidligere kode forble som det var. Vi tok oss ikke nok tid til å jobbe med prosjektet. Vi trodde at innlevering var etter påske slik at vi kunne jobbe med det i påsken og fin pusse det veldig da slik at alt skulle være bra. Det er mange steder hvor vi kunne ha brukt case eller enum classes. Noe som også kunne blitt bedre er Buttons, som det er veldig mange av nå. Det blir mye repitisjon som fører til at programmet evt kjører sakte. Ants er blitt mer optimalisert slik at det ikke skal bli et stort problem, men all maten og skyer er ikke blitt optimalisert slik at det vil kreve mer og mer minne, men det skal fungere over en lang periode uten noen problemer.
Vi burde ha jobbet mye mer forrige uke, denne uken har vi jobbet omtrent 6-8 timer hver dag. Utviklingen av dette programmet har vært veldig gøy, men det har krevd mye av oss. Det er mye som kan bli forbedret, men selve produktet er noe vi er fornøyd med.


William: 
Jeg og Sondre bestemte oss for å jobbe sammen, for vi hadde allerede en ide til et prosjekt vi hadde lyst til å lage sammen tidligere i semesteret. Det tok vi oss aldri tid til, før nå når vi måtte. Veldig glad vi gjorde det, for det har vært motiverende og gøy. 


Planen var å lage snake. Da vi søkte rundt på OpenGameArt.org fant vi en skikkelig søt liten maur sprite. Plutselig ble spillet et totalt unikt game som ikke har noe med snake å gjøre: Ant. 

Vi hadde et møte hvor vi bestemte oss for hva vi skulle ha i spillet. Det inkluderte en meny, selve spillet og en meny hvor man kan se poengsum.


Vi bestemte oss for å bruke GitHub for å jobbe sammen og delegerte arbeidsoppgaver. Jeg fokuserte mest på Ant.h og Ant.cpp mens Sondre tok seg av GUI og slikt. Selvfølgelig hjalp vi hverandre, men det var hovedfordelingen. 

Menyen tok oss 2 uker å lage. Plutselig hadde vi bare 1 uke igjen. Aka, mange timer jobbing hver dag, for vi manglet selve gamet. 
Utrolig hvor mange bugs det var…

I prosessen har mesteparten av koden blitt endret. Switch ble lagt til, noen funskjoner ble fjernet, en enum class måtte brukes og bilder ble pekere til bilder istedenfor. Tok utrolig lang tid, men vi lærte masse. 

Skulle jeg fortsatt på prosjektet ville jeg fikset opp i koden og strukturen. Game_screen kunne vært case 1, 2 osv for eksempel. Vi hadde dårlig tid på slutten så koden ble bare mer og mer rotete. En del ting som vi skulle ha inni Ant_Window ble aldri satt inn der, en del av bildene i resources er fortsatt ikke pekt mot osv. 

Til slutt vil jeg bare si: Klarte aldri å fikse en bug som dukker opp her og der. Veldig sjeldent, men noen ganger vil spiller mauren spise mat også kjøres en loop 30-50 ganger mer enn den skal. Satt med studass 3 timer i dag… fikk ikke løst det. Om det skjer, bare start på nytt. Skal ikke skje ofte.
