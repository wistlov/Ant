# Ant
CPP project

Strukturen (Hvordan ting henger sammen)

Forklare hva som er i hver fil

Logikken bak maurene

Intro og overskrift

Dokumentasjon:

ant: – Basisklassen for alle typer maur.

Har ansvar for:

Posisjon (både "ekte" rutenettposisjon og visuell posisjon)

Retning og fart

Animasjon (veksler mellom to sprites)

Endring av retning (change_direction)

Oppdatering hver frame (posisjon + animasjon)

Animated_Ant – Arver fra Ants. Brukes til maur (eller skyer) som går automatisk og teleporterer tilbake når de forlater skjermen.

Player_Ant – En spesialisert Ants som styres av brukeren.

Leser input (f.eks. "up", "left", ...) og forsøker å snu i den retningen.

Har funksjoner for å sjekke:

Kollisjon med vegger

Treff på mat

Follower_Ant – Maur som følger etter spilleren, lik "halen" i Snake.

Tar imot et mål (set_destination)

Går mot målet, og stopper når den er fremme

Har en id, sannsynligvis for å holde orden på rekkefølgen i halen

Cloud – En slags sky basert på Animated_Ant, som bruker en annen sprite og er større i størrelse.

Når spillet kjøres, lages det én Player_Ant som spilleren kontrollerer.


Etter hvert kan det lages Follower_Ant-objekter som følger etter spilleren.


Maurene beveger seg på et rutenett, og når de beveger seg én rute (64 piksler), oppdateres den interne posisjonen.


Animasjonssprites veksles etter en intern klokke basert på hastighet.


Hvis spilleren treffer mat eller vegger, kan det oppstå endringer i spilletilstanden (f.eks. poeng, tap, o.l.).


food:

game:

GUI:

highscore inneholder: highscore_menu, difficulty_menu, control_menu og paused_menu. Disse blir kalt i game.cpp for å lage de forskjelige game_screens. Kjapt fortalt det er bare utsene hovedsakelig. highscore_menu kaller også på text-filen vår scores.txt som printer ut highscore i tabellen som er laget.

main kjører funksjonen play_gmae og spillet begynner

reasources inneholder alle bildene som blir brukt, de blir innisialisert.

save_and_load lagrer informasjon som blir skrevet i i terminalen etter at game_over funksjonen blir kjørt. Det blir lagret og så skrevet inn i highscore. Det er også et av stedene hvor vi bruker error chatch. 

REFLEKSJONS NOTAT:

Det som er lett å se er at koden er veldig komplex og veldig skjør, det er fordi vi læret mens vi jobbet og når vi lærte og fikk feilmeldinger fikset vi det med hva vi lærte, men gikk ikke lengre tilbake slik at tidligere kode forble som det var. Vi tok oss ikke nok tid til å jobbe med prosjektet. Vi trodde innlevering var etter påske slik at vi kunne jobbbe med de i påsken og fin pusse det veldig da slik at alt skulle være bra. Det er mange steder hvor vi kunne ha brukt case eller enmu classes. Spesilt på Buttons, som det er veldig mange av nå, så det blir mye reprtiasjon som fører til at programmet evt kjører sakte. Vi burde ha jobbet mye mer forrige uke, denne uken har vi jobbet omtrent 6-8 timer hver dag. Utviklingen av dette programmet har vært veldig gøy, men det har krevd mye av oss. Det er mye som kan bli forbedret, men selve produktet er noe vi er fornøyd med. 