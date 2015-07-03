lexer grammar CrapGrammatic;
options {
  language=C;

}

PLUS : '+' ;
MINUS : '-' ;
PROD : '*' ;
PER_PROD : '.*' ;
DIV : '/' ;
PER_DIV : './' ;
POT : '^' ;
PER_POT : '-^' ;
TRANS : '\'' ;
EQUAL : '=' ;
T20 : ' ' ;
T21 : '(' ;
T22 : ')' ;
T23 : 'sin' ;
T24 : 'cos' ;
T25 : 'tan' ;
T26 : 'sqrt' ;
T27 : 'abs' ;
T28 : 'exp' ;
T29 : 'log' ;
T30 : 'log10' ;
T31 : 'floor' ;
T32 : 'ceil' ;
T33 : 'asin' ;
T34 : 'acos' ;
T35 : 'atan' ;
T36 : 'sinh' ;
T37 : 'cosh' ;
T38 : 'tanh' ;
T39 : 'size' ;
T40 : 'round' ;
T41 : 'cross' ;
T42 : ',' ;
T43 : 'trapz' ;
T44 : 'der1' ;
T45 : 'der2' ;
T46 : 'der3' ;
T47 : 'der4' ;
T48 : 'rand' ;
T49 : 'det' ;
T50 : 'ones' ;
T51 : 'zeros' ;
T52 : 'inv' ;
T53 : 'gauss' ;
T54 : 'res' ;
T55 : 'adj' ;
T56 : 'gaussv' ;
T57 : '[' ;
T58 : ':' ;
T59 : ';' ;
T60 : ']' ;
T61 : 'plot' ;

// $ANTLR src "C:\Users\BOB\Documents\ANTLR Gramatics\CrapGrammatic\CrapGrammatic.g" 111
Number	:	SP?  ( ( (Digit)+ ( '.' (Digit)+ )? ) | ('pi'|'PI') | ('e'|'E') ) SP?
	;
// $ANTLR src "C:\Users\BOB\Documents\ANTLR Gramatics\CrapGrammatic\CrapGrammatic.g" 113
Digit	:	('0'..'9') 
	;
// $ANTLR src "C:\Users\BOB\Documents\ANTLR Gramatics\CrapGrammatic\CrapGrammatic.g" 115
SP	:	(' ')+ 	{ $channel = HIDDEN; }
	;


// $ANTLR src "C:\Users\BOB\Documents\ANTLR Gramatics\CrapGrammatic\CrapGrammatic.g" 119
PreChar:	( ('A'..'Z') | ('a'..'z') | '_' )
	;
// $ANTLR src "C:\Users\BOB\Documents\ANTLR Gramatics\CrapGrammatic\CrapGrammatic.g" 121
PostChar:	(PreChar | Digit)
	;
// $ANTLR src "C:\Users\BOB\Documents\ANTLR Gramatics\CrapGrammatic\CrapGrammatic.g" 123
Variable:	PreChar PostChar*
	;


