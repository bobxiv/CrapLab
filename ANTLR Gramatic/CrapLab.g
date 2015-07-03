grammar CrapLab;

@header{
	#include <Store.h>

}

@options{


}


	
	Num	: 	('0'..'9')+
		;
		
	ID 	:	('a'..'z'|'A'..'Z')+
		;
			
		
		
	SP 	:       (' ')+
		;
	Del	:	(';')
		;
	Plus	:	('+')
		;
	Minus	:	('-')
		;
	Prod	:	('*'|'.*')
		;
	Div	:	('/'|'./')
		;
		
		
	
	Expr	:	(ID|Num) SP* (Plus|Minus|Prod|Div) SP* (ID|Num)
		;
	

	Asig 	:	('=')
		;
	

	Matrix	:	'[' ( Num (SP|Del)+ )* ']'
		;
	
	
	res	:	Expr+
	
		{
				
			}
		;
	


	
	


	
