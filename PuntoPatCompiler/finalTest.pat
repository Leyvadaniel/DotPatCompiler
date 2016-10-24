GVList{float F; bool ran;}

void randomizer ( float x ){	
	if (ran == true) 
		then
			F = F * x;
		done
	else
			F =F + 2;
		done
}
void rerandomizer (float x){
	call randomizer (x * F);
	print(F);
}
main{
	VList { int numeroEntrada; bool x;}
	x = true;
	
		print('N','1');
		receive(numeroEntrada);
		print(numeroEntrada);
		send_d(numeroEntrada);
		call randomizer(numeroEntrada);
		
		loop(x) do
		if(F <=20)
			then
				F = F * 2;
				ran = false;
				call randomizer(F);
				print(F);
			done
		F=F*1.5;
		if(F > 120)
			then
				print('F','E','L','I','C','I','D','A','D','E','S');
					send_bool(true);
					send_bool(false);
					send_bool(true);
					send_bool(false);
					x= false;
			done

	end	
}
