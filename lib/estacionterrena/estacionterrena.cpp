#include "estacionterrena.h"
#include <iostream>
#include <algorithm>

using namespace std;

EstacionTerrena::EstacionTerrena(std::string nombre, std::vector<Task *> tareas, std::vector<Satelite *> satelites)
:name(nombre), tasks(tareas), satellites(satelites){
	cout<<"Estacion terrena: "<<name<<endl;
	cout<<"Tareas:"<<endl;
	for (auto &t:tasks){
		cout<<*t<<endl;
	}
	cout<<"Satelites:"<<endl;
	for (auto &s:satellites){
		cout<<*s<<endl;
	}
}

// lanza los clientes de cada satalite
void EstacionTerrena::run(){
	for (auto &s:satellites){
		if(s->connect2sat()==0){
			cout<<"Conectado a ";
		} else {
			cout<<"Fallo conexion a ";
		}
		cout<<s->getName()<<" at port "<<s->getPort()<<endl;
	}
	return;
}

// asigna tareas a cada satelite y las ejecuta
void EstacionTerrena::work(){
	
	assignTasks();
	cout<<"Tareas por satelite:"<<endl;
	for (auto &s:satellites){
		cout<<*s<<endl;
		cout<<"Ejecutando..."<<endl;
		s->execute();
	}
}

// Detiene el cliente de cada satelite
void EstacionTerrena::stop(){
	for (auto &s:satellites){
		if(s->stop()==0){
			cout<<"Se detuvo conexion a ";
		} else {
			cout<<"Fallo detencion de conexion a ";
		}
		cout<<s->getName()<<" at port "<<s->getPort()<<endl;
	}
	return;
}

// asigna tareas a cada satelite dependiendo del payload
// y uso de recursos
void EstacionTerrena::assignTasks(void){
	std::sort(tasks.begin(), tasks.end());
	int flag;
	for(size_t i=0;i<tasks.size(); ++i){
		if(tasks[i]->isAttended()) continue;
		for(size_t k=0;k<satellites.size(); k++){
			flag=0;
			for(auto j:tasks[i]->resources){
				if(satellites[k]->usingResource(j)){
					flag=1;
					break;
				}
			}
			if (flag==0) {
				satellites[k]->addTask(tasks[i]);
				break;
			}
		}
	}
}

const std::vector<Task*> &EstacionTerrena::getTasks(){
	return tasks;
}
