#inclue <systemc.h>

SC_MODULE(tb)
{
	sc_in<bool> clk;
	sc_out<bool> rst;
	sc_out<sc_int<16>> inp;
	sc_in<sc_int<16>> outp;

	void source();
	void sink();

	SC_CTOR(tb){
		SC_CTHREAD(source,clk.pos());
		SC_CTHREAD(sink,clk.pos());
	}
}