# Esercizio C++ - Mini File Browser

## USAGE
Una volta aperto il programma scansiona una cartella, in seguito è possibile fare i seguenti comandi:<br>
- dir (stampa il contenuto della cartella corrente)
- cd nuovaCartella (cambia la cartella corrente in nuovaCartella)
- cd.. (imposta la cartella parent come cartella corrente)
- open nomeFile (apre il file nomeFile)
- search something (cerca nella cartella corrente e nelle sottocartelle e stampa i nomi dei file che contengono “something”)
- exit (chiude il programma)

## DESCRIPTION
Creare un mini file browser che gestisca 4 tipi di file: txt, jpg, mp3, mp4<br>
Il programma inizia scansionando il contenuto di una cartella (hardcodata) e organizza i file/cartelle in una struttura dati apposita.<br><br>
Per salvare i dati (lista di file e cartelle) creare una struttura dati che implementi le seguenti funzionalità:
- Aggiunta di file
- Ricerca
- Stampa file/directory contenute in una cartella

Implementare un comando per cambiare la cartella corrente (tipo cd di windows)<br>
Ogni tipo di file deve essere stampato in modo diverso quando stampo il contenuto di una cartella (es. Testo: nomefile.txt; Immagine: nome.jpeg ecc…)<br>
Deve essere possibile aprire il file
