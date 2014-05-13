Explication du fonctionnement de play_rtttl.

A l'origine, le RTTTL a été créé par Nokia. Il existe différentes documentations dont celle-ci qui est bien faite :
http://en.wikipedia.org/wiki/Ring_Tone_Transfer_Language


J'ai juste rajouté quelque nouvelles lettres afin de commander les servos :
Lettre	Opération
z	1 _\	2 /_	3 __
y	1 *\\	2 *\	3 *-	4 */	5 *//	~ **
x	1 //*	2 /*	3 -*	4 \*	5 \\*	~ **
w	1 //\\	2 /\	3 --	4 \/	5 \\//	~ **

Où
* => Non modifier
- => Horizontale
/, \ => Inclinaison médiane
//, \\ => Inclinaison maximale


Pour faciliter les animations, je commencé à mettre en place un serveur de données
htt://tipouic.dyndns.info:15380/rtttl.php
