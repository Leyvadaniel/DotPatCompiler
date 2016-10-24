GVList{int F;}

void factorial ( int x ){	
	if( x > 1 ) then
		call factorial(x-1);
	done
	F = F * x;
}
main{
	F = 1;
	call factorial(5);
	print(F);
}
