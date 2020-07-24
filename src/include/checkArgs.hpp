#ifndef _CHECKARGS_H_
#define _CHECKARGS_H_

#include <unistd.h>

extern char *optarg;
extern int optind, opterr, optopt;

class checkArgs {
private:
	// 1) Modificar esta sección
	const std::string optString = "N:t:l:L:h";
	
	const std::string opciones = "-N num -t num -l num -L num [-h]";

	const std::string descripcion  = "Descripción:\n"
	                                 "\t-N   :tamaño  del arreglo\n"
					 "\t-t   :numero de threads\n"
					 "\t-l   :limite inferior rango aleatorio\n"
					 "\t-L   :limite inferior rango aleatorio\n"
					 "\t-[h] :Muestra la ayuda de uso y termina\n";
	
	typedef struct args_t{
		uint64_t TamanioArreglo;
		uint32_t NumThreads;
		uint32_t LimiteInf;
		uint32_t LimiteSup;
	} args_t;
	
	args_t  parametros;
	
	int argc;
	char **argv;

	
public:
	checkArgs(int _argc , char **_argv);
	~checkArgs();
	args_t getArgs();
	
private:
	void printUsage();
};

checkArgs::checkArgs(int _argc , char **_argv){
	parametros.TamanioArreglo =  0;
	parametros.NumThreads  = 0;
	parametros.LimiteInf  = 0;
	parametros.LimiteSup  = 0;

	argc = _argc;
	argv = _argv;
	
}

checkArgs::~checkArgs(){
	
}

checkArgs::args_t checkArgs::getArgs(){
	int opcion;
	
	while ((opcion = getopt (argc, argv, optString.c_str())) != -1){
		switch (opcion) {
			case 'N':
					parametros.TamanioArreglo = atoi(optarg);
					break;
			case 't':
					parametros.NumThreads = atoi(optarg);
					break;
			case 'l':
					parametros.LimiteInf = atoi(optarg);
					break;
			case 'L':
					parametros.LimiteSup = atoi(optarg);
					break;
			case 'h':
			default:
					printUsage();
					exit(EXIT_FAILURE);
		}
	}

	if ( parametros.TamanioArreglo == 0 || parametros.NumThreads == 0 || parametros.LimiteSup == 0){
		printUsage();
		exit(EXIT_FAILURE);
	}
	
	return(parametros);
}

void checkArgs::printUsage(){
	std::cout << "Uso: " <<
		argv[0] << " " << opciones << " " << descripcion << std::endl;
}



#endif

