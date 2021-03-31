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

	//Reset
	outp.write(0);
	wait();

	while(true){
	for(int i = 4; i>0; i--){
	taps[i] = taps[i-1];
		}
	taps[0] = inp.read();

	sc_int<16> val;
	for(int i = 0; i<5; i++){
			val+= coef[i]*taps[i];

		}

		outp.write(val);
	}
}