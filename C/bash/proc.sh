#trouver les liens symboliques d'un fichier dans un répertoire
#DEBUT
switch($#argv)
case 2:
set f=$1
set rep=$2
breaksw

default:
echo  "Ce programme afficher tous les liens symboliques d'un fichier "
echo  "usage : ./prog  file_name répertorie"
exit

endsw

if(! -d $rep) then
echo le repertoire $rep n’existe pas
exit
endif

if (! -f $r/$f) then
echo le fichier $f n’existe pas
exit
endif

tree $rep | grep –e  "-> $f"
