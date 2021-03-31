#include "tb.h"

void tb::source(){
	//Reset
	inp.write(0);
	rst.write(1);
	wait();
	rst.write(0);
	wait();

	sc_int<16> tmp;

	for(int i =0 ; i<64; i++){
		if(i>23 && i<29)
			tmp = 256;
		else
			tmp = 0;

		inp.write(tmp);
		wait();
	}
}

void tb::sink()
{
	sc_int<16> indata;
	for(int i = 0; i<64; i++)
	{
		indata = outp.read();
		cout <<i<<":\t"<<indata.to_int()<<endl;
	}

	sc_stop();
}