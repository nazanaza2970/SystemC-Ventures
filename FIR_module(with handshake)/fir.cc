//Coefficients for each fir
const sc_uint<8> coef[5] = {
	18,
	77,
	107,
	77,
	18
};

#include "fir.h"

//FR main thread


void fir::fir_main(void)
{

	sc_int<16> taps[5];

	//Reset protocol
	for(int i = 0; i<5; i++){
		taps[i] = 0;
	}

	//Initializing handshake
	inp_rdy.write(0);
	outp_vld.write(0);
	outp.write(0);
	wait();

	//FIR filter
	while(true){
		sc_int<16> in_val;
		sc_int<16> out_val;

		inp_rdy.write(1);
		do{
			wait();
		}while(!inp_vld.read());
		in_val = inp.read();
		inp_rdy.write(0);

		//Read input into shift registers
		for(int i = 5-1;i>0; i--){
			taps[i] = taps[i-1]
		}
		taps[0] = in_val;

		//Perform multipky and accumulate
		for(int i = 0; i<5; i++){
			out_val += coef[i]*taps[i];
		}

		outp_vld.write(1);
		do{
			wait();
		}while(!out_rdy.read());
		outp.write(out_val);
		outp_vld.write(0);
		
	}
}