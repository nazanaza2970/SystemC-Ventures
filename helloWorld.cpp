#include <systemc>
SC_MODULE(Hello_SystemC){
	
	SC_CTOR(Hello_SystemC){
	SC_THREAD(man_thread);
	}

	void main_thread(void){
		SC_REPORT_INFO("Hello SystemC World!");
	}
};

int sc_main(int st_argc, char* sc_argv[]){
	Hello_SystemC HelloWorld_i("HelloWorld_i");

	sc_start();

	return 0;
}