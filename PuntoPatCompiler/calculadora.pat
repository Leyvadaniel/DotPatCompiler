main{
	VList { int valorLlegadaUno, valorLlegadaDos, valorLlegadaTres, suma, resta, mult, termina; int respuesta; bool x;}
	
	suma = 0-3;
	resta = 0-1;
	mult = 0-2;
	termina = 0-4;

	x = true;
	loop(x) do
		print('V', '1');
		receive(valorLlegadaUno);
		print(valorLlegadaUno);
		send_d(valorLlegadaUno);

		print('V', '2');
		receive(valorLlegadaDos);
		print(valorLlegadaDos);
		send_d(valorLlegadaDos);

		print('O', 'P');
		receive(valorLlegadaTres);
		print(valorLlegadaTres);

		send_bool(true);
		send_bool(false);
		send_bool(true);
		send_bool(false);

		if(valorLlegadaTres == suma)
		then
			respuesta = valorLlegadaUno + valorLlegadaDos;
			send_b(respuesta);
		done
		if(valorLlegadaTres == resta)
		then
			respuesta = valorLlegadaUno - valorLlegadaDos;
			send_b(respuesta);
		done
		if(valorLlegadaTres == mult)
		then
			respuesta = valorLlegadaUno * valorLlegadaDos;
			send_b(respuesta);
		done
		if(valorLlegadaTres == termina)then
			x = false;
		done
		print('R');
		print(respuesta);
	end	
}
