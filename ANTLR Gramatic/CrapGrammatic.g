grammar CrapGrammatic;

options
{
language=C;
output=AST;
}

tokens
{
	PLUS= '+';
	MINUS= '-';
	PROD='*';
	PER_PROD='.*';
	DIV='/';
	PER_DIV='./';
	POT='^';
	PER_POT='.^';
	TRANS='\'';
	
	EQUAL='=';
	
}

entry	:	 empty | asignation | expression | plot ;

//esta es la 'salida', si el usuario no ingresa nada entonces se completa un espacio en blanco
//y se considera como que no se ingreso nada y se espera un proximo ingreso
//Esto soluciona el error de gramatica producto de un ingreso vacio
empty	:	' '	
	;

//expression es un termino
expression
	:   subterm SP? ( (PLUS|MINUS)^ SP? subterm)* notprint?
	;
subterm	
	:	(potence) SP? ((PER_PROD|PER_DIV|PROD|DIV)^ SP? potence)*	
	;
potence	
	:	(function|Number|Variable|PreChar|array) SP? ((POT|PER_POT)^ SP? (function|Number|Variable|PreChar|array) )*
	;
function	
	:	( 'sin'^ SP? '('! SP? (expression) SP? ')'! ) 	| 
		( 'cos'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'tan'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'sqrt'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'abs'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'exp'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'log'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'log10'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'floor'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'ceil'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'asin'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'acos'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'atan'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'sinh'^ SP? '('! SP? (expression) SP? ')'! )	|		
		( 'cosh'^ SP? '('! SP? (expression) SP? ')'! ) 	|		
		( 'tanh'^ SP? '('! SP? (expression) SP? ')'! )  |
		( 'size'^ SP? '('! SP? (expression) SP? ')'! )	|
		( 'round'^ SP? '('! SP? (expression) SP? ')'! )	|
		( 'cross'^ SP? '('! SP?  (expression) SP? ','! SP? (expression) SP? ')'! ) |
		( 'trapz'^ SP? '('! SP?  (expression) SP? ','! SP? (expression) SP? ')'! ) |
		//( 'der1_2p'^ SP? '('! SP?  (expression) SP? ','! SP? (expression) SP? ')'! ) |
		( 'der1'^/*_3p*/ SP? '('! SP?  (expression) SP? ','! SP? (expression) SP? ')'! ) |
		( 'der2'^/*_3p*/ SP? '('! SP?  (expression) SP? ','! SP? (expression) SP? ')'! ) |
		( 'der3'^/*_4p*/ SP? '('! SP?  (expression) SP? ','! SP? (expression) SP? ')'! ) |
		( 'der4'^/*_5p*/ SP? '('! SP?  (expression) SP? ','! SP? (expression) SP? ')'! ) |
		( 'rand'^/*_5p*/ SP? '('! SP?  (expression) SP? ','! SP? (expression) SP? ')'! ) |
		( 'det'^/*_5p*/ SP? '('! SP?  (expression) SP? ')'! ) |
		( 'ones'^/*_5p*/ SP? '('! SP?  (expression) SP? ')'! ) |
		( 'zeros'^/*_5p*/ SP? '('! SP?  (expression) SP? ')'! ) |
		( 'inv'^/*_5p*/ SP? '('! SP?  (expression) SP? ')'! ) |
		( 'gauss'^/*_5p*/ SP? '('! SP?  (expression) SP? ')'! ) |
		( 'res'^/*_5p*/ SP? '('! SP?  (expression) SP? ')'! ) |
		( 'adj'^/*_5p*/ SP? '('! SP?  (expression) SP? ')'! ) |
		( 'gaussv'^/*_5p*/ SP? '('! SP?  (expression) SP? ')'! ) |
		( '-'^/*_5p*/  SP?  (function|Number|Variable|PreChar|array) SP?  )
	;
	

asignation
	:	(Variable|PreChar) SP? EQUAL^ SP? (expression)
	;		

basic_array
	:
		'['^
		 SP? expression SP? ( ( ','! SP? expression)* | ( ':' SP? expression? SP? ':' SP? expression ) ) 
		(';' SP? expression SP? ( ( ','! SP? expression)* | ( ':' SP? expression? SP? ':' SP? expression ) ) )* 
		']'!
	;
	
array	:	 basic_array		//|
		//basic_array SP? TRANS^
	;
	
plot	:	'plot'^ SP? '('! SP? (expression) SP? ','! SP? (expression) SP? ')'!
	;
	
notprint
	:	';'
	;
		//si se descomenta este menos unario, deja deandar el operador binario menos!
Number	:	SP?  /*MINUS? SP?*/ ( ( (Digit)+ ( '.' (Digit)+ )? ) | ('pi'|'PI') | ('e'|'E') ) SP?
	;
Digit	:	('0'..'9') 
	;
SP	:	(' ')+ 	{ $channel = HIDDEN; }
	;


PreChar:	( ('A'..'Z') | ('a'..'z') | '_' )
	;
PostChar:	(PreChar | Digit)
	;
Variable:	PreChar PostChar*
	;


